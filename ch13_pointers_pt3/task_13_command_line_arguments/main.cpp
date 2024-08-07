#include <iostream>

int main(int argc, char *argv[])
{
    std::cout << "Program name (argument 0): " << argv[0] << std::endl;

    for (int i{1}; i < argc; i++)
        std::cout << "Argument " << i << ": " << argv[i] << std::endl;

    return 0;
}
