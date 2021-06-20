#include "Sort.h"
#include "Log.h"

int main()
{

    const int array_len = 5;
    int* array = new int[array_len]{2, 1, 5, 3, 5};

    Sort::quick_sort(array, array_len);
    Log::array_contents(array, array_len);

    // Cleanup
    Log::set_logging_enabled(false);
    return 0;
}

