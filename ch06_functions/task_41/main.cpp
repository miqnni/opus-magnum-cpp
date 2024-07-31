#include <iostream>

void f();

int main()
{
    for (int i{0}; i < 100; i++)
    {
        f();
    }

    return 0;
}

void f()
{
    static int callCount = 1;
    if (!(callCount % 12))
        std::cout << "nowy tuzin (" << callCount << ")" << std::endl;
    else
        std::cout << ". (" << callCount << ")" << std::endl;
    callCount++;
}