#include <iostream>
#include "Stack.h"
#include "Blob.h"
#include "Log.h"

int main()
{
    Log::set_logging_enabled(false);
    Collections::Stack<Blob>* stack = new Collections::Stack<Blob>(3);
    stack->push(Blob(9));
    stack->push(Blob(10));
    stack->push(Blob(11));
    Log::set_logging_enabled(true);

    for (const Blob& b : *stack)
    {
        Log::logf("> Found blob at [%p], int = %d", Log::get_mem_address(b), b.get_int());
    }

    // Cleanup
    Log::set_logging_enabled(false);
    delete stack;
    return 0;
}

