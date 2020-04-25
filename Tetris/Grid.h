#ifndef GRID_H
#define GRID_H

#include "Movement.h"
#include "Tetromino.h"
#include "GridSquare.h"

class Grid
{
public:
    static constexpr int c_grid_width = 10;
    static constexpr int c_grid_height = 20;
    bool rotation_collides(const Tetromino* const piece);
    bool direction_collides(const Tetromino* const piece, Movement::Direction dir);
    void render();
    // TODO: Convert grid_ to be dynamically allocated, the free appropriately

private:
    GridSquare grid_[c_grid_width][c_grid_height] = {};
    bool collides(const Vector2& pos, Tetromino::Shape shape, Movement::Rotation rot);
};

#endif