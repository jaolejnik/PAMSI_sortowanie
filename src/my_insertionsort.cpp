#include "../inc/my_insertionsort.hh"

// Implementation of insertionsort.
template <typename MyType>
void insertionsort(MyType arr[], int start, int end)
{
    MyType key;
    int smaller_index;

    for (int key_index = start+1; key_index <= end; key_index++)		// Main loop that picks keys
    {
        key = arr[key_index];
        smaller_index = key_index - 1;

        while(smaller_index >= start && arr[smaller_index] > key)	// As long as the smaller index is greater or equal 0
        {														// AND element with smaller index is greater than the key,
            arr[smaller_index + 1] = arr[smaller_index];		// move elements one position ahead
            smaller_index--;

        }
        arr[smaller_index + 1] = key;	// put key in the right place
    }
}

template void insertionsort<int>(int arr[], int start, int end);

template void insertionsort<double>(double arr[], int start, int end);