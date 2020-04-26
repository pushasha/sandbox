#ifndef MOVEMENT_H
#define MOVEMENT_H

#include "Vector2.h"

namespace Movement
{
    const Vector2 c_vec_up = Vector2(0, -1);
    const Vector2 c_vec_down = Vector2(0, 1);
    const Vector2 c_vec_right = Vector2(1, 0);
    const Vector2 c_vec_left = Vector2(-1, 0);

    enum class Rotation { ZERO = 0, NINETY = 1, ONE_EIGHTY = 2, TWO_SEVENTY = 3, NUM_ROTATIONS };
    enum class Direction { UP, DOWN, LEFT, RIGHT };

    const Vector2& get_direction_vector(Direction dir);
    const Movement::Rotation get_next_rotation(Movement::Rotation rot);
}

#endif
