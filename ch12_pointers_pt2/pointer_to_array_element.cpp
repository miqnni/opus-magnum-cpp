#include <iostream>

void printElements(int array[], int arraySize);
void printElements(double array[], int arraySize);

// ************************************************

int main()
{
    constexpr int INT_ARRAY_SIZE{8};
    constexpr int DOUBLE_ARRAY_SIZE{6};

    int sampleIntArray[INT_ARRAY_SIZE]{0, 1, 2, 3, 4, 5, 6, 7};
    double sampleDoubleArray[DOUBLE_ARRAY_SIZE]{1.2, 2.4, 3.6, 5.4, 6.0, 9.6};

    std::cout << "(BEFORE)" << std::endl;
    std::cout << "sampleIntArray" << std::endl;
    printElements(sampleIntArray, INT_ARRAY_SIZE);
    std::cout << "sampleDoubleArray" << std::endl;
    printElements(sampleDoubleArray, DOUBLE_ARRAY_SIZE);

    int *intElementPointer = sampleIntArray;              // OR: int *intElementPointer = &sampleIntArray[0];
    double *doubleElementPointer = &sampleDoubleArray[0]; // OR: double *doubleElementPointer = sampleDoubleArray;

    intElementPointer += 6;    // Moving the pointer by six array elements of type `int` (6 * 4 bytes).
    *intElementPointer *= 100; // Changing the value of array element.

    doubleElementPointer += 3;    // Moving the pointer by three array elements of type `double` (3 * 8 bytes).
    *doubleElementPointer *= 100; // Changing the value of array element.

    intElementPointer = &sampleIntArray[2]; // Setting the pointer to the array element with index 2. The same as: `intElementPointer = sampleIntArray + 2;`.
    *intElementPointer += 25;

    std::cout << std::endl
              << "(AFTER)" << std::endl;
    std::cout << "sampleIntArray" << std::endl;
    printElements(sampleIntArray, INT_ARRAY_SIZE);
    std::cout << "sampleDoubleArray" << std::endl;
    printElements(sampleDoubleArray, DOUBLE_ARRAY_SIZE);

    return 0;
}

// ************************************************

void printElements(int array[], int arraySize)
{
    std::cout << "{\n\t";
    for (int i{}; i < arraySize; i++)
    {
        if (i > 0)
            std::cout << "\n\t";
        std::cout << array[i] // OR *(array + i)
                  << "\t (address: " << reinterpret_cast<unsigned long>(array + i) << ")" << ",";
    }
    std::cout << "\n}" << std::endl;
}

// ************************************************

void printElements(double array[], int arraySize)
{
    std::cout << "{\n\t";
    for (int i{}; i < arraySize; i++)
    {
        if (i > 0)
            std::cout << "\n\t";
        std::cout << array[i] << "\t (address: " << reinterpret_cast<unsigned long>(array + i) << ")" << ",";
    }
    std::cout << "\n}" << std::endl;
}
