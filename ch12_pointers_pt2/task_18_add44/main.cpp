#include <iostream>

void add44(int arr[], int len)
{
    for (int i{}; i < len; i++)
        arr[i] += 44;
}

int main()
{
    int loc[10]{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

    add44(loc, 10);
    add44(loc, 5);

    for (const auto &el : loc)
        std::cout << el << std::endl;

    return 0;
}
