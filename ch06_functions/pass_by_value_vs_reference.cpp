#include <iostream>

void byValue(int xFormal);
void byReference(int &xFormal);

void valueReferenceComparison(int aFormal, int &bFormalRef);

int main()
{
    // int xActual{10};

    // std::cout << "x (in main, before function call): " << xActual << std::endl;
    // byValue(xActual);
    // std::cout << "x (in main, after function call): " << xActual << std::endl;

    // std::cout << "x (in main, before function call): " << xActual << std::endl;
    // byReference(xActual);
    // std::cout << "x (in main, after function call): " << xActual << std::endl;

    int aActual{10}, bActual{20};

    std::cout << "a, b (in main, before function call): " << aActual << ", " << bActual << std::endl;
    valueReferenceComparison(aActual, bActual);
    std::cout << "a, b (in main, after function call): " << aActual << ", " << bActual << std::endl;

    return 0;
}

void byValue(int xFormal)
{
    std::cout << "\tx (inside function, before modifying): " << xFormal << std::endl;
    xFormal++;
    std::cout << "\tx (inside function, after modifying): " << xFormal << std::endl;
}

void byReference(int &xFormal)
{
    std::cout << "\tx (inside function, before modifying): " << xFormal << std::endl;
    xFormal++;
    std::cout << "\tx (inside function, after modifying): " << xFormal << std::endl;
}

void valueReferenceComparison(int aFormal, int &bFormalRef)
{
    std::cout << "a, b (inside function, before modifying): " << aFormal << ", " << bFormalRef << std::endl;
    aFormal++;
    bFormalRef++;
    std::cout << "a, b (inside function, after modifying): " << aFormal << ", " << bFormalRef << std::endl;
}
