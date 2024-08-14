#include <iostream>
#include <string>

class WashingMachine
{
    std::string name; // The default access modifier is `private`.

public:
    void wash();
    void makeSound();

    WashingMachine()
        : name("Unnamed") {}

    WashingMachine(std::string name)
        : name(name) {}

    WashingMachine(std::string name, int programNumber, double washingTemperature)
        : name(name), programNumber(programNumber), washingTemperature(washingTemperature) {}

    ~WashingMachine();

    void setName(std::string name) { this->name = name; }
    void setWashingTemperature(double washingTemperature) { this->washingTemperature = washingTemperature; }
    void setProgramNumber(int programNumber) { this->programNumber = programNumber; }

private:
    int programNumber{};
    double washingTemperature{30};
};

void WashingMachine::wash()
{
    std::cout << name << " is using program #" << programNumber << " at the temperature of " << washingTemperature << "C." << std::endl;
    makeSound();
}

void WashingMachine::makeSound()
{
    std::cout << "\tWrrrrrrrr!" << std::endl;
}

WashingMachine::~WashingMachine()
{
    std::cout << "Washing Machine \"" << name << "\" destroyed." << std::endl;
}

int main()
{
    WashingMachine myDevice;
    myDevice.setName("PRO");

    WashingMachine *pMyDevice{&myDevice};
    pMyDevice->setProgramNumber(12);

    WashingMachine &refMyDevice{myDevice};
    refMyDevice.setWashingTemperature(40);

    std::cout << "Artificially calling the destructor: ";
    myDevice.~WashingMachine();
    std::cout << "---------------------" << std::endl;

    myDevice.wash();

    {
        WashingMachine localMachine("Local");
        localMachine.wash();
    }
    std::cout << "Local block has ended." << std::endl;

    return 0;
}
