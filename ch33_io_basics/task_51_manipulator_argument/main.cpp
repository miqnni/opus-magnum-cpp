#include <iostream>
#include <iomanip>
#include <string>

class MyManip
{
private:
    int width;
    char fill;

public:
    MyManip(int width, char fill = ' ') : width(width), fill(fill) {}

    void run(std::ostream &os)
    {
        os << std::setfill(fill) << std::setw(width);
    }
};

std::ostream &operator<<(std::ostream &os, MyManip man)
{
    man.run(os);
    return os;
};

int main()
{
    std::string sampleName("Lorem ipsum");

    std::cout << "#" << sampleName << "#\n";
    std::cout << "#" << MyManip(20) << sampleName << "#\n";
    std::cout << "#" << MyManip(20, '%') << sampleName << "#\n";

    return 0;
}
