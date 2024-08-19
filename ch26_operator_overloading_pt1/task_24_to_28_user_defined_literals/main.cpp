#include <iostream>

// ************************************************

enum class TemperatureScale
{
    CELSIUS,
    FAHRENHEIT,
};

// ************************************************

class Temperature
{
private:
    double degreesCelsius;
    double degreesFahrenheitAbsoluteValue;
    TemperatureScale defaultScale;

public:
    constexpr Temperature() : degreesCelsius{}, degreesFahrenheitAbsoluteValue{}, defaultScale{TemperatureScale::CELSIUS} {}
    constexpr Temperature(double degrees, TemperatureScale scale = TemperatureScale::CELSIUS)
        : degreesCelsius{
              scale == TemperatureScale::CELSIUS ? degrees : fahrenheitToCelsius(degrees)},
          degreesFahrenheitAbsoluteValue{scale == TemperatureScale::FAHRENHEIT ? degrees : celsiusToFahrenheit(degrees)}, defaultScale{scale}
    {
    }

    double getDegreesCelsius() { return degreesCelsius; }
    double getDegreesFahrenheit() { return degreesFahrenheitAbsoluteValue; }

    friend std::ostream &operator<<(std::ostream &out, Temperature temperature);

    constexpr operator double() { return degreesCelsius; }

    constexpr Temperature operator-()
    {
        return Temperature((-1) * (defaultScale == TemperatureScale::CELSIUS ? degreesCelsius : degreesFahrenheitAbsoluteValue), defaultScale);
    }

private:
    constexpr double celsiusToFahrenheit(double degrees)
    {
        return (9. / 5) * degrees + 32;
    }
    constexpr double fahrenheitToCelsius(double degrees)
    {
        return (degrees - 32) * 5 / 9.;
    }
};

// ************************************************

constexpr Temperature operator"" _degC(long double degrees)
{
    return Temperature(degrees, TemperatureScale::CELSIUS);
}

constexpr Temperature operator"" _degF(long double degrees)
{
    return Temperature(degrees, TemperatureScale::FAHRENHEIT);
}

std::ostream &operator<<(std::ostream &out, Temperature temperature)
{
    out << temperature.degreesCelsius << " [deg C]";
    return out;
}

// ************************************************

int main()
{
    // Task 24
    constexpr Temperature temperatureA{36.6_degC};
    std::cout << "temperatureA: " << temperatureA << std::endl; // 36.6

    // Task 25
    constexpr Temperature temperatureB{100.0_degF};
    std::cout << "temperatureB: " << temperatureB << std::endl; // 37.7778

    // Task 26
    constexpr double convertedTemperature{80.0_degF};
    std::cout << "convertedTemperature: " << convertedTemperature << std::endl; // 26.6667

    // Task 27
    constexpr Temperature temperatureC0{-1.0_degF};
    constexpr Temperature temperatureC1{0.0_degF};
    constexpr Temperature temperatureC2{1.0_degF};
    constexpr Temperature temperatureC3{-40.0_degF};
    std::cout << "temperatureC0: " << temperatureC0 << std::endl; // -18.3
    std::cout << "temperatureC1: " << temperatureC1 << std::endl; // -17.8
    std::cout << "temperatureC2: " << temperatureC2 << std::endl; // -17.2
    std::cout << "temperatureC3: " << temperatureC3 << std::endl; // -40

    // Task 28
    constexpr Temperature temperatureD0{40.0_degF};
    constexpr Temperature temperatureD1{-40.0_degF};
    constexpr Temperature temperatureD2{-(-40.0_degF)};
    constexpr Temperature temperatureD3{-(-(-40.0_degF))};
    constexpr Temperature temperatureD4{-(-(-(-40.0_degF)))};
    std::cout << "temperatureD0: " << temperatureD0 << std::endl; // 4.44
    std::cout << "temperatureD1: " << temperatureD1 << std::endl; // -40
    std::cout << "temperatureD2: " << temperatureD2 << std::endl; // 4.44
    std::cout << "temperatureD3: " << temperatureD3 << std::endl; // -40
    std::cout << "temperatureD4: " << temperatureD4 << std::endl; // 4.44

    return 0;
}
