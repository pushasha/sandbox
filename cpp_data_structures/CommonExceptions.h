#ifndef COMMONEXCEPTIONS_H
#define COMMONEXCEPTIONS_H

#include <exception>
#include "CommonTypes.h"

namespace Exceptions
{
class OutOfBoundsException : public std::exception {
public:
    OutOfBoundsException(uint index, uint size)
            :index(index), size(size) { }

    const char* what() const noexcept override;
private:
    uint index;
    uint size;
};
}

#endif //COMMONEXCEPTIONS_H
