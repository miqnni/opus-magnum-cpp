#include <iostream>
#include <cstdlib>
#include <ctime>

constexpr int ARRAY_SIZE{9100};

// `randomLowerBound` inclusive, `randomUpperBound` non-inclusive
void assignRandomValues(long array[], int arraySize, long randomLowerBound, long randomUpperBound);

void multiplyAllElements(long array[], int arraySize, int multiplyBy);

// `startIndex` inclusive, `limitIndex` non-inclusive
void printArrayElements(long array[], int startIndex, int limitIndex);

int main()
{
    srand(time(NULL));

    long numberSample[ARRAY_SIZE];

    assignRandomValues(numberSample, ARRAY_SIZE, 5, 12);
    multiplyAllElements(numberSample, ARRAY_SIZE, 2);
    printArrayElements(numberSample, 200, 214);
    return 0;
}

void assignRandomValues(long array[], int arraySize, long randomLowerBound, long randomUpperBound)
{
    for (int i{}; i < arraySize; i++)
    {
        array[i] = randomLowerBound + (rand() % (randomUpperBound - randomLowerBound));
    }
}

void multiplyAllElements(long array[], int arraySize, int multiplyBy)
{
    for (int i{}; i < arraySize; i++)
    {
        array[i] *= multiplyBy;
    }
}

void printArrayElements(long array[], int startIndex, int limitIndex)
{
    for (int i{startIndex}; i < limitIndex; i++)
    {
        std::cout << "[" << i << "]: " << array[i] << std::endl;
    }
}
