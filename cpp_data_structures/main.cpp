#include <iostream>
#include "LinkedList.h"
#include "Blob.h"
#include "Log.h"

int main()
{
    Log::set_logging_enabled(false);
    Collections::LinkedList<Blob>* list = new Collections::LinkedList<Blob>();
    list -> add(Blob(9));
    list -> add(Blob(8));
    list -> add(Blob(7));

    for (const Blob& blob : *list) {
        std::cout << blob.get_int() << std::endl;
    }

    // Cleanup

    delete list;
    return 0;
}

