#include <iostream>
#include <iomanip> // std::setw()

int main()
{
    double number{91.66666666};
    constexpr int descriptionWidth{16};
    std::cout << "PRECISION 6" << std::endl;
    std::cout << std::setw(descriptionWidth) << "defaultfloat: " << std::defaultfloat << number << std::endl;
    std::cout << std::setw(descriptionWidth) << "fixed: " << std::fixed << number << std::endl;
    std::cout << std::setw(descriptionWidth) << "scientific: " << std::scientific << number << std::endl;

    return 0;
}