#ifndef PROJEKT_1_SORTOWANIE_MY_MERGESORT_HH
#define PROJEKT_1_SORTOWANIE_MY_MERGESORT_HH

// An implementation of mergesort

// Merge function
template <class MyType>
void merge(MyType arr[], int start, int middle, int end);

// Mergesort function
template <class MyType>
void mergesort(MyType arr[], int start, int end);

// Function to sort an array of given size and type
template <class MyType>
double start_mergesort(int size);

#endif //PROJEKT_1_SORTOWANIE_MY_MERGESORT_HH
