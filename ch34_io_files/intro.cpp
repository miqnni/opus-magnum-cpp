#include <iostream>
#include <fstream>

int main()
{
    std::ofstream fileOut;
    fileOut.open("./result.txt");
    // OR: std::ofstream fileOut("./result.txt");

    fileOut << "Mission Complete!";
    fileOut.close();

    return 0;
}
