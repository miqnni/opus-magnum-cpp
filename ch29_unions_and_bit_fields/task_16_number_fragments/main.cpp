#include <iostream>

struct NumberFragments
{
    unsigned int blue : 6, : 4,
        green : 5, : 1,
        red : 3;
};

union Slicer
{
    uint32_t whole;
    NumberFragments fragm;
};

int main()
{
    uint32_t userNumber;
    std::cout << "Your eight-digit number: ";
    std::cin >> userNumber;

    Slicer slicer;
    slicer.whole = userNumber;

    // Dec version
    std::cout << userNumber
              << " --> blue = " << slicer.fragm.blue << ", "
              << " green = " << slicer.fragm.green << ", "
              << " red = " << slicer.fragm.red
              << std::endl;

    // Hex version
    std::cout << std::hex << "0x" << userNumber
              << " --> blue = 0x" << slicer.fragm.blue << ", "
              << " green = 0x" << slicer.fragm.green << ", "
              << " red = 0x" << slicer.fragm.red
              << std::dec << std::endl;

    return 0;
}