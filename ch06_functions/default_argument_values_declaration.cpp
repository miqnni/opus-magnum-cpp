#include <iostream>

void printArguments(int arg0 = 1, int arg1 = 6);

int squareAndIncrement(int x);

// ************************************************

int main()
{

    return 0;
}

// ************************************************

void printArguments(int arg0, int arg1)
{
    std::cout << "f(" << arg0 << ", " << arg1 << ")" << std::endl;
}

// ************************************************

int squareAndIncrement(int x)
{
    return x * x + 1;
}