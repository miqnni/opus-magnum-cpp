#include <iostream>
#include <cmath>

constexpr double PI{3.1415926};

// ************************************************

constexpr long long factorial(int num)
{
    return num > 0 ? num * factorial(num - 1) : 1;
}

// ************************************************

constexpr double power(double base, int exponent)
{
    return exponent > 0 ? base * power(base, exponent - 1) : 1;
}

// ************************************************

constexpr double sinApproximation(double x)
{
    return x -
           power(x, 3) / factorial(3) +
           power(x, 5) / factorial(5) -
           power(x, 7) / factorial(7) +
           power(x, 9) / factorial(9) -
           power(x, 11) / factorial(11) +
           power(x, 13) / factorial(13) -
           power(x, 15) / factorial(15) +
           power(x, 17) / factorial(17) -
           power(x, 19) / factorial(19) +
           power(x, 21) / factorial(21);
}

// ************************************************

constexpr double changeDegreesToRadians(double degrees)
{
    return PI * degrees / 180;
}

// ************************************************

int main()
{
    for (int i = 270; i <= 360; i += 10)
    {
        double iAsDouble = static_cast<double>(i);
        std::cout << i << " degrees:" << std::endl
                  << "\t my sin:\t" << sinApproximation(changeDegreesToRadians(iAsDouble)) << std::endl
                  << "\tlib sin:\t" << sin(changeDegreesToRadians(iAsDouble)) << std::endl;
    }

    return 0;
}