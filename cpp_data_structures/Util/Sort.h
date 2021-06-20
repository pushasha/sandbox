#ifndef SORT_H
#define SORT_H

#include <stdexcept>
#include "StringUtils.h"
#include "CommonTypes.h"

namespace Sort
{
    template <class T>
    void quick_sort(T* array, uint start_idx, uint end_idx)
    {
        if (start_idx > end_idx){
            throw std::invalid_argument(StringUtils::fmt("start_idx (%d) was greater than end_idx (%d)", start_idx, end_idx));
        }

        if (start_idx == end_idx){
            return;
        }

        // choose pivot
        int pivot = array[start_idx + ((end_idx - start_idx) / 2)]; // TODO: Choose at random instead

        uint i = start_idx, j = end_idx;

        while (i < j){
            int i_val = array[i];
            if (i_val >= pivot){
                for (; i < j; --j){
                    int j_val = array[j];
                    if (j_val <= pivot && j_val != i_val){
                        array[i] = j_val;
                        array[j] = i_val;
                        break;
                    }
                }
            }

            if (i < j){
                ++i;
            }
        }

        // Call recursively for both "halves": start_idx - i, j+1 - end_idx
        quick_sort(array, start_idx, i);

        if (j < end_idx){
            quick_sort(array, j + 1, end_idx);
        }
    }

    template <class T>
    void quick_sort(T* array, uint len)
    {
        quick_sort(array, 0, len - 1);
    }
}
#endif //SORT_H
