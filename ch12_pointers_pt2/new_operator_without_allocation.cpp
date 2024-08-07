#include <iostream>
#include <vector>
#include <new> // new(...)

#define MAX(a, b) (a > b ? a : b)

constexpr int FENCE_SIZE{1000};
constexpr int MAX_PICKET_HEIGHT{20};

void printFence(int *fence, int startIndex = 0, int endIndex = FENCE_SIZE - 1);

// ************************************************

int main()
{
    try
    {
        // We use operator new() with `where` parameter when we want
        // to create/place an object in specific already-allocated memory cells
        // (e.g. creating an array element in a memory cell that has been allocated
        // along with other cells for elements of that array using `new[]` operator).

        // First, let's allocate some memory.
        int *fencePicketHeight = new int[FENCE_SIZE];

        // Initial values.
        for (int picketIndex{}; picketIndex < FENCE_SIZE; picketIndex++)
            fencePicketHeight[picketIndex] = 5;

        std::cout << "fencePicketHeight[49]: " << fencePicketHeight[49] << std::endl;

        // Now, we are going to place an array element in a specific
        // memory locatiion using `new()`.
        void *whereToCreateTheObject{&fencePicketHeight[750]};
        int *pImportantElement0{new (whereToCreateTheObject) int};

        *pImportantElement0 = 14;

        std::cout << "fencePicketHeight[750]: " << fencePicketHeight[750] << std::endl;

        // Another object.
        whereToCreateTheObject = &fencePicketHeight[751];
        int *pImportantElement1{new (whereToCreateTheObject) int};
        *pImportantElement1 = 3;

        // Another object.
        whereToCreateTheObject = &fencePicketHeight[754];
        int *pImportantElement2{new (whereToCreateTheObject) int};
        *pImportantElement2 = 7;

        // ===== DYNAMIC MEMORY ALLOCATION =====
        // Now the user decides about the address (this is what dynamic allocation is for) and height.
        std::cout << "Select an address between " << reinterpret_cast<unsigned long>(&fencePicketHeight[755]) << " and " << reinterpret_cast<unsigned long>(&fencePicketHeight[760]) << " (both inclusive)." << std::endl;
        std::cout << "Address: ";
        unsigned long userAddress;
        std::cin >> userAddress;

        whereToCreateTheObject = reinterpret_cast<void *>(userAddress);
        if (whereToCreateTheObject < &fencePicketHeight[755] || whereToCreateTheObject > &fencePicketHeight[760])
            throw std::runtime_error("Incorrect address.");

        int *pUserElement{new (whereToCreateTheObject) int}; // DYNAMIC MEMORY ALLOCATION

        std::cout << "Picket height (" << "0 -- " << MAX_PICKET_HEIGHT << "): ";
        int userHeight;
        std::cin >> userHeight;

        if (userHeight < 0 || userHeight > MAX_PICKET_HEIGHT)
            throw std::runtime_error("Incorrect picket height.");

        *pUserElement = userHeight;
        // =====================================

        // Print the fence that you have built.
        printFence(fencePicketHeight, 748, 760);

        // Cleaning up.
        // Do not use `delete` for objects placed with `new()` operator,
        // because no additional memory is allocated for them.
        // Here, we place the objects only in memory cells already allocated
        // using `new[]` (`int *fencePicketHeight = new int[FENCE_SIZE];`),
        // so it is only necessary to use `delete[]` operator.
        delete[] fencePicketHeight;

        // Preventing the catastrophic use of `delete` on the freed address
        // (using `delete` on a pointer to address 0 does nothing, because
        // no object can have the address 0).
        fencePicketHeight = nullptr;
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }

    return 0;
}

// ************************************************

void printFence(int *fence, int startIndex, int endIndex)
{
    int maxPicketHeight{};
    for (int picketIndex{startIndex}; picketIndex <= endIndex; picketIndex++)
        maxPicketHeight = MAX(maxPicketHeight, fence[picketIndex]);

    std::vector<std::vector<bool>> fenceRepresentation(
        maxPicketHeight,
        std::vector<bool>(
            endIndex - startIndex + 1,
            false));

    for (int picketIndex{startIndex}; picketIndex <= endIndex; picketIndex++)
    {
        int representationIndexHorizontal{picketIndex - startIndex};
        for (int currentPicketSection{}; currentPicketSection < fence[picketIndex]; currentPicketSection++)
        {
            int representationIndexVertical{maxPicketHeight - 1 - currentPicketSection};
            fenceRepresentation[representationIndexVertical][representationIndexHorizontal] = true;
        }
    }

    // Print the fence representation.
    for (int i{0}; i < fenceRepresentation.size(); i++)
    {
        for (int j{0}; j < fenceRepresentation[i].size(); j++)
        {
            char sectionRepresentation{fenceRepresentation[i][j] ? '#' : '\''};
            std::cout << sectionRepresentation;
        }
        std::cout << std::endl;
    }
}
