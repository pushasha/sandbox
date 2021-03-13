#include <iostream>
#include "Stack.h"

int main()
{
    Collections::Stack* stack = new Collections::Stack(2);
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

