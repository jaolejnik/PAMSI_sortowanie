#include "../inc/my_quicksort.hh"
#include "../inc/helper_func.hh"

// Generates a random pivot
int random_pivot(int low, int high)
{
    // Generate a random number in between
    // low .. high
    srand(time(NULL));
    int random = low + rand() % (high - low);

    return random;
}


// Function that "creates" partitions, by putting elements smaller than pivot to the left
// and bigger to the right of it, then returns pivot's index.
template <typename MyType>
int partition (MyType arr[], int low, int high)
{
    int pivot = arr[high];
    int left_element = (low - 1);

    // Until right_element reaches the pivot's index
    for (int right_element = low; right_element <= high - 1; right_element++)
    {
        if (arr[right_element] <= pivot)    // If it's smaller than pivot
        {
            left_element++;     // Move left_element one step ahead
            swap(&arr[left_element], &arr[right_element]);  // swap both elements.
        }
    }
    swap(&arr[left_element + 1], &arr[high]);   // Swap element nex to the left one and pivot.
    return (left_element + 1);      // Return pivot index.
}


// Implementation of quicksort.
template <typename MyType>
void quicksort(MyType arr[], int low, int high)
{
    if (low < high)
    {
        int r = random_pivot(low,high); // Get a random pivot
        swap(&arr[r], &arr[high]);  // swap it's element with the last one

        int pivot_index = partition(arr, low, high);    // Get the pivot index

        quicksort(arr, low, pivot_index - 1);   // Start recursive sort of the left part
        quicksort(arr, pivot_index + 1, high);  // Start recursive sort of the right part
    }
}

template int partition<int>(int arr[], int low, int high);
template void quicksort<int>(int arr[], int low, int high);

template int partition<double>(double arr[], int low, int high);
template void quicksort<double>(double arr[], int low, int high);