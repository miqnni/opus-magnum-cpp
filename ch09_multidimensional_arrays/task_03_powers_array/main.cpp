#include <iostream>

constexpr int ROWS{10};
constexpr int COLUMNS{3};

inline int power(int base, int exp)
{
    return (exp > 0 ? base * power(base, exp - 1) : 1);
}

// ************************************************

void loadArray(int array[][COLUMNS], int rows);
void printArray(int array[][COLUMNS], int rows);

// ************************************************

int main()
{
    int tab[ROWS][COLUMNS];
    loadArray(tab, ROWS);
    printArray(tab, ROWS);

    return 0;
}

// ************************************************

void loadArray(int array[][COLUMNS], int rows)
{
    for (int i{}; i < rows; i++)
    {
        for (int j{}; j < COLUMNS; j++)
        {
            array[i][j] = power(i, j + 1);
        }
    }
}

// ************************************************

void printArray(int array[][COLUMNS], int rows)
{
    for (int i{}; i < rows; i++)
    {
        for (int j{}; j < COLUMNS; j++)
        {
            std::cout << array[i][j] << "\t";
        }
        std::cout << std::endl;
    }
}
