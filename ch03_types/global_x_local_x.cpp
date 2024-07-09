#include <iostream>

constexpr int GLOBAL_VALUE = 26;
constexpr int LOCAL_VALUE = 34;

int x = GLOBAL_VALUE;

int main()
{
    std::cout << "Global value: " << x << std::endl;

    {
        // Local scope
        int x = LOCAL_VALUE;
        std::cout << "Local value: " << x << std::endl;
        std::cout << "Global value inside the local scope: " << ::x << std::endl;
    }

    std::cout << "Global value: " << x << std::endl;

    return 0;
}
