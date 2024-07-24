#include <iostream>

void functionThatDoesNotUseSomeArgument(int usedArg0, int unusedArg0, double usedArg1);

int main()
{
    functionThatDoesNotUseSomeArgument(5, 4321, 2.3);

    return 0;
}

void functionThatDoesNotUseSomeArgument(int usedArg0, int /* unusedArg0 */, double usedArg1)
{
    std::cout << "Product of used arguments: " << usedArg0 * usedArg1 << std::endl;
}
