#include <iostream>
#include "add_string.h"

constexpr int ARRAY_SIZE_A{50};
constexpr int ARRAY_SIZE_B{300};

int main()
{
    char originalString[ARRAY_SIZE_A] = {"This is the original string. Added part:"};
    char addedString[ARRAY_SIZE_B] = {"This is another string that should be added to the original string."};

    addString(originalString, ARRAY_SIZE_A, addedString);

    std::cout << "originalString (after adding): " << originalString << std::endl;

    return 0;
}