#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <utility>
#include "LinkedListIterator.h"
#include "Log.h"

namespace Collections
{

template<class T>
class LinkedList {
public:
    friend class LinkedListIterator<T>;

    LinkedList()
    {
        Log::logf_event("Creating [LinkedList | &%p] (default ctor)", Log::get_mem_address(*this));
    }

    LinkedList(const LinkedList& other)
    {
        Log::logf_event("Copy-constructing [LinkedList | &%p] to [LinkedList | &%p]", Log::get_mem_address(other), Log::get_mem_address(*this));
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

    void add(T&& item)
    {
        if (head == nullptr) {
            head = tail = new Node(std::forward<T>(item));
            return;
        }

        tail->next = new Node(std::forward<T>(item));
        tail = tail->next; // update tail to point to new node
    }

    void remove(const T& item)
    {
        Node* previous = nullptr;
        Node* current = head;

        while (current != nullptr) {
            if (current->data == item) {

                if (current == head){
                    // special case for head
                    head = current->next;
                }
                else {
                    previous->next = current->next;
                }

                if (current == tail) {
                    tail = previous;
                }

                delete current;
                return;
            }

            previous = current;
            current = current->next;
        }
    }

    bool contains(const T& item) const
    {
        Node* current = head;

        while (current != nullptr) {
            if (current->data == item) {
                return true;
            }

            current = current->next;
        }

        return false;
    }

    bool is_empty() const
    {
        return head == nullptr;
    }

    LinkedListIterator<T> begin() { return LinkedListIterator<T>(head); }
    LinkedListIterator<T> end() { return LinkedListIterator<T>(nullptr); }

private:
    class Node {
    public:
        Node() = default;
        explicit Node(T&& a_data) : data(std::forward<T>(a_data)){}
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
