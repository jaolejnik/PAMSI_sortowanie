#include "../inc/my_introsort.hh"

template <typename MyType>
void intro_r(MyType arr[],MyType *begin, MyType *end, int maxdepth)
{

    if ((end - begin) < 16) // perform insertion sort if partition size is 16 or smaller
    {
        insertionsort(arr, begin - arr, end - arr);
    }

    else if (maxdepth == 0) // perform heapsort if maximum depth is 0
    {
        heapsort(arr,begin-arr, end-arr );
    }

    else    // otherwise perform quicksort
    {
        int pivot = random_partition(arr, begin - arr, end - arr);
        intro_r(arr, begin, arr + pivot - 1, maxdepth - 1);
        intro_r(arr, arr + pivot + 1, end, maxdepth - 1);
    }
}

template <typename MyType>
void introsort(MyType arr[], int start, int end)
{
    intro_r(arr, arr+start, arr+end, 2*log(end - start));
}

template void introsort(int arr[], int start, int end);
template void intro_r( int arr[], int *begin,  int *end, int maxdepth);

template void intro_r( double arr[], double *begin,  double *end, int maxdepth);
template void introsort(double arr[], int start, int end);
