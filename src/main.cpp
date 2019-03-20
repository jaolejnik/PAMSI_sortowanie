#include "../inc/helper_func.hh"
#include "../inc/file_managment.hh"
#include "../inc/my_mergesort.hh"
#include "../inc/my_quicksort.hh"

using namespace std;

int main()
{
    /*
    int arr[100];
    random_filler(arr,100);

    quicksort(arr, 0, 100-1);
    for (int x: arr)
        cout << x << endl;
    */

    void (*merge_pointer)(int [], int, int) = &mergesort;
    void (*quick_pointer)(int [], int, int) = &quicksort;
    void (*pf[3])(int [], int, int) = { mergesort, quicksort};

    string base_name = "results.csv";
    string name;
    float part_sort[] = {0, 25, 50, 75, 95, 99, 99.7, 100};
    int sizes[] = {10000, 50000, 100000, 500000, 1000000};
    double time[100];
    char tmp;

    for (int i = 0; i < 2; i++)
    {
        if (pf[i] == merge_pointer)
        {
            name = "mergesort_" + base_name;
            cout << endl;
            cout << "MERGESORT: " << endl;
        }
        else if (pf[i] == quick_pointer)
        {
            name = "quicksort_" + base_name;
            cout << endl;
            cout << "QUICKSORT: " << endl;
        }

        //if(file_exist(name))
            //change_file_name(&name);

        for (float percent : part_sort)
        {
            cout << endl;
            cout << percent << "% OF ARRAY IS SORTED";
            if (percent == 100)
                cout << ", BUT IT'S REVERSED";
            cout << endl;
            cout << endl;

            for (int capacity: sizes)
            {
                cout << "Sorting arrays with " << capacity << " elements." << endl;
                for (double &t: time)
                    t = start_sorting(capacity, percent, pf[i]);
                time_to_file(name, time, capacity, percent);
            }
        }
        mark_as_full(name);
        cout << endl;
        cout << "Saved results to " << name << endl;
        cout << endl;

        cout << "Continue? [y/n]" << endl;
        cin.get(tmp);
        if (tmp == 'y')
            continue;
        else
            break;
    }

    return 0;

}