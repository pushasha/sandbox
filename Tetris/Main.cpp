#include "Core.h"
#include "Vector2.h"
#include "Sprite.h"
#include "Tetromino.h"
#include "GridSquare.h"

constexpr int c_grid_width = 10;
constexpr int c_grid_height = 20;

Tetromino* g_current_piece;
GridSquare g_grid[c_grid_width][c_grid_height] = {};
int g_tick_count = 0;
int g_ticks_before_drop = 1000;

bool collides(const Tetromino* const piece, const GridSquare(&grid)[c_grid_width][c_grid_height], Movement::Direction dir)
{
	const Vector2 piece_pos = (piece->get_pos()) + Movement::get_direction_vector(dir);

	// for each block...
	const Vector2* blocks = piece->get_blocks();

	for (unsigned short i = 0; i < c_num_blocks_per_tetromino; i++)
	{
		const Vector2 block_pos = blocks[i] + piece_pos;

		// Make sure it's within grid bounds. If not, report collision.
		if (block_pos.Y() >= c_grid_height || block_pos.X() >= c_grid_width || block_pos.X() < 0)
		{
			return true;
		}

		if (grid[(int)block_pos.X()][(int)block_pos.Y()].is_filled())
		{
			return true;
		}
	}

	return false;
}

//Update loop
bool Update()
{
	bool input_processed = false;
	if (g_hge->Input_KeyUp(HGEK_UP))
	{
		g_current_piece->rotate();
		input_processed = true;
	}

	if (!input_processed && g_hge->Input_KeyUp(HGEK_DOWN))
	{
		if (!collides(g_current_piece, g_grid, Movement::Direction::DOWN))
		{
			g_current_piece->move(Movement::Direction::DOWN);
		}
		input_processed = true;
	}

	if (!input_processed && g_hge->Input_KeyUp(HGEK_LEFT))
	{
		if (!collides(g_current_piece, g_grid, Movement::Direction::LEFT))
		{
			g_current_piece->move(Movement::Direction::LEFT);
		}
		input_processed = true;
	}

	if (!input_processed && g_hge->Input_KeyUp(HGEK_RIGHT))
	{
		if (!collides(g_current_piece, g_grid, Movement::Direction::RIGHT))
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

	if (collides(g_current_piece, g_grid, Movement::Direction::DOWN))
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
	int width = ((c_block_size - c_border_size) * c_grid_width) + c_border_size;
	int height = ((c_block_size - c_border_size) * c_grid_height) + c_border_size;
	Initialize(width, height, Update, Render);

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

