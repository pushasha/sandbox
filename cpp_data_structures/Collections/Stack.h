#ifndef STACK_H
#define STACK_H

#include <utility>
#include "CommonTypes.h"
#include "CollectionsCommon.h"
#include "CommonExceptions.h"
#include "Log.h"

namespace Collections {
    template<class T>
    class Stack {
    public:
        static constexpr const char* c_log_tag = "Stack";

        Stack():Stack(c_default_capacity) { }

        Stack(const Stack& other)
        {
            size = other.size;
            capacity = other.capacity;
            array = new T[capacity];

            for (uint i = 0; i < size; i++) {
                array[i] = other.array[i];
            }
        }

        explicit Stack(uint initial_capacity)
        {
            size = 0;
            capacity = initial_capacity;
            array = new T[capacity];
        }

        virtual ~Stack()
        {
            size = 0;
            capacity = 0;
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

        T pop()
        {
            if (size == 0) {
                throw Exceptions::InvalidOperationException("Cannot use pop() on an empty Stack.");
            }

            const T& to_pop = array[size - 1];
            size--;

            return to_pop;
        }

        void push(T&& item)
        {
            if (size == capacity) {
                resize();
            }

            array[size] = std::forward<T>(item);
            size++;
        }

        void push(const T& item)
        {
            if (size == capacity) {
                resize();
            }

            array[size] = item;
            size++;
        }

        const T& peek() const
        {
            if (size == 0) {
                throw Exceptions::InvalidOperationException("Cannot use peek() on an empty Stack.");
            }

            return array[size - 1];
        }

    private:
        uint size;
        uint capacity;
        T* array;

        void resize()
        {
            Log::logf_event(this, "Start resizing stack from %d to %d", capacity, capacity << c_grow_shift);
            capacity = capacity << c_grow_shift;

            T* resized = new T[capacity];
            for (uint i = 0; i < size; i++) {
                resized[i] = std::move(array[i]);
            }

            delete[] array;
            array = resized;
            Log::log_event(this, "Finished resizing stack");
        }
    };
}

#endif //STACK_H
