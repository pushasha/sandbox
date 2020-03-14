#ifndef GRID_SQUARE_H
#define GRID_SQUARE_H

#include "Color.h"
#include "Sprite.h"

constexpr unsigned short int c_block_size = 32;
constexpr unsigned short int c_border_size = 3;

class GridSquare
{
public:
	GridSquare() : color_(Colors::c_color_clear), is_filled_(false) {}
	~GridSquare() {}
	Colors::Color get_color() const;
	bool is_filled() const;
	void set_fill(const Colors::Color& color);
	void clear();
	void render(Sprite* block, const Vector2& pos) const;

private:
	Colors::Color color_;
	bool is_filled_;
};

#endif
