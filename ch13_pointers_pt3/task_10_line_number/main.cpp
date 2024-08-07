#include <iostream>
#include <cstring> // strcpy(), strcat()

void allocateLineArray()
{
    char **lineArray = new char *[10]; // More precise name: `arrayOfPointersToCharArrays`.

    for (int i{}; i < 10; i++)
    {
        lineArray[i] = new char[80];
        strcpy(lineArray[i], "This is a line number ");

        char lineNumberCString[2] = {" "}; // {' ', '\0'}

        lineNumberCString[0] = '0' + static_cast<char>(i);

        strcat(lineArray[i], lineNumberCString);
    }

    std::cout << "Before Swapping 3 <--> 6" << std::endl;
    for (int i{}; i < 10; i++)
        std::cout << "CString #" << i << ":" << lineArray[i] << std::endl;

    // Swap 3 <--> 6
    char *tmp = lineArray[3];
    lineArray[3] = lineArray[6];
    lineArray[6] = tmp;

    std::cout << "After Swapping 3 <--> 6" << std::endl;
    for (int i{}; i < 10; i++)
        std::cout << "CString #" << i << ":" << lineArray[i] << std::endl;

    // Cleaning up.
    for (int i{}; i < 10; i++)
        delete[] lineArray[i];

    delete[] lineArray;
}

int main()
{
    allocateLineArray();

    return 0;
}