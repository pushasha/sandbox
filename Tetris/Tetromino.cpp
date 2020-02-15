#include "Tetromino.h"

void Tetromino::render(Sprite* const block, const Vector2& piece_pos) const
{
	block->SetColor(c_shape_colors[Tetromino::Z]);
	for (size_t i = 0; i < 4; i++)
	{
		Vector2 pos = c_block_layouts[Tetromino::Z][i];
		g_square_sprite->Render(pos + piece_pos);
	}
}
