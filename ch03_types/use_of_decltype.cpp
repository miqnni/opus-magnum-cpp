#include <iostream>

constexpr int ARR_SIZE = 10000;

int main()
{
    auto x0{3uLL};
    decltype(x0) x1;

    using saved_type_0 = decltype(x1);   // unsigned long long
    using saved_type_1 = decltype(3.1f); // float

    saved_type_0 x2;

    saved_type_1 y0;
    saved_type_1 *y1;
    saved_type_1 y2[ARR_SIZE];

    x1 = 1000000000000;
    x2 = 1000000000000;

    y0 = 3.121212;
    y1 = &y0;
    y2[0] = *y1;

    std::cout << "x0: " << x0 << std::endl;
    std::cout << "x1: " << x1 << std::endl;
    std::cout << "x2: " << x2 << std::endl;
    std::cout << "y0: " << y0 << std::endl;
    std::cout << "y1: " << y1 << std::endl;
    std::cout << "*y1: " << *y1 << std::endl;
    std::cout << "y2[0]: " << y2[0] << std::endl;

    return 0;
}
