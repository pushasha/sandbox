#include "Tetromino.h"

const Vector2 Tetromino::c_vec_y = Vector2(0, 1);
const Vector2 Tetromino::c_vec_x = Vector2(1, 0);

void Tetromino::render(Sprite* block) const
{
	block->SetColor(c_shape_colors[shape_]);
	for (size_t i = 0; i < 4; i++)
	{
		Vector2 block_pos = c_blocks[shape_][rotation_][i];
		g_square_sprite->Render((block_pos + position_) * (c_cell_size - 3));
	}
}

void Tetromino::rotate()
{
	rotation_ = (rotation_ + 1) % 4;
}

void Tetromino::move(const Direction& dir)
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
