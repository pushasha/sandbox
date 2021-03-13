#ifndef COMMONEXCEPTIONS_H
#define COMMONEXCEPTIONS_H

#include <exception>
#include "CommonTypes.h"

namespace Exceptions
{
class InvalidOperationException : public std::exception {
public:
    InvalidOperationException(const char* a_msg)
            :msg(a_msg) { }

    const char* what() const noexcept override;
private:
    const char* msg;
};
}

#endif //COMMONEXCEPTIONS_H
