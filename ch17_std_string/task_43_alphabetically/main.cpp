#include <iostream>
#include <string>
#include <cctype> // tolower()

int alphabetically(std::string s0, std::string s1)
{
    for (auto &el : s0)
        el = tolower(el);

    for (auto &el : s1)
        el = tolower(el);

    return s0.compare(s1);
}

int main()
{
    std::string myS0("alabama");
    std::string myS1("Bratislava");

    std::cout << "Compare result: " << alphabetically(myS0, myS1) << std::endl;
    std::cout << "Compare result: " << alphabetically(myS1, myS0) << std::endl;
    std::cout << "Compare result: " << alphabetically(myS0, myS0) << std::endl;

    return 0;
}
