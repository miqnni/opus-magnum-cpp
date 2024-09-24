#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <cmath>

// For binary files, use extension .bin (or .dat).
constexpr int arraySize{200};
constexpr int objOutputWidth{18};
const std::string binaryFileName{"array.bin"};

class SampleClass
{
public:
    double db{};
    int in{};
    char ch{};
};

std::ostream &operator<<(std::ostream &out, SampleClass obj)
{
    std::streamsize currWidth = out.width();
    std::streamsize doubleWidth{};
    std::streamsize intWidth{};
    if (currWidth - 9 > 0)
    {
        doubleWidth = ceil((currWidth - 9) / 2.);
        intWidth = floor((currWidth - 9) / 2.);
    }
    out << std::setw(0) << "{"
        << std::setw(doubleWidth) << obj.db << ", "
        << std::setw(intWidth) << obj.in << ", \'"
        << obj.ch << "\'}"; // 8 "decorative" chars total.
    return out;
}

void printArray(SampleClass arr[], int size = arraySize, int cols = 5, std::ostream &out = std::cout)
{
    out << std::setprecision(2) << std::fixed;
    for (int i = 0; i < size; i++)
    {
        out << std::setw(objOutputWidth) << arr[i];
        out << ((i + 1) % cols == 0 ? "\n" : ", ");
    }

    if (size % cols != 0)
        out << "\n";

    out << std::setprecision(6) << std::defaultfloat << std::flush;
}

int main()
{
    SampleClass objArray[arraySize]{};
    for (int i{}; i < arraySize; i++)
    {
        objArray[i].db = i / 100.;
        objArray[i].in = i;
        objArray[i].ch = 'a' + (i % 26);
    }

    // Save the contents of the array to a binary file.
    std::ofstream outfile(binaryFileName, std::ios::out | std::ios::binary);
    outfile.write(reinterpret_cast<char *>(objArray), sizeof(objArray));

    outfile.close();

    // Fill the array with zeros.
    for (int i{}; i < arraySize; i++)
        objArray[i] = {0, 0, 'a'};

    // Ask the user for the index of the array element whose value they want to know.
    int userIndex{-1};
    do
    {
        std::cout << "Select and index [0 - " << arraySize - 1 << "]: ";
        std::cin >> userIndex;
        if (userIndex < 0 || userIndex >= arraySize)
            std::cout << "Incorrect index. Try again." << std::endl;
    } while (userIndex < 0 || userIndex >= arraySize);

    // Find the value in the binary file,
    // insert it into the array
    // and print it (std::cout).
    std::ifstream infile(binaryFileName, std::ios::in | std::ios::binary);
    if (!infile)
    {
        std::cerr << "File open error." << std::endl;
        return 1;
    }

    infile.seekg(userIndex * sizeof(SampleClass));
    if (!infile.read(reinterpret_cast<char *>(&objArray[userIndex]), sizeof(SampleClass)))
    {
        std::cerr << "File read error." << std::endl;
        return 1;
    }
    infile.close();

    printArray(objArray, arraySize);
    if (userIndex >= 0 && userIndex < arraySize)
        std::cout << "Value: " << objArray[userIndex] << std::endl;

    return 0;
}