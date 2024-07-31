#include <iostream>
#include "header_file.h"

int fileOneInt{4};
double fileOneDouble{1.1};
char fileOneChar{'a'};

extern void fileTwoFunctionOne();
extern void fileTwoFunctionTwo();

void fileOneFunction();

int main()
{
    std::cout << "first.cpp main (before): " << std::endl
              << "\t" << fileOneInt << std::endl
              << "\t" << fileOneDouble << std::endl
              << "\t" << fileOneChar << std::endl
              << "\t" << fileTwoInt << std::endl
              << "\t" << fileTwoDouble << std::endl
              << "\t" << fileTwoChar << std::endl
              << std::endl;

    fileOneInt++;
    fileOneDouble++;
    fileOneChar++;
    fileTwoInt++;
    fileTwoDouble++;
    fileTwoChar++;

    std::cout << "first.cpp main (after): " << std::endl
              << "\t" << fileOneInt << std::endl
              << "\t" << fileOneDouble << std::endl
              << "\t" << fileOneChar << std::endl
              << "\t" << fileTwoInt << std::endl
              << "\t" << fileTwoDouble << std::endl
              << "\t" << fileTwoChar << std::endl
              << std::endl;

    std::cout << "==========================" << std::endl
              << std::endl;

    fileOneFunction();

    return 0;
}

void fileOneFunction()
{
    std::cout << "first.cpp fileOneFunction (before): " << std::endl
              << "\t" << fileOneInt << std::endl
              << "\t" << fileOneDouble << std::endl
              << "\t" << fileOneChar << std::endl
              << "\t" << fileTwoInt << std::endl
              << "\t" << fileTwoDouble << std::endl
              << "\t" << fileTwoChar << std::endl
              << std::endl;

    fileOneInt++;
    fileOneDouble++;
    fileOneChar++;
    fileTwoInt++;
    fileTwoDouble++;
    fileTwoChar++;

    std::cout << "first.cpp fileOneFunction (after): " << std::endl
              << "\t" << fileOneInt << std::endl
              << "\t" << fileOneDouble << std::endl
              << "\t" << fileOneChar << std::endl
              << "\t" << fileTwoInt << std::endl
              << "\t" << fileTwoDouble << std::endl
              << "\t" << fileTwoChar << std::endl
              << std::endl;

    std::cout << "==========================" << std::endl
              << std::endl;

    fileTwoFunctionOne();
}
