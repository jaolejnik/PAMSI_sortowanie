#include "../inc/menu.hh"

void show_menu()
{
    std::cout << std::endl;
    std::cout << "Choose type of sorting algorithm:" << std::endl;
    std::cout << "---------------------------------" << std::endl;
    std::cout << "1)   Mergesort" << std::endl;
    std::cout << "2)   Quicksort" << std::endl;
    std::cout << "3)   Introsort" << std::endl;
    std::cout << "==============" << std::endl;
    std::cout << "4) All of them" << std::endl;
    std::cout << std::endl;
    std::cout << "q - exit" << std::endl;
    std::cout << std::endl;
    std::cout << "Your choice:";
}

template <typename MyType>
void menu(char tmp, void (*pf[3])(MyType [], int, int))
{
    switch(tmp)
    {
        case '1': start_test(pf[0]);
            break;

        case '2': start_test(pf[1]);
            break;

        case '3': start_test(pf[2]);
            break;

        case '4':
            for (int i = 0; i < 3; i++)
                start_test(pf[i]);
            break;

        case 'q': cout << "Closing..." << endl;
            break;

        default:
            cout << endl;
            cout<< "Invalid option! Chose one of the below:" << endl;
            break;
    }
}

template void menu<int>(char tmp, void (*pf[3])(int [], int, int));

template void menu<double>(char tmp, void (*pf[3])(double [], int, int));