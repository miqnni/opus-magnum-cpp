#include <iostream>
#include <iomanip>
#include <string>

class MyManip
{
private:
    int width;

public:
    MyManip(int width) : width(width) {}

    void run(std::ostream &os) const
    {
        os << std::setw(width);
    }
};

std::ostream &operator<<(std::ostream &os, MyManip const &man)
{
    man.run(os);
    return os;
};

// // Unncecssary if the function above has a const reference in the second argument.
// std::ostream &operator<<(std::ostream &os, MyManip &&man)
// {
//     return os << man;
// };

int main()
{
    double sampleValue{36.6};
    MyManip styleTemperature(12);
    MyManip styleDensity(25);

    std::cout
        << "[" << styleTemperature << sampleValue << "],\n"
        << "[" << styleDensity << sampleValue << "],\n"
        << "[" << MyManip(7) << sampleValue << "]"
        << std::endl;

    return 0;
}
