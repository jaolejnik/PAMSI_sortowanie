#include "helper_func.hh"
#include "my_mergesort.hh"
#include <random>
#include <iostream>
#include <fstream>
#include <chrono>
#include <iomanip>

using namespace std;

template <typename MyType>
double  start_sorting(int size, void (*pf)(MyType [], int, int))
{
    MyType * arr = new MyType[size];

    random_filler<MyType>(arr, size);

    auto clock_start = std::chrono::high_resolution_clock::now();
    //mergesort<MyType>(arr, 0, size - 1);
    (*pf)(arr, 0, size - 1);
    auto clock_stop = std::chrono::high_resolution_clock::now();

    if (!is_sorted<MyType>(arr, size))
    {
        std::cerr << "The array is not sorted!" << std::endl;
        return -1;
    }
    else
    {
        auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(clock_stop - clock_start);
        return duration.count();
    }
}


template<typename MyType>
bool is_sorted(MyType arr[], int size)
{
    for(int i = 0; i < (size - 1); i++)
    {
        if(arr[i] <= arr[i + 1])
            continue;
        else
            return false;
    }
    return true;
}


bool file_exist(string name)
{
    ifstream myFile;
    myFile.open(name);
    return myFile.is_open();
}


void change_file_name(string * name)
{
    static int file_index = 0;
    file_index++;
    *name = "new_" + *name;
    if(file_exist(*name))
        change_file_name(name);
}


bool time_to_file(string name ,double sort_time[], int size)
{
    ofstream myFile(name, ios_base::out| ios_base::app);

    if(is_full(name))
        ofstream myFile(name);

    if(!myFile.is_open())
    {
        cerr << " Error: Opening file to save have failed!" << endl;
        return false;
    }

    myFile << fixed << setprecision(2);
    myFile << "Average time it took to sort 1 array with " << size << " elements:\n ";
    myFile << sum_array(sort_time, 100)/100 << ';' << endl;


    for (int i = 0; i < 100; i++)
    {
        myFile << "Array nr. " << i + 1 << ";";
        myFile  << sort_time[i] << endl;
    }

    myFile << endl;
    
    myFile.close();

    return true;
}

bool mark_as_full(string name)
{
    ofstream myFile(name, ios_base::out| ios_base::app);
    myFile << endl;
    myFile << "End of results";
}

bool is_full(string name)
{
    string temp;
    ifstream myFile(name);
    if(!myFile.is_open())
    {
        cerr << " Error: Opening file to read have failed!" << endl;
        return false;
    }

    myFile.seekg(-1,ios_base::end);                // go to one spot before the EOF

    bool keepLooping = true;
    while(keepLooping)
    {
        char ch;
        myFile.get(ch);                            // Get current byte's data

        if((int)myFile.tellg() <= 1)
        {             // If the data was at or before the 0th byte
            myFile.seekg(0);                       // The first line is the last line
            keepLooping = false;                // So stop there
        }
        else if(ch == '\n')
        {                   // If the data was a newline
            keepLooping = false;                // Stop at the current position.
        }
        else
        {                                  // If the data was neither a newline nor at the 0 byte
            myFile.seekg(-2,ios_base::cur);        // Move to the front of that data, then to the front of the data before it
        }
    }

    getline(myFile, temp);
    
    return temp == "End of results";
}


template<typename MyType>
void random_filler(MyType arr[], int size)
{
    random_device rd;
    mt19937 mt(rd());
    uniform_int_distribution<int> distribution(0,2000000);
    if( typeid(MyType) == typeid(double) )
        uniform_real_distribution<double> distribution(0,2000000);

    for(int i = 0; i < 100; i++)
        arr[i] = distribution(mt);
}


double sum_array(double *arr, int size)
{
    double sum = 0;

    for (int i = 0; i < size; i++)
        sum += arr[i];

    return sum;
}




template bool is_sorted<int>(int arr[], int size);
template void random_filler<int>(int arr[], int size);
template double start_sorting<int>(int size, void (*pf)(int [], int, int));

template bool is_sorted<double>(double arr[], int size);
template void random_filler<double>(double arr[], int size);
template double start_sorting<double>(int size, void (*pf)(double [], int, int));