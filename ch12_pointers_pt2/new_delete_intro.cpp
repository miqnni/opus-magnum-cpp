#include <iostream>

int main()
{
    char *charPtr;
    charPtr = new char;
    delete charPtr;
    charPtr = nullptr;

    double *doublePtr;
    doublePtr = new double[21];
    delete[] doublePtr;
    doublePtr = nullptr;

    return 0;
}