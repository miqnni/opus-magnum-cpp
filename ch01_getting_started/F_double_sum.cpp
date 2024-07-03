// Chapter 1 final task (my own)
// Write a program that reads an integer `n` from standard input
// and then reads `n` numbers of type `double`.
// Finally, print the sum of the `n` provided numbers.

#include <iostream>
#include <cstdlib>

constexpr int MAX_USER_NUMBER_COUNT = 10;

int main()
{
    try
    {
        int user_number_count;
        std::cout << "How many numbers should be added? ";
        std::cin >> user_number_count;

        if (user_number_count > MAX_USER_NUMBER_COUNT)
            throw(user_number_count);

        double curr_user_number;
        double user_number_sum = 0.;
        for (int i = 0; i < user_number_count; i++)
        {
            std::cout << "Number to be added (" << i + 1 << "/" << user_number_count << "): ";
            std::cin >> curr_user_number;
            user_number_sum += curr_user_number;
        }

        std::cout << "SUM: " << user_number_sum << std::endl;
    }
    catch (int actual_user_number_count)
    {
        std::cout << "You can sum up to " << MAX_USER_NUMBER_COUNT << " numbers" << std::endl;
        std::cout << actual_user_number_count << " is too big!" << std::endl;
    }

    system("pause");
    return 0;
}
