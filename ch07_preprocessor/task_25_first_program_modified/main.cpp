#include <iostream>

int main()
{
    std::cout << "Welcome aboard!" << std::endl;
    std::cout << "File name: " << __FILE__ << std::endl;
    std::cout << "Current line: " << __LINE__ << std::endl;
    std::cout << "Compilation date: " << __DATE__ << std::endl;
    std::cout << "Compilation time: " << __TIME__ << std::endl;
    std::cout << "C++ compiler used? ";

#ifdef __cplusplus
    std::cout << "YES";
#else
    std::cout << "NO";
#endif // __cplusplus

    std::cout << std::endl;

    return 0;
}