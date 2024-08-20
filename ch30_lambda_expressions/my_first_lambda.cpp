#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm> // std::count_if

int main()
{
    std::vector<int> examResults{36, 49, 98, 83, 51, 55, 86, 85, 76, 25, 66, 75};

    std::vector<int>::iterator iVectorStart = examResults.begin();
    std::vector<int>::iterator iVectorEnd = examResults.end();

    std::map<char, int> gradeCount;

    int minScoreForB{84};
    int minScoreForA{91};
    gradeCount['B'] = std::count_if(
        iVectorStart,
        iVectorEnd,
        // LAMBDA
        [minScoreForB, minScoreForA](int x)
        { return x >= minScoreForB && x < minScoreForA; }
        // ^ LAMBDA
    );

    std::cout << "gradeCount['B']: " << gradeCount['B'] << std::endl;

    return 0;
}
