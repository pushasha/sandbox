#ifndef LINKED_LIST_ITERATOR_H
#define LINKED_LIST_ITERATOR_H

namespace Collections {

template <class T> class LinkedList; // fwd decl

template<class T>
class LinkedListIterator {
public:
    LinkedListIterator() = default;
    explicit LinkedListIterator(typename LinkedList<T>::Node* ptr) : pointee(ptr){}
    LinkedListIterator(const LinkedListIterator& other) = default;
    ~LinkedListIterator() = default;

    LinkedListIterator& operator++()
    {
        pointee = pointee->next;
        return *this;
    }

    bool operator==(const LinkedListIterator& other) const
    {
        return pointee == other.pointee;
    }

    bool operator!=(const LinkedListIterator& other) const
    {
        return !operator==(other);
    }

    const T& operator*() const
    {
        return pointee->data;
    }

    T* operator->() const
    {
        return &(operator*());
    }

private:
    typename LinkedList<T>::Node* pointee;
};

}

#endif //LINKED_LIST_ITERATOR_H
