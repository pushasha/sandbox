#include <iostream>
#include "Stack.h"
#include "Blob.h"
#include "Log.h"

int main()
{
    Collections::Stack<Blob>* stack = new Collections::Stack<Blob>(0);
    Log::log("pushin'...");
    stack->push(Blob(9));

    Log::log("poppin'...");
    Blob popped(stack->pop());
    Log::logf("popped onto &%p", Log::get_mem_address(popped));

    // Cleanup
    Log::set_logging_enabled(false);
    delete stack;
    return 0;
}

