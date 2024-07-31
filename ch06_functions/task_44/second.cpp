#include <iostream>
#include "header_file.h"

int fileTwoInt{17};
double fileTwoDouble{10.2};
char fileTwoChar{'M'};

void fileTwoFunctionOne();
void fileTwoFunctionTwo();

void fileTwoFunctionOne()
{
    std::cout << "first.cpp fileTwoFunctionOne (before): " << std::endl
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

    std::cout << "first.cpp fileTwoFunctionOne (after): " << std::endl
              << "\t" << fileOneInt << std::endl
              << "\t" << fileOneDouble << std::endl
              << "\t" << fileOneChar << std::endl
              << "\t" << fileTwoInt << std::endl
              << "\t" << fileTwoDouble << std::endl
              << "\t" << fileTwoChar << std::endl
              << std::endl;

    std::cout << "==========================" << std::endl
              << std::endl;

    fileTwoFunctionTwo();
}

void fileTwoFunctionTwo()
{
    std::cout << "first.cpp fileTwoFunctionTwo (before): " << std::endl
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

    std::cout << "first.cpp fileTwoFunctionTwo (after): " << std::endl
              << "\t" << fileOneInt << std::endl
              << "\t" << fileOneDouble << std::endl
              << "\t" << fileOneChar << std::endl
              << "\t" << fileTwoInt << std::endl
              << "\t" << fileTwoDouble << std::endl
              << "\t" << fileTwoChar << std::endl
              << std::endl;

    std::cout << "==========================" << std::endl
              << std::endl;
}
