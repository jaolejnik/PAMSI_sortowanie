#ifndef PROJEKT_1_SORTOWANIE_MENU_HH
#define PROJEKT_1_SORTOWANIE_MENU_HH

#include <iostream>
#include "ArrayToSort.hh"


void show_size_menu();

void show_sorts_menu();

void show_types_menu();

void size_menu(char tmp, int * size);

template <typename MyType>
void sorts_menu(char tmp, ArrayToSort<MyType> * arrayToSort, const int size)
{
    switch(tmp)
    {
        case '1': arrayToSort->merge_sort(0,size-1);
            break;
        case '2': std::cout << "Not implemented yet." << std::endl;//arrayToSort->quick_sort();
            break;
        case '3': std::cout << "Not implemented yet." << std::endl;//arrayToSort->intro_sort();
            break;
        case '4': std::cout << "Not implemented yet." << std::endl;
            break;
        case 'b':
            break;
        case 'q': std::cout << "The program is now closing." << std::endl;
            break;
        default: show_sorts_menu();
            break;
    }
}

#endif //PROJEKT_1_SORTOWANIE_MENU_HH
