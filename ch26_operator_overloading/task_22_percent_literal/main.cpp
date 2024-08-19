#include <iostream>

// constexpr long double operator"" _percent(long double val)
// {
//     return val * 0.01L;
// }
// constexpr long double operator"" _percent(unsigned long long val)
// {
//     return static_cast<long double>(val) * 0.01L;
// }

constexpr double operator"" _percent(long double val)
{
    return val * 0.01;
}
constexpr double operator"" _percent(unsigned long long val)
{
    return val * 0.01;
}

int main()
{
    double result1 = 666 * 20_percent;          // result1 = 133.2
    double result2 = 600 * 33.33333333_percent; //  result2 = 200

    std::cout << "result1: " << result1 << std::endl;
    std::cout << "result2: " << result2 << std::endl;
    return 0;
}
