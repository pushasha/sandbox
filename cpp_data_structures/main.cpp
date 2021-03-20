#include <iostream>
#include "Stack.h"
#include "Queue.h"
#include "Blob.h"
#include "Log.h"

int main()
{
    Collections::Queue<Blob>* queue = new Collections::Queue<Blob>(2);
    queue->enqueue(Blob(1));
    queue->enqueue(Blob(2));
    Log::log("dequeue");
    Blob aBlob = queue->dequeue();
    Log::log("enqueue");
    queue->enqueue(Blob(3));
    queue->enqueue(Blob(4));

    // Cleanup
    Log::set_logging_enabled(false);
    delete queue;
    return 0;
}

