#include <iostream>

void printThreeCStrings(const char *threeCStringArray[])
{
    std::cout << "Your CStrings: " << threeCStringArray[0] << ", " << threeCStringArray[1] << ", " << threeCStringArray[2] << std::endl;
};

int main()
{
    const char *names[]{
        "John",
        "Carl",
        "Nicholas",
        "Gustav",
        "Michael",
        "Margaret",
        "Susan",
        "Sophia",
    };

    const char *threeCStrings[3];

    threeCStrings[0] = names[1];
    threeCStrings[1] = names[6];
    threeCStrings[2] = "Custom Text";

    printThreeCStrings(threeCStrings);

    return 0;
}