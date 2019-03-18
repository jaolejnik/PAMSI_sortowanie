#include "helper_func.hh"
#include "my_mergesort.hh"
#include "my_quicksort.hh"

using namespace std;

int main()
{

    void (*merge_pointer)(int [], int, int) = &mergesort;
    void (*quick_pointer)(int [], int, int) = &quicksort;
    //merge_pointer = mergesort;
    void (*pf[3])(int [], int, int) = {mergesort,quicksort};

    string base_name = "results.csv";
    string name;
    int sizes[] = {10000, 50000, 100000, 500000, 1000000};
    double time[100];

    for (int i = 0; i < 2; i++)
    {
        if (pf[i] == merge_pointer)
        {
            name = "mergesort_" + base_name;
            cout << endl;
            cout << "MERGESORT: " << endl;
            cout << endl;
        }
        else if (pf[i] == quick_pointer)
        {
            name = "quicksort_" + base_name;
            cout << endl;
            cout << "QUICKSORT: " << endl;
            cout << endl;
        }

        //if(file_exist(name))
            //change_file_name(&name);

        for (int capacity: sizes)
        {
            cout << "Sorting arrays with " << capacity << " elements." << endl;
            for (double &t: time)
                t = start_sorting(capacity, pf[0]);
            time_to_file(name, time, capacity);
        }
        mark_as_full(name);
        cout << endl;
        cout << "Saved results to " << name << endl;
        cout << endl;
    }

    return 0;
}