#include <iostream>
#include <map>
#include <string>

constexpr int STATISTICS_ARRAY_SIZE{16};

enum class SignalFlag
{
    DGF = 001,
    HEC = 002,
    GER = 004,
    FRS = 010,
};

// std::map<SignalFlag, std::string> SignalName{
//     {SignalFlag::DGF, "DGF"},
//     {SignalFlag::HEC, "HEC"},
//     {SignalFlag::GER, "GER"},
//     {SignalFlag::FRS, "FRS"},
// };

void displayStatistics(int statisticsArray[]);
void displayStatisticsDescending(int statisticsArray[]);

int main()
{
    int statistics[STATISTICS_ARRAY_SIZE] = {
        100,
        101,
        102,
        103,
        104,
        105,
        106,
        107,
        108,
        109,
        110,
        111,
        112,
        113,
        114,
        115,
    };

    displayStatistics(statistics);
    std::cout << "==========================" << std::endl
              << std::endl;
    displayStatisticsDescending(statistics);

    return 0;
}

void displayStatistics(int statisticsArray[])
{
    std::cout << "The following combinations of signals have occurred the corresponding number of times:" << std::endl;
    for (int signalCombinationIndex{0}; signalCombinationIndex < STATISTICS_ARRAY_SIZE; signalCombinationIndex++)
    {
        std::cout << "Combination: ";

        // Determine the names of the signals that make up the combination.
        if (signalCombinationIndex & static_cast<int>(SignalFlag::FRS))
            std::cout << "FRS ";
        if (signalCombinationIndex & static_cast<int>(SignalFlag::GER))
            std::cout << "GER ";
        if (signalCombinationIndex & static_cast<int>(SignalFlag::HEC))
            std::cout << "HEC ";
        if (signalCombinationIndex & static_cast<int>(SignalFlag::DGF))
            std::cout << "DGF ";

        std::cout << "-> " << statisticsArray[signalCombinationIndex] << " times" << std::endl;
    }
}

// Brute force
void displayStatisticsDescending(int statisticsArray[])
{
    for (int numberOfBytes{4}; numberOfBytes > 0; numberOfBytes--)
    {
        std::cout << "Combinations of " << numberOfBytes << " bytes ***********" << std::endl;

        for (int signalCombinationIndex{0}; signalCombinationIndex < STATISTICS_ARRAY_SIZE; signalCombinationIndex++)
        {
            int actualNumberOfBytesWithValue1{0};

            if (signalCombinationIndex & static_cast<int>(SignalFlag::FRS))
                actualNumberOfBytesWithValue1++;
            if (signalCombinationIndex & static_cast<int>(SignalFlag::GER))
                actualNumberOfBytesWithValue1++;
            if (signalCombinationIndex & static_cast<int>(SignalFlag::HEC))
                actualNumberOfBytesWithValue1++;
            if (signalCombinationIndex & static_cast<int>(SignalFlag::DGF))
                actualNumberOfBytesWithValue1++;

            if (actualNumberOfBytesWithValue1 != numberOfBytes)
                continue;

            std::cout << "Combination: ";

            if (signalCombinationIndex & static_cast<int>(SignalFlag::FRS))
                std::cout << "FRS ";
            if (signalCombinationIndex & static_cast<int>(SignalFlag::GER))
                std::cout << "GER ";
            if (signalCombinationIndex & static_cast<int>(SignalFlag::HEC))
                std::cout << "HEC ";
            if (signalCombinationIndex & static_cast<int>(SignalFlag::DGF))
                std::cout << "DGF ";

            std::cout << "-> " << statisticsArray[signalCombinationIndex] << " times" << std::endl;
        }
    }
}
