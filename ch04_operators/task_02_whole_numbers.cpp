#include <iostream>

constexpr int INFO_NUM = 10;

void wholeNumbers(int start, int end)
{
    try
    {
        if (start > end)
            throw std::runtime_error("The starting number cannot be greater than the final number.");

        for (int i{start}; i <= end; i++)
        {
            std::cout << i;
            if (!(i % INFO_NUM))
                std::cout << " zakonczona dziesiatka";
            std::cout << std::endl;
        }
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }
}

int main()
{
    // wholeNumbers(2, -3);
    // wholeNumbers(-32, 11);
    wholeNumbers(1, 100);
    return 0;
}