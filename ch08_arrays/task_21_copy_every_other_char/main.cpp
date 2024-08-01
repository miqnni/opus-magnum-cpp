#include <iostream>

constexpr int ARRAY_SIZE{25};

void strcpySkipEveryOtherChar(char destination[], char source[]);

int main()
{
    char tabA[ARRAY_SIZE] = {"Some C-string example"};
    char tabB[ARRAY_SIZE];

    char tabC[ARRAY_SIZE] = {"instytut"};
    char tabD[ARRAY_SIZE];

    strcpySkipEveryOtherChar(tabB, tabA);
    strcpySkipEveryOtherChar(tabD, tabC);

    std::cout << "tabB: " << tabB << std::endl;
    std::cout << "tabD: " << tabD << std::endl;

    return 0;
}

void strcpySkipEveryOtherChar(char destination[], char source[])
{
    int sourceIndex{};
    int destinationIndex{};
    while (source[sourceIndex] != 0)
    {
        if (sourceIndex % 2 == 0)
        {
            destination[destinationIndex] = source[sourceIndex];
            destinationIndex++;
        }
        sourceIndex++;
    }
    destination[destinationIndex] = 0;
}
