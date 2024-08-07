#include <iostream>

int main()
{
    int a0;
    int *const pA0{&a0}; // const pointer to int object

    const int ca0{23};
    const int *const pCa0{&ca0}; // const pointer to const int object
    return 0;

    // AUTO KEYWORD
    double obj{37.1};

    auto *ptrA{&obj};             // double *
    const auto *ptrB{&obj};       // const double *
    auto *const ptrC{&obj};       // double *const
    const auto *const ptrD{&obj}; // const double *const

    const double cobj{36.5};

    // OK, because:
    // `const` works on the type directly on the left
    // and if there's nothing on the left, because it is
    // the beginning of the line, it works on the type
    // directly on the right.
    double const cobjTest{56.4};

    auto *ptrE{&obj};             // const double *
    const auto *ptrF{&obj};       // const double *
    auto *const ptrG{&obj};       // const double *const
    const auto *const ptrH{&obj}; // const double *const
}
