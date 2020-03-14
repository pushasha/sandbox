#include "Core.h"
#include "Vector2.h"
#include "Sprite.h"
#include "Tetromino.h"
#include "GridSquare.h"

constexpr int c_grid_width = 10;
constexpr int c_grid_height = 20;

Tetromino* g_current_piece;
GridSquare g_grid[10][20] = {};
int g_tick_count = 0;
int g_ticks_before_drop = 1000;

//Update loop
bool Update()
{
	if (g_hge->Input_KeyUp(HGEK_UP))
	{
		g_current_piece->rotate();
	}

	if (g_hge->Input_KeyUp(HGEK_DOWN))
	{
		g_current_piece->move(Tetromino::Direction::DOWN);
	}

	if (g_hge->Input_KeyUp(HGEK_LEFT))
	{
		g_current_piece->move(Tetromino::Direction::LEFT);
	}

	if (g_hge->Input_KeyUp(HGEK_RIGHT))
	{
		g_current_piece->move(Tetromino::Direction::RIGHT);
	}

	if (g_hge->Input_KeyUp(HGEK_SPACE))
	{
		
		// TODO: Hard drop
	}

	if (g_tick_count < g_ticks_before_drop)
	{
		g_tick_count++;
		return false;
	}

	if (g_current_piece->get_pos().Y() >= c_grid_height)
	{
		// TODO: lock in place
	}
	else
	{
		g_current_piece->move(Tetromino::Direction::DOWN);
	}

	g_tick_count = 0; // reset tick counter
	return false;
}

//Render loop
bool Render()
{
	RenderBegin();

	for (size_t i = 0; i < c_grid_width; i++)
	{
		for (size_t j = 0; j < c_grid_height; j++)
		{
			g_grid[i][j].render(g_square_sprite, Vector2(i, j));
		}
	}

	g_current_piece->render(g_square_sprite, c_block_size, c_border_size);

	RenderEnd();
	return false;
}

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
	Initialize(293, 583, Update, Render); // 10 x 20

	if(IsInitialized())
	{
		const char* path = "..//square_3px_border.png";
		g_square_sprite = new Sprite(const_cast<char*>(path), Vector2(0, 0), Vector2(c_block_size, c_block_size));
		g_current_piece = new Tetromino(Tetromino::Shape::Z);
		Run();
	}
	
	Shutdown();

	return 0;
}


