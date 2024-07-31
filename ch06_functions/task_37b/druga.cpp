#include <iostream>

inline int wieksza(int a, int b)
{
    return a > b ? a : b;
}

void druga(int a, int b)
{
    if (wieksza(a, b) == a)
        std::cout << a << " >= " << b << std::endl;
    else
        std::cout << a << " <= " << b << std::endl;
}
