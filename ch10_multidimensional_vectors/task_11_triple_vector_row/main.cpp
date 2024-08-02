#include <iostream>
#include <vector>

void tripleAllElementsInVector(std::vector<double> &originalVector);

int main()
{
    std::vector<std::vector<double>> dataVector{
        3,
        std::vector<double>(
            6,
            1.4 // Example value
            ),
    };

    std::cout << "Sample element\nBefore: " << dataVector[2][3] << std::endl;
    tripleAllElementsInVector(dataVector[2]);
    std::cout << "After: " << dataVector[2][3] << std::endl;

    return 0;
}

void tripleAllElementsInVector(std::vector<double> &originalVector)
{
    for (auto &vectorElement : originalVector)
    {
        vectorElement *= 3;
    }
}
