#include <iostream>

constexpr int val1 = 26;
constexpr int val2 = 34;

int main()
{
    int user_input;
    std::cout << "Value: ";
    std::cin >> user_input;
    const int user_selection{user_input};

    switch (user_selection)
    {
    case val1:
        std::cout << "Value 1" << std::endl;
        break;
    case val2:
        std::cout << "Value 2" << std::endl;
        break;
    default:
        std::cout << "Some other value" << std::endl;
        break;
    }

    return 0;
}
