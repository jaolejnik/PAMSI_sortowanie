#ifndef PROJEKT_1_SORTOWANIE_SORTARRAY_HH
#define PROJEKT_1_SORTOWANIE_SORTARRAY_HH

#include <random>
#include <iostream>
#include <fstream>
#include <chrono>

// Class creating objects that consist of 2D array of given type (int or double)
//                                             ^
//                                    (100 arrays of given size)

template <typename MyType>
class ArrayToSort {

private:
    int size;
    MyType ** arr;
    double average_time;

public:
    // Constructor that dynamically allocates 2D array
    ArrayToSort(const int capacity)
    {
        size = capacity;
        arr = new MyType *[100];
        for (int i = 0; i < 100; i++)
            arr[i] = new MyType[size];
    }

    // Destructor
    ~ArrayToSort(){delete [] arr[100];}

    // Method that sorts the arrays using implemented merge_sort()
    void merge_sort(int start, int end);
    void merge(int start, int middle, int end);
    void quick_sort();
    void intro_sort();
    void random_fill();
    bool save_to_file();
    void print_arrays();

};

#endif //PROJEKT_1_SORTOWANIE_SORTARRAY_HH
