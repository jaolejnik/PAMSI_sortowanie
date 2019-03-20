#ifndef PROJEKT_1_SORTOWANIE_HELPER_FUNC_HH
#define PROJEKT_1_SORTOWANIE_HELPER_FUNC_HH

#include <random>
#include <chrono>
#include <iostream>

template <typename MyType>
void  reverse_arr(MyType arr[], int size);

template <typename MyType>
double start_sorting(int size, float percent, void (*pf)(MyType [], int, int));

template <typename MyType>
bool is_sorted(MyType arr[], int size);

template <typename MyType>
void random_filler(MyType arr[], int size);

double sum_array(double arr[], int size);

#endif //PROJEKT_1_SORTOWANIE_HELPER_FUNC_HH
