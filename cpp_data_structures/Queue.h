#ifndef QUEUE_H
#define QUEUE_H

#include "CommonTypes.h"
#include "CollectionsCommon.h"
#include "Blob.h" // TODO: Make this templated

namespace Collections
{
class Queue {
public:
    Queue() : Queue(c_default_capacity){}
    explicit Queue(uint initial_capacity);
    virtual ~Queue();
    void clear();
    bool contains(const Blob& item) const;
    Blob dequeue();
    void enqueue(const Blob& item);
    const Blob& peek() const;

    // TODO: add begin/end iterator stuff
};
}


#endif // QUEUE_H
