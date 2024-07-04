// Modified version of `simple_switch.cpp`
// for testing the behavior of the `switch` statement
// (especially what happens when we put the `default` label
// between different cases and not at the end).

#include <iostream>

int main()
{
    int user_points;
    std::cout << "Number of points (0/.../4): ";
    std::cin >> user_points;

    switch (user_points)
    {
    case 4:
        std::cout << "You have four points." << std::endl;
        break;
    case 3:
        std::cout << "You have three points." << std::endl;
        break;
    case 2:
        std::cout << "You have two points." << std::endl;
        break;

    // Default is not at the end now.
    default:
        std::cout << "You have a non-standard number of points (" << user_points << ")." << std::endl;
        break;

    case 1:
        std::cout << "You have one point." << std::endl;
        break;
    case 0:
        std::cout << "You have zero points." << std::endl;
        break;
    }

    return 0;
}
