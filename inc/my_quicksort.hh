#ifndef PROJEKT_1_SORTOWANIE_MY_QUICKSORT_HH
#define PROJEKT_1_SORTOWANIE_MY_QUICKSORT_HH

#include <random>
#include <ctime>
#include "../inc/helper_func.hh"

// Generates a random pivot
int random_pivot(int low, int high);

// Function that "creates" partitions, by putting elements smaller than pivot to the left
// and bigger to the right of it, then returns pivot's index.
template <typename MyType>
int partition(MyType arr[], int low, int high);

// Implementation of quicksort.
template <typename MyType>
void quicksort(MyType arr[], int low, int high);

#endif //PROJEKT_1_SORTOWANIE_MY_QUICKSORT_HH
