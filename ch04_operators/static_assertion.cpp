// #include <iostream>
#include <limits>

constexpr int VAL0 = 3;

// Example error 0
// static_assert((VAL0 % 2) == 0, "Error: The value of VAL0 must be even.");

int main()
{

    // Example error 1
    // static_assert(sizeof(int) == 2, "Error: In this compiler int does not take 2 bytes. This program requires int to take 2 bytes.");

    // Example error 2
    // static_assert(std::numeric_limits<char>::is_signed, "Error: This compiler considers char to be an unsigned type!");

    // Example error 3
    // static_assert(5000000000 < std::numeric_limits<int>::max(), "Error: the provided value is too big for the type int!")

    return 0;
}