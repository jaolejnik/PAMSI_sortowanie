#include "../inc/menu.hh"

int main()
{
    // If you want to test sorting algorithm on double type data just comment and uncomment below lines.

    void (*pf[3])(int [], int, int) = { mergesort, quicksort, introsort};
    //void (*pf[3])(double [], int, int) = { mergesort, quicksort, introsort};

    char tmp = '.';

    while(tmp != 'q')
    {
        show_menu();
        cin.get(tmp);
        cin.ignore(1,'\n');
        menu(tmp,pf);
    }

    return 0;
}