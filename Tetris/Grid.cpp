#include "Grid.h"

bool Grid::collides(const Vector2& pos, Tetromino::Shape shape, Movement::Rotation rot)
{
	// for each block...
	const Vector2* blocks = Tetromino::get_blocks_for_shape_rotation(shape, rot);

	for (unsigned short i = 0; i < c_num_blocks_per_tetromino; i++)
	{
		const Vector2 block_pos = blocks[i] + pos;

		// Make sure it's within grid bounds. If not, report collision.
		if (block_pos.Y() >= c_grid_height || block_pos.X() >= c_grid_width || block_pos.X() < 0)
		{
			return true;
		}

		if (grid_[(int)block_pos.X()][(int)block_pos.Y()].is_filled())
		{
			return true;
		}
	}

	return false;
}

bool Grid::rotation_collides(const Tetromino* const piece)
{
	Movement::Rotation rotated = Movement::get_next_rotation(piece->get_rotation());
	return collides(piece->get_pos(), piece->get_shape(), rotated);
}

bool Grid::direction_collides(const Tetromino* const piece, Movement::Direction dir)
{
	const Vector2 piece_pos = (piece->get_pos()) + Movement::get_direction_vector(dir);

	return collides(piece_pos, piece->get_shape(), piece->get_rotation());
}

void Grid::render()
{
	for (size_t i = 0; i < c_grid_width; i++)
	{
		for (size_t j = 0; j < c_grid_height; j++)
		{
			grid_[i][j].render(g_square_sprite, Vector2(i, j));
		}
	}
}
