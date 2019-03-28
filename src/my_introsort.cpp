#include "../inc/my_introsort.hh"
#include "../inc/helper_func.hh"

int median_of_three(int a, int b, int c)
{
    if (a < b && b < c)
        return b;

    if (a < c && c <= b)
        return c;

    if (b <= a && a < c)
        return a;

    if (b < c && c <= a)
        return c;

    if (c <= a && a < b)
        return a;

    if (c <= b && b <= a)
        return b;
}


template<typename MyType>
void intro_r(MyType arr[], int start, int end, int max_depth)
{
    if(end - start < 16)
    {
        //std::cout << "insert" << std::endl;
        insertionsort(arr, start, end);
        if (!is_sorted(arr, start, end))      // if not
            std::cerr << "The array is not sorted!INSERT\a" << std::endl; // return error
    }
    if(max_depth == 0)
    {
        //std::cout << "heap" << std::endl;
        part_heapsort(arr, start, end);
        if (!is_sorted(arr, start, end))      // if not
            std::cerr << "The array is not sorted! HEAP\a" << std::endl; // return error
    }
    else
    {
        if (start < end )
        {
            int r = median_of_three(start, end/2, end);
            swap(&arr[r],&arr[end]);

            int pivot_index = partition(arr, start, end);
            //std::cout << "rekur" << std::endl;
            intro_r(arr, start, pivot_index -1, max_depth-1);
            intro_r(arr, pivot_index +1, end, max_depth-1);
        }

    }
}

// Implementation of introsort
// ( tmp is passed as an argument, because of the pointer to a function compatibility)
template <typename MyType>
void introsort(MyType arr[], int start, int end)
{
    int max_depth = 2*log(end - start);
    intro_r(arr, start, end, max_depth);

}


template void introsort<int>(int arr[], int start, int end);
template void intro_r(int arr[], int start, int end, int max_depth);

template void introsort<double>(double arr[], int start, int end);
template void intro_r(double *arr, int start, int end, int max_depth);
