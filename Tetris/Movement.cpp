#include "Movement.h"

namespace Movement
{
    const Vector2& get_direction_vector(Direction dir)
    {
        switch (dir)
        {
            case Direction::DOWN:
                return c_vec_down;
            case Direction::LEFT:
                return c_vec_left;
            case Direction::RIGHT:
                return c_vec_right;
        }
    }

    const Movement::Rotation Movement::get_next_rotation(Movement::Rotation rot)
    {
        return (Movement::Rotation) (((int)rot + 1) % (int)Movement::Rotation::NUM_ROTATIONS);
    }
}