#include "../inc/my_heapsort.hh"
#include "../inc/helper_func.hh"

// Function that is responsible for heap representation of the array.
template<typename MyType>
void heapify(MyType arr[], int root_index, int size)
{
    int largest_index = root_index;     // index of largest element
    int left = 2*root_index + 1;            // index of left node
    int right = 2*root_index + 2;       // index of right node

    if(left <= size && arr[left] > arr[largest_index])      // If the left index doesn't exceed size of
        largest_index = left;                               // of the  array AND it's element is larger
    // than root, make it new largest.
    if(right <= size && arr[right] > arr[largest_index])    // Do the same for the right index.
        largest_index = right;

    if(largest_index != root_index)     // If largest index is no more root index
    {
        swap(&arr[root_index], &arr[largest_index]);    // swap them
        heapify(arr, largest_index, size);              // and build subheap
    }
}


// Builds max heap from the given array, so the largest element is stored
// at the root of the heap
template<typename MyType>
void build_max_heap(MyType arr[], int size)
{
    for(int i = size/2; i >= 0; i--)
        heapify(arr,i, size);
}

// Implementation of heapsort.
template<typename MyType>
void heapsort(MyType arr[], int start, int end)
{               //starting array  // size
    build_max_heap( (arr+start), (end-start) );      // Create a max heap.

    for (int i = end; i >= start; i--)     // Until there is only 1 element left
    {
        swap(arr+start, &arr[i]);         // swap the first and the last element,
        end--;                         // reduce the size,
        heapify((arr+start), 0, (end - start) );          // build a heap of the remaining elements.
    }
}

template void heapify<int>(int arr[], int root_index, int size);
template void build_max_heap<int>(int arr[], int size);
template void heapsort<int>(int arr[], int start, int end);

template void heapify<double>(double arr[], int root_index, int size);
template void build_max_heap<double>(double arr[], int size);
template void heapsort<double>(double arr[], int start, int end);