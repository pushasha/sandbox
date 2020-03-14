#ifndef TETROMINO_H
#define TETROMINO_H

#include "Vector2.h"
#include "Color.h"
#include "Sprite.h"
#include "Movement.h"

typedef Vector2 V2;

constexpr unsigned short int c_num_shapes = 7;
constexpr unsigned short int c_num_blocks_per_tetromino = 4;
constexpr unsigned short int c_num_rotations = 4;

static const V2 c_blocks[c_num_shapes][c_num_rotations][c_num_blocks_per_tetromino] = // [shape][rotation][block]
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

static const Colors::Color c_shape_colors[c_num_shapes] = { Colors::c_color_cyan, Colors::c_color_yellow, Colors::c_color_magenta, Colors::c_color_blue, Colors::c_color_orange, Colors::c_color_green, Colors::c_color_red };

class Tetromino
{
public:
	enum Shape { I = 0, O, T, J, L, S, Z };
	explicit Tetromino(Shape shape) : shape_(shape), rotation_(0), position_(Vector2(0,0)) {}
	~Tetromino() {}
	const Vector2& get_pos() const;
	void render(Sprite* block, const unsigned short int block_size, const unsigned short int border_size) const;
	void rotate();
	void move(const Movement::Direction dir);
	const Vector2* get_blocks() const;
	
	
private:
	Shape shape_;
	char rotation_;
	Vector2 position_;
};

#endif