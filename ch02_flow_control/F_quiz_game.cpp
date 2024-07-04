#include <iostream>
#include <cstdlib>
#include <string>
#include <map>
#include <cctype> // toupper()

constexpr int OPTIONS_PER_QUESTION = 4;
constexpr int STARTING_Q_NO = 1;

enum question_status
{
    NOT_ANSWERED = -1,
    INCORRECT = 0,
    CORRECT = 1
};

enum grade
{
    GRADE_A,
    GRADE_B,
    GRADE_C,
    GRADE_F
};

std::map<grade, double> required_score_for_grade = {
    {GRADE_A, 0.91},
    {GRADE_B, 0.81},
    {GRADE_C, 0.71},
    {GRADE_F, 0.00},
};

struct quiz_question
{
    std::string question;
    std::string options[OPTIONS_PER_QUESTION];
    int correct_ans_idx;
    int points;
    question_status status;
};

quiz_question quiz_questions[] = {
    {
        "In which country is the city \"Katowice\" located?",
        {
            "Poland",
            "Germany",
            "Czech Republic",
            "Slovakia",
        },
        0,
        1,
        NOT_ANSWERED,
    },
    {
        "In which country is the city \"Bergen\" located?",
        {
            "Sweden",
            "Finland",
            "Denmark",
            "Norway",
        },
        3,
        1,
        NOT_ANSWERED,
    },
    {
        "In which country is the city \"Santiago\" located?",
        {
            "Brazil",
            "Chile",
            "Spain",
            "Portugal",
        },
        1,
        1,
        NOT_ANSWERED,
    },
    {
        "In which country is the city \"Paris\" located?",
        {
            "Germany",
            "France",
            "Belgium",
            "The Netherlands",
        },
        1,
        1,
        NOT_ANSWERED,
    },
    {
        "In which country is the city \"Auckland\" located?",
        {
            "UK",
            "USA",
            "New Zealand",
            "Australia",
        },
        2,
        1,
        NOT_ANSWERED,
    },
    {
        "In which country is the city \"Luzern\" located?",
        {
            "Austria",
            "Switzerland",
            "France",
            "Italy",
        },
        1,
        1,
        NOT_ANSWERED,
    },
    {
        "In which country is the city \"Dublin\" located?",
        {
            "UK",
            "USA",
            "Canada",
            "Ireland",
        },
        3,
        2,
        NOT_ANSWERED,
    },
    {
        "In which country is the city \"Edmonton\" located?",
        {
            "UK",
            "USA",
            "Canada",
            "Ireland",
        },
        2,
        1,
        NOT_ANSWERED,
    },
};

int main()
{
    int user_points;
    int max_points;
    int q_no; // Question number

    bool playing = true;
    while (playing)
    {
        user_points = 0;
        max_points = 0;
        q_no = STARTING_Q_NO;

        // Welcome message
        std::cout << "=== QUIZ GAME ===" << std::endl;
        std::cout << "Answer each question using one letter, e.g. \'A\'." << std::endl;
        std::cout << "=================\n"
                  << std::endl;

        // We use `&curr_question` instead of `curr_question`,
        // because `curr_question` (without an ampersand) would make a copy
        // of each object in the array `quiz_question`. Using a reference
        // (`&curr_question`) allows us to update the objects, namely
        // change the status of each question depending on whether the user's
        // answer is correct or not.
        for (quiz_question &curr_question : quiz_questions)
        {
            // Print the contents of the current question.
            std::cout << "Q" << q_no++ << ": " << curr_question.question << " (" << curr_question.points << " pts)" << std::endl;
            for (int opt_no = 0; opt_no < OPTIONS_PER_QUESTION; opt_no++)
            {
                char opt_letter_symbol = 'A' + opt_no;
                std::cout << "\t" << opt_letter_symbol << ". " << curr_question.options[opt_no] << std::endl;
            }

            // Get the user's answer.
            char user_ans;
            do
            {
                std::cout << "Your answer (A/.../" << (char)('A' + OPTIONS_PER_QUESTION - 1) << "): ";
                std::cin >> user_ans;
                user_ans = toupper(user_ans);
            } while (!('A' <= user_ans && user_ans < 'A' + OPTIONS_PER_QUESTION));

            // Check if the user's answer is correct.
            int user_ans_idx = (int)(user_ans - 'A');
            if (user_ans_idx == curr_question.correct_ans_idx)
            {
                curr_question.status = CORRECT;
                user_points += curr_question.points;
                std::cout << "Correct\n"
                          << std::endl;
            }
            else
            {
                curr_question.status = INCORRECT;
                std::cout << "Incorrect. Expected answer: " << (char)('A' + curr_question.correct_ans_idx) << std::endl;
            }

            max_points += curr_question.points;
        }

        // Print final results.
        std::cout << "RESULTS: " << std::endl;
        q_no = STARTING_Q_NO;
        for (quiz_question curr_question : quiz_questions)
        {
            std::cout << "\tQ" << q_no++ << ": " << ((curr_question.status == CORRECT) ? curr_question.points : 0) << "/" << curr_question.points << std::endl;
        }
        double final_score = (double)user_points / (double)max_points;
        std::cout << "Total score: " << (double)user_points << "/" << (double)max_points << " (" << final_score * 100 << "%)" << std::endl;

        grade final_grade;

        if (final_score >= required_score_for_grade[GRADE_A])
            final_grade = GRADE_A;
        else if (final_score >= required_score_for_grade[GRADE_B])
            final_grade = GRADE_B;
        else if (final_score >= required_score_for_grade[GRADE_C])
            final_grade = GRADE_C;
        else
            final_grade = GRADE_F;

        char grade_symbol;
        switch (final_grade)
        {
        case GRADE_A:
            grade_symbol = 'A';
            break;
        case GRADE_B:
            grade_symbol = 'B';
            break;
        case GRADE_C:
            grade_symbol = 'C';
            break;
        default:
            grade_symbol = 'F';
            break;
        }
        std::cout << "Grade: " << grade_symbol << std::endl;

        // An option to play again
        char play_again_status;
        do
        {
            std::cout << "Play again? (Y/N): ";
            std::cin >> play_again_status;
            play_again_status = toupper(play_again_status);

            if (play_again_status == 'N')
                playing = false;
        } while (play_again_status != 'Y' && play_again_status != 'N');

        std::cout << std::endl;
    }

    std::cout << "Thanks for playing!" << std::endl;
    system("pause");

    return 0;
}
