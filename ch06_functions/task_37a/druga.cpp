#include <iostream>
#include "wieksza.h"

void druga(int a, int b)
{
    if (wieksza(a, b) == a)
        std::cout << a << " >= " << b << std::endl;
    else
        std::cout << a << " <= " << b << std::endl;
}
