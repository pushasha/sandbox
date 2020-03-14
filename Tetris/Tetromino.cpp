#include "Tetromino.h"

const Vector2 Tetromino::c_vec_y = Vector2(0, 1);
const Vector2 Tetromino::c_vec_x = Vector2(1, 0);

Vector2& Tetromino::get_pos()
{
	return position_;
}

void Tetromino::render(Sprite* block, const unsigned short int block_size, const unsigned short int border_size) const
{
	Colors::Color c = c_shape_colors[shape_];
	block->SetColor(c);
	for (size_t i = 0; i < c_num_blocks_per_tetromino; i++)
	{
		Vector2 block_pos = c_blocks[shape_][rotation_][i];
		block->Render((block_pos + position_) * (block_size - border_size));
	}
}

void Tetromino::rotate()
{
	rotation_ = (rotation_ + 1) % c_num_rotations;
}

void Tetromino::move(const Tetromino::Direction dir)
{
	// TODO: Check bounds before allowing movement
	switch (dir)
	{
		case Direction::DOWN:
			position_ += c_vec_y;
			break;
		case Direction::LEFT:
			position_ -= c_vec_x;
			break;
		case Direction::RIGHT:
			position_ += c_vec_x;
			break;
	}
}
