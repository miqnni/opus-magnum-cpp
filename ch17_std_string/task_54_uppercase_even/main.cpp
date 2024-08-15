#include <iostream>
#include <string>
#include <cctype> // toupper()

std::string uppercaseEven(const std::string &original)
{
    std::string modified(original);

    for (int i{}; i < modified.size(); i++)
        modified[i] = i % 2 ? tolower(modified[i]) : toupper(modified[i]);

    return modified;
}

std::string uppercaseEvenWithIterator(const std::string &original)
{
    std::string modified(original);

    std::string::iterator it{modified.begin()};
    for (int i{}; it != modified.end(); i++, it++)
    {
        if (!(i % 2))
            *it = toupper(*it);
        else
            *it = tolower(*it);
    }

    return modified;
}

int main()
{
    std::string sample("picturesqueValley");
    std::cout << uppercaseEven(sample) << std::endl;
    std::cout << uppercaseEvenWithIterator(sample) << std::endl;

    return 0;
}
