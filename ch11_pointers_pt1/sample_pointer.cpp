#include <iostream>

int main()
{
    int myInt{41};
    void *myPtr{&myInt};
    int *pMyInt{reinterpret_cast<int *>(myPtr)};
    std::cout << "*pMyInt: " << *pMyInt << std::endl;

    return 0;
}