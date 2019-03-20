#ifndef PROJEKT_1_SORTOWANIE_MY_QUICKSORT_HH
#define PROJEKT_1_SORTOWANIE_MY_QUICKSORT_HH

#include <random>
#include <ctime>

int random_pivot(int low, int high);
void swap(int *a, int *b);
int partition(int arr[], int low, int high);
int partition_r (int arr[], int low, int high);
void quicksort(int arr[], int low, int high);

#endif //PROJEKT_1_SORTOWANIE_MY_QUICKSORT_HH
