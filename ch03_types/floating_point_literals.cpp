#include <iostream>
#include <string>
#include <map>
#include <typeinfo> // typeid()

using std::cout;
using std::endl;
using std::map;
using std::string;

int main()
{
    map<string, double> floating_point_numbers;
    floating_point_numbers["4."] = 4.;
    floating_point_numbers["4.0F"] = 4.0F;
    floating_point_numbers["4.01L"] = 4.01L;
    floating_point_numbers[".01"] = .01;
    floating_point_numbers["14.9e-3"] = 14.9e-3;
    floating_point_numbers["-23e7L"] = -23e7L;

    map<string, double>::iterator it = floating_point_numbers.begin();
    long double sum_of_all = 0;
    cout << "Literal\tValue\tType\b\b\b\n";
    while (it != floating_point_numbers.end())
    {
        auto curr_value = it->second;
        cout << it->first << "\t" << curr_value << "\t" << typeid(curr_value).name() << endl;

        sum_of_all += curr_value;

        ++it;
    }
    cout << "\aSUM: " << sum_of_all << endl;

    return 0;
}
