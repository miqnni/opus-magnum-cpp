#include <iostream>
#include <string>

void charsInBrackets(std::string toBePrinted, char leftBracket = '[', char rightBracket = ']')
{
    for (auto el : toBePrinted)
        std::cout << leftBracket << el << rightBracket;
    std::cout << std::endl;
}

int main()
{
    std::string myString(3, '*');
    myString += " Alabama!";
    charsInBrackets(myString);

    return 0;
}
