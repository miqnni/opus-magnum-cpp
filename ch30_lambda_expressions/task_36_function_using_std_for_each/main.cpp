#include <iostream>
#include <vector>
#include <algorithm>  // std::for_each
#include <functional> // std::function

void multiplyAll(std::vector<double> &v, const int par)
{
    std::function<void(double &)> f;
    f = [par](double &el)
    { el *= par; };

    std::for_each(v.begin(), v.end(), f);
}

int main()
{
    std::vector<double> sample{2.1, 4.3, 0.5};
    multiplyAll(sample, 3);

    for (const auto &el : sample)
        std::cout << el << std::endl;

    return 0;
}
