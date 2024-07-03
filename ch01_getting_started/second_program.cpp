#include <iostream>
#include <cstdlib>

// 1 ft == 0.3048 m
constexpr double FEET_TO_METERS_FACTOR = 0.3048;

// Reminding myself of unions that I've used in C.
//
// In C++ (unlike in C) there is no need to use `typedef`
// with structs or unions,
// unless there is another declaration with the same name.
union height
{
    double feet;
    double meters;
};

int main()
{
    height curr_height;

    std::cout << "Height in feet: ";
    std::cin >> curr_height.feet;
    curr_height.meters = curr_height.feet * FEET_TO_METERS_FACTOR;
    std::cout << "Height in meters: " << curr_height.meters << std::endl;

    system("pause");
    return 0;
}
