#include <iostream>

int main()
{
    int localObj{50};
    auto addingLambda = [localObj](int a, int b)
    { return a + b + localObj; };

    std::cout << addingLambda(100, 200) << std::endl; // 350

    return 0;
}
