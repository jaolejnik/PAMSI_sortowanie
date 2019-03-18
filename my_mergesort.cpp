// An implementation of mergesort

#include "my_mergesort.hh"
#include "helper_func.hh"


// Merge function
template <class MyType>
void merge(MyType arr[], int start, int middle, int end)
{
    int left_index, right_index, merge_index;

    int left_size = middle - start + 1;
    int right_size = end - middle;

    MyType * left_half = new MyType[left_size];
    MyType * right_half = new MyType[right_size];

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
template <class MyType>
void mergesort(MyType arr[], int start, int end)
{
    if( start < end )
    {
        int middle = (start + end) / 2;

        mergesort<MyType>(arr, start, middle);
        mergesort<MyType>(arr, middle + 1, end);

        merge<MyType>(arr, start, middle, end);
    }
}



template void mergesort<int>(int arr[], int start, int end);
template void merge<int>(int arr[], int start, int middle, int end);

template void mergesort<double>(double arr[], int start, int end);
template void merge<double>(double arr[], int start, int middle, int end);