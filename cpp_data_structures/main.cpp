#include <iostream>
#include "Stack.h"

int main()
{
    Collections::Stack* stack = new Collections::Stack(2);
    log("pushin'...");
    stack->push(Blob(9));

    log("poppin'...");
    Blob popped = stack->pop();
    log("popped onto &%p", (void*)&popped);

    std::cin.get(); // wait for keypress to end

    // Cleanup
    delete stack;
    return 0;
}

