#ifndef COLLECTIONS_COMMON_H
#define COLLECTIONS_COMMON_H

#include "CommonTypes.h"

namespace Collections
{
    constexpr uint c_default_capacity = 10;
    constexpr uint c_grow_size = 10;

    template<class T>
    class Iterator {
    public:
        typedef void (*go_next_func)(const T** ptr);

        Iterator(const T* ptr, go_next_func next):ptr(ptr), next(next) { }

        Iterator operator++()
        {
            next(&ptr); // go to next item (previous item in stack)
            return *this;
        }

        bool operator!=(const Iterator<T>& other) const
        {
            return ptr != other.ptr;
        }

        const T& operator*() const
        {
            return *ptr;
        }

    private:
        const T* ptr;
        go_next_func next;
    };
}

#endif //COLLECTIONS_COMMON_H
