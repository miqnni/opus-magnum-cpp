#include <iostream>

void zero(int *p);

int main()
{
    int arr[10] = {2, 4, 6, 8, 10, 12, 14, 16, 18, 20};

    for (const auto &idx : {0, 3, 4, 7})
        zero(&arr[idx]);

    for (const auto &el : arr)
        std::cout << el << " ";
    std::cout << std::endl;

    return 0;
}

void zero(int *p)
{
    *p = 0;
}