#include <iostream>
#include <cstring>

// Comment out if necessary.
// #define USE_DEFAULT_COPY_CONSTRUCTOR
#define MOVE_CONSTRUCTOR

class NormalPerson
{
private:
    char *pName;
    int nameLength{};
    int id{};

public:
    NormalPerson(const char *givenName, int id)
    {
        std::cout << "NormalPerson constructor..." << std::endl;

        nameLength = strlen(givenName) + 1;
        pName = new char[nameLength]; // [!!!]
        std::memcpy(pName, givenName, nameLength);
        this->id = id;
    }

#ifndef USE_DEFAULT_COPY_CONSTRUCTOR
    NormalPerson(const NormalPerson &other)
    {
        std::cout << "NormalPerson COPY constructor..." << std::endl;
        nameLength = other.nameLength;
        pName = new char[nameLength];
        memcpy(pName, other.pName, nameLength);
        id = other.id;
    }
#endif // USE_DEFAULT_COPY_CONSTRUCTOR

#ifdef MOVE_CONSTRUCTOR
    NormalPerson(NormalPerson &&other) noexcept
    {
        std::cout << "NormalPerson MOVE constructor..." << std::endl;
        nameLength = other.nameLength;
        pName = other.pName; // [!]

        // [!!!]
        other.nameLength = 0;
        other.pName = nullptr;

        // Waste of time:
        // other.id = 0;
    }

#endif // MOVE_CONSTRUCTOR

    ~NormalPerson()
    {
        std::cout << "NormalPerson destructor..." << std::endl;
        if (!pName)
            return;
        delete[] pName;
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
};

int main()
{
    {
        // Pointer `char *`
        // WORKS INCORRECTLY WITH DEFAULT COPY CONSTRUCTOR (shallow copy)
        NormalPerson normalA{"Dan", 2001};
        NormalPerson normalB{normalA};

        normalB.replacement('I', 1998);
        std::cout << "A ";
        normalA.details(); // Should not change. But without the default copy constructor it changes.
        std::cout << "B ";
        normalB.details();

        // Use the MOVE CONSTRUCTOR instead of COPY CONSTRUCTOR.
        // The object `normalB` gets PLUNDERED.
        // NormalPerson normalC{static_cast<NormalPerson &&>(normalB)}; // Not-so-good a practice.
        NormalPerson normalC{std::move(normalB)}; // A better practice than casting (does the same, but more universal and you don't need to use the type name).
        normalC.replacement('F', 2011);

        std::cout << "*** One more time." << std::endl;
        std::cout << "A ";
        normalA.details();

        // (ERRORS start)
        // std::cout << "B ";
        // normalB.details();
        // (ERRORS end)

        std::cout << "C ";
        normalC.details();
    }

    // ****************
    std::cout << std::endl;

    {
        // Array `char[SIZE]`
        // WORKS CORRECTLY WITH DEFAULT COPY CONSTRUCTOR (deep copy)
        AltPerson altA{"Dan", 2001};
        AltPerson altB{altA};

        altB.replacement('I', 1998);
        std::cout << "A ";
        altA.details();
        std::cout << "B ";
        altB.details();
    }

    return 0;
}