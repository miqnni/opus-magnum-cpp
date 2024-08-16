#include <iostream>

void resident();

class Sample
{
    using SampleSize = unsigned int;
    enum Direction : SampleSize
    {
        NORTH = 0,
        EAST = 90,
        SOUTH = 180,
        WEST = 270,
    };

    friend void resident()
    {
        std::cout << "Current directions:" << std::endl;
        for (const auto &dir : {NORTH, EAST, SOUTH, WEST})
        {
            std::cout << "\t" << static_cast<SampleSize>(dir) << std::endl;
        }
    }
};

int main()
{
    resident();

    return 0;
}
