#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

// For binary files, use extension .bin (or .dat).
constexpr int arraySize{200};
const std::string binaryFileName{"array.bin"};

void printArray(double arr[], int size = arraySize, int cols = 10, std::ostream &out = std::cout)
{
    out << std::setprecision(2) << std::fixed;
    for (int i = 0; i < size; i++)
    {
        out << std::setw(6) << arr[i];
        out << ((i + 1) % cols == 0 ? "\n" : ", ");
    }

    if (size % cols != 0)
        out << "\n";

    out << std::setprecision(6) << std::defaultfloat << std::flush;
}

int main()
{
    double doubleArray[arraySize]{};
    for (int i{}; i < arraySize; i++)
        doubleArray[i] = i / 100.;

    // Save the contents of the array to a binary file.
    std::ofstream outfile(binaryFileName, std::ios::out | std::ios::binary);
    // for (int i{}; i < arraySize; i++)
    //     outfile.write(reinterpret_cast<char *>(&doubleArray[i]), sizeof(double));
    outfile.write(reinterpret_cast<char *>(doubleArray), sizeof(doubleArray));

    outfile.close();

    // Fill the array with zeros.
    for (int i{}; i < arraySize; i++)
        doubleArray[i] = 0;

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

    infile.seekg(userIndex * sizeof(double));
    if (!infile.read(reinterpret_cast<char *>(&doubleArray[userIndex]), sizeof(double)))
    {
        std::cerr << "File read error." << std::endl;
        return 1;
    }
    infile.close();

    printArray(doubleArray, arraySize);
    if (userIndex >= 0 && userIndex < arraySize)
        std::cout << "Value: " << doubleArray[userIndex] << std::endl;

    return 0;
}