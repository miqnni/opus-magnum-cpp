#include <iostream>

// ************************************************

class Door
{
    const int weight;

public:
    Door() = delete;

    Door(int weight) : weight{weight} {}
};

// ************************************************

class Tire
{
private:
    int id;

public:
    Tire() : Tire(-1) {}

    Tire(int id) : id{id} {}
};

// ************************************************
class Car
{
private:
    Door leftDoor;
    Door rightDoor;
    Tire tires[4];

public:
    Car() : Car(0, 0)
    {
        std::cout << "Empty car created." << std::endl;
    }

    Car(int leftDoorWeight, int rightDoorWeight)
        : leftDoor{Door{leftDoorWeight}}, rightDoor{Door{rightDoorWeight}}, tires{10, 11, 12, 13}
    {
        std::cout << "Car created. Door weight: " << leftDoorWeight << ", " << rightDoorWeight << std::endl;
    }
};

// ************************************************

int main()
{
    Car myCar;

    return 0;
}
