#include <iostream>
#include <string>

void lineNumbers(std::string s)
{
    int lineNumber{1};
    std::cout << "Line " << lineNumber++ << ": ";

    for (const auto &el : s)
    {
        std::cout << el;
        if (el == '\n')
            std::cout << "Line " << lineNumber++ << ": ";
        }
    std::cout << std::endl;
}

int main()
{
    const char elelele[200] = R"(line one,
line two
line three)";
    std::string sample(elelele);
    lineNumbers(sample);
    return 0;
}