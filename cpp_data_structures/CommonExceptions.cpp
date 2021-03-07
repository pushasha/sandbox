#include "CommonExceptions.h"

const char* Exceptions::OutOfBoundsException::what() const noexcept
{
    return "Index was out-of-bounds.";
}
