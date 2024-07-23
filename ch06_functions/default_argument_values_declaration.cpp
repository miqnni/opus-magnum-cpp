#include <iostream>

void printArguments(int arg0, int arg1 = 6);
void printArguments(int arg0 = 1, int arg1);

int squareAndIncrement(int x);

int someGlobalVariable{8};

// ************************************************

int main()
{
    printArguments();

    { // Local scope
        std::cout << "--- (inside local scope)" << std::endl;
        printArguments();

        int someLocalVariable{4};

        // void printArguments(int arg0, int arg1 = someLocalVariable); // ERROR: Local objects are not allowed in function declarations.
        // void printArguments(int arg0 = 0, int arg1); // ERROR: `int arg1` does not automatically have the value from the outer scope.

        void printArguments(int arg0, int arg1 = 2);

        // printArguments(); // ERROR: After the redeclaration, you cannot call the function as if it had the previous declaration.

        printArguments(1);
        printArguments(someLocalVariable);

        someGlobalVariable = 3 * someGlobalVariable - 8;
        void printArguments(int arg0 = squareAndIncrement(someGlobalVariable) - 27, int);

        printArguments();
    }

    std::cout << "--- (outside local scope)" << std::endl;
    printArguments();

    return 0;
}

// ************************************************

void printArguments(int arg0, int arg1)
{
    std::cout << "f(" << arg0 << ", " << arg1 << ")" << std::endl;
}

// ************************************************

int squareAndIncrement(int x)
{
    return x * x + 1;
}