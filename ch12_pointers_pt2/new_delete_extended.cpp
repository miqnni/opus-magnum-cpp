#include <iostream>
#include <cstdlib>
#include <ctime>

char *producer(void);     // A correct function.
char *fakeProducer(void); // What happens without `new` keyword?

char *globalCharPtr;

// ************************************************

int main()
{
    srand(time(NULL));

    char *mainCharPtr0{new char{'U'}}; // OR: globalCharPtr = new char('U');
    globalCharPtr = new char('J');     // OR: globalCharPtr = new char{'J'};

    char *mainCharPtr1{nullptr}; // OR char *mainCharPtr1{}; (beause nullptr has value 0)
    mainCharPtr1 = producer();
    // mainCharPtr1 = fakeProducer();

    char *mainCharPtr2{producer()};
    // char *mainCharPtr2{fakeProducer()};

    // ****************
    // *globalCharPtr = 'J';
    // *mainCharPtr0 = 'U';
    *mainCharPtr1 = 'Z';
    std::cout << "Char values: " << *globalCharPtr << ", " << *mainCharPtr0 << ", " << *mainCharPtr1 << ", " << *mainCharPtr2 << std::endl;

    // ****************
    // Deleting objects
    delete globalCharPtr;
    globalCharPtr = nullptr;
    delete mainCharPtr0;
    mainCharPtr0 = nullptr;
    delete mainCharPtr1;
    mainCharPtr1 = nullptr;
    delete mainCharPtr2;
    mainCharPtr2 = nullptr;

    return 0;
}

// ************************************************

char *producer(void)
{
    char localChar{'b'};
    char *somePtr;

    std::cout << "Producing an object..." << std::endl;

    // An object created with `new` inside a function
    // => It is NOT kept on stack, but rather in the memory area
    // called FREE STORE or HEAP.
    somePtr = new char;

    // (working with the created object)
    *somePtr = rand() % ('z' - 'a' + 1) + 'a';
    std::cout << "\t --> " << *somePtr << std::endl;

    return somePtr;
}

char *fakeProducer(void)
{
    char localChar{'b'};
    char *somePtr{nullptr};
    somePtr = &localChar;

    std::cout << "Producing an object... " << reinterpret_cast<unsigned long>(somePtr) << std::endl;

    // somePtr = new char;

    // (working with the created object)
    *somePtr = rand() % ('z' - 'a' + 1) + 'a';
    std::cout << "\t --> " << *somePtr << std::endl;

    return somePtr;
}
