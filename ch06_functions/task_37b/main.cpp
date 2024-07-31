#include <iostream>

inline int wieksza(int a, int b)
{
    return a > b ? a : b;
}

int main()
{
    int x{23};
    int y{18};

    std::cout << "Larger number: " << wieksza(x, y) << std::endl;

    return 0;
}
