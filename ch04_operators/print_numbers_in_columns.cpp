#include <iostream>
#include <stdexcept>

// #define TEST_CATCH_ALL

constexpr int VALUE_THAT_THROWS_AN_EXCEPTION = -3;

class Printer
{
private:
    int number_start; // inclusive
    int number_end;   // non-inclusive
    int numbers_per_row;

public:
    Printer(int n_start, int n_end, int n_row)
        : number_start(n_start), number_end(n_end), numbers_per_row(n_row) {}

    void printNumbers()
    {
        for (int curr_number = number_start; curr_number < number_end; curr_number++)
        {
            if ((curr_number - number_start) % numbers_per_row)
                std::cout << "\t";
            else
                std::cout << "\n";

            std::cout << curr_number;
        }
        std::cout << std::endl
                  << std::endl;
    }
};

int main()
{
    try
    {
        int user_number_start;
        int user_number_end;
        int user_numbers_per_row;

        std::cout << "NUMBER PRINTER" << std::endl;

#ifdef TEST_CATCH_ALL
        std::cout << "\t Type " << VALUE_THAT_THROWS_AN_EXCEPTION << " to throw a default exception." << std::endl;
#endif // TEST_CATCH_ALL

        std::cout << "First number (inclusive): ";
        std::cin >> user_number_start;

#ifdef TEST_CATCH_ALL
        if (user_number_start == VALUE_THAT_THROWS_AN_EXCEPTION)
            throw VALUE_THAT_THROWS_AN_EXCEPTION;
#endif // TEST_CATCH_ALL

        std::cout << "Last number (non-inclusive): ";
        std::cin >> user_number_end;

#ifdef TEST_CATCH_ALL
        if (user_number_end == VALUE_THAT_THROWS_AN_EXCEPTION)
            throw VALUE_THAT_THROWS_AN_EXCEPTION;
#endif // TEST_CATCH_ALL

        if (user_number_end <= user_number_start)
        {
            throw std::runtime_error(
                "The \"last\" number must be greater than the \"first\" number.");
        }

        std::cout << "Numbers in one row: ";
        std::cin >> user_numbers_per_row;

#ifdef TEST_CATCH_ALL
        if (user_numbers_per_row == VALUE_THAT_THROWS_AN_EXCEPTION)
            throw VALUE_THAT_THROWS_AN_EXCEPTION;
#endif // TEST_CATCH_ALL

        if (user_numbers_per_row <= 0)
        {
            throw std::runtime_error(
                "There should be a *positive* amount of numbers in every row.");
        }

        Printer main_printer = Printer(user_number_start, user_number_end, user_numbers_per_row);
        main_printer.printNumbers();
    }
    catch (const std::exception &e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
    catch (...)
    {
        // Catch-all block
        // (used for handling exception that do not match the exception
        // datatype in any of the `catch` blocks)
        std::cerr << "Default exception" << std::endl;
    }

    return 0;
}