#include <iostream>
#include <string>

int main()
{
    std::string myString("AlabamaXYZ Sample Text Hello World");

    int stringStart{7};
    int numberOfChars{3};

    std::string fragmV0(myString, stringStart, numberOfChars);
    std::string fragmV1{myString.substr(stringStart, numberOfChars)};

    std::cout << "fragmV0: " << fragmV0 << std::endl;
    std::cout << "fragmV1: " << fragmV1 << std::endl;

    return 0;
}