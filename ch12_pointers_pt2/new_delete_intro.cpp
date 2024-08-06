#include <iostream>

int main()
{
    char *charPtr;
    charPtr = new char;
    delete charPtr;

    double *doublePtr;
    doublePtr = new double[21];
    delete[] doublePtr;

    return 0;
}