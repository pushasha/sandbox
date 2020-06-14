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
    bool collides(const Tetromino* const piece) const;
    bool rotation_collides(const Tetromino* const piece) const;
    bool direction_collides(const Tetromino* const piece, Movement::Direction dir) const;
    void add_tetromino(const Tetromino* const piece);
    void hard_drop(Tetromino* const piece);
    void check_and_clear_rows(const Tetromino* const piece);
    void render() const;
    // TODO: Convert grid_ to be dynamically allocated, the free appropriately

private:
    GridSquare grid_[c_grid_width][c_grid_height] = {};
    bool collides(const Vector2& pos, Tetromino::Shape shape, Movement::Rotation rot) const;
    void move_row_down(int row, int amount);
    void clear_row(int row);
    bool is_row_filled(int row);
};

#endif