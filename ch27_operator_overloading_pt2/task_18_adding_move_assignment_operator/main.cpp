// Modified version of:
// ch22_copy_and_move_constructor/default_copy_constructor_vs_array.cpp

#include <iostream>
#include <cstring>

class NormalPerson
{
private:
    char *pName;
    int nameLength{};
    int id{};

public:
    NormalPerson(const char *givenName, int id)
    {
        std::cout << "\tNormalPerson constructor..." << std::endl;

        nameLength = strlen(givenName) + 1;
        pName = new char[nameLength]; // [!!!]
        std::memcpy(pName, givenName, nameLength);
        this->id = id;
    }

    NormalPerson(const NormalPerson &other)
    {
        std::cout << "\tNormalPerson COPY constructor..." << std::endl;
        pName = new char[other.nameLength];
        nameLength = other.nameLength;
        memcpy(pName, other.pName, nameLength);
        id = other.id;
    }

    NormalPerson(NormalPerson &&other) noexcept
    {
        std::cout << "\tNormalPerson MOVE constructor..." << std::endl;
        pName = other.pName; // [!]
        nameLength = other.nameLength;
        id = other.id;

        // [!!!]
        other.nameLength = 0;
        other.pName = nullptr;

        // Waste of time:
        // other.id = 0;
    }

    ~NormalPerson()
    {
        std::cout << "\tNormalPerson destructor..." << std::endl;
        if (!pName)
            return;
        delete[] pName;
    }

    // ****************
    // Add a "talking" move assignment operator.
    NormalPerson &operator=(NormalPerson &&other) noexcept
    {
        std::cout << "\tNormalPerson MOVE assignment operator..." << std::endl;

        if (this == &other)
            return *this;

        delete[] pName;

        pName = other.pName;
        nameLength = other.nameLength;
        id = other.id;

        other.pName = nullptr;

        return *this;
    }

    // ****************

    // Copy assignment operator
    NormalPerson &operator=(const NormalPerson &other)
    {
        std::cout << "\tNormalPerson COPY assignment operator..." << std::endl;

        if (this == &other)
            return *this;

        delete[] pName;

        nameLength = other.nameLength;
        pName = new char[nameLength];
        memcpy(pName, other.pName, nameLength);
        id = other.id;

        return *this;
    }

    void details()
    {
        std::cout << "NORMAL PERSON: " << pName << ", " << id << std::endl;
    }

    void replacement(char newFirstLetter, int newId)
    {
        pName[0] = newFirstLetter;
        id = newId;
    }
};

int main()
{
    {

        std::cout << "*** Before" << std::endl;

        NormalPerson normalA{"Dan", 2001};
        NormalPerson normalB{normalA};
        normalB.replacement('I', 1998);
        std::cout << "A ";
        normalA.details();
        std::cout << "B ";
        normalB.details();

        std::cout << "Person C plunders person B in order to create itself." << std::endl;
        NormalPerson normalC{std::move(normalB)}; // A better practice than casting (does the same, but more universal and you don't need to use the type name).
        normalC.replacement('F', 2011);

        std::cout << "A ";
        normalA.details();

        std::cout << "C ";
        normalC.details();
        std::cout << "*** After (move assignment operator test)" << std::endl;
        // ****************
        // Test the move assignment operator.
        NormalPerson normalD{"placeholder D", 0};
        NormalPerson normalE{"placeholder E", 1};
        NormalPerson normalF{"placeholder F", 2};
        normalD = normalA;                   // COPY assignment operator
        normalE = std::move(normalC);        // MOVE assignment operator
        normalF = NormalPerson{"San", 2000}; // MOVE assignment operator
        std::cout << "A ";
        normalA.details();
        std::cout << "D ";
        normalD.details();
        std::cout << "E ";
        normalE.details();
        std::cout << "F ";
        normalF.details();

        // ****************
    }

    return 0;
}
