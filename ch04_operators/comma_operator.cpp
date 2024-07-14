#include <iostream>

int main()
{
    int a = 1, x = 2, y;
    int expr_val = (a = 3, x = a * 2, y = 100 * x);

    std::cout << "value of expression (a = 3, x = a * 2, y = 100 * x): " << expr_val << std::endl;

    for (int i = 0; i < 100; i++)
        std::cout << i << std::endl;

    return 0;
}