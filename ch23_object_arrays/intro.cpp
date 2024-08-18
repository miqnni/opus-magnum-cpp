#include <iostream>

class SampleAggregate
{
public:
    int a, b, c;
};

int main()
{
    SampleAggregate arr[6] =
        {
            {1, 2, 3},
            {4, 5},
        };

    for (const auto &el : arr)
        std::cout << el.a << " " << el.b << " " << el.c << std::endl;

    return 0;
}