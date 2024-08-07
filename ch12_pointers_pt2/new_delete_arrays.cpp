#include <iostream>
#include <cstdlib>
#include <ctime>

// constexpr int NEW_ARRAY_SIZE{32};
// static_assert(NEW_ARRAY_SIZE > 0, "The size of an array initialized with `new` operator must be greater than 0.");

constexpr int RAND_LOWER{1000};
constexpr int RAND_UPPER_INCLUSIVE{10000};

int main()
{
    try
    {
        srand(time(NULL));

        int *arrayPtr;

        int arraySize; // Non-const.
        std::cout << "Array size: ";
        std::cin >> arraySize;

        if (arraySize <= 0)
            throw std::runtime_error("The size of an array initialized with `new` operator must be greater than 0.");

        arrayPtr = new int[arraySize]; // `new[]` is a distinct operator from `new`, used for arrays (just like `delete[]` is distinct from `delete`)

        *arrayPtr = 50; // OR: arrayPtr[0] = 50;

        // Assign values to array elements.
        for (int i{}; i < arraySize; i++)
        {
            arrayPtr[i] = rand() % (RAND_UPPER_INCLUSIVE - RAND_LOWER + 1) + RAND_LOWER;
        }

        const int *markedArrayIndexPtr{new const int{arraySize - 1}};
        arrayPtr[*markedArrayIndexPtr] = 32;
        delete markedArrayIndexPtr;
        markedArrayIndexPtr = nullptr;

        // Print array elements.
        for (int i{}; i < arraySize; i++)
        {
            std::cout << "arrayPtr[" << i << "]: " << arrayPtr[i] << std::endl;
        }

        delete[] arrayPtr; // Operator `delete[]` does not return any value (the result type is `void`).
        arrayPtr = nullptr;
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }

    return 0;
}