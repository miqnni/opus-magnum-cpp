#include <iostream>
#include <vector>

bool moreThan(int number, int comparedTo)
{
    return number > comparedTo;
}

bool moreThan51(int number)
{
    return moreThan(number, 51);
}

using ConditionFunction = decltype(&moreThan51); // bool (*)(int)

int sumIf(std::vector<int> numbers, ConditionFunction condition)
{
    int finalSum{};
    for (const auto &el : numbers)
    {
        if (condition(el))
            finalSum += el;
    }
    return finalSum;
}
int countIf(std::vector<int> numbers, ConditionFunction condition)
{
    int finalCount{};
    for (const auto &el : numbers)
    {
        if (condition(el))
            finalCount++;
    }
    return finalCount;
}

int main()
{
    std::vector<int> sample{26, 54, 34, 100, 96, 91, 30, 19, 55, 76, 81, 86, 51, 85};
    std::cout << "sumIf(sample, &moreThan51): " << sumIf(sample, &moreThan51) << std::endl;
    std::cout << "countIf(sample, &moreThan51): " << countIf(sample, &moreThan51) << std::endl;

    return 0;
}