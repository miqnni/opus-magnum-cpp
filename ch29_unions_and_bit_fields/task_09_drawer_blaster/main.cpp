#include <iostream>
#include <vector>
#include <string>

// ************************************************
class Blaster
{
public:
    Blaster(double k = 1)
    {
        accumulator = new double[150];
        for (int i{0}; i < 150; i++)
            accumulator[i] = k * i;
    }

    ~Blaster();
    Blaster(const Blaster &) = delete;
    Blaster &operator=(const Blaster &other);

    void info()
    {
        for (int i{0}; i < 7; i++)
            std::cout << accumulator[i] << " ";
    }

private:
    double *accumulator{nullptr};
};

// ************************************************

Blaster::~Blaster()
{
    // std::cout << "\tBlaster DESTRUCTOR called." << std::endl;

    delete[] accumulator;
}

Blaster &Blaster::operator=(const Blaster &other)
{
    if (this == &other)
        return *this;

    delete[] accumulator;
    accumulator = new double[150];

    for (int i{0}; i < 150; i++)
        accumulator[i] = other.accumulator[i];

    return *this;
}

// ************************************************

class Drawer
{
public:
    Drawer();
    ~Drawer() noexcept;
    Drawer &operator=(const std::vector<double> &values);
    Drawer &operator=(const std::string &text);
    Drawer &operator=(const Blaster &blaster);

    void stateOfUnion();

private:
    union
    {
        std::vector<double> values;
        std::string text;
        Blaster blaster;
    };

    enum DrawerVariant
    {
        VectorMode,
        TextMode,
        BlasterMode,
    };
    DrawerVariant variant;
};

// ************************************************
Drawer::Drawer() : variant(VectorMode)
{
    new (&values) std::vector<double>;
}

Drawer::~Drawer() noexcept
{
    // std::cout << "\tDrawer DESTRUCTOR called." << std::endl;
    switch (variant)
    {
    case VectorMode:
        values.~vector<double>();
        break;

    case TextMode:
        using std::string;
        text.~string();
        break;

    case BlasterMode:
        blaster.~Blaster();
        break;

    default:
        break;
    }
}

Drawer &Drawer::operator=(const std::vector<double> &values)
{
    // std::cout << "\tDrawer ASSIGNMENT(vector) operator called." << std::endl;

    if (variant == VectorMode)
    {
        this->values = values;
        return *this;
    }

    if (variant == TextMode)
    {
        using std::string;
        text.~string();
    }
    else if (variant == BlasterMode)
    {
        blaster.~Blaster();
    }

    new (&(this->values)) std::vector<double>(values);
    variant = VectorMode;
    return *this;
}

Drawer &Drawer::operator=(const std::string &text)
{
    // std::cout << "\tDrawer ASSIGNMENT(string) operator called." << std::endl;

    if (variant == TextMode)
    {
        this->text = text;
        return *this;
    }

    if (variant == VectorMode)
        values.~vector<double>();
    else if (variant == BlasterMode)
        blaster.~Blaster();

    new (&(this->text)) std::string(text);
    variant = TextMode;
    return *this;
}

Drawer &Drawer::operator=(const Blaster &blaster)
{
    // std::cout << "\tDrawer ASSIGNMENT(Blaster) operator called." << std::endl;

    if (variant == BlasterMode)
    {
        this->blaster = blaster;
        return *this;
    }

    if (variant == TextMode)
    {
        using std::string;
        text.~string();
    }
    else if (variant == VectorMode)
        values.~vector<double>();

    new (&(this->blaster)) Blaster;
    this->blaster = blaster;
    variant = BlasterMode;
    return *this;
}

void Drawer::stateOfUnion()
{
    switch (variant)
    {
    case VectorMode:
        std::cout << "Union Vector Mode | ";
        for (const auto &el : values)
            std::cout << el << " ";
        break;

    case TextMode:
        std::cout << "Union Text Mode | " << text;
        break;

    case BlasterMode:
        std::cout << "Union Blaster Mode | ";
        blaster.info();
        break;

    default:
        break;
    }
    std::cout << std::endl;
}

// ************************************************

int main()
{
    Drawer sampleDrawer;
    sampleDrawer = "txt1";
    sampleDrawer.stateOfUnion();
    Blaster gun(20);
    sampleDrawer = gun;
    sampleDrawer.stateOfUnion();
    sampleDrawer = std::vector<double>{1.0, 2.2, 3, 3, 4.4};
    sampleDrawer.stateOfUnion();
    sampleDrawer = Blaster(3);
    sampleDrawer.stateOfUnion();
    sampleDrawer = Blaster(0.2);
    sampleDrawer.stateOfUnion();
    sampleDrawer = "txt2";
    sampleDrawer.stateOfUnion();

    return 0;
}
