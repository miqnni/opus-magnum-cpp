#include <iostream>
#include <cstdlib>
#include <string>

constexpr double PASS_THRESHOLD{0.55};

int main()
{
    int user_test_points;
    int max_test_points;

    try
    {

        std::cout << "Points that you got in the test: ";
        std::cin >> user_test_points;

        std::cout << "Maximum possible number of points in the test: ";
        std::cin >> max_test_points;

        if (max_test_points == 0)
            throw(max_test_points); // Do not throw strings. If you want to send a message, create an exception class (not implemented here).

        double test_score{(double)user_test_points / (double)max_test_points};

        // Local variable `pass_status`
        // is available only within this if...else statement.
        if (int pass_status{(int)(test_score / PASS_THRESHOLD)})
        {
            std::cout << "Test passed (status: " << pass_status << "). Score: " << test_score << std::endl;
        }
        else
        {
            std::cout << "Test failed (status: " << pass_status << "). Score: " << test_score << std::endl;
        }
    }
    catch (int no)
    {
        std::cout << "Error: incorrect number of max points (" << no << ")." << std::endl;
        exit(EXIT_FAILURE);
    }

    return 0;
}