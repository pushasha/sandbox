#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <utility>
#include "LinkedListIterator.h"

namespace Collections
{

template<class T>
class LinkedList {
public:
    friend class LinkedListIterator<T>;

    LinkedList() = default;
    LinkedList(const LinkedList& other)
    {
        if (other.head == nullptr) {
            return;
        }

        head = new Node(*other.head);

        Node* other_current = other.head;
        Node* this_current = head;

        while (other_current != nullptr) {
            other_current = other_current->next;
            if (other_current == nullptr) {
                this_current->next = nullptr;
            }
            else {
                this_current->next = new Node(*other_current);
                this_current = this_current->next;
            }
        }
        tail = this_current;
    }
    ~LinkedList()
    {
        Node* current = head;
        Node* next;

        while (current != nullptr) {
            next = current->next;
            delete current;
            current = next;
        }
    }

    void add(const T& item)
    {
        if (head == nullptr) {
            head = tail = new Node(item);
            return;
        }

        tail->next = new Node(item);
        tail = tail->next; // update tail to point to new node
    }

    LinkedListIterator<T> begin() { return LinkedListIterator<T>(head); }
    LinkedListIterator<T> end() { return LinkedListIterator<T>(nullptr); }

private:
    class Node {
    public:
        Node() = default;
        explicit Node(T&& a_data) : data(a_data){}
        explicit Node(const T& a_data) : data(a_data){}
        Node(const Node& other) = default;
        T data;
        Node* next = nullptr;
    };

    Node* head = nullptr;
    Node* tail = nullptr;
};

}

#endif //LINKED_LIST_H
