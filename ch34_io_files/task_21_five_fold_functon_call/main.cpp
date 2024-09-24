#include <iostream>

void takeNumbersIndivisibleBy7(std::istream &in);
void takeEvenNumbers(std::istream &in);

int main()
{
    std::cout << "Enter five numbers indivisible by 7:" << std::endl;
    for (int i{}; i < 5; i++)
    {
        if (std::cin.fail())
            break;
        takeNumbersIndivisibleBy7(std::cin);
    }

    if (std::cin.fail())
    {
        // Remove the failbit flag.
        std::cin.clear(std::cin.rdstate() & ~std::ios::failbit);

        std::cout << "Enter five even numbers:" << std::endl;
        for (int i{}; i < 5; i++)
        {
            if (std::cin.fail())
                break;
            takeEvenNumbers(std::cin);
        }
    }

    if (std::cin.fail())
        std::cout << "Numbers entered incorrectly." << std::endl;
    else
        std::cout << "Numbers entered correctly." << std::endl;

    return 0;
}

void takeNumbersIndivisibleBy7(std::istream &in)
{
    int num{};
    in >> num;
    if (num % 7 == 0)
    {
        in.setstate(std::ios::failbit);
    }
}

void takeEvenNumbers(std::istream &in)
{
    int num{};
    in >> num;
    if (num % 2 != 0)
    {
        in.setstate(std::ios::failbit);
    }
}
