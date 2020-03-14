#include "GridSquare.h"
#include "Color.h"

Colors::Color GridSquare::get_color() const
{
    return color_;
}

bool GridSquare::is_filled() const
{
    return is_filled_;
}

void GridSquare::set_fill(const Colors::Color& fill_color)
{
    color_ = fill_color;
    is_filled_ = true;
}

void GridSquare::clear()
{
    color_ = Colors::c_color_clear;
    is_filled_ = false;
}

void GridSquare::render(Sprite* block, const Vector2& pos) const
{
    block->SetColor(color_);
    block->Render(pos * (c_block_size - c_border_size));
}
