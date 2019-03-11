#include "ArrayToSort.hh"
#include "menu.hh"

using namespace std;

int main()
{
    int size = 1;
    char tmp = '.';
    while (true)
    {
        show_size_menu();
        cin >> tmp;
        size_menu(tmp, &size);
        if(tmp == 'q')
            break;
        ArrayToSort<int> test(size);
        test.random_fill();

        show_sorts_menu();
        cin >> tmp;
        sorts_menu(tmp, &test, size);
        if(tmp == 'q')
            break;
        else if(tmp == 'b')
            continue;

        if(test.save_to_file())
            return 0;
        else
            return 1;
    }
    return 0;
}