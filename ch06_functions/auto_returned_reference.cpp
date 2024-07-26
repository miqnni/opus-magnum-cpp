#include <iostream>
#include <string>

double global0{1.2}, global1{2.4}, global2{7.2};

// ************************************************

double &referenceToGlobal(int whichGlobal);
const double &referenceToGlobalConstEdition(int aaa);
void printGlobals();

// ************************************************

int main()
{
    printGlobals();

    auto &myReference = referenceToGlobal(1); // double &
    myReference++;

    auto &myConstReference = referenceToGlobalConstEdition(1); // const double &

    std::cout << "myConstReference: " << myConstReference << std::endl;

    printGlobals();

    return 0;
}

// ************************************************

double &referenceToGlobal(int whichGlobal)
{
    switch (whichGlobal)
    {
    case 0:
        return global0;
        break;
    case 1:
        return global1;
        break;
    default:
        return global2;
        break;
    }
}

// ************************************************

const double &referenceToGlobalConstEdition(int whichGlobal)
{
    switch (whichGlobal)
    {
    case 0:
        return global0;
        break;
    case 1:
        return global1;
        break;
    default:
        return global2;
        break;
    }
}

void printGlobals()
{
    std::cout << "g0: " << global0 << " | g1: " << global1 << " | g2: " << global2 << "" << std::endl;
}
