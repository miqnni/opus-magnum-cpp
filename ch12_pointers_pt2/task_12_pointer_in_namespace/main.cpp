#include <iostream>

namespace ptrTest
{
    int *p;
};

int main()
{
    std::cout << "ptrTest::p: " << ptrTest::p << std::endl;
    return 0;
}