#include <iostream>
#include <string>

std::string numberInfo(int number)
{
    std::string info("Number " + std::to_string(number) + " is ");
    info += ((number % 2) ? "odd" : "even");
    info += ".";

    return info;
}

int main()
{
    std::cout << numberInfo(55) << std::endl;
    std::cout << numberInfo(1) << std::endl;
    std::cout << numberInfo(56) << std::endl;
    std::cout << numberInfo(99) << std::endl;
    std::cout << numberInfo(0) << std::endl;

    return 0;
}
