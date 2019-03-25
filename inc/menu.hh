#ifndef PROJEKT_1_SORTOWANIE_MENU_HH
#define PROJEKT_1_SORTOWANIE_MENU_HH

#include "helper_func.hh"
#include "file_managment.hh"
#include "my_mergesort.hh"
#include "my_introsort.hh"

using namespace std;

void show_menu();

template <typename MyType>
void menu(char tmp, void (*pf[3])(MyType [], int, int));

#endif //PROJEKT_1_SORTOWANIE_MENU_HH
