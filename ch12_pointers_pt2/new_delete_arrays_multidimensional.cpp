#include <iostream>

constexpr int ARRAY_SIZE_Y{5};
constexpr int ARRAY_SIZE_Z{7};

int main()
{
    int arraySizeX; // Non-const.
    std::cout << "We are going to create a 3d array of size: [ ? ] x " << ARRAY_SIZE_Y << " x " << ARRAY_SIZE_Z << std::endl;
    std::cout << "What size should we replace `[ ? ]` with ? ";
    std::cin >> arraySizeX;

    int(*array3DPtr)[ARRAY_SIZE_Y][ARRAY_SIZE_Z] = new int[arraySizeX][ARRAY_SIZE_Y][ARRAY_SIZE_Z]; // (dynamic) Memory allocation.
    // OR
    // auto *array3DPtr = new int[arraySizeX][ARRAY_SIZE_Y][ARRAY_SIZE_Z];

    *array3DPtr[0][0] = 1003;
    std::cout << "array3DPtr[0][0][0]: " << array3DPtr[0][0][0] << std::endl;

    array3DPtr[arraySizeX - 1][ARRAY_SIZE_Y - 1][ARRAY_SIZE_Z - 1] = 47;
    std::cout << "array3DPtr[" << arraySizeX - 1 << "][" << ARRAY_SIZE_Y - 1 << "][" << ARRAY_SIZE_Z - 1 << "]: " << array3DPtr[arraySizeX - 1][ARRAY_SIZE_Y - 1][ARRAY_SIZE_Z - 1] << std::endl;

    delete[] array3DPtr;
    array3DPtr = nullptr;
    return 0;
}
