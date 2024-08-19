#include <iostream>
#include <cstdlib> // system()

int operator"" _cmd(const char *command, std::size_t)
{
    return system(command);
}

int main()
{
    int commandReturnValue = "dir"_cmd;
    std::cout << "Command return value: " << commandReturnValue << std::endl;

    int commandReturnValue2 = "pause"_cmd;
    std::cout << "Command return value 2: " << commandReturnValue << std::endl;

    return 0;
}