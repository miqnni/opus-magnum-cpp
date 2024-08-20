#include <iostream>
#include <vector>
#include <functional>
#include <algorithm>

void applyToAllElements(std::vector<double> &v, std::function<void(double &)> f)
{
    for (double &el : v)
        f(el);
}

int main()
{
    std::vector<double> sample{44, 66, 99, 123, 234, 555};
    int par{4};
    std::function<void(double &)> multiplyByPar = [par](double &d)
    {
        d *= par;
    };

    applyToAllElements(sample, multiplyByPar);

    for (const auto &el : sample)
        std::cout << el << std::endl;

    return 0;
}