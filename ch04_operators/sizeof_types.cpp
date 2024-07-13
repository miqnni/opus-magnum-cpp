#include <iostream>
#include <string>
#include <map>

std::map<std::string, size_t> size_of_type =
    {
        {"bool", sizeof(bool)},
        {"char", sizeof(char)},
        {"short", sizeof(short)},
        {"int", sizeof(int)},
        {"long", sizeof(long)},
        {"long long", sizeof(long long)},
        {"float", sizeof(float)},
        {"double", sizeof(double)},
        {"long double", sizeof(long double)},
};

class Alabama
{
private:
    unsigned long long sweet;
    long double home;

public:
    Alabama()
        : sweet(10uLL), home(10.L) {}

    void incr()
    {
        sweet++;
        home++;
    }

    auto sumBoth()
    {
        return sweet + home;
    }
};

int main()
{
    std::cout << "Size [B] of different types on this computer:" << std::endl;
    std::cout << "TYPE\tSIZE" << std::endl
              << "----\t----" << std::endl;

    std::map<std::string, size_t>::iterator it = size_of_type.begin();
    while (it != size_of_type.end())
    {
        std::cout << it->first << "\t" << it->second << std::endl;

        ++it;
    }

    Alabama my_obj = Alabama();
    std::cout << "Size [B] of an example of object of some user-defined type: " << sizeof(my_obj) << std::endl;

    return 0;
}