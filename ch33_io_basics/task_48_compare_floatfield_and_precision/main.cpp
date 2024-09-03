#include <iostream>
#include <iomanip> // std::setw()

int main()
{
    double numA{123.623456789};
    double numB{0.0000567890123456789};
    double numC{12345.678901234}; // For precision < 5 it is printed as scientific, else it is printed as fixed.

    constexpr int numberWidth{25};

    for (const auto &currentFlag : {std::ios::fixed, std::ios::scientific, std::ios::fmtflags(0)})
    {
        std::cout.setf(currentFlag, std::ios::floatfield);

        if (std::cout.std::ios::flags() & std::ios::fixed)
            std::cout << "FIXED" << std::endl;
        else if (std::cout.std::ios::flags() & std::ios::scientific)
            std::cout << "SCIENTIFIC" << std::endl;
        else
            std::cout << "DEFAULTFLOAT" << std::endl;

        for (int currentPrecision{3}; currentPrecision < 8; currentPrecision++)
        {
            std::cout << std::setprecision(currentPrecision);
            std::cout << "[Precision " << currentPrecision << "]";
            for (const double &num : {numA, numB, numC})
                std::cout << std::setw(numberWidth) << num;
            std::cout << "\n";
        }
        std::cout << "\n";
    }

    return 0;
}
