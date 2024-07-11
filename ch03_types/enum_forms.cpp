#include <iostream>
#include <cstdlib>

using Grade = long;
using LevelStatus = int;

enum : Grade
{
    SCORE_FRAGILE = -50,
    SCORE_VERY_BAD = -25,
    SCORE_POOR_EFFORT = 10,
    SCORE_NORMAL_EFFORT = 55,
    SCORE_GOOD_EFFORT = 80,
    SCORE_VERY_GOOD_EFFORT = 91,
    SCORE_CLEAR = 100,
};

// The above `enum` without a name means the same as writing:
// constexpr Grade SCORE_FRAGILE = -50;
// constexpr Grade SCORE_VERY_BAD = -25;
// constexpr Grade SCORE_POOR_EFFORT = 10;
// constexpr Grade SCORE_NORMAL_EFFORT = 55;
// constexpr Grade SCORE_GOOD_EFFORT = 80;
// constexpr Grade SCORE_VERY_GOOD_EFFORT = 91;
// constexpr Grade SCORE_CLEAR = 100;

// Good practice: scoped enum (defined using `enum class` or `enum struct`)
enum class Tcontest_results : Grade
// enum struct Tcontest_results : Grade // Alternative option
{
    fragile = SCORE_FRAGILE,
    very_bad = SCORE_VERY_BAD,
    poor_effort = SCORE_POOR_EFFORT,
    normal_effort = SCORE_NORMAL_EFFORT,
    good_effort = SCORE_GOOD_EFFORT,
    very_good_effort = SCORE_VERY_GOOD_EFFORT,
    clear = SCORE_CLEAR,
};

// Not-so-good practice: plain enum (defined using `enum` -- without `class`)
enum Tlevel_status : LevelStatus
{
    not_started,
    started,
    midway_point = 50,
    halfway_through = midway_point,
    almost_there = 99,
    complete,
    clear = complete + 6,
};

int main()
{
    // `Tcontest_results::` required.
    Tcontest_results contest_grade = Tcontest_results::poor_effort;

    // No `Tlevel_status::` required, but greater risk of name conflict.
    Tlevel_status level_completion_status = not_started;

    Grade user_score;
    std::cout << "Your score (range: [-50, 100]): ";
    std::cin >> user_score;

    try
    {
        if (user_score >= SCORE_FRAGILE && user_score < SCORE_VERY_BAD)
            contest_grade = Tcontest_results::fragile;
        else if (user_score >= SCORE_VERY_BAD && user_score < SCORE_POOR_EFFORT)
            contest_grade = Tcontest_results::very_bad;
        else if (user_score >= SCORE_POOR_EFFORT && user_score < SCORE_NORMAL_EFFORT)
            contest_grade = Tcontest_results::poor_effort;
        else if (user_score >= SCORE_NORMAL_EFFORT && user_score < SCORE_GOOD_EFFORT)
            contest_grade = Tcontest_results::normal_effort;
        else if (user_score >= SCORE_GOOD_EFFORT && user_score < SCORE_VERY_GOOD_EFFORT)
            contest_grade = Tcontest_results::good_effort;
        else if (user_score >= SCORE_VERY_GOOD_EFFORT && user_score < SCORE_CLEAR)
            contest_grade = Tcontest_results::very_good_effort;
        else if (user_score == SCORE_CLEAR)
            contest_grade = Tcontest_results::clear;
        else
            throw(user_score);
    }
    catch (Grade wrong_value)
    {
        std::cout << "Wrong value was provided: " << wrong_value << std::endl;
        exit(EXIT_FAILURE);
    }

    std::cout << "[CONTEST RESULTS] ";
    switch (contest_grade)
    {
    case Tcontest_results::fragile:
        std::cout << "Your family must be ashamed of your level of incompetence." << std::endl;
        level_completion_status = started;
        break;
    case Tcontest_results::normal_effort:
        std::cout << "Lucky you! Your effort is noticeable -- at least to some extent." << std::endl;
        level_completion_status = halfway_through;
        break;
    case Tcontest_results::good_effort:
        std::cout << "Wow, you must be really average." << std::endl;
        level_completion_status = almost_there;
        break;
    case Tcontest_results::very_good_effort:
        std::cout << "Now you can say you have achieved something." << std::endl;
        level_completion_status = complete;
        break;
    case Tcontest_results::clear:
        std::cout << "Full clear." << std::endl;
        level_completion_status = clear;
        break;
    default:
        std::cout << "That was not a good attempt." << std::endl;
        level_completion_status = started;
        break;
    }

    Grade threshold_reached = static_cast<Grade>(contest_grade);
    Grade level_completion_status_value = static_cast<LevelStatus>(level_completion_status);
    std::cout << "Threshold reached [points]: " << threshold_reached << std::endl;
    std::cout << "Level completion status: " << level_completion_status_value << "% (max. possible: 106%)" << std::endl;

    return 0;
}
