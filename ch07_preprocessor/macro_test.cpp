#include <iostream>

#define MACRO(par) std::cout << "In line "                             \
                             << __LINE__ << ", value of expression \"" \
                             << #par << "\" is equal to " << par << std::endl;

#define WHERE_AM_I() std::cout << "Line " \
                               << __LINE__ << ", function " << __func__ << std::endl;

void functionY();

int main()
{
    int variableX{41};
    MACRO(variableX);

    functionY();

    return 0;
}

void functionY()
{
    WHERE_AM_I();
}
