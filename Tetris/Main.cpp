#include "Core.h"
#include "Vector2.h"
#include "Sprite.h"
#include "Tetromino.h"
#include "GridSquare.h"
#include "Grid.h"
#include "HGE/hgefont.h"
#include <stdlib.h>

const Vector2 c_spawn_x = Vector2((float)(Grid::c_grid_width / 2), 0);
const int c_ticks_before_drop = 1000;
const int c_ticks_before_clear = 2;

Grid* g_grid;
Tetromino* g_current_piece = nullptr;
bool g_tetromino_locked;
bool g_game_lost = false;
int g_tick_count = 0;

bool try_spawn_piece(Tetromino*& piece)
{
	Tetromino::Shape shape = (Tetromino::Shape)(rand() % (int)Tetromino::Shape::NUM_SHAPES);
	piece = new Tetromino(shape, c_spawn_x);
	return !g_grid->collides(piece);
}

//Update loop
bool Update()
{
	if (g_game_lost)
	{
		return false;
	}

	if (g_tetromino_locked && g_current_piece != nullptr)
	{
		// add slight delay after tetromino is locked 
		if (g_tick_count < c_ticks_before_clear)
		{
			g_tick_count++;
			return false;
		}
		g_tick_count = 0;

		g_grid->check_and_clear_rows(g_current_piece);
		
		delete g_current_piece;
		g_current_piece = nullptr;
		g_tetromino_locked = false;
		
		return false;
	}

	if (g_current_piece == nullptr && !try_spawn_piece(g_current_piece))
	{
		g_game_lost = true;
		return false;
	}
	
	bool input_processed = false;
	if (g_hge->Input_KeyDown(HGEK_UP))
	{
		if (!g_grid->rotation_collides(g_current_piece)) 
		{
			g_current_piece->rotate();
		}
		input_processed = true;
	}

	if (!input_processed && g_hge->Input_KeyDown(HGEK_DOWN))
	{
		if (!g_grid->direction_collides(g_current_piece, Movement::Direction::DOWN))
		{
			g_current_piece->move(Movement::Direction::DOWN);
		}
		input_processed = true;
	}

	if (!input_processed && g_hge->Input_KeyDown(HGEK_LEFT))
	{
		if (!g_grid->direction_collides(g_current_piece, Movement::Direction::LEFT))
		{
			g_current_piece->move(Movement::Direction::LEFT);
		}
		input_processed = true;
	}

	if (!input_processed && g_hge->Input_KeyDown(HGEK_RIGHT))
	{
		if (!g_grid->direction_collides(g_current_piece, Movement::Direction::RIGHT))
		{
			g_current_piece->move(Movement::Direction::RIGHT);
		}
		input_processed = true;
	}

	if (!input_processed && g_hge->Input_KeyUp(HGEK_SPACE))
	{
		g_grid->hard_drop(g_current_piece);
		input_processed = true;
	}

	if (g_tick_count < c_ticks_before_drop)
	{
		g_tick_count++;
		return false;
	}

	if (g_grid->direction_collides(g_current_piece, Movement::Direction::DOWN))
	{
		g_grid->add_tetromino(g_current_piece);
		g_tetromino_locked = true;
	}
	else
	{
		g_current_piece->move(Movement::Direction::DOWN);
	}

	g_tick_count = 0; // reset tick counter
	return false;
}

//Render loop
bool Render()
{
	RenderBegin();

	if (g_game_lost)
	{
		// TODO: render text
	}
	else
	{
		g_grid->render();

		if (g_current_piece != nullptr)
		{
			g_current_piece->render(g_square_sprite, c_block_size, c_border_size);
		}
	}

	RenderEnd();
	return false;
}

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
	int width = ((c_block_size - c_border_size) * Grid::c_grid_width) + c_border_size;
	int height = ((c_block_size - c_border_size) * Grid::c_grid_height) + c_border_size;
	Initialize(width, height, Update, Render);

	if(IsInitialized())
	{
		const char* sprite_path = "..//square_3px_border.png";
		g_square_sprite = new Sprite(const_cast<char*>(sprite_path), Vector2(0, 0), Vector2(c_block_size, c_block_size));
		g_grid = new Grid();
		Run();
	}
	
	Shutdown();

	return 0;
}
