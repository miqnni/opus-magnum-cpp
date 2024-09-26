#include "helper.h"
#include <iostream>
#include <fstream> // TASK 21

int main()
{
    double omega = 0;
    double beta = 0;
    double newPar = 0;

    // TASK 21 (start)
    const std::string fileName{"parameters.txt"};
    std::ifstream parametersTxt(fileName);
    try
    {
        if (!parametersTxt)
            throw std::runtime_error("unable to open " + fileName);
    }
    catch (std::runtime_error &e)
    {
        std::cout << "Error while opening the file: " << e.what() << std::endl;
    }
    // TASK 21 (end)

    try
    {
        omega = strhelper::loadParameter(parametersTxt, "omega");
        std::cout << "Correctly loaded parameter: omega = " << omega << std::endl;

        beta = SH::loadParameter(parametersTxt, "BetA");
        std::cout << "Correctly loaded parameter: beta = " << beta << std::endl;
    }
    catch (SH::KeywordException &k)
    {
        std::cout << k.message << std::endl;
        std::cout << "Tip: add this keyword (and its value) to the content"
                     " of the string 'parametersTxt' "
                  << std::endl;
        return 1;
    }
    catch (SH::ValueException &k)
    {
        std::cout << k.message << std::endl;
        std::cout << "Tip: write the number after this keyword in a better way in the "
                     "string 'parametersTxt' "
                  << std::endl;
        throw;
    }
    catch (...)
    {
        std::cout << "An unknown exception has been caught. Terminating the program." << std::endl;
        throw;
    }

    std::cout << "Trying to read a parameter that may be absent..." << std::endl;
    newPar = SH::loadOptionalParameter(parametersTxt, "newPar", 22);
    std::cout << "Newly set newPar = " << newPar << std::endl;

    parametersTxt.close(); // TASK 21
}
