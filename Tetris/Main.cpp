#include "Core.h"
#include "Vector2.h"
#include "Sprite.h"
#include "Tetromino.h"
#include "GridSquare.h"
#include "Grid.h"

Grid* g_grid;
Tetromino* g_current_piece;
int g_tick_count = 0;
int g_ticks_before_drop = 1000;

//Update loop
bool Update()
{
	bool input_processed = false;
	if (g_hge->Input_KeyUp(HGEK_UP))
	{
		if (!g_grid->rotation_collides(g_current_piece)) 
		{
			g_current_piece->rotate();
		}
		input_processed = true;
	}

	if (!input_processed && g_hge->Input_KeyUp(HGEK_DOWN))
	{
		if (!g_grid->direction_collides(g_current_piece, Movement::Direction::DOWN))
		{
			g_current_piece->move(Movement::Direction::DOWN);
		}
		input_processed = true;
	}

	if (!input_processed && g_hge->Input_KeyUp(HGEK_LEFT))
	{
		if (!g_grid->direction_collides(g_current_piece, Movement::Direction::LEFT))
		{
			g_current_piece->move(Movement::Direction::LEFT);
		}
		input_processed = true;
	}

	if (!input_processed && g_hge->Input_KeyUp(HGEK_RIGHT))
	{
		if (!g_grid->direction_collides(g_current_piece, Movement::Direction::RIGHT))
		{
			g_current_piece->move(Movement::Direction::RIGHT);
		}
		input_processed = true;
	}

	if (!input_processed && g_hge->Input_KeyUp(HGEK_SPACE))
	{
		// TODO: Hard drop
		input_processed = true;
	}

	if (g_tick_count < g_ticks_before_drop)
	{
		g_tick_count++;
		return false;
	}

	if (g_grid->direction_collides(g_current_piece, Movement::Direction::DOWN))
	{

		// TODO: lock in place
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

	g_grid->render();
	g_current_piece->render(g_square_sprite, c_block_size, c_border_size);

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
		const char* path = "..//square_3px_border.png";
		g_square_sprite = new Sprite(const_cast<char*>(path), Vector2(0, 0), Vector2(c_block_size, c_block_size));
		g_current_piece = new Tetromino(Tetromino::Shape::Z);
		g_grid = new Grid();
		Run();
	}
	
	Shutdown();

	return 0;
}

