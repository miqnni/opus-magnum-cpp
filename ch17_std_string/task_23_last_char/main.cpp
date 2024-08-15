#include <iostream>
#include <string>

int main()
{
    std::string myString("AlabamaXYZ Sample Text Hello World");
    char lastChar{myString[myString.find_last_not_of("")]};
    std::cout << "lastChar: " << lastChar << std::endl;

    char lastCharAlt{myString.back()};
    std::cout << "lastCharAlt: " << lastCharAlt << std::endl;

    return 0;
}