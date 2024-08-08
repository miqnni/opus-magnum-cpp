#include <iostream>

int f0();
auto f1() -> int;

double f2(int, int);
// double f3(int, char);

// ************************************************

int main()
{
    int (*pointerToIntFunction)();
    pointerToIntFunction = nullptr;

    int userChoice;
    std::cout << "Select a function: 0, 1" << std::endl;
    std::cout << "Your choice: ";
    std::cin >> userChoice;

    switch (userChoice)
    {
    case 0:
        pointerToIntFunction = &f0;
        break;
    case 1:
        pointerToIntFunction = &f1;
        break;
    default:
        break;
    }

    if (pointerToIntFunction)
        (*pointerToIntFunction)();

    // Define a pointer to f2.
    // double f2(int, int);
    double (*pF2)(int, int){&f2};
    std::cout << "(*pF2)(24, 25):\t" << (*pF2)(24, 25) << std::endl;
    std::cout << "pF2(24, 25):\t" << pF2(24, 25) << std::endl;

    // double f3(int, char);
    double (*pF3)(int, char);

    int(*(*fw)(int, char *))[2];
    // `fw` is a pointer that can point to a function
    // taking arguments of types `int` and `char *` (pointer to `char`)
    // and returning a pointer to a two-element array of
    // objects of type `int`.

    return 0;
}

// ************************************************

int f0()
{
    std::cout << "Function f0" << std::endl;
    return 81;
}

// ************************************************

int f1()
{
    std::cout << "Function f1" << std::endl;
    return 72;
}

// ************************************************

double f2(int a, int b)
{
    return static_cast<double>(a) / b;
}
