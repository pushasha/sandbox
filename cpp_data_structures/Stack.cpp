#include "Stack.h"
#include "CommonExceptions.h"

Collections::Stack::Stack(uint initial_capacity)
{
    size = 0;
    capacity = initial_capacity;
    array = new Blob[capacity];
}

void Collections::Stack::clear()
{
    for (uint i = 0; i < size; i++)
    {
        // Destroy each blob, but don't delete!
        // Delete will give mem back to OS. We want to hold onto it.
        array[i].~Blob();
    }

    size = 0;
}

bool Collections::Stack::contains(const Blob& item) const
{
    for (uint i = 0; i < size; i ++) {
        if (item == array[i]) {
            return true;
        }
    }
    return false;
}

Blob Collections::Stack::pop()
{
    if (size == 0)
    {
        throw Exceptions::OutOfBoundsException(0, 0);
    }

    const Blob& to_pop = array[size - 1];
    size--;

    return to_pop;
}

void Collections::Stack::push(const Blob& item)
{
    if (size == capacity)
    {
        log_event("Resizing stack from %d to %d", capacity, capacity + c_grow_size);
        capacity += c_grow_size;

        Blob* resized = new Blob[capacity];
        for (uint i = 0; i < size; i++)
        {
            resized[i] = array[i];
        }

        delete[] array;
        array = resized;
    }

    array[size] = item;
    size++;
}

const Blob& Collections::Stack::peek() const
{
    if (size == 0)
    {
        throw Exceptions::OutOfBoundsException(0, 0);
    }

    return array[size - 1];
}
