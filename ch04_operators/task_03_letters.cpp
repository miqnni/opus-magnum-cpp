#include <iostream>

constexpr int START_CHAR{'A'};
constexpr int DEFAULT_DISPLAY_END_CHAR{'H'};
constexpr int END_CHAR{'Z'};
static_assert(START_CHAR <= DEFAULT_DISPLAY_END_CHAR && DEFAULT_DISPLAY_END_CHAR <= END_CHAR);

constexpr char DEFAULT_ROW_SIZE{2};
constexpr char MAX_ROW_SIZE{10};
static_assert(DEFAULT_ROW_SIZE > 0 && DEFAULT_ROW_SIZE < MAX_ROW_SIZE);

int main()
{
    try
    {
        // Display the first set of chars with a pre-set number of chars in a row.
        for (char curr_char = START_CHAR; curr_char <= DEFAULT_DISPLAY_END_CHAR; curr_char++)
        {
            std::cout << curr_char;
            int typed_chars_count = (curr_char - START_CHAR + 1);
            bool continue_row = typed_chars_count % DEFAULT_ROW_SIZE;
            std::cout << (continue_row ? ' ' : '\n');
        }

        // Ask the user how many chars in a row should be displayed now. Handle errors.
        int user_row_size_input;
        std::cout << std::endl
                  << "From now on, how many letters should be displayed in one row? (max: " << static_cast<int>(MAX_ROW_SIZE) << "): ";
        std::cin >> user_row_size_input;
        if (user_row_size_input < 1)
            throw std::runtime_error("There should be at least one character in each row.");
        else if (user_row_size_input > MAX_ROW_SIZE)
            throw std::runtime_error("The provided number of characters in one row is too big!");

        // Important values for the part where we print more chars.
        const char new_row_size{static_cast<char>(user_row_size_input)};
        const char new_start_char{DEFAULT_DISPLAY_END_CHAR + 1};

        // Display the remaining chars in the alphabet.
        for (char curr_char = new_start_char; curr_char <= END_CHAR; curr_char++)
        {
            std::cout << curr_char;
            int typed_chars_count{(curr_char - new_start_char + 1)};
            bool continue_row{typed_chars_count % new_row_size};
            std::cout << (continue_row ? ' ' : '\n');
        }

        // std::cout << "sizeof(short int): " << sizeof(short int) << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << "Exception: " << e.what() << '\n';
    }

    return 0;
}