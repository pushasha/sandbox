#include "Sort.h"
#include "StringUtils.h"
#include <stdexcept>

namespace Sort
{
    void quick_sort(int* array, uint start_idx, uint end_idx)
    {
        if (start_idx > end_idx)
        {
            throw std::invalid_argument(StringUtils::fmt("start_idx (%d) was greater than end_idx (%d)", start_idx, end_idx));
        }

        if (start_idx == end_idx)
        {
            return;
        }

        // choose pivot
        int pivot = array[start_idx + (end_idx - start_idx / 2)]; // TODO: Choose at random instead

        uint i = start_idx, j = end_idx;
        while (i <= j && i <= end_idx) {
            int i_val = array[i];
            if (i_val >= pivot) {

                for (; i <= j && j >= 0; --j) {
                    int j_val = array[j];
                    if (pivot >= j_val) {

                        array[i] = j_val;
                        array[j] = i_val;
                        break;
                    }
                }
            }

            if ( )
        }

        // Call recursively for both "halves": start_idx - j, i - end_idx
        quick_sort(array, start_idx, j);
        quick_sort(array, i, end_idx);
    }
}