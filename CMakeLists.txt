cmake_minimum_required(VERSION 3.12)
project(Projekt_1___Sortowanie)

set(CMAKE_CXX_STANDARD 14)

add_executable(Projekt_1___Sortowanie src/main.cpp inc/helper_func.hh src/my_mergesort.cpp inc/my_mergesort.hh src/helper_func.cpp src/my_quicksort.cpp inc/my_quicksort.hh src/file_managment.cpp inc/file_managment.hh src/my_introsort.cpp inc/my_introsort.hh src/my_insertionsort.cpp inc/my_insertionsort.hh src/my_heapsort.cpp inc/my_heapsort.hh src/menu.cpp inc/menu.hh)