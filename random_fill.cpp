#include "random_fill.hh"


template<typename myType>
void random_fill(myType arr[], int size)
{
    std::random_device rd;
    std::mt19937 mt(rd());
    std::uniform_int_distribution<int> distribution(0,2000000);
    if( typeid(myType) == typeid(double) )
        std::uniform_real_distribution<double> distribution(0,2000000);

    for(int i = 0; i < size; i++)
    {
        //std::cout << i << std::endl;
        arr[i] = distribution(mt);
    }

}

template void random_fill<int>(int arr[], int size);
template void random_fill<double>(double arr[], int size);



