#include <iostream>
#include <string>
#include <iomanip>

std::string whichLetter(int letterNumber)
{
    if (letterNumber < 1 || letterNumber > 26)
        return std::string("There is no letter number #") + std::to_string(letterNumber) + std::string(" in the English alphabet.");
    char letter = 'A' + (letterNumber - 1);
    return std::string("The letter number #") + std::to_string(letterNumber) + std::string(" in the alphabet is: ") + std::string({letter});
}

int main()
{
    for (const auto &x : {1, 2, 3, 6, 0, 27, 25, 26, 14})
    {
        std::cout << std::setw(2) << x << ": " << whichLetter(x) << std::endl;
    }

    return 0;
}