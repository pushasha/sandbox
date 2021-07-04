#include "Sort.h"
#include "Log.h"

int main()
{

    const uint array_len = 5;
    int* a = new int[array_len]{6, 3, 5, 2, 6};
    Sort::merge_sort(a, 0, array_len);

    Log::array_contents(a, array_len);

    // Cleanup
    Log::set_logging_enabled(false);
    return 0;
}

