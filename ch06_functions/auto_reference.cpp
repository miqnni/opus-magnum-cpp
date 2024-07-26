#include <iostream>
#include <string>

// ************************************************

void compareVariables(const double &arg0, std::string argName0, const double &arg1, std::string argName1);

// ************************************************

int main()
{
    double myDouble{3.75};
    double &myDoubleReference{myDouble};
    const double &myDoubleConstReference{myDouble};

    auto mdc0{myDouble};               // myDoubleCopy #0 (type: double)
    auto mdc1{myDoubleReference};      // myDoubleCopy #1 (type: double)
    auto mdc2{myDoubleConstReference}; // myDoubleCopy #2 (type: double)

    myDouble = -14;

    compareVariables(mdc0, "mdc0", myDouble, "myDouble");
    compareVariables(mdc1, "mdc1", myDoubleReference, "myDoubleReference");
    compareVariables(mdc2, "mdc2", myDoubleConstReference, "myDoubleConstReference");
    std::cout << std::endl;

    auto &refMyDouble{myDouble};                             // (type: double &)
    auto &refMyDoubleReference{myDoubleReference};           // (type: double &)
    auto &refMyDoubleConstReference{myDoubleConstReference}; // (type: const double &)

    myDouble = -17;
    compareVariables(refMyDouble, "refMyDouble", myDouble, "myDouble");
    compareVariables(refMyDoubleReference, "refMyDoubleReference", myDoubleReference, "myDoubleReference");
    compareVariables(refMyDoubleConstReference, "refMyDoubleConstReference", myDoubleConstReference, "myDoubleConstReference");
    std::cout << std::endl;

    refMyDoubleReference = -11;
    // refMyDoubleConstReference = 23; // ERROR: Const references do not allow modifications.

    compareVariables(refMyDouble, "refMyDouble", myDouble, "myDouble");
    compareVariables(refMyDoubleReference, "refMyDoubleReference", myDoubleReference, "myDoubleReference");
    compareVariables(refMyDoubleConstReference, "refMyDoubleConstReference", myDoubleConstReference, "myDoubleConstReference");
    std::cout << std::endl;

    const double myMultiplier{3.14};
    auto &myMultiplierReference{myMultiplier}; // (type: const double &)
    // myMultiplier = 2.7; // ERROR: Const references do not allow modifications.

    // double &myMultiplierReferenceNoAuto{myMultiplier}; // ERROR: `qualifiers dropped in binding reference of type "double &" to initializer of type "const double"C/C++(433)`
    const auto &myMultiplierReferenceV2{myMultiplier};       // (type: const double &)
    const double &myMultiplierReferenceNoAuto{myMultiplier}; // (type: const double &)

    std::cout << "myMultiplier: " << myMultiplier << std::endl;
    std::cout << "myMultiplierReference: " << myMultiplierReference << std::endl;
    std::cout << "myMultiplierReferenceV2: " << myMultiplierReferenceV2 << std::endl;
    std::cout << "myMultiplierReferenceNoAuto: " << myMultiplierReferenceNoAuto << std::endl;

    return 0;
}

// ************************************************

void compareVariables(const double &arg0, std::string argName0, const double &arg1, std::string argName1)
{
    std::cout << argName0 << ": " << arg0
              << ", " << argName1 << ": " << arg1
              << "\tTheir addresses are "
              << (&arg0 == &arg1 ? "identical (reference)" : "different (copy)") << std::endl;
}