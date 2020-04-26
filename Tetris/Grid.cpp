#include "Grid.h"
#include <vector>

bool Grid::collides(const Vector2& pos, Tetromino::Shape shape, Movement::Rotation rot) const
{
	// for each block...
	const Vector2* blocks = Tetromino::get_blocks_for_shape_rotation(shape, rot);

	for (unsigned short i = 0; i < Tetromino::c_num_blocks_per_tetromino; i++)
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

void Grid::clear_row(int row)
{
	for (size_t i = 0; i < c_grid_width; i++)
	{
		grid_[i][row].clear();
	}

	// TODO: move everything above this row down

}

bool Grid::rotation_collides(const Tetromino* const piece) const
{
	Movement::Rotation rotated = Movement::get_next_rotation(piece->get_rotation());
	return collides(piece->get_pos(), piece->get_shape(), rotated);
}

bool Grid::direction_collides(const Tetromino* const piece, Movement::Direction dir) const
{
	const Vector2 piece_pos = (piece->get_pos()) + Movement::get_direction_vector(dir);

	return collides(piece_pos, piece->get_shape(), piece->get_rotation());
}

void Grid::add_tetromino(const Tetromino* const piece)
{
	const Vector2* const block_positions = piece->get_block_positions();
	const Colors::Color& block_color = piece->get_color();
	
	for (size_t i = 0; i < Tetromino::c_num_blocks_per_tetromino; i++)
	{
		Vector2 block_pos = block_positions[i];
		grid_[(int)block_pos.X()][(int)block_pos.Y()].set_fill(block_color);
	}
}

void Grid::hard_drop(Tetromino* const piece)
{
	const Vector2* block_offset_positions = Tetromino::get_blocks_for_shape_rotation(piece->get_shape(), piece->get_rotation());
	const Vector2* current_block_positions = piece->get_block_positions();
	float highest_origin_y = c_grid_height;

	for (unsigned short i = 0; i < Tetromino::c_num_blocks_per_tetromino; i++)
	{
		const Vector2 block_pos = current_block_positions[i];

		// get y value of highest block in column
		int highest_filled_y = c_grid_height;
		for (size_t i = 0; i < c_grid_height; i++)
		{
			if (grid_[(int)block_pos.X()][i].is_filled())
			{
				highest_filled_y = i;
				break;
			}
		}

		// Get origin of tetromino if block is is one above the highest filled block
		const Vector2 block_offset_pos = block_offset_positions[i];
		Vector2 origin = (Vector2(block_pos.X(), highest_filled_y) + Movement::get_direction_vector(Movement::Direction::UP)) - block_offset_pos;

		if (origin.Y() < highest_origin_y)
		{
			highest_origin_y = origin.Y();
		}
	}

	const Vector2 new_pos = Vector2(piece->get_pos().X(), highest_origin_y);
	piece->move(new_pos);
}

void Grid::check_and_clear_rows(const Tetromino* const piece)
{
	std::vector<int> rows_to_check = std::vector<int>();
	std::vector<int> rows_to_clear = std::vector<int>();

	const Vector2* current_blocks = piece->get_block_positions();

	// consolidate rows to check
	for (size_t i = 0; i < Tetromino::c_num_blocks_per_tetromino; i++)
	{
		bool already_checked = false;
		for (size_t j = 0; j < rows_to_check.size(); j++)
		{
			if (rows_to_check[j] == (int)current_blocks[i].Y())
			{
				already_checked = true;
				break;
			}
		}

		if (!already_checked)
		{
			rows_to_check.push_back((int)current_blocks[i].Y());
		}
	}

	// check rows to clear
	for (size_t i = 0; i < rows_to_check.size(); i++)
	{
		int row_to_check = rows_to_check[i];

		// check if clear
		bool found_empty = false;
		for (size_t j = 0; j < c_grid_width; j++)
		{
			if (!grid_[j][row_to_check].is_filled())
			{
				found_empty = true;
				break;
			}
		}

		if (!found_empty)
		{
			rows_to_clear.push_back(rows_to_check[i]);
		}
	}

	for (size_t i = 0; i < rows_to_clear.size(); i++)
	{
		clear_row(rows_to_clear[i]);
	}
}

void Grid::render() const
{
	for (size_t i = 0; i < c_grid_width; i++)
	{
		for (size_t j = 0; j < c_grid_height; j++)
		{
			grid_[i][j].render(g_square_sprite, Vector2(i, j));
		}
	}
}
