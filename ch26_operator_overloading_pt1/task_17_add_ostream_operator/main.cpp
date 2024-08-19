#include <iostream>
#include <cstring>

// Class `K` from:
// ch24_pointers_to_class_members/task04_pointer_instructions/main.cpp
// Modified so that `a`, `b`, `c` are private
// and one has to use a constructor to initialize them
// and getters to check their values.
class K
{
private:
    int a, b, c;

public:
    K(int a, int b, int c) : a{a}, b{b}, c{c} {}

    int getA() { return a; }
    int getB() { return b; }
    int getC() { return c; }

    // ADDED LINE (non-resident function) -- method 1
    friend std::ostream &operator<<(std::ostream &out, K k);
};

// ************************************************

// Class `AltPerson` from:
// ch22_copy_and_move_constructor/default_copy_constructor_vs_array.cpp
class AltPerson
{
private:
    char arrName[50]{"(unknown)"};
    int id{};

public:
    AltPerson(const char *givenName, int id)
    {
        std::cout << "AltPerson constructor..." << std::endl;
        size_t tmpNameLength = strlen(givenName);
        memcpy(this->arrName, givenName, tmpNameLength + 1);
        this->id = id;
    }

    ~AltPerson()
    {
        std::cout << "AltPerson destructor..." << std::endl;
        if (!arrName)
            return;
        // delete[] arrName;
    }

    void details()
    {
        std::cout << "ALT PERSON: " << arrName << ", " << id << std::endl;
    }

    void replacement(char newFirstLetter, int newId)
    {
        arrName[0] = newFirstLetter;
        id = newId;
    }

    // ADDED LINEs (resident function) -- method 2
    friend std::ostream &operator<<(std::ostream &out, AltPerson person)
    {
        out << "[PERSON | name: " << person.arrName << "; ID: " << person.id << "]";
        return out;
    }
};

// ************************************************

std::ostream &operator<<(std::ostream &out, K k)
{
    out << "{" << k.a << ", " << k.b << ", " << k.c << "}";
    return out;
}

// std::ostream &operator<<(std::ostream &out, AltPerson person)
// {
//     out << "[PERSON | name: " << person.arrName << "; ID: " << person.id << "]";
//     return out;
// }

// ************************************************

int main()
{
    K sampleK{30, 70, 15};
    AltPerson samplePerson{"John", 32};

    std::cout << "sampleK: " << sampleK << std::endl;
    std::cout << "samplePerson: " << samplePerson << std::endl;

    return 0;
}