#include <iostream>

enum class CarMake
{
    FIAT,
    MERCEDES,
    VOLKSWAGEN,
    BMW,
    TOYOTA,
    HYUNDAI,
    KIA,
    MITSUBISHI,
    SUZUKI,
    HONDA,
    OPEL,
    RENAULT,
    CITROEN,
    SKODA,
};

class Vehicle
{
protected:
    unsigned short number_of_wheels;
    unsigned long distance;

public:
    Vehicle(unsigned short number_of_wheels) : number_of_wheels(number_of_wheels), distance(0) {}

    void ride()
    {
        std::cout << "Wroom! ";
        for (unsigned short wheel{}; wheel < number_of_wheels; wheel++)
        {
            std::cout << " O ";
        }
        distance++;
        std::cout << "--> TOTAL DISTANCE [km]: " << distance << std::endl;
    }
};

class Car : public Vehicle
{
private:
    CarMake make;

public:
    Car(unsigned short number_of_wheels, CarMake make) : Vehicle(number_of_wheels), make(make) {};
    Car(CarMake make) : Vehicle(4), make(make) {};

    void ride()
    {
        std::cout << "Driving a car... ";
        for (unsigned short wheel{}; wheel < number_of_wheels; wheel++)
        {
            std::cout << "-O-";
            distance++;
        }
        std::cout << " (total: " << distance << " km)" << std::endl;
    }
};

int main()
{
    /*
    **********************
    STATIC CAST, pt. 1
    **********************
    */
    std::cout << "STATIC CAST, pt. 1" << std::endl;

    // Static cast -- narrowing conversion
    double double0 = 1.49;
    int int0;
    int0 = static_cast<int>(double0);
    std::cout << "int0: " << int0 << std::endl;
    std::cout << "static_cast<int>(3.1): " << static_cast<int>(3.1) << std::endl;

    // ***
    // How to use static_cast for pointers to class objects.
    Car my_car = Car(CarMake::MERCEDES);
    Vehicle *pVehicle;
    Car *pCar = &my_car;
    Car *pCar2;

    // Using the defined pointers to class objects.
    pVehicle = pCar;
    // pCar2 = pVehicle; // The other way around of such assignment is not allowed -- compilation error.
    pCar2 = static_cast<Car *>(pVehicle);
    (*pCar2).ride();
    (*pCar2).ride();
    std::cout << "--------------------------" << std::endl
              << std::endl; // ***

    /*
    **********************
    DYNAMIC CAST
    **********************
    */
    // // DYNAMIC CAST
    // Car *pCar3;
    // // error: cannot dynamic_cast 'pVehicle' (of type 'class Vehicle*') to type 'class Car*' (source type is not polymorphic)
    // pCar3 = dynamic_cast<Car *>(pVehicle);
    // (*pCar3).ride();

    /*
    **********************
    STATIC CAST, pt. 2
    **********************
    */
    std::cout << "STATIC CAST, pt. 2" << std::endl;

    // ***
    volatile int vint1{10};
    const int cint1{10};

    double double1a{static_cast<double>(vint1)};
    double double1b{static_cast<double>(cint1)};

    double1a += 0.3;
    std::cout << "double1a: " << double1a << std::endl;

    double1b += 0.3; // non-const
    std::cout << "double1b: " << double1b << std::endl;
    // ***

    // ***
    volatile double vdouble2{20.1};
    const double cdouble2{20.1};

    double double2a{static_cast<double>(vdouble2)};
    double double2b{static_cast<double>(cdouble2)};

    double2a += 0.3;
    std::cout << "double2a: " << double2a << std::endl;

    double2b += 0.3; // non-const
    std::cout << "double2b: " << double2b << std::endl;
    std::cout << "--------------------------" << std::endl
              << std::endl;
    // ***

    /*
    **********************
    CONST CAST, pt. 1
    **********************
    */
    std::cout << "CONST CAST, pt. 1" << std::endl;

    const double cdouble3{50.7};
    double double3{cdouble3}; // No casting required.
    std::cout << "double3: " << double3 << std::endl;

    const double *pCdouble3{&cdouble3};
    std::cout << "&cdouble3: " << &cdouble3 << std::endl;
    std::cout << "pCdouble3: " << pCdouble3 << std::endl;

    double *nonConstPCdouble3;

    // error: invalid conversion from 'const double*' to 'double*'
    // nonConstPCdouble3 = pCdouble3;

    // error: increment of read-only location '* pCdouble3'
    // (*pCdouble3)++;

    nonConstPCdouble3 = const_cast<double *>(pCdouble3);
    (*nonConstPCdouble3)++;
    std::cout << "(after const_cast and incrementation)" << std::endl;
    std::cout << "&cdouble3: " << &cdouble3 << std::endl;
    std::cout << "pCdouble3: " << pCdouble3 << std::endl;
    std::cout << "nonConstPCdouble3: " << nonConstPCdouble3 << std::endl;
    std::cout << "cdouble3: " << cdouble3 << std::endl;
    std::cout << "*pCdouble3: " << *pCdouble3 << std::endl;
    std::cout << "*nonConstPCdouble3: " << *nonConstPCdouble3 << std::endl;

    std::cout << "--------------------------" << std::endl
              << std::endl;
    /*
    **********************
    CONST CAST, pt. 2 -- the same, but with `volatile` specifier
    **********************
    */
    std::cout << "CONST CAST, pt. 2" << std::endl;

    volatile double vdouble4{40.2};
    std::cout << "vdouble4: " << vdouble4 << std::endl;
    double double4{vdouble4}; // No casting required.
    std::cout << "double4: " << double4 << std::endl;

    volatile double *pVdouble4{&vdouble4};
    double *nonVolatilePVdouble4;

    // error: invalid conversion from 'volatile double*' to 'double*'
    // nonVolatilePVdouble4 = pVdouble4;

    (*pVdouble4)++; // OK
    std::cout << "vdouble4: " << vdouble4 << std::endl;

    nonVolatilePVdouble4 = const_cast<double *>(pVdouble4);
    (*nonVolatilePVdouble4)++;
    std::cout << "*nonVolatilePVdouble4: " << *nonVolatilePVdouble4 << std::endl;
    std::cout << "vdouble4: " << vdouble4 << std::endl;

    std::cout << "--------------------------" << std::endl
              << std::endl;

    /*
    **********************
    REINTERPRET CAST
    **********************
    */
    std::cout << "REINTERPRET CAST" << std::endl;

    // Car car5 = Car(CarMake::TOYOTA);
    Car *
        pCar5;
    int int5 = 30;
    int *pInt5{&int5};
    std::cout << "pInt5: " << pInt5 << std::endl;

    // error: invalid conversion from 'int' to 'Car*'
    // pCar5 = int5;

    pCar5 = reinterpret_cast<Car *>(pInt5);
    std::cout << "pCar5: " << pCar5 << std::endl;

    std::cout << "--------------------------" << std::endl
              << std::endl;

    return 0;
}
