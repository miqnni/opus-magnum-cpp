#include <iostream>

class M
{
private:
    int y;

public:
    M() : y{} {}
    M(int y) : y{y} {};

    int getY() { return y; }
    void setY(int y)
    {
        std::cout << "Member M::y changed from " << this->y << " to ";
        std::cout << (this->y = y);
        std::cout << "." << std::endl;
    }
};

class K
{
private:
    int x;

public:
    K() : x{} {}
    K(int x) : x{x} {};

    int getX() { return x; }

    // Conversion M -> K
    K(M m) : x{m.getY()}
    {
        std::cout << "CONSTRUCTOR: converting M -> K" << std::endl;
    };

    // Conversion K -> M
    operator M()
    {
        std::cout << "OPERATOR: converting K -> M" << std::endl;
        return M(x);
    }
};
int main()
{
    K sampleK(3);

    M sampleM = sampleK;

    std::cout << "sampleM.getY(): " << sampleM.getY() << std::endl;

    sampleM.setY(4);
    K anotherSampleK;
    anotherSampleK = sampleM;

    std::cout << "anotherSampleK.getX(): " << anotherSampleK.getX() << std::endl;

    return 0;
}