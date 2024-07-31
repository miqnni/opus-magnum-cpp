#include <iostream>

void binaryPrint(int decimalNumber);

int main()
{
    binaryPrint(11767);
    binaryPrint(32);
    binaryPrint(0);
    binaryPrint(1);
    binaryPrint(2);
    binaryPrint(31);
    binaryPrint(65);

    // EXPECTED
    // 10 1101 1111 0111
    // 10 0000
    // 0
    // 1
    // 10
    // 1 1111
    // 100 0001

    return 0;
}

void binaryPrint(int decimalNumber)
{
    static int recursionLevel{0};

    int currentBinaryDigit = decimalNumber % 2;

    recursionLevel++;
    if (decimalNumber > 1)
        binaryPrint(decimalNumber / 2);
    recursionLevel--;

    std::cout << currentBinaryDigit << (recursionLevel % 4 == 0 && recursionLevel > 0 ? " " : "");

    if (!recursionLevel)
        std::cout << std::endl;
}

// DEC 11 767
// BIN 10 1101 1111 0111