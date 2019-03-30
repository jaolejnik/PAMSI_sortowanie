#ifndef PROJEKT_1_SORTOWANIE_MY_HEAPSORT_HH
#define PROJEKT_1_SORTOWANIE_MY_HEAPSORT_HH

#include <algorithm> // To get heapsort that sorts

// Function that is responsible for heap representation of the array.
template <typename MyType>
void heapify(MyType arr[], int root, int size);

// Builds max heap from the given array, so the largest element is stored
// at the root of the heap.
template <typename MyType>
void build_max_heap(MyType arr[], int size);

// Implementation of heapsort.
template <typename MyType>
void heapsort(MyType arr[], int start, int end);


#endif //PROJEKT_1_SORTOWANIE_MY_HEAPSORT_HH