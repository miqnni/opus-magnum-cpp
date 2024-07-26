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
           power(x, 9) / factorial(9);
}

// ************************************************

constexpr double changeDegreesToRadians(double degrees)
{
    return PI * degrees / 180;
}

// ************************************************

constexpr double sinArray[] = {
    sinApproximation(changeDegreesToRadians(0.0)),
    sinApproximation(changeDegreesToRadians(2.5)),
    sinApproximation(changeDegreesToRadians(5.0)),
    sinApproximation(changeDegreesToRadians(7.5)),
};

constexpr int myNum{6};
constexpr int myNumFactorial{factorial(myNum)};

int main()
{
    std::cout << "myNumFactorial: " << myNumFactorial << std::endl;

    int localNum{4};
    int nonConstexprResult = factorial(localNum);

    std::cout << "Factorial of local variable: " << nonConstexprResult << std::endl;

    std::cout << "sin(1 rad) \\approx " << sinApproximation(1) << " (result of `sin` library function: " << sin(1) << ")" << std::endl;
    std::cout << "sin(45 deg) \\approx " << sinApproximation(changeDegreesToRadians(45)) << " (result of `sin` library function: " << sin(changeDegreesToRadians(45)) << ")" << std::endl;

    for (int i{0}; i < 4; i++)
    {
        std::cout << "sin(" << i * 2.5 << " deg): " << sinArray[i] << std::endl;
    }

    return 0;
}
