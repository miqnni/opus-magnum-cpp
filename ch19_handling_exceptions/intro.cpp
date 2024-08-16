#include <iostream>
#include <string>

int main()
{
    std::cout << "Enter a string containing at least one digit: ";
    std::string userInput;
    getline(std::cin, userInput);

    try
    {
        size_t digitPos{userInput.find_first_of("0123456789")};
        if (digitPos == std::string::npos)
            throw std::runtime_error("No digit has been found.");

        std::cout << "First digit in the string: " << userInput[digitPos] << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }

    return 0;
}
