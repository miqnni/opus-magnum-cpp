#include <iostream>
#include <string>

int main(int argc, char const *argv[])
{
    if (argc != 3)
    {
        std::cout << "Usage:" << argv[0] << " -{serv|file|stre|...} <name>" << std::endl;
        return 1;
    }

    std::string firstArg(argv[1]);
    std::string secondArg(argv[2]);

    std::string firstArgCode("");
    firstArgCode = firstArg[0] == '-' ? firstArg.substr(1, 4) : firstArg.substr(0, 4);

    std::string firstArgDescription("");

    if (firstArgCode == "serv")
        firstArgDescription = "server ";
    else if (firstArgCode == "file")
        firstArgDescription = "file ";
    else if (firstArgCode == "stre")
        firstArgDescription = "stream ";
    else
        firstArgDescription = "(unknown source type) ";

    std::cout << "The data will come from " << firstArgDescription << secondArg << std::endl;

    return 0;
}
