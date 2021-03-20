#ifndef QUEUE_H
#define QUEUE_H

#include <utility>
#include "CommonTypes.h"
#include "CollectionsCommon.h"
#include "CommonExceptions.h"
#include "Log.h"

namespace Collections
{
template<class T>
class Queue {
public:
    static constexpr const char* c_log_tag = "Queue";

    Queue() : Queue(c_default_capacity){}
    Queue(const Queue& other)
    {
        size = other.size;
        capacity = other.capacity;
        head_idx = other.head_idx;
        array = new T[capacity];

        for (uint i = 0; i < size; i++) {
            array[i] = other.array[(head_idx + i) % capacity];
        }
    }
    explicit Queue(uint initial_capacity)
    {
        size = 0;
        capacity = initial_capacity;
        head_idx = 0;
        array = new T[capacity];
        Log::log_event(this, "Completed ctor");
    }

    virtual ~Queue()
    {
        size = 0;
        capacity = 0;
        head_idx = 0;
        delete[] array;
        array = nullptr;
    }

    void clear()
    {
        for (uint i = 0; i < size; i++) {
            // Destroy each item, but don't delete!
            // Delete will give mem back to OS. We want to hold onto it.
            array[i].~T();
        }

        size = 0;
    }

    bool contains(const T& item) const
    {
        for (uint i = 0; i < size; i++) {
            if (item == array[i]) {
                return true;
            }
        }
        return false;
    }

    T dequeue()
    {
        if (size == 0) {
            throw Exceptions::InvalidOperationException("Cannot use dequeue() on an empty Queue.");
        }

        const T& to_dequeue = array[head_idx];
        size--;
        if (size > 0)
        {
            head_idx = (head_idx + 1) % capacity;
        }

        return to_dequeue;
    }

    void enqueue(const T& item)
    {
        if (size == capacity) {
            resize();
        }
        array[(head_idx + size) % capacity] = item;
        size++;
    }

    void enqueue(T&& item)
    {
        if (size == capacity) {
            resize();
        }

        array[(head_idx + size) % capacity] = std::forward<T>(item);
        size++;
    }

private:
    uint size;
    uint capacity;
    T* array;
    uint head_idx;

    void resize()
    {
        uint old_cap = capacity;
        capacity = capacity << c_grow_shift;

        Log::logf_event(this, "Start resizing Queue from %d to %d", old_cap, capacity);

        T* resized_array = new T[capacity];

        for (uint i = 0; i < size; i++) {
            uint other_idx = (head_idx + i) % old_cap;
            resized_array[i] = std::move(array[other_idx]);
        }

        delete[] array;

        array = resized_array;
        head_idx = 0;
        Log::log_event(this, "Finished resizing Queue");
    }
};
}


#endif // QUEUE_H
