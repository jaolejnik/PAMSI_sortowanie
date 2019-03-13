#include "ArrayToSort.hh"
#include "change_name.hh"

template <typename MyType>
void ArrayToSort<MyType>::merge(int start, int middle, int end)
{
    int left_index, right_index, merge_index;

    int left_size = middle - start + 1;
    int right_size = end - middle;


    MyType * left_half = new MyType[left_size];
    MyType * right_half = new MyType[right_size];

    for (int i = 0; i < 100; i++)
    {
        for(left_index = 0; left_index < left_size; left_index++)
            left_half[left_index] = arr[i][left_index + start];

        for(right_index = 0; right_index < right_size; right_index++)
            right_half[right_index] = arr[i][right_index + middle + 1];

        left_index = 0;
        right_index = 0;
        merge_index = start;

        while(left_index < left_size && right_index < right_size)
        {
            if(left_half[left_index] <= right_half[right_index])
            {
                arr[i][merge_index] = left_half[left_index];
                left_index++;
            }
            else
            {
                arr[i][merge_index] = right_half[right_index];
                right_index++;
            }
            merge_index++;
        }

        while(left_index < left_size)
        {
            arr[i][merge_index] = left_half[left_index];
            left_index++;
            merge_index++;
        }


        while(right_index < right_size)
        {
            arr[i][merge_index] = right_half[right_index];
            right_index++;
            merge_index++;
        }
    }

    delete [] left_half;
    delete [] right_half;
}


template <typename MyType>
void ArrayToSort<MyType>::merge_sort(int start, int end)
{
    static int call_counter = 0;
    static std::chrono::time_point<std::chrono::system_clock> clock_start, clock_stop;

    if(call_counter == 0)
        clock_start = std::chrono::high_resolution_clock::now();;
    call_counter++;

    if( start < end )
    {
        int middle = (start + end) / 2;

        this->merge_sort(start, middle);
        this->merge_sort(middle + 1, end);


        this->merge(start, middle, end);
    }

    call_counter--;
    if(call_counter == 0)
    {
        clock_stop = std::chrono::high_resolution_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(clock_stop - clock_start);
        average_time = duration.count() / 100;
    }
}


template <typename MyType>
void ArrayToSort<MyType>::quick_sort() {

}


template <typename MyType>
void ArrayToSort<MyType>::intro_sort() {

}


template <typename MyType>
void ArrayToSort<MyType>::random_fill()
{
    std::random_device rd;
    std::mt19937 mt(rd());
    std::uniform_int_distribution<int> distribution(0,2000000);
    if( typeid(MyType) == typeid(double) )
        std::uniform_real_distribution<double> distribution(0,2000000);

    for(int i = 0; i < 100; i++)
        for(int j = 0; j < size; j++)
            arr[i][j] = distribution(mt);
}


template<typename MyType>
bool ArrayToSort<MyType>::save_to_file()
{
    std::string name = "Results.csv";

    if(file_exist(name))
        change_file_name(&name);

    std::ofstream myfile(name);
    if(!myfile.is_open())
    {
        std::cerr << " Error: Opening file to save have failed!" << std::endl;
        return false;
    }

    myfile << "Average time it took to sort 1 array with " << size << " elements:\n ";
    myfile<< average_time << "; ms\n";

    for (int i = 1; i <= 100; i++)
        myfile << "Array nr. " << i << ';';

    myfile << "\n";

    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < 100; j++)
            myfile << arr[j][i] << ';';
        myfile << "\n";
    }

    myfile.close();
    std::cout << "Saved to file!";

    return true;
}




template<typename MyType>
void ArrayToSort<MyType>::print_arrays()
{
    for (int i = 0; i < 100; i++)
    {
        std::cout << "Array nr. " << i+1 << std::endl;
        for (int j = 0; j < size; j++)
            std::cout << arr[i][j] << " ";
        std::cout << std::endl;
        std::cout << std::endl;
    }
}


template class ArrayToSort<int>;
template class ArrayToSort<double>;
