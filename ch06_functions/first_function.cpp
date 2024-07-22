#include <iostream>
#include <string>

constexpr int TRIANGLE_ARG{8};

int triangle(int height);

int main()
{
    std::cout << "Triangle:" << std::endl;
    int returnValue = triangle(TRIANGLE_ARG);
    std::cout << "This triangle is composed of " << returnValue << " characters.";
    return 0;
}

int triangle(int height)
{
    int charCount{};
    for (int i{0}; i < height; i++)
    {
        std::string level(i + 1, '*');
        std::cout << level << std::endl;
        charCount += i + 1;
    }

    return charCount;
}