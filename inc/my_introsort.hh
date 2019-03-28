#ifndef PROJEKT_1_SORTOWANIE_MY_INTROSORT_HH
#define PROJEKT_1_SORTOWANIE_MY_INTROSORT_HH

#include <iostream>
#include "../inc/my_quicksort.hh"
#include "../inc/my_heapsort.hh"
#include "../inc/my_insertionsort.hh"

int median_of_three(int a, int b, int c);

template <typename MyType>
void intro_r(MyType arr[],int start, int end, int max_depth);

// Implementation of introsort.
template <typename MyType>
void introsort(MyType arr[],int start, int end);


#endif //PROJEKT_1_SORTOWANIE_MY_INTROSORT_HH
