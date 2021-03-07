#ifndef QUEUE_H
#define QUEUE_H

class Queue {
public:
    Queue();
    void clear();
    bool contains(int item) const;
    int dequeue();
    void enqueue(int item);
    int peek() const;

    // TODO: add begin/end iterator stuff
};

#endif // QUEUE_H
