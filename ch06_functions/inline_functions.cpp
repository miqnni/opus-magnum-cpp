#include <iostream>

namespace coordinateSystem
{
    double originPointX;
    double originPointY;

    double scaleX{1};
    double scaleY{1};
}

// ************************************************

void printPointCoordinates(double pointX, double pointY);

// ************************************************

inline double xCoordinate(double oldXCoordinate)
{
    return (oldXCoordinate - coordinateSystem::originPointX) * coordinateSystem::scaleX;
}

// ************************************************

inline double yCoordinate(double oldYCoordinate)
{
    return (oldYCoordinate - coordinateSystem::originPointY) * coordinateSystem::scaleY;
}

// ************************************************

int main()
{
    double x0 = 250,
           y0 = 250;

    printPointCoordinates(x0, y0);

    std::cout << "Changing the ogigin point of the coordinate system to ("
              << (coordinateSystem::originPointX = 10) << ", "
              << (coordinateSystem::originPointY = -300) << ")" << std::endl;

    printPointCoordinates(x0, y0);

    std::cout << "Changing the X-Scale to " << (coordinateSystem::scaleX = 0.75) << std::endl;

    printPointCoordinates(x0, y0);

    std::cout << "Changing the Y-Scale to " << (coordinateSystem::scaleY = -0.5) << std::endl;

    printPointCoordinates(x0, y0);

    return 0;
}

void printPointCoordinates(double pointX, double pointY)
{
    std::cout << "Coordinates of point P0: (" << xCoordinate(pointX) << ", " << yCoordinate(pointY) << ")" << std::endl;
}
