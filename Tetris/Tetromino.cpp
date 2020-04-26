#include "Tetromino.h"

const Colors::Color Tetromino::c_shape_colors[c_num_shapes] = { Colors::c_color_cyan, Colors::c_color_yellow, Colors::c_color_magenta, Colors::c_color_blue, Colors::c_color_orange, Colors::c_color_green, Colors::c_color_red };

const V2 Tetromino::c_blocks[c_num_shapes][c_num_rotations][c_num_blocks_per_tetromino] = // [shape][rotation][block]
{
	{ // I
		{ V2(0,1), V2(1,1), V2(2,1), V2(3,1) }, // 0
		{ V2(2,0), V2(2,1), V2(2,2), V2(2,3) }, // 90
		{ V2(0,2), V2(1,2), V2(2,2), V2(3,2) }, // 180
		{ V2(1,0), V2(1,1), V2(1,2), V2(1,3) } // 270
	},
	{ // O
		{ V2(1,0), V2(2,0), V2(1,1), V2(2,1) }, // 0
		{ V2(1,0), V2(2,0), V2(1,1), V2(2,1) }, // 90
		{ V2(1,0), V2(2,0), V2(1,1), V2(2,1) }, // 180
		{ V2(1,0), V2(2,0), V2(1,1), V2(2,1) } // 270
	},
	{ // T
		{ V2(1,0), V2(0,1), V2(1,1), V2(2,1) }, // 0
		{ V2(1,0), V2(1,1), V2(2,1), V2(1,2) }, // 90
		{ V2(0,1), V2(1,1), V2(2,1), V2(1,2) }, // 180
		{ V2(1,0), V2(0,1), V2(1,1), V2(1,2) } // 270
	},
	{ // J
		{ V2(0,0), V2(0,1), V2(1,1), V2(2,1) }, // 0
		{ V2(1,0), V2(2,0), V2(1,1), V2(1,2) }, // 90
		{ V2(0,1), V2(1,1), V2(2,1), V2(2,2) }, // 180
		{ V2(1,0), V2(1,1), V2(1,2), V2(0,2) } // 270
	},
	{ // L
		{ V2(2,0), V2(2,1), V2(1,1), V2(0,1) }, // 0
		{ V2(1,0), V2(1,1), V2(1,2), V2(2,2) }, // 90
		{ V2(0,1), V2(0,2), V2(1,1), V2(2,1) }, // 180
		{ V2(0,0), V2(1,0), V2(1,1), V2(1,2) } // 270
	},
	{ // S
		{ V2(1,0), V2(2,0), V2(0,1), V2(1,1) }, // 0
		{ V2(1,0), V2(1,1), V2(2,1), V2(2,2) }, // 90
		{ V2(0,2), V2(1,1), V2(1,2), V2(2,1) }, // 180
		{ V2(0,0), V2(0,1), V2(1,1), V2(1,2) } // 270
	},
	{ // Z
		{ V2(0,0), V2(1,0), V2(1,1), V2(2,1) }, // 0
		{ V2(2,0), V2(2,1), V2(1,1), V2(1,2) }, // 90
		{ V2(0,1), V2(1,1), V2(1,2), V2(2,2) }, // 180
		{ V2(1,0), V2(1,1), V2(0,1), V2(0,2) } // 270
	}
};


Tetromino::Tetromino(Shape shape) : shape_(shape), rotation_(Movement::Rotation::ZERO), position_(Vector2(0, 0)), block_positions_(new Vector2[c_num_blocks_per_tetromino])
{
	const Vector2* shape_blocks = get_blocks_for_shape_rotation(shape_, rotation_);
	for (size_t i = 0; i < c_num_blocks_per_tetromino; i++)
	{
		block_positions_[i] = shape_blocks[i];
	}
}

Tetromino::Shape Tetromino::get_shape() const
{
	return shape_;
}

const Colors::Color& Tetromino::get_color() const
{
	return c_shape_colors[(int)shape_];
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
	block->SetColor(get_color());

	for (size_t i = 0; i < c_num_blocks_per_tetromino; i++)
	{
		block->Render(block_positions_[i] * (block_size - border_size));
	}
}

void Tetromino::rotate()
{
	rotation_ = Movement::get_next_rotation(rotation_);

	const Vector2* shape_blocks = get_blocks_for_shape_rotation(shape_, rotation_);
	for (size_t i = 0; i < c_num_blocks_per_tetromino; i++)
	{
		Vector2 shape_block_pos = shape_blocks[i];
		block_positions_[i] = shape_block_pos + position_;
	}
}

void Tetromino::move(const Movement::Direction dir)
{
	const Vector2& direction_vector = Movement::get_direction_vector(dir);
	move(position_ + direction_vector);
}

void Tetromino::move(const Vector2& pos)
{
	position_ = pos;

	const Vector2* shape_blocks = get_blocks_for_shape_rotation(shape_, rotation_);
	for (size_t i = 0; i < c_num_blocks_per_tetromino; i++)
	{
		Vector2 shape_block_pos = shape_blocks[i];
		block_positions_[i] = shape_block_pos + position_;
	}
}

const Vector2* Tetromino::get_blocks_for_shape_rotation(Shape shape, Movement::Rotation rot)
{
	return c_blocks[(int)shape][(int)rot];
}

const Vector2* const Tetromino::get_block_positions() const
{
	return block_positions_;
}