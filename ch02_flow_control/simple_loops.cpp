#include <iostream>
#include <cctype> // toupper()

int main()
{
    while (true)
    {
        char user_input_char;
        do
        {
            std::cout << "Type in an uppercase letter: ";
            std::cin >> user_input_char;
            for (char curr_char = user_input_char; 'A' <= curr_char && curr_char <= 'Z'; curr_char--)
            {
                std::cout << curr_char << " ";
            }
            std::cout << std::endl;
        } while ('A' <= user_input_char && user_input_char <= 'Z');

        std::cout << "You typed a different character (" << user_input_char << ") than any uppercase letter." << std::endl;
        do
        {
            std::cout << "Continue? (Y/N) ";
            std::cin >> user_input_char;
            user_input_char = toupper(user_input_char);
        } while (user_input_char != 'Y' && user_input_char != 'N');

        if (user_input_char == 'N')
            break;
    }

    return 0;
}