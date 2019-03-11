#include "menu.hh"




void show_size_menu()
{
    std::cout << std::endl;
    std::cout << "Choose size of the arrays" << std::endl;
    std::cout << "---------------------------------" << std::endl;
    std::cout << "1)      10 000" << std::endl;
    std::cout << "2)      50 000" << std::endl;
    std::cout << "3)     100 000" << std::endl;
    std::cout << "4)     500 000" << std::endl;
    std::cout << "5)   1 000 000" << std::endl;
    std::cout << "==============" << std::endl;
    std::cout << "6) All of them (not implemented yet)" << std::endl;
    std::cout << std::endl;
    std:: cout << "q - exit" << std::endl;
    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << "Your choice:";
}


void size_menu(char tmp, int * size)
{
    switch(tmp)
    {
        case '1': *size = 10000;
            break;
        case '2': *size = 50000;
            break;
        case '3': *size = 100000;
            break;
        case '4': *size = 500000;
            break;
        case '5': *size = 1000000;
            break;
        case '6': std::cout << "Not implemented yet." << std::endl;
            break;
        case 'q': std::cout << "The program is now closing." << std::endl;
            break;
        default:
            {
                std::cout << "Invalid input! Choose one of the below:" << std::endl;
                show_size_menu();
                break;
            }
    }
}


void show_sorts_menu()
{
    std::cout << std::endl;
    std::cout << "Choose type of sorting algorithm:" << std::endl;
    std::cout << "---------------------------------" << std::endl;
    std::cout << "1)   Mergesort" << std::endl;
    std::cout << "2)   Quicksort (not implemented yet)" << std::endl;
    std::cout << "3)   Introsort (not implemented yet)" << std::endl;
    std::cout << "==============" << std::endl;
    std::cout << "4) All of them (not implemented yet)" << std::endl;
    std::cout << std::endl;
    std::cout << "b - go back" << std::endl;
    std::cout << "q - exit" << std::endl;
    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << "Your choice:";
}

