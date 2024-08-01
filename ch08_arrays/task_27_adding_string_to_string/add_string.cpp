#include "add_string.h"

void addString(char destination[], int destinationSize, char source[])
{
    int destinationIndex{0};
    int sourceIndex{0};

    while (destinationIndex < destinationSize && destination[destinationIndex] != 0)
    {
        destinationIndex++;
    }

    while (destinationIndex < destinationSize)
    {
        if ((destination[destinationIndex++] = source[sourceIndex]) == 0)
            break;

        sourceIndex++;
    }

    if (destinationIndex == destinationSize)
        destination[destinationSize - 1] = 0;
}