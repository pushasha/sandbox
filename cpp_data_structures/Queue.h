#ifndef QUEUE_H
#define QUEUE_H

#include "Blob.h" // TODO: Make this templated

class Queue {
public:
    Queue();
    void clear();
    bool contains(const Blob& item) const;
    Blob dequeue();
    void enqueue(const Blob& item);
    const Blob& peek() const;

    // TODO: add begin/end iterator stuff
};

#endif // QUEUE_H
