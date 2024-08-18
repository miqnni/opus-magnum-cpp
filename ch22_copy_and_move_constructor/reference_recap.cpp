#include <iostream>

int main()
{
    int x{21};
    int y{32};

    int &ref{x};
    ref = y;

    ref *= 2;

    std::cout << "x: " << x << std::endl;
    std::cout << "y: " << y << std::endl;

    return 0;
}