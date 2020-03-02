#ifndef TETROMINO_H
#define TETROMINO_H

#include "Vector2.h"
#include "Color.h"
#include "Sprite.h"

typedef Vector2 V2;

constexpr unsigned short int c_cell_size = 32;

static const V2 c_blocks[7][4][4] = // [shape][rotation][block]
{
	{ // I
		{ V2(0,1), V2(1,1), V2(2,1), V2(3,1) }, // 0
		{ V2(2,0), V2(2,1), V2(2,2), V2(2,3) }, // 90
		{ V2(0,2), V2(1,2), V2(2,2), V2(3,2) }, // 180
		{ V2(1,0), V2(1,1), V2(1,2), V2(1,3) } // 270
	},
	{ // O
		{ V2(1,0), V2(2,0), V2(1,1), V2(2,2) }, // 0
		{ V2(1,0), V2(2,0), V2(1,1), V2(2,2) }, // 90
		{ V2(1,0), V2(2,0), V2(1,1), V2(2,2) }, // 180
		{ V2(1,0), V2(2,0), V2(1,1), V2(2,2) } // 270
	},
	{ // T
		{ V2(1,0), V2(0,1), V2(1,1), V2(2,1) }, // 0
		{ V2(1,0), V2(1,1), V2(2,1), V2(1,2) }, // 90
		{ V2(0,1), V2(1,1), V2(2,1), V2(2,2) }, // 180
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

static const Color c_shape_colors[7] = { c_color_cyan, c_color_yellow, c_color_magenta, c_color_blue, c_color_orange, c_color_green, c_color_red };

class Tetromino
{
public:
	enum Shape { I = 0, O, T, J, L, S, Z };
	enum class Direction { DOWN, LEFT, RIGHT };
	explicit Tetromino(Shape shape) : shape_(shape), rotation_(0), position_(Vector2(0,0)) {}
	~Tetromino() {}
	void render(Sprite* block) const;
	void rotate();
	void move(const Direction& dir);
	
private:
	Shape shape_;
	char rotation_;
	Vector2 position_;
	static const Vector2 c_vec_x, c_vec_y;
};

#endif