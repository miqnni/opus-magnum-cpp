#include <iostream>
#include <map>
#include <string>

// The following means that
// any instance of `cout`, `map`, `string`, `endl`
// in this program will be from namespace `std`
// and we can skip the `std::` prefix.
using std::cout;
using std::endl;
using std::map;
using std::string;

int main()
{
    map<string, int> forms_of_100;
    forms_of_100["dec"] = 100;
    forms_of_100["oct"] = 0100;
    forms_of_100["hex"] = 0x100;
    forms_of_100["bin"] = 0b100; // Binary literals standardized in C++14.

    // Iterator pointing to the map's first element.
    map<string, int>::iterator it = forms_of_100.begin();

    int sum_of_all = 0;
    cout << "Value of \"100\" with " << forms_of_100.size() << " different system bases:" << endl;

    // Iterating through the entire map.
    while (it != forms_of_100.end())
    {
        cout << "100_(" << it->first
             << "): " << it->second << endl;

        // You can do arithmetic operation on int literals written in different forms.
        sum_of_all += it->second;

        ++it; // Increment the iterator (!!!)
    }

    cout << "SUM: " << sum_of_all << endl;

    return 0;
}
