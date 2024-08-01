#include <iostream>

enum class Tgrade
{
    Fragile,
    Weak,
    Acceptable,
    Good,
    Exemplary
};

void printFinalGrades(Tgrade finalGrades[], int finalGradesSize);

int main()
{
    const int courseParticipantCount{6};
    Tgrade participantFinalGrade[courseParticipantCount] = {Tgrade::Acceptable, Tgrade::Acceptable, Tgrade::Exemplary};

    participantFinalGrade[2] = Tgrade::Good;
    participantFinalGrade[4] = Tgrade::Exemplary;

    printFinalGrades(participantFinalGrade, courseParticipantCount);

    return 0;
}

void printFinalGrades(Tgrade finalGrades[], int finalGradesSize)
{
    for (int i{}; i < finalGradesSize; i++)
    {
        std::cout << "Student #" << i << ": ";
        int gradeStarCount{static_cast<int>(finalGrades[i])};
        for (int j{}; j < gradeStarCount; j++)
        {
            std::cout << "*";
        }
        for (int j{gradeStarCount}; j < static_cast<int>(Tgrade::Exemplary); j++)
        {
            std::cout << "-";
        }
        std::cout << std::endl;
    }
}
