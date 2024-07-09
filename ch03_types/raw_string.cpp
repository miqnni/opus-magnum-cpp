#include <iostream>

int main()
{
    std::cout << "NORMAL STRINGS" << std::endl;
    std::cout << "Path to \"file.cpp\":\nC:\\projects\\project\\file.cpp\n";
    std::cout << "Path to my file (\"file.cpp\"):\nC:\\projects\\project\\file.cpp\n";

    std::cout << std::endl;
    std::cout << "RAW STRINGS" << std::endl;
    std::cout << R"(Path to "file.cpp":
C:\projects\project\file.cpp
)";
    // Custom delimiter
    std::cout << R"custom_delimiter(Path to my file ("file.cpp"):
C:\projects\project\file.cpp
)custom_delimiter";
    return 0;
}