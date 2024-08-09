#include <iostream>

void sampleF(int x)
{
    std::cout << "x = " << x << " | INT" << std::endl;
}

void sampleF(double x)
{
    std::cout << "x = " << x << " | DOUBLE" << std::endl;
}

// `ptrReturn` is a function returning a pointer to
// another function that takes an `int` argument
// and returns no result (`void`).
void (*ptrReturn(void))(int)
{
    return sampleF;
}

// void arrTest(int arr[])
// {
//     // std::cout << "sizeof(arr): " << sizeof(arr) << std::endl; // ERROR
//     std::cout << "arr[0]: " << arr[0] << std::endl;
// }

int main()
{
    (ptrReturn())(4);

    // int arrt[26]{4, 3, 5};
    // std::cout << "sizeof(arrt): " << sizeof(arrt) << std::endl;
    // arrTest(arrt);

    return 0;
}