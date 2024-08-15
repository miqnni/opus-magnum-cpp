#include <iostream>
#include <string>
#include <iomanip> // std::setw()

std::string removeFileExtension(std::string fileName)
{
    // Equal to the number of chars in the file name
    // without the last dot and anything afterwards.
    size_t lastDotPosition{fileName.rfind('.')};

    // If the character is not found,
    // `rfind` returns `npos`.

    return fileName.substr(0, lastDotPosition);
}

int main()
{
    std::string sampleFileName("reservation_february.2024-07.data");
    std::string extensionRemoved(removeFileExtension(sampleFileName));
    std::cout << std::setw(40) << sampleFileName << " ---> " << extensionRemoved << std::endl;

    std::string noDotFileName("Makefile");
    std::cout << std::setw(40) << noDotFileName << " ---> " << removeFileExtension(noDotFileName) << std::endl;

    std::string beginningWithLastDot(".gitignore");
    std::cout << std::setw(40) << beginningWithLastDot << " ---> " << removeFileExtension(beginningWithLastDot) << std::endl;

    return 0;
}