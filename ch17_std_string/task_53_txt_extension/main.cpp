#include <iostream>
#include <string>

std::string txtExtension()
{
    std::string fileName;
    std::cout << "Your file name: ";
    getline(std::cin, fileName, '\n');

    size_t lastDotPos{fileName.rfind('.')};
    if (lastDotPos == std::string::npos)
        return fileName + ".txt";

    fileName.replace(lastDotPos, std::string::npos, ".txt");
    return fileName;
}

int main()
{
    std::string finalFileName(txtExtension());
    std::cout << "Final file name: " << finalFileName << std::endl;

    return 0;
}
