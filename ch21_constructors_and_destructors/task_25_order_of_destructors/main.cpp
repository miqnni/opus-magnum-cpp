// MODIFIED PROGRAM FROM TASK 24.
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

    ~Tire()
    {
        std::cout << "TIRE destroyed. Total: " << --count << std::endl;
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

    ~Door()
    {
        std::cout << "DOOR destroyed. Total: " << --count << std::endl;
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
    ~Car()
    {
        std::cout << "CAR destroyed." << std::endl;
    }
};

// ************************************************

int main()
{
    {
        Car myCar;
    }

    return 0;
}