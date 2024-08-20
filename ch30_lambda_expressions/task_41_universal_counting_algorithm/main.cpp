#include <iostream>
#include <vector>
#include <functional>

int counting(
    std::vector<int> v,
    std::function<bool(int)> cond = [](int x)
    { return x > 0; }

)
{
    int res{};

    for (const auto &el : v)
    {
        if (cond(el))
            res++;
    }

    return res;
}

int main()
{
    std::vector<int> myV{3, 6, 5, -1, 7, 10};

    int myCond{5};
    auto f1 = [myCond](int x) -> bool
    {
        return x > myCond;
    };

    std::cout << "counting(myV, f1): " << counting(myV, f1) << std::endl;
    std::cout << "counting(myV): " << counting(myV) << std::endl;

    return 0;
}
