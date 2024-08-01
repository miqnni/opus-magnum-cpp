#include <iostream>

constexpr int SIZE0{4};
constexpr int SIZE1{5};
constexpr int SIZE2{6};

void fillWithZeros(double array[][SIZE1][SIZE2], int arraySize);

int main()
{
    double tab[SIZE0][SIZE1][SIZE2];

    fillWithZeros(tab, SIZE0);

    for (int i{}; i < SIZE0; i++)
    {
        for (int j{}; j < SIZE1; j++)
        {
            for (int k{}; k < SIZE2; k++)
            {
                std::cout << i << "," << j << "," << k << ": " << tab[i][j][k]
                          << std::endl;
            }
        }
    }

    return 0;
}

void fillWithZeros(double array[][SIZE1][SIZE2], int arraySize)
{
    for (int i{}; i < arraySize; i++)
    {
        for (int j{}; j < SIZE1; j++)
        {
            for (int k{}; k < SIZE2; k++)
            {
                array[i][j][k] = 0;
            }
        }
    }
}