#include <iostream>
#include "Stack.h"
#include "Blob.h"

int main()
{
    Collections::Stack<Blob>* stack = new Collections::Stack<Blob>(2);
    log("pushin'...");
    stack->push(Blob(9));

    log("poppin'...");
    Blob popped(stack->pop());
    log("popped onto &%p", (void*)&popped);

    // Cleanup
    set_logging_enabled(false);
    delete stack;
    return 0;
}

