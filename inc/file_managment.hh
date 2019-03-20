#ifndef PROJEKT_1_SORTOWANIE_FILE_MANAGMENT_HH
#define PROJEKT_1_SORTOWANIE_FILE_MANAGMENT_HH

#include <iostream>
#include <fstream>
#include <iomanip>


bool file_exist(std::string name);

void change_file_name(std::string * name);

bool time_to_file(std::string name, double sort_time[], int size, float percent);

bool mark_as_full(std::string name);

bool is_full(std::string name);
#endif //PROJEKT_1_SORTOWANIE_FILE_MANAGMENT_HH
