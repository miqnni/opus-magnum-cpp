#include <iostream>
#include <string>
#include <initializer_list>

class Inscription : public std::string
{
public:
    using std::string::string;

    Inscription(std::initializer_list<char> chars)
    {
        constexpr int reps{5};
        for (const auto &el : chars)
            this->append(reps, el);
    }
};

int main()
{
    Inscription ziu{'z', 'i', 'u'};

    std::cout << "ziu: " << ziu << std::endl;

    return 0;
}