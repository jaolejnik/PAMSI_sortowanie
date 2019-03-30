#include "../inc/menu.hh"

int main()
{
    /*
    int start = 0;
    int size = 1000;
    int * arr = new int[size];
    //int arr[] = {4, 10, 3, 5, 1};
    random_filler(arr,size);

    for (int i = 0; i < size; ++i) {
        cout << "NR. "<< i << " " << arr[i] << endl;
    }
    cout << endl;
    introsort(arr, start, size);

    for (int i = 0; i < size; ++i) {
        cout << "NR. " << i << " " << arr[i] << endl;
    }
    if(!is_sorted(arr, start, size-1))
        cout << "NIEPOSORTOWANE" << endl;

    */

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