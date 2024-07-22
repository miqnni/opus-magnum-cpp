#include <iostream>
#include <vector>
#include <string>

const std::string SOUGHT_WORD{"Alabama"};

constexpr int AVAILABLE_ATTEMPTS{10};
constexpr char BLANK_CHAR{'-'};

static_assert(AVAILABLE_ATTEMPTS > 0, "Error: The user should have at least one available attempt.");

enum class GameResult
{
    Defeat = -1,
    Unresolved, // = 0
    Victory,    // = 1
};

int main()
{
    std::vector<char> guessedWord(SOUGHT_WORD.size(), BLANK_CHAR);
    std::vector<char> incorrectGuesses(0);
    GameResult finalResult = GameResult::Unresolved;

    // Empty brace initializes the local variable
    // with zero (appropriate to the type).
    bool gameOver{};
    int roundNo{};

    while (!gameOver)
    {
        std::cout << std::endl
                  << "=== ROUND " << ++roundNo << " ===" << std::endl;
        // Print the current state of the game.
        // - guessed word
        std::cout << "Guessed: ";
        for (size_t i{0}; i < guessedWord.size(); i++)
        {
            std::cout << guessedWord[i];
        }
        std::cout << std::endl;

        // - incorrect guesses
        if (incorrectGuesses.size())
        {
            std::cout << "Incorrect guesses: ";
            for (size_t i{0}; i < incorrectGuesses.size(); i++)
            {
                std::cout << incorrectGuesses[i] << ", ";
            }
            std::cout << std::endl;
        }

        // - hangman status
        std::cout << "Hangman status: ";
        for (size_t i{0}; i < AVAILABLE_ATTEMPTS; i++)
        {
            char barElement = (i < incorrectGuesses.size()) ? 'X' : 'O';
            std::cout << barElement;
        }
        std::cout << std::endl;

        // Ask the user about the letter and check if it is present in
        // the sought word. If it is, change the corresponding
        // vector element to the guessed char.
        char userGuess;
        std::cout << "Your letter: ";
        std::cin >> userGuess;

        // Check if the char from input is a letter.
        if ((userGuess < 'a' || userGuess > 'z') && (userGuess < 'A' || userGuess > 'Z'))
        {
            std::cout << "This is not a letter!" << std::endl;
            continue;
        }

        // Check if the letter has not been used before.
        bool letterNotUsed{true};
        for (size_t i{0}; i < incorrectGuesses.size(); i++)
        {
            if (tolower(incorrectGuesses[i]) == tolower(userGuess))
            {
                letterNotUsed = false;
                break;
            }
        }

        if (letterNotUsed)
        {
            for (size_t i{0}; i < guessedWord.size(); i++)
            {
                if (guessedWord[i] == BLANK_CHAR)
                    continue;

                if (tolower(guessedWord[i]) == tolower(userGuess))
                {
                    letterNotUsed = false;
                    break;
                }
            }
        }

        if (!letterNotUsed)
        {
            std::cout << "This letter has been used before." << std::endl;
            continue;
        }

        // Check if the guess is correct
        bool correctGuess{};
        for (size_t i{0}; i < SOUGHT_WORD.size(); i++)
        {
            if (tolower(SOUGHT_WORD[i]) == tolower(userGuess))
            {
                guessedWord[i] = SOUGHT_WORD[i];
                correctGuess = true;
            }
        }
        if (!correctGuess)
        {
            incorrectGuesses.push_back(toupper(userGuess));
        }

        // Check if the game has ended.
        if (incorrectGuesses.size() >= AVAILABLE_ATTEMPTS)
        {
            gameOver = true;
            finalResult = GameResult::Defeat;
        }

        bool guessedFlag{true};
        for (size_t i{0}; i < guessedWord.size(); i++)
        {
            if (guessedWord[i] == BLANK_CHAR)
            {
                guessedFlag = false;
                break;
            }
        }
        if (guessedFlag)
        {
            gameOver = true;
            finalResult = GameResult::Victory;
        }
    }

    std::string finalResultTxt = (finalResult == GameResult::Victory ? "VICTORY (word: " + SOUGHT_WORD + ")" : "DEFEAT");
    std::cout << "Game over. Result: " << finalResultTxt << std::endl;

    return 0;
}
