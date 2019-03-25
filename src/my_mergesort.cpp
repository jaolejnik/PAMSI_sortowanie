// An implementation of mergesort

#include "../inc/my_mergesort.hh"
#include "../inc/helper_func.hh"


// Function that merges the array
template <class MyType>
void merge(MyType arr[], int start, int middle, int end)
{
    int left_index, right_index, merge_index;

    int left_size = middle - start + 1;     // Get size of the the left half of the array.
    int right_size = end - middle;          // Get size of the the right half of the array.

    MyType * left_half = new MyType[left_size];     // Create array that stores the the left half.
    MyType * right_half = new MyType[right_size];   // Create array that stores the the right half.

    for(left_index = 0; left_index < left_size; left_index++)   // Fill it.
        left_half[left_index] = arr[left_index + start];

    for(right_index = 0; right_index < right_size; right_index++)   // Fill it.
        right_half[right_index] = arr[right_index + middle + 1];

    left_index = 0;
    right_index = 0;
    merge_index = start;

    while(left_index < left_size && right_index < right_size)   // Until indexes doesn't exceed sizes
    {
        if(left_half[left_index] <= right_half[right_index])    // If corresponding element form the the left half
        {                                                       // is smaller than the one from the the right half
            arr[merge_index] = left_half[left_index];           // put it in the main array
            left_index++;                                       // and move the left index on step ahead.
        }
        else
        {
            arr[merge_index] = right_half[right_index];         // If it's not, put the the right one
            right_index++;                                      // and move the right index one step ahead
        }
        merge_index++;      // Move merge index one step ahead
    }

    while(left_index < left_size)   // Until index doesn't exceed size
    {
        arr[merge_index] = left_half[left_index];       // Place rest of the elements into the main array
        left_index++;
        merge_index++;
    }


    while(right_index < right_size) // Until index doesn't exceed size
    {
        arr[merge_index] = right_half[right_index];     // Place rest of the elements into the main array
        right_index++;
        merge_index++;
    }
    delete [] left_half;    // delete the halves
    delete [] right_half;
}


// Implementation of mergesort
template <class MyType>
void mergesort(MyType arr[], int start, int end)
{
    if( start < end )
    {
        int middle = (start + end) / 2;     // get middle of the array

        mergesort<MyType>(arr, start, middle);      // start recursive sorting the left half
        mergesort<MyType>(arr, middle + 1, end);    // start recursive sorting the right half

        merge<MyType>(arr, start, middle, end);     // merge the halves
    }
}



template void mergesort<int>(int arr[], int start, int end);
template void merge<int>(int arr[], int start, int middle, int end);

template void mergesort<double>(double arr[], int start, int end);
template void merge<double>(double arr[], int start, int middle, int end);