#include <iostream>
#include <cassert>

template <typename T>
class SomeData
{
private:
    int points{100};
    T special{11};

public:
    int getPoints() { return points; }
    int getSpecial() { return special; }
};

int main()
{
    SomeData<double> sd;

    assert(("points initialized", sd.getPoints() == 100));
    assert(("special initialized", abs(sd.getSpecial() - 11) < 0.0001));

    std::cout << "OK" << std::endl;

    return 0;
}
