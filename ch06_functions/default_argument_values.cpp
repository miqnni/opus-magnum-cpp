#include <iostream>

void grade(double score, int displayForm = 2);

int defaultShortTestWeight{3};

void chapterCompleteScore(
    double taskScore,
    double shortTestScore,
    double projectScore,
    double testScore,
    double taskWeight = 1,
    double shortTestWeight = defaultShortTestWeight,
    double projectWeight = 2,
    double testWeight = defaultShortTestWeight + 1);

// ************************************************

int main()
{
    grade(0.55, 2);
    grade(0.325, 0);
    grade(0.76856, 0);
    grade(1.00, 1);
    grade(0.75, 6);
    grade(0.6667);

    double myTaskScore{0.55};
    double myShortTestScore{0.80};
    double myProjectScore{0.76};
    double myTestScore{0.93};

    chapterCompleteScore(myTaskScore, myShortTestScore, myProjectScore, myTestScore);
    chapterCompleteScore(myTaskScore, myShortTestScore, myProjectScore, myTestScore, 2);
    chapterCompleteScore(myTaskScore, myShortTestScore, myProjectScore, myTestScore, 2, 3, 1);
    chapterCompleteScore(myTaskScore, myShortTestScore, myProjectScore, myTestScore, 1, 2, 4, 3);

    return 0;
}

// ************************************************

void grade(double score, int displayForm)
{
    std::cout << "Your grade: ";

    switch (displayForm)
    {
    case 0:
        std::cout << score * 100 << "/100";
        break;
    case 1:
        std::cout << score * 3 << "/3";
        break;
    case 2:
        std::cout << score * 5 << "/5";
        break;
    default:
        std::cout << score;
        break;
    }
    std::cout << std::endl;
}

void chapterCompleteScore(
    double taskScore,
    double shortTestScore,
    double projectScore,
    double testScore,
    double taskWeight,
    double shortTestWeight,
    double projectWeight,
    double testWeight)
{
    double chapterScore{((taskScore * taskWeight) + (shortTestScore * shortTestWeight) + (projectScore * projectWeight) + (testScore * testWeight)) / (taskWeight + shortTestWeight + projectWeight + testWeight)};
    std::cout << "Your score: " << chapterScore << std::endl;
}