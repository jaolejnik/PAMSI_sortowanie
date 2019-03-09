// An implementation of mergesort

#include "my_mergesort.hh"


// Merge function
template <class myType>
void merge(myType arr[], int start, int middle, int end)
{
    int left_index, right_index, merge_index;

    int left_size = middle - start + 1;
    int right_size = end - middle;

    myType * left_half = new myType[left_size];
    myType * right_half = new myType[right_size];

    for(left_index = 0; left_index < left_size; left_index++)
        left_half[left_index] = arr[left_index + start];

    for(right_index = 0; right_index < right_size; right_index++)
        right_half[right_index] = arr[right_index + middle + 1];

    left_index = 0;
    right_index = 0;
    merge_index = start;

    while(left_index < left_size && right_index < right_size)
    {
        if(left_half[left_index] <= right_half[right_index])
        {
            arr[merge_index] = left_half[left_index];
            left_index++;
        }
        else
        {
            arr[merge_index] = right_half[right_index];
            right_index++;
        }
        merge_index++;
    }

    while(left_index < left_size)
    {
        arr[merge_index] = left_half[left_index];
        left_index++;
        merge_index++;
    }


    while(right_index < right_size)
    {
        arr[merge_index] = right_half[right_index];
        right_index++;
        merge_index++;
    }
    delete [] left_half;
    delete [] right_half;
}

// Mergesort
template <class myType>
void merge_sort(myType arr[], int start, int end)
{
    if( start < end )
    {
        int middle = (start + end) / 2;

        merge_sort<myType>(arr, start, middle);
        merge_sort<myType>(arr, middle + 1, end);

        merge<myType>(arr, start, middle, end);
    }
}


template void merge_sort<int>(int arr[], int start, int end);
template void merge<int>(int arr[], int start, int middle, int end);
template void merge_sort<double>(double arr[], int start, int end);
template void merge<double>(double arr[], int start, int middle, int end);
