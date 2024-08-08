#include <iostream>

int f0();
int f1();
int f2();

int bigF(int (*otherFunction)());

int main()
{
    std::cout << bigF(&f0) << std::endl;
    std::cout << bigF(&f1) << std::endl;
    std::cout << bigF(&f2) << std::endl;

    return 0;
}

int f0() { return 10; }
int f1() { return 11; }
int f2() { return 12; }

int bigF(int (*otherFunction)()) { return (*otherFunction)(); } // OR: return otherFunction();
