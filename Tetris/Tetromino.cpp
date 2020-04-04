#include "Tetromino.h"

Tetromino::Shape Tetromino::get_shape() const
{
	return shape_;
}

const Vector2& Tetromino::get_pos() const
{
	return position_;
}

Movement::Rotation Tetromino::get_rotation() const
{
	return rotation_;
}

void Tetromino::render(Sprite* block, const unsigned short int block_size, const unsigned short int border_size) const
{
	Colors::Color c = c_shape_colors[(int)shape_];
	block->SetColor(c);
	for (size_t i = 0; i < c_num_blocks_per_tetromino; i++)
	{
		Vector2 block_pos = c_blocks[(int)shape_][(int)rotation_][i];
		block->Render((block_pos + position_) * (block_size - border_size));
	}
}

void Tetromino::rotate()
{
	rotation_ = Movement::get_next_rotation(rotation_);
}

void Tetromino::move(const Movement::Direction dir)
{
	// TODO: Check bounds before allowing movement
	position_ += Movement::get_direction_vector(dir);
}

const Vector2* Tetromino::get_blocks_for_shape_rotation(Shape shape, Movement::Rotation rot)
{
	return c_blocks[(int)shape][(int)rot];
}

const Vector2* Tetromino::get_blocks() const
{
	return get_blocks_for_shape_rotation(shape_, rotation_);
}