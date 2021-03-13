#include "CommonExceptions.h"

const char* Exceptions::InvalidOperationException::what() const noexcept
{
    return msg;
}
