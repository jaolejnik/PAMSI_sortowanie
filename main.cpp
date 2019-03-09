#include "my_mergesort.hh"
#include "random_fill.hh"
using namespace std;

int main()
{
    int size = 1000000;

    int * arr = new int[size];
    random_fill<int>(arr, size);

    cout << endl;
    cout << "NOT SORTED:"<< endl;
    cout << "---------------------------"<< endl;
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
    cout << endl;

    cout << "SORTED:"<< endl;
    cout << "---------------------------"<< endl;
    merge_sort<int>(arr, 0, size - 1);
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;

    delete[] arr;

    return 0;
}