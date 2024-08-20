#include <iostream>
#include <vector>
#include <algorithm>  // std::transform
#include <functional> // std::function
#include <string>     // std::to_string()

void modifyVector(std::vector<double> &v, std::function<double(double)> f)
{
    std::transform(v.begin(), v.end(), v.begin(), f);
}

void display(std::vector<double> v)
{
    for (auto &el : v)
        std::cout << el << " ";
    std::cout << std::endl;
}

int main()
{
    std::vector<double> myV{1.2, 1.3, -10.45, 12.7, 7.0, 6.5, 7.5, 5};
    std::vector<double> myVZero{1.2, 1.3, -10.45, 12.7, 7.0, 6.5, 7.5, 0};
    std::vector<double> myVFiftyFive{1.2, 1.3, -10.45, 12.7, 7.0, 6.5, 7.5, 55};

    std::function<double(double)> myLambda = [](double x)
    {
        if (x == 0 || x == 55)
            throw std::domain_error("Incorrect value: " + std::to_string(x));

        return 1. / x;
    };

    try
    {
        for (std::vector<double> &vect : std::vector<std::vector<double>>{
                 myV,
                 //  myVZero,
                 //  myVFiftyFive,
                 // Comment out any vector above to skip it.
             }

        )
        {
            modifyVector(vect, myLambda);
            display(vect);
        }
    }
    catch (std::exception &e)
    {
        std::cout << "Exception : " << e.what() << std::endl;
    }

    return 0;
}
