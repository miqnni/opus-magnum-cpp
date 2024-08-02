#include <iostream>
#include <string>
#include <vector>
#include <iomanip>

constexpr int ELEMENT_VALUE_FIELD_WIDTH{4};
constexpr int ROW_INDEX_FIELD_WIDTH{2};

void printVector2D(std::vector<std::vector<int>> vectorToPrint, std::string vectorName);
void resizeBothDimensions(std::vector<std::vector<int>> &vector2D, int newRowCount, int newColumnCount);

// ************************************************

int main()
{
    // **************** SAMPLE 0
    std::vector<std::vector<int>> sample0{
        {84, 32, 28},
        {49, 622, 815},
    };
    printVector2D(sample0, "sample0");
    std::cout << std::endl
              << std::endl;
    // ****************

    // **************** SAMPLE 1
    unsigned long sample1RowCount{4};
    unsigned long sample1ColumnCount{10};

    // All elements are initialized with:
    // - zeros -- for primitive types
    // - class objects where default constructor has been called -- for classes
    std::vector<std::vector<int>> sample1{
        sample1RowCount,                      // How many rows are there?
        std::vector<int>(sample1ColumnCount), // What type are the rows? (here: vectors with `sample1ColumnCount` elements)
    };

    // Assigning some values.
    sample1[1][3] = 40;
    sample1[2][5] = 600;

    printVector2D(sample1, "sample1");

    // Resize
    sample1.resize(5);
    printVector2D(sample1, "sample1 (after increasing the number of rows to 5)");

    for (auto &currentVectorRow : sample1)
    {
        currentVectorRow.resize(4);
    }
    printVector2D(sample1, "sample1 (after setting each row's size to 4)");

    sample1.resize(7);
    printVector2D(sample1, "sample1 (after increasing the number of rows to 7)");

    sample1[3].push_back(81);
    printVector2D(sample1, "sample1 (after adding an element to row 3)");

    sample1.resize(8);
    printVector2D(sample1, "sample1 (after increasing the number of rows to 8)");

    resizeBothDimensions(sample1, 10, 6);
    printVector2D(sample1, "sample1 (after resizing both dimensions with a function)");

    sample1[8].pop_back();
    printVector2D(sample1, "sample1 (after popping back from row 8)");
    // ****************

    return 0;
}

// ************************************************

void printVector2D(std::vector<std::vector<int>> vectorToPrint, std::string vectorName)
{
    std::cout << "VECTOR `" << vectorName << "` (" << vectorToPrint.size() << " rows)" << std::endl;

    for (int currentVectorRowIndex{}; currentVectorRowIndex < vectorToPrint.size(); currentVectorRowIndex++)
    {
        std::cout << "Row " << std::setw(ROW_INDEX_FIELD_WIDTH) << currentVectorRowIndex << ": | ";
        for (int currentVectorColumn{}; currentVectorColumn < vectorToPrint[currentVectorRowIndex].size(); currentVectorColumn++)
        {
            std::cout << std::setw(ELEMENT_VALUE_FIELD_WIDTH) << vectorToPrint[currentVectorRowIndex][currentVectorColumn] << " | ";
        }
        std::cout << " (" << vectorToPrint[currentVectorRowIndex].size() << " columns)" << std::endl;
    }
    std::cout << std::endl;
}

void resizeBothDimensions(std::vector<std::vector<int>> &vector2D, int newRowCount, int newColumnCount)
{
    vector2D.resize(newRowCount);
    for (auto &currentVectorRow : vector2D)
    {
        currentVectorRow.resize(newColumnCount);
    }
}
