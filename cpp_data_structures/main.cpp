#include <iostream>
#include "HashSet.h"
#include "Blob.h"
#include "Log.h"

int main()
{
    Collections::HashSet<int> set(5);

    set.add(34);
    set.add(54);
    set.add(64);
    set.add(33);

    set.remove(54);
    set.remove(34);

    for (const int a_int : set) {
        std::cout << a_int << std::endl;
    }


    // Cleanup
    Log::set_logging_enabled(false);
    return 0;
}

