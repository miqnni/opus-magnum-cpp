#include <iostream>
#include <string>
#include <vector>

std::string nextStop(size_t nextStopNumber)
{
    static std::vector<std::string> stopList{
        "Start",
        "Stop One",
        "Stop Two",
        "Stop Three",
        "Stop Four",
        "Stop Five",
    };

    if (nextStopNumber < stopList.size())
        return "Next stop: " + stopList[nextStopNumber];

    return "(no next stop)";
}

int main()
{
    std::cout << nextStop(3) << std::endl;

    return 0;
}