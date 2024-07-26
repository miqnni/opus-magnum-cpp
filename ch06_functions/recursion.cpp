#include <iostream>
#include <string>

int sumOfNumbersFromZeroTo(int num);
void printInBinary(int num, std::string currentForm = ""); // num > 0
void printInBinaryV2(int num);                             // num >= 0

int main()
{
    for (int i{-3}; i < 8; i++)
        std::cout << i << ": " << sumOfNumbersFromZeroTo(i) << std::endl;

    int numbersToPrintInBinary[] = {32, 31, 12, 50, 1, 0};

    for (auto el : numbersToPrintInBinary)
        printInBinary(el);

    for (auto el : numbersToPrintInBinary)
    {
        printInBinaryV2(el);
        std::cout << std::endl;
    }

    return 0;
}

int sumOfNumbersFromZeroTo(int num)
{
    if (num <= 0)
        return 0;
    return num + sumOfNumbersFromZeroTo(num - 1);
}

void printInBinary(int num, std::string currentForm)
{
    if (num <= 0)
    {
        std::cout << currentForm << std::endl;
        return;
    }

    printInBinary(num / 2, std::to_string(num % 2) + currentForm);
}

void printInBinaryV2(int num)
{
    int remainder{num % 2};
    if (num > 1)
        printInBinaryV2(num / 2);

    std::cout << remainder;
    return;
}