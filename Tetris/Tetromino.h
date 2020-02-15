#ifndef TETROMINO_H
#define TETROMINO_H

#include "Vector2.h"
#include "Color.h"
#include "Sprite.h"

constexpr unsigned short int c_cell_size = 32;
static const Vector2 c_block_layouts[7][4] =
{
	{ Vector2(0, 0), Vector2(0, c_cell_size), Vector2(0, c_cell_size * 2), Vector2(0, c_cell_size * 3) },
	{ Vector2(0, 0), Vector2(c_cell_size, 0), Vector2(0, c_cell_size), Vector2(c_cell_size, c_cell_size) },
	{ Vector2(0, 0), Vector2(0, c_cell_size), Vector2(0, c_cell_size * 2), Vector2(c_cell_size, c_cell_size) },
	{ Vector2(0, c_cell_size * 2), Vector2(c_cell_size, 0), Vector2(c_cell_size, c_cell_size), Vector2(c_cell_size, c_cell_size * 2) },
	{ Vector2(0, 0), Vector2(0, c_cell_size), Vector2(0, c_cell_size * 2), Vector2(c_cell_size, c_cell_size * 2) },
	{ Vector2(c_cell_size, 0), Vector2(c_cell_size * 2, 0), Vector2(0, c_cell_size), Vector2(c_cell_size, c_cell_size) },
	{ Vector2(0, 0), Vector2(c_cell_size, 0), Vector2(c_cell_size, c_cell_size), Vector2(c_cell_size * 2, c_cell_size) }
};

static const Color c_shape_colors[7] = { c_color_cyan, c_color_yellow, c_color_magenta, c_color_blue, c_color_orange, c_color_green, c_color_red };

class Tetromino
{
public:
	enum Shape { I = 0, O, T, J, L, S, Z };
	Tetromino(Shape shape) : shape_(shape) {}
	~Tetromino() {}
	void render(Sprite* const block, const Vector2& piece_pos) const;

private:
	Shape shape_;
};

#endif