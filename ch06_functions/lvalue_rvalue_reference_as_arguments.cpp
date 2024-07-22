#include <iostream>

void functionByValue(int value);                                    // function A
void functionLvalueReference(int &lvalueReference);                 // function B
void functionConstLvalueReference(const int &constLvalueReference); // function C
void functionRvalueReference(int &&rvalueReference);                // function D

// ************************************************

int main()
{
    int x = 42; // `x` is an lvalue

    // [fA] Calling the function taking an argument by value ("by copy")
    std::cout << "=== fA ===" << std::endl;

    std::cout << "[main] x value: " << x << std::endl;

    functionByValue(x);      // Calling function A with an lvalue
    functionByValue(7);      // Calling function A with an rvalue
    functionByValue(31 + 2); // Calling function A with an rvalue

    std::cout << "[main] x value: " << x << std::endl;

    // [fB] Calling the function taking  an argument by object reference (i.e. lvalue reference)
    std::cout << "=== fB ===" << std::endl;

    std::cout << "[main] x value: " << x << std::endl;
    functionLvalueReference(x);
    std::cout << "[main] x value: " << x << std::endl;

    // functionLvalueReference(31 + 2); // ERROR: 31 + 2 is an rvalue, NOT an lvalue.
    // int &lvalueReference = 31 + 2; // ERROR: 31 + 2 is an rvalue, NOT an lvalue.

    return 0;
}

// ************************************************

void functionByValue(int value)
{
    value++;
    std::cout << "\t[fA] Copy of value, incremented: " << value << std::endl;
}

// ************************************************

void functionLvalueReference(int &lvalueReference)
{
    std::cout << "\t[fB] Received value (a reference of an lvalue): " << lvalueReference << std::endl;
    lvalueReference++;
    std::cout << "\t[fB] Incremented original value: " << lvalueReference << std::endl;
}

// ************************************************

void functionConstLvalueReference(const int &constLvalueReference)
{
    // ...
}