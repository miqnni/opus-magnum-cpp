#include <iostream>
#include <string>

std::string analyze_file_name(
    const std::string fileName,
    const std::string soughtExtension = std::string("poly"),
    const std::string soughtFragment = std::string("_polygon_"))
{
    const size_t extensionWithDotSize{soughtExtension.size() + 1};
    if (fileName.size() < extensionWithDotSize)
        return std::string("");

    const size_t lastDotPos{fileName.rfind('.')};
    if (lastDotPos == std::string::npos)
        return std::string("");

    if (fileName.substr(lastDotPos) != "." + soughtExtension)
        return std::string("");

    const size_t lastSoughtFragmentPos{fileName.rfind(soughtFragment)};
    if (lastSoughtFragmentPos == std::string::npos)
        return std::string("");

    const size_t finalSubstringStart{lastSoughtFragmentPos + soughtFragment.size()};

    // `+ 1` due to a dot in the extension
    const size_t finalSubstringSize{fileName.size() - finalSubstringStart - extensionWithDotSize};

    return fileName.substr(finalSubstringStart, finalSubstringSize);
}

int main()
{
    std::cout << "Result: " << analyze_file_name(std::string("matrix_zet_vs_aoq_polygon_cr54")) << std::endl;
    std::cout << "Result: " << analyze_file_name(std::string("matrix_zet_vs_aoq_polygon_cr54.exe")) << std::endl;
    std::cout << "Result: " << analyze_file_name(std::string("matrix_zet_vs_aoq_HEXAGON_cr54.poly")) << std::endl;
    std::cout << "Result: " << analyze_file_name(std::string("matrix_zet_vs_aoq_polygon_cr54.poly")) << std::endl;
    return 0;
}
