#include <iostream>
#include <windows.h>

int square(int x)
{
    return x * x;
}

int cube(int x)
{
    return x * square(x);
}

int power4(int x)
{
    return x * cube(x);
}

int power5(int x)
{
    return x * power4(x);
}

void changingNumber()
{
    for (int i{1000}; i < 10000; i++)
    {
        std::cout << "Value: [[  " << i << "  ]]\r" << std::flush;
        Sleep(0.05);
    }
    std::cout << std::endl
              << "Display end." << std::endl;
}

int main()
{
    // int availableFunctions[4];
    int (*availableFunctions[4])(int){&square, &cube, &power4, &power5};

    int sampleX{2};

    // v1
    std::cout << "v1: ";
    for (int (*functionPtr)(int) : availableFunctions)
        std::cout << functionPtr(sampleX) << " "; // OR: (*functionPtr)(sampleX)
    std::cout << std::endl;

    // v2
    std::cout << "v2: ";
    for (int i{}; i < 4; i++)
        std::cout << availableFunctions[i](sampleX) << " "; // OR: (*availableFunctions[i])(sampleX)
    std::cout << std::endl;

    changingNumber();

    return 0;
}