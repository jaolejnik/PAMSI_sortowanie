#include "../inc/my_introsort.hh"

// Implementation of introsort
// ( tmp is passed as an argument, because of the pointer to a function compatibility)
template <typename MyType>
void introsort(MyType arr[], int tmp, int last_index)
{
    int r = random_pivot(0,last_index);     // Get a random pivot
    swap(&arr[r], &arr[last_index]);    // swap it's element with the last one
    int partition_size = partition(arr, 0, last_index);     // get partition size

    if (partition_size < 16)    // if it's smaller than 16
        insertionsort(arr, last_index+1);        // sort using insertionsort

    else if ( partition_size > (2*log(last_index+1)) )      // if it's greater than possible depth limit
        heapsort(arr, last_index);                          // (defined as 2*log(size)) sort using heapsort

    else                                // if it falls between those two
        quicksort(arr, 0, last_index);   // sort using quicksort
}

template void introsort<int>(int arr[], int tmp, int last_index);

template void introsort<double>(double arr[], int tmp, int last_index);
