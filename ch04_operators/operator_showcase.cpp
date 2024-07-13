#include <iostream>

void showcaseIncrDecr()
{
    std::cout << "=== INCREMENTATION / DECREMENTATION ===" << std::endl;

    int x = 1;
    int y = 1;
    int z = 1;
    int w = 1;

    std::cout << "Initial values:" << std::endl;
    std::cout << "\t x: " << x << std::endl;
    std::cout << "\t y: " << y << std::endl;
    std::cout << "\t z: " << z << std::endl;
    std::cout << "\t w: " << w << std::endl;
    std::cout << std::endl;

    int a = ++x; // a == 2 && x == 2
    int b = y++; // b == 1 && y == 1

    int c = --z; // c == 0 && z == 0
    int d = w--; // d == 1 && w == 1

    std::cout << "Expression values:" << std::endl;
    std::cout << "\t ++x: " << a << " (++x == x value AFTER incrementation)" << std::endl;
    std::cout << "\t y++: " << b << " (y++ == y value BEFORE incrementation)" << std::endl;
    std::cout << "\t --z: " << c << " (--z == z value AFTER decrementation)" << std::endl;
    std::cout << "\t w--: " << d << " (w-- == w value BEFORE decrementation)" << std::endl;
    std::cout << std::endl;

    std::cout << "Final values:" << std::endl;
    std::cout << "\t x: " << x << std::endl;
    std::cout << "\t y: " << y << std::endl;
    std::cout << "\t z: " << z << std::endl;
    std::cout << "\t w: " << w << std::endl;
    std::cout << std::endl;
}

void showcaseAssignment()
{
    std::cout << "=== ASSIGNMENT ===" << std::endl;
    int x_a, x_b;
    x_a = (x_b = 3.4);
    std::cout << "x_a = (x_b = 3.4); (x_a, x_b -- int variables)" << std::endl
              << "Value of x_a: " << x_a << std::endl
              << "Value of x_b: " << x_b << std::endl;
    std::cout << std::endl;
}

void showcaseAssignmentVsEquality()
{
    std::cout << "=== OPERATOR \"=\" VS. OPERATOR \"==\" ===" << std::endl;

    int a = 2;
    int b = 3;

    std::cout << "Initial values:" << std::endl;
    std::cout << "\t a: " << a << std::endl;
    std::cout << "\t b: " << b << std::endl;
    std::cout << std::endl;

    std::cout << "Checking conditions" << std::endl;

    std::cout << "\t (a == b): ";
    if (a == b)
    {
        std::cout << "true";
    }
    else
    {
        std::cout << "false";
    }
    std::cout << std::endl;

    std::cout << "\t (a = b): ";
    if ((a = b))
    {
        std::cout << "true";
    }
    else
    {
        std::cout << "false";
    }
    std::cout << std::endl
              << std::endl;

    std::cout << "Final values:" << std::endl;
    std::cout << "\t a: " << a << std::endl;
    std::cout << "\t b: " << b << std::endl;
    std::cout << std::endl;
}

enum : unsigned short
{
    CALL_INCR = 01,
    CALL_ASGN = 02,
    CALL_ASEQ = 04,
};

constexpr unsigned short FULL_MASK = CALL_INCR | CALL_ASGN | CALL_ASEQ;

int main()
{
    try
    {
        int user_input;
        std::cout << "Type a number between 0 and 7 to start: ";
        std::cin >> user_input;

        if (user_input < 0)
            throw std::runtime_error(
                "Negative numbers are not allowed.");

        unsigned short user_choice{(unsigned short)user_input};
        // Conditional operator.
        user_choice = (user_choice > FULL_MASK)
                          ? FULL_MASK
                          : user_choice;

        std::cout << ((user_choice > 00 && user_choice < 07) ? "You have chosen some (but not all) of the functions." : "You have chosen either none or all of the functions") << std::endl;

        int incoming_function_calls{};

        for (unsigned short tmp_mask{user_choice}; tmp_mask > 00; tmp_mask >>= 1)
        {
            if (tmp_mask & 01)
            {
                std::cout << "Number of functions to be called: " << ++incoming_function_calls << std::endl;
            }
        }
        std::cout << std::endl
                  << "Function results" << std::endl
                  << "----------------" << std::endl
                  << std::endl;

        if (user_choice & CALL_INCR)
            showcaseIncrDecr();
        if (user_choice & CALL_ASGN)
            showcaseAssignment();
        if (user_choice & CALL_ASEQ)
            showcaseAssignmentVsEquality();
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}
