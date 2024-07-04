#include <iostream>
#include <cmath> // std::floor()
#include <string>
#include <map>

int main()
{
    double exam_score;

    // Create a map of grades (string keys)
    // and the required score to get these grades (double values).
    std::map<std::string, double> min_score_for_grade = {
        {"excellent", 1.00},
        {"very good", 0.86},
        {"acceptable", 0.71},
    };

    std::cout << "Type in your exam score (0.00 - 1.00): ";
    std::cin >> exam_score;

    // Truncate the exam score to the 2nd decimal place.
    double exam_score_truncated = std::floor(exam_score * 100.) / 100.;
    std::string final_grade;
    bool passed = false;
    if (exam_score_truncated >= min_score_for_grade["excellent"])
    {
        final_grade = "excellent";
        passed = true;
    }
    else if (exam_score_truncated >= min_score_for_grade["very good"])
    {
        final_grade = "very good";
        passed = true;
    }
    else if (exam_score_truncated >= min_score_for_grade["acceptable"])
    {
        final_grade = "acceptable";
        passed = true;
    }
    else
        final_grade = "unsatisfactory";

    // Print the exam results.
    std::cout << "Your final grade: " << final_grade << " (score: " << exam_score_truncated << ")" << std::endl;
    if (passed)
        std::cout << "You have passed the exam." << std::endl;
    else
        std::cout << "You have not passed the exam." << std::endl;

    return 0;
}
