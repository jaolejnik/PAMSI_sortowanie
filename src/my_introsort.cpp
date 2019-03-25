#include "../inc/my_introsort.hh"

// Implementation of introsort
// ( tmp is passed as an argument, because of the pointer to a function compatibility)
template <typename MyType>
void introsort(MyType arr[], int tmp, int last_index)
{
    int partition_size = partition(arr, 0, last_index); // get partition size

    if (partition_size < 16)    // if it's smaller than 16
    {
        //std::cout << "insertion" << std::endl;
        insertionsort(arr, last_index+1);
    }
           // sort using insertionsort

    else if ( partition_size > (2*log(last_index)) )      // if it's greater than possible depth limit
    {
        //std::cout << "heap" << std::endl;
        heapsort(arr, last_index);
    }
                                // (defined as 2*log(size - 1)) sort using heapsort

    else                                // if it falls between those two
    {
        //std::cout << "quick" << std::endl;
        quicksort(arr, 0, last_index);
    }
                // sort using quicksort

}

template void introsort<int>(int arr[], int tmp, int last_index);

template void introsort<double>(double arr[], int tmp, int last_index);
