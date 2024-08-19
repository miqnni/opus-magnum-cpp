#include <iostream>
#include <string>
#include <iomanip> // std::cout << std::hex << (variableName) << std::dec;

std::string operator"" _binary(unsigned long long value)
{
    std::string result{""};

    for (int i{}; i < 32; i++)
    {
        if (i % 4 == 0)
            result = " " + result;

        char newDigit{value % 2 ? '1' : '0'};
        result = newDigit + result;

        value /= 2;
    }

    // Ramove the whitespace inserted at the beginning.
    // Due to `if (i % 4 == 0) ...`
    result.pop_back();
    return result;
}

int main()
{
    std::cout << "0x" << std::hex << 0xfa << std::dec << " --> " << 0xfa_binary << std::endl;

    return 0;
}
