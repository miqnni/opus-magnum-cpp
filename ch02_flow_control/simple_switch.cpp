#include <iostream>

int main()
{
    int user_points;
    std::cout << "Type in your number of points (0/1/2/3/4): ";
    std::cin >> user_points;

    // Interpreting the number of points.
    switch (user_points)
    {
    // Satisfactory results
    case 4:
    case 3:
        std::cout << "Well done!" << std::endl;
        break;
    case 2:
        std::cout << "You did okay!" << std::endl;
        break;

    // Unsatisfactory results
    case 1:
        std::cout << "Well, at least you've got one point." << std::endl;
    case 0:
        // Will be printed for `case 1` as well (due to the lack of `break;` statement there).
        std::cout << "Unfortunately, this is not a satisfactory result." << std::endl;
        break;

    // Invalid input
    default:
        std::cout << "This is not a valid number of points." << std::endl;
        break;
    }

    return 0;
}
