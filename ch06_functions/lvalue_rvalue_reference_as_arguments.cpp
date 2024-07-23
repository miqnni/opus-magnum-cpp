#include <iostream>

void functionByValue(int value);                                    // function A
void functionLvalueReference(int &lvalueReference);                 // function B
void functionConstLvalueReference(const int &constLvalueReference); // function C
void functionRvalueReference(int &&rvalueReference);                // function D

// ************************************************

int main()
{
    int x = 42; // `x` is an lvalue

    // [fA] Calling the function taking an argument by value ("by copy").
    std::cout << "=== fA ===" << std::endl;

    std::cout << "[main] x value: " << x << std::endl;

    functionByValue(x);      // Calling function A with an lvalue.
    functionByValue(7);      // Calling function A with an rvalue.
    functionByValue(31 + 2); // Calling function A with an rvalue.

    std::cout << "[main] x value: " << x << std::endl;

    // ****************

    // [fB] Calling the function taking an argument by object reference (i.e. lvalue reference).
    std::cout << "=== fB ===" << std::endl;

    std::cout << "[main] x value: " << x << std::endl;
    functionLvalueReference(x);
    std::cout << "[main] x value: " << x << std::endl;

    // functionLvalueReference(31 + 2); // ERROR: 31 + 2 is an rvalue, NOT an lvalue.
    // int &lvalueReference = 31 + 2; // ERROR: 31 + 2 is an rvalue, NOT an lvalue.

    // ****************

    // [fC] Calling a function taking (as an argument) a reference to a const object.
    std::cout << "=== fC ===" << std::endl;
    std::cout << "[main] x value: " << x << std::endl;

    // `x` is not a const object, but the function will treat it as one,
    // making it impossible to modify it (inside the function).
    functionConstLvalueReference(x);

    // The function (because of `const`) cannot change the value of
    // its argument, so it is also possible to use CONST rvalues.
    functionConstLvalueReference(31 + 2);

    // Another CONST rvalue example.
    const int &constReference = 26 + 1;
    functionConstLvalueReference(constReference);

    // ****************

    // [fD] Calling a function taking (as an argument) an rvalue reference.
    std::cout << "=== fD ===" << std::endl;

    // functionRvalueReference(x); // ERROR: `x` is not an rvalue.

    // int &&rvalueReference = x; // ERROR: `x` is not an rvalue.

    functionRvalueReference(31 + 2);

    int &&rvalueReference = 26 + 1;
    // functionRvalueReference(rvalueReference); // ERROR: The rvalue reference we heve created above is, in fact, an lvalue.

    std::cout << "=== fB/fC v2 ===" << std::endl;
    functionLvalueReference(rvalueReference);      // This is acceptable.
    functionConstLvalueReference(rvalueReference); // This is acceptable.
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
    std::cout << "\t[fB] Received value (a reference to an lvalue): " << lvalueReference << std::endl;
    lvalueReference++;
    std::cout << "\t[fB] Incremented original value: " << lvalueReference << std::endl;
}

// ************************************************

void functionConstLvalueReference(const int &constLvalueReference)
{
    std::cout << "\t[fC] Received value (a reference to a const lvalue): " << constLvalueReference
              << ". Incrementation is not allowed." << std::endl;
}

// ************************************************

void functionRvalueReference(int &&rvalueReference)
{
    std::cout << "\t[fB] Received value (a reference to an rvalue that can be freely modified): " << rvalueReference << std::endl;
    rvalueReference++;
    std::cout << "\t[fB] Incremented rvalue: " << rvalueReference << std::endl;
}
