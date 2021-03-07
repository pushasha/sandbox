#ifndef STACK_H
#define STACK_H

#include "CommonTypes.h"
#include "CollectionsCommon.h"
#include "Blob.h" // TODO: Make this templated

namespace Collections {
class Stack {
public:
    Stack() : Stack(c_default_capacity){}
    explicit Stack(uint initial_capacity);
    void clear();
    bool contains(const Blob& item) const;
    Blob pop();
    void push(const Blob& item);
    const Blob& peek() const;
    // TODO: add begin/end iterator stuff
private:
    uint size;
    uint capacity;
    Blob* array;
};
}

#endif //STACK_H
