#ifndef SORT_H
#define SORT_H

#include <stdexcept>
#include "StringUtils.h"
#include "CommonTypes.h"

namespace Sort {

template <class T>
void quick_sort(T* array, uint start_idx, uint end_idx)
{
    if (start_idx > end_idx) {
        throw std::invalid_argument(
                StringUtils::fmt("start_idx (%d) was greater than end_idx (%d)", start_idx, end_idx));
    }

    if (start_idx == end_idx) {
        return;
    }

    // choose pivot
    int pivot = array[start_idx + ((end_idx - start_idx) / 2)]; // TODO: Choose at random instead

    uint i = start_idx, j = end_idx;

    while (i < j) {
        int i_val = array[i];
        if (i_val >= pivot) {
            for (; i < j; --j) {
                int j_val = array[j];
                if (j_val <= pivot && j_val != i_val) {
                    array[i] = j_val;
                    array[j] = i_val;
                    break;
                }
            }
        }

        if (i < j) {
            ++i;
        }
    }

    // Call recursively for both "halves": start_idx - i, j+1 - end_idx
    quick_sort(array, start_idx, i);

    if (j < end_idx) {
        quick_sort(array, j + 1, end_idx);
    }
}

template <class T>
void merge_sort(T* array, uint begin, uint end)
{
    if (begin == end - 1) {
        return;
    }

    uint mid = (begin + end) / 2;// find midpoint
    merge_sort(array, begin, mid); // left half
    merge_sort(array, mid, end); // right half

    // Start merge
    uint temp_len = end - begin;
    T* temp = new T[temp_len];
    uint a_head = begin, b_head = mid, temp_tail = 0;

    while (a_head < mid && b_head < end) {
        T a_val = array[a_head];
        T b_val = array[b_head];

        // take min value and append to temp array
        if (a_val < b_val) {
            temp[temp_tail] = a_val;
            a_head++; // "pop" head

        }
        else {
            temp[temp_tail] = b_val;
            b_head++; // "pop" head
        }

        temp_tail++;
    }

    while (a_head < mid) {
        temp[temp_tail] = array[a_head];
        a_head++;
        temp_tail++;
    }

    while (b_head < end) {
        temp[temp_tail] = array[b_head];
        b_head++;
        temp_tail++;
    }

    // copy results back to result array
    std::copy(temp, temp + temp_len, array + begin);
    delete[] temp;
}

}
#endif //SORT_H
