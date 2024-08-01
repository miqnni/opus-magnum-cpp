#include <iostream>

constexpr int ARRAY_SIZE{10000};

void splitWords(char destinationEven[], char destinationOdd[], char source[]);

int main()
{
    // Word index:                      0    1  2 3    4        5  6    7  8      9    10   11   12  13     14    15  16   17 18   19   20   21
    char longCString[ARRAY_SIZE] = {"   This is a long CString. It will be copied into more than one array. Let's see what it will look like afterwards."};

    char parzyste[ARRAY_SIZE];    // Words 0, 2, ..., 20 (even indices)
    char nieparzyste[ARRAY_SIZE]; // Words 1, 3, ..., 21 (odd indices)

    splitWords(parzyste, nieparzyste, longCString);

    std::cout << "parzyste: " << parzyste << std::endl;
    std::cout << "nieparzyste: " << nieparzyste << std::endl;

    return 0;
}

void splitWords(char destinationEven[], char destinationOdd[], char source[])
{
    bool copyIntoEvenWordArray{true};
    bool newWordStarted{false};
    int sourceIndex{0}, destinationEvenIndex{0}, destinationOddIndex{0};

    while (source[sourceIndex] != 0)
    {
        // Skip whitespaces.
        while (source[sourceIndex] == ' ')
        {
            sourceIndex++;
        }

        // Copy the char into proper array.
        if (copyIntoEvenWordArray)
        {

            // If we are starting a new word, then separate it with whitespace from the previous word.
            // If the new word is the first one in the array, don't use whitespace.
            if (newWordStarted)
            {
                if (destinationEvenIndex != 0)
                    destinationEven[destinationEvenIndex++] = ' ';
                newWordStarted = false;
            }

            // The copying process itself.
            destinationEven[destinationEvenIndex++] = source[sourceIndex];
        }
        else
        {
            // The same as above.
            if (newWordStarted)
            {
                if (destinationOddIndex != 0)
                    destinationOdd[destinationOddIndex++] = ' ';
                newWordStarted = false;
            }
            destinationOdd[destinationOddIndex++] = source[sourceIndex];
        }

        // Go to the next char.
        sourceIndex++;

        // Check if the current word has ended.
        if (source[sourceIndex] == ' ')
        {
            copyIntoEvenWordArray = !copyIntoEvenWordArray;
            newWordStarted = true;
        }
    }

    // End the strings in arrays with null char.
    destinationEven[destinationEvenIndex] = 0;
    destinationOdd[destinationOddIndex] = 0;
}