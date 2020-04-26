#ifndef TETROMINO_H
#define TETROMINO_H

#include "Vector2.h"
#include "Color.h"
#include "Sprite.h"
#include "Movement.h"

typedef Vector2 V2;

class Tetromino
{
public:
	static constexpr unsigned short int c_num_blocks_per_tetromino = 4;
	enum class Shape { I = 0, O, T, J, L, S, Z, NUM_SHAPES};

	explicit Tetromino(Shape shape);
	~Tetromino() { delete[] block_positions_; }
	Shape get_shape() const;
	const Colors::Color& get_color() const;
	const Vector2& get_pos() const;
	Movement::Rotation get_rotation() const;
	void render(Sprite* block, const unsigned short int block_size, const unsigned short int border_size) const;
	void rotate();
	void move(const Movement::Direction dir);
	void move(const Vector2& pos);
	const Vector2* const get_block_positions() const;
	static const Vector2* get_blocks_for_shape_rotation(Shape shape, Movement::Rotation rot);
	
private:
	static constexpr unsigned short int c_num_shapes = 7;
	static constexpr unsigned short int c_num_rotations = 4;
	static const V2 c_blocks[c_num_shapes][c_num_rotations][c_num_blocks_per_tetromino]; // [shape][rotation][block]
	static const Colors::Color c_shape_colors[c_num_shapes];

	Shape shape_;
	Movement::Rotation rotation_;
	Vector2 position_;
	Vector2* block_positions_;
};



#endif