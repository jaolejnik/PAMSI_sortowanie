#ifndef PROJEKT_1_SORTOWANIE_HELPER_FUNC_HH
#define PROJEKT_1_SORTOWANIE_HELPER_FUNC_HH

#include <iostream>
#include <fstream>
#include <chrono>


template <typename MyType>
double start_sorting(int size, void (*pf)(MyType [], int, int));

template <typename MyType>
bool is_sorted(MyType arr[], int size);

template <typename MyType>
void random_filler(MyType arr[], int size);

double sum_array(double arr[], int size);

bool file_exist(std::string name);

void change_file_name(std::string * name);

bool time_to_file(std::string name, double sort_time[], int size);

bool mark_as_full(std::string name);

bool is_full(std::string name);

#endif //PROJEKT_1_SORTOWANIE_HELPER_FUNC_HH
