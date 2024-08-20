#include <iostream>

// ************************************************

class Base
{
protected:
    int alpha;
    int beta;

public:
    // Base() : Base(0, 0) {}

    Base(int alpha, int beta) : alpha{alpha}, beta{beta} {}

    // Task 31
    Base(const Base &other) : alpha{other.alpha}, beta{other.beta} {};

    Base &operator=(const Base &other);
};

// ************************************************

Base &Base::operator=(const Base &other)
{
    if (this == &other)
        return *this;

    alpha = other.alpha;
    beta = other.beta;

    return *this;
}

// ************************************************

class Inherited : public Base
{
private:
    double x;
    double y;

public:
    Inherited(int alpha = 0, int beta = 0, double x = 0, double y = 0)
        : Base{alpha, beta}, x{x}, y{y} {}

    // Task 31
    Inherited(const Inherited &other) : Base{other}, x{other.x}, y{other.y} {}

    Inherited &operator=(const Inherited &other);

    friend std::ostream &operator<<(std::ostream &out, const Inherited &inherited);
};

// ************************************************

Inherited &Inherited::operator=(const Inherited &other)
{
    if (this == &other)
        return *this;

    Base::operator=(other);
    x = other.x;
    y = other.y;

    return *this;
}

std::ostream &operator<<(std::ostream &out, const Inherited &inherited)
{
    out << inherited.alpha << " " << inherited.beta << " " << inherited.x << " " << inherited.y;
    return out;
}

// ************************************************

int main()
{
    Inherited gold{100, 500, 3.14, 77.7};
    Inherited second;
    second = gold;
    std::cout << second << std::endl;

    // Task 31
    const Inherited third{gold};
    std::cout << third << std::endl;

    // Task 32
    Inherited fourth{third};
    Inherited fifth;
    fifth = third;
    std::cout << fourth << std::endl;
    std::cout << fifth << std::endl;

    return 0;
}