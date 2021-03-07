#ifndef STACK_H
#define STACK_H

#include "Blob.h" // TODO: Make this templated

class Stack {
public:
    Stack();
    void clear();
    bool contains(const Blob& item) const;
    Blob& pop();
    void push(const Blob& item);
    const Blob& peek() const;
    // TODO: add begin/end iterator stuff
private:
    Blob& blob; // TODO: Make this more than one item
};

#endif //STACK_H
