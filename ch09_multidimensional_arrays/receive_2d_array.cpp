#include <iostream>

constexpr int ROWS_PER_ARRAY{3};
constexpr int CHARS_PER_ROW{20};

void printHorizontalLine(int lineLength, char lineElement = '-');
void printCharArray2D(char array[][CHARS_PER_ROW], int rowCount, int columnCount);

int main()
{
    char sampleArray[ROWS_PER_ARRAY][CHARS_PER_ROW];

    char startingChar{'!'};

    for (int i{}; i < ROWS_PER_ARRAY; i++)
    {
        for (int j{}; j < CHARS_PER_ROW; j++)
        {
            sampleArray[i][j] = startingChar++;
        }
    }

    printCharArray2D(sampleArray, ROWS_PER_ARRAY, CHARS_PER_ROW);

    return 0;
}

void printHorizontalLine(int lineLength, char lineElement)
{
    for (int i{}; i < lineLength; i++)
    {
        std::cout << lineElement;
    }
    std::cout << std::endl;
}

void printCharArray2D(char array[][CHARS_PER_ROW], int rowCount, int columnCount)
{
    int outputWidth{2 * CHARS_PER_ROW + 1};
    printHorizontalLine(outputWidth);

    for (int i{}; i < ROWS_PER_ARRAY; i++)
    {
        for (int j{}; j < CHARS_PER_ROW; j++)
        {
            std::cout << "|" << array[i][j];
        }
        std::cout << "|" << std::endl;
    }

    printHorizontalLine(outputWidth);
}
