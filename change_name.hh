#ifndef PROJEKT_1_SORTOWANIE_CHANGE_NAME_HH
#define PROJEKT_1_SORTOWANIE_CHANGE_NAME_HH

#include <iostream>
#include <fstream>


bool file_exist(std::string name)
{
    std::ifstream myfile;
    myfile.open(name);
    return myfile.is_open();
}

void change_file_name(std::string * name)
{
    *name = "new_" + *name;
    if(file_exist(*name))
        change_file_name(name);
}


#endif //PROJEKT_1_SORTOWANIE_CHANGE_NAME_HH
