#include <iostream>
#include "Sort.h"
#include "Log.h"

int main()
{

    int* array = new int[2]{3, 1};

    Sort::quick_sort(array, 0, 1);

    // Cleanup
    Log::set_logging_enabled(false);
    return 0;
}

