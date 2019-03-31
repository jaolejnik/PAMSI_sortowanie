#ifndef PROJEKT_1_SORTOWANIE_MY_INTROSORT_HH
#define PROJEKT_1_SORTOWANIE_MY_INTROSORT_HH

#include <iostream>
#include "../inc/my_quicksort.hh"
#include "../inc/my_heapsort.hh"
#include "../inc/my_insertionsort.hh"

template <typename MyType>
void intro_r(MyType arr[], MyType *begin, MyType *end, int maxdepth);

template <typename MyType>
void introsort(MyType arr[], int start, int end);


#endif //PROJEKT_1_SORTOWANIE_MY_INTROSORT_HH
