#include <iostream>

// ************************************************

class Tire
{
private:
    static int count;

public:
    Tire()
    {
        std::cout << "TIRE created. Total: " << ++count << std::endl;
    }
};

int Tire::count;

// ************************************************

class Door
{
private:
    static int count;

public:
    Door()
    {
        std::cout << "DOOR created. Total: " << ++count << std::endl;
    }
};

int Door::count;

// ************************************************
class Car
{
private:
    Tire tireA;
    Tire tireB;
    Tire tireC;
    Tire tireD;
    Tire tireE;

    Door doorA;
    Door doorB;

public:
    Car()
    {
        std::cout << "CAR created." << std::endl;
    }
};

// ************************************************

int main()
{
    Car myCar;

    return 0;
}