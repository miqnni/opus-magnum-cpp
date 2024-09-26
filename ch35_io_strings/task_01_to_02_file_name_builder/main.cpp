#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <iomanip>

const std::string repetitiveFileContent{
    R"(Results:
    A .......... 5/5
    B .......... 4/4
    C .......... 5/5
    D .......... 5/5
    E .......... 3/3
DONE)"};

bool report(int sampleNo, int massNo, std::string isotope);

int main()
{
    report(0, 238, "uranium");
    report(1, 129, "some random   and  kinda      arbitrary     element");
    report(2, 0, "");
    report(2004, 2, "deuterium");

    return 0;
}

// File names:
// V1: report_< 4-digit sample number >_of_reaction_< 3-digit mass number >_< isotope name >.txt
// V2: report_< 4-digit sample number >_< isotope name >_< 3-digit mass number >.txt
bool report(int sampleNo, int massNo, std::string isotope)
{
    // Replace any whitespace sequences with '_' in the isotope name.
    std::istringstream isotopeIn(isotope);
    std::ostringstream isotopeOut;

    std::string currentIsotopePart;
    isotopeIn >> currentIsotopePart;
    isotopeOut << currentIsotopePart;

    while (isotopeIn >> currentIsotopePart)
    {
        isotopeOut << "_" << currentIsotopePart;
    }

    std::string isotopeNameInFile{isotopeOut.str()};

    std::ostringstream fileNameStream;

    // Create the file names.
    fileNameStream << "report_" << std::setfill('0') << std::setw(4) << sampleNo << "_of_reaction_" << std::setw(3) << massNo << "_" << isotopeNameInFile << ".txt" << std::flush;
    if (!fileNameStream)
    {
        std::cout << "File A name construction error!";
        return false;
    }
    std::string fileNameA{fileNameStream.str()};

    fileNameStream.str(""); // Clear the ostringstream.
    fileNameStream << "report_" << std::setfill('0') << std::setw(4) << sampleNo << "_" << isotopeNameInFile << "_" << std::setw(3) << massNo << ".txt" << std::flush;
    if (!fileNameStream)
    {
        std::cout << "File B name construction error!";
        return false;
    }
    std::string fileNameB{fileNameStream.str()};

    // Create the files and print the proper content inside them.
    std::ofstream fileA(fileNameA);
    std::ofstream fileB(fileNameB);

    if (!fileA)
    {
        std::cout << "File A open error!";
        return false;
    }

    if (!fileB)
    {
        std::cout << "File B open error!";
        return false;
    }

    std::ostringstream customFileContent;
    customFileContent << "Element (isotope): " << isotopeNameInFile
                      << "\nMass number: " << massNo
                      << "\nSample number: " << sampleNo << "\n"
                      << std::string(12, '-') << "\n";

    fileA << customFileContent.str() << repetitiveFileContent;
    fileB << customFileContent.str() << repetitiveFileContent;

    if (!fileA)
    {
        std::cout << "File A output error!";
        return false;
    }

    if (!fileB)
    {
        std::cout << "File B output error!";
        return false;
    }

    // fileA.close();
    // fileB.close();

    return true;
}
