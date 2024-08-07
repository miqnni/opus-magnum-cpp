#include <iostream>

constexpr int ALPHABET_SIZE{27}; // 26 + 1 x '\0'

int main()
{
    char alphabet[27] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    char *ptr = alphabet + 3;
    // LUB: char *ptr = &alphabet[3];'

    for (; ptr < alphabet + 26; ptr += 4)
        std::cout << *ptr;

    std::cout << std::endl;

    return 0;
}