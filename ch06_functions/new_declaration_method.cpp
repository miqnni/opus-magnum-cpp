#include <iostream>

double f1(int arg1, double arg2);
auto f2(int arg1, double arg2) -> double;
// ************************************************

int main()
{
    std::cout << f1(3, 5.25) << std::endl;
    std::cout << f2(3, 5.25) << std::endl;

    return 0;
}
// ************************************************

double f1(int arg1, double arg2)
{
    return arg1 * 2 * arg2;
}
// ************************************************

auto f2(int arg1, double arg2) -> double
{
    return arg1 * 3 * arg2;
}
