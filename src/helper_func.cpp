#include "../inc/helper_func.hh"
#include "../inc/my_mergesort.hh"
#include "../inc/my_introsort.hh"
#include "../inc/my_quicksort.hh"
#include "../inc/file_managment.hh"
#include "unistd.h"

using namespace std;

// Utility function for swapping two values
template <typename MyType>
void swap(MyType *x, MyType *y)
{
    MyType tmp = *x;
    *x = *y;
    *y = tmp;
}


// Function that reverses an array
template <typename MyType>
void  reverse_arr(MyType arr[], int size)
{
    MyType tmp;
    for (int i = 0; i < size/2 ; i++)   // Every iteration
    {
        tmp = arr[i];                   // front element is stored in the template
        arr[i] = arr[size - i -1];      // end element is assigned to the front one
        arr[size - i -1] = tmp;         // front element is assigned to the end one
    }
}


// Func that checks whether the array is sorted
template<typename MyType>
bool is_sorted(MyType arr[], int size)
{
    for(int i = 0; i < (size - 1); i++)
    {
        if(arr[i] <= arr[i + 1])    // If the right element is smaller than the left one
            continue;               // go on
        else
            return false;           // If not return false
    }
    return true;
}


// Function that generates random numbers in range of 0 to 2 000 000 and fills the array with them.
template<typename MyType>
void random_filler(MyType arr[], int size)
{
    random_device rd;
    mt19937 mt(rd());
    uniform_int_distribution<int> distribution(0,2000000);      // Default type is int
    if( typeid(MyType) == typeid(double) )      // If MyType is double
        uniform_real_distribution<double> distribution(0,2000000);  // Overshadow above definition

    for(int i = 0; i < size; i++)   // Filling the array
        arr[i] = distribution(mt);
}


// Function that sums all of arrays elements
double sum_array(double *arr, int size)
{
    double sum = 0;

    for (int i = 0; i < size; i++)
        sum += arr[i];

    return sum;
}


// Function that creates an array of given size and type, then fills it with random numbers.
// If the percent argument is greater than 0, then that percent of the array is sorted
// (using mergesort). Next it measures time it took to sort using given sorting algorithm and
// returns it if the array was sorted successfully.
template <typename MyType>
double  start_sorting(int size, float percent, void (*pf)(MyType [], int, int))
{
    MyType * arr = new MyType[size];    // Dynamically allocate array of given type and size

    random_filler<MyType>(arr, size);   // Fill the array with numbers in range of 0 t 2 000 000

    if (percent > 0)    // If the percent is greater than 0
    {
        mergesort<MyType>(arr, 0, (int)(size * (percent / 100) - 1));   // percent of the array is sorted
        if (percent == 100)     // if percent equals 100
            reverse_arr(arr, size);     // then reverse the array
    }

    auto clock_start = chrono::high_resolution_clock::now();   // Start clock
    (*pf)(arr, 0, size - 1);                                        // Sort
    auto clock_stop = chrono::high_resolution_clock::now();    // Stop clock

    // Check if sorted
    if (!is_sorted<MyType>(arr, size))      // if not
    {
        cerr << "The array is not sorted!\a" << endl; // return error
        delete [] arr;
        return -1;
    }
    else    // if it is
    {       // return time it took to sort
        auto duration = chrono::duration_cast<chrono::milliseconds>(clock_stop - clock_start);
        delete [] arr;
        return duration.count();
    }
}


// Function that:
// - goes over every size and level of sorted arrays
// - collects time and saves it to the file
template<typename MyType>
void start_test(void (*pointer_func)(MyType *, int, int))
{
    // pointers to the sorting functions created for comparison
    void (*merge_pointer)(MyType [], int, int) = &mergesort;
    void (*quick_pointer)(MyType [], int, int) = &quicksort;
    void (*intro_pointer)(MyType [], int, int) = &introsort;

    string base_name = "results.csv";
    string name;
    float part_sort[] = {0, 25, 50, 75, 95, 99, 99.7, 100};
    int sizes[] = {10000, 50000, 100000, 500000, 1000000};
    double time[100];

    if (pointer_func == merge_pointer)      // Detects which function was passed as argument and
    {                                       // names the file after the sorting algorithm
        name = "Results/mergesort_" + base_name;
        cout << endl;
        cout << " MERGESORT: " << endl;
    }
    else if (pointer_func == quick_pointer)
    {
        name = "Results/quicksort_" + base_name;
        cout << endl;
        cout << " QUICKSORT: " << endl;
    }
    else if (pointer_func == intro_pointer)
    {
        name = "Results/introsort_" + base_name;
        cout << endl;
        cout << " INTROSORT: " << endl;
    }

    for (float percent : part_sort)     // Loop in which every percent of "sortiness" is applied
    {
        cout << endl;
        cout << '\t' << percent << "% OF ARRAY IS SORTED";
        if (percent == 100)
            cout << ", BUT IT'S REVERSED";
        cout << endl;
        cout << endl;

        for (int capacity: sizes)      // Loop in which every size of the array is sorted
        {
            cout << "Sorting arrays with " << capacity << " elements:" << endl;

            for (int i = 0; i < 100; ++i)
            {
                time[i] = start_sorting(capacity, percent, pointer_func);     //  Saving time to the array

                cout << "\b\b\b\b";
                cout << i+1 << "%" << std::flush;
            }
            time_to_file(name, time, capacity, percent);                //  that is saved to the file
            cout << endl;
        }
    }
    mark_as_full(name);     // marking the file as full for future use
    cout << endl;
    cout << "Saved results to " << name << endl;
    cout << endl;
}

template void swap<int>(int * a, int * b);
template bool is_sorted<int>(int arr[], int size);
template void random_filler<int>(int arr[], int size);
template double start_sorting<int>(int size, float percent, void (*pointer_func)(int [], int, int));
template void  reverse_arr<int>(int arr[], int size);
template void start_test<int>(void (*pointer_func)(int [], int, int));

template void swap<double>(double * a, double * b);
template bool is_sorted<double>(double arr[], int size);
template void random_filler<double>(double arr[], int size);
template double start_sorting<double>(int size, float percent, void (*pointer_func)(double [], int, int));
template void  reverse_arr<double>(double arr[], int size);
template void start_test<double>(void (*pointer_func)(double [], int, int));