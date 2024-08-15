#include <iostream>
#include <string>

int main()
{
    std::string userName;
    std::string userPlaceOfBirth;
    std::string userDescription;

    std::cout << "Type in your name and press Enter." << std::endl;
    getline(std::cin, userName);

    std::cout << "Type in the place (e.g. city) of your birth and press Enter." << std::endl;
    getline(std::cin, userPlaceOfBirth);

    std::cout << "Provide a description of your personality.\nEnd your description with \'#\' and then press Enter." << std::endl;
    getline(std::cin, userDescription, '#');

    std::cout << "1) Name" << std::endl;
    std::cout << userName << std::endl;
    std::cout << "2) Place of birth" << std::endl;
    std::cout << userPlaceOfBirth << std::endl;
    std::cout << "3) Description" << std::endl;
    std::cout << userDescription << std::endl;

    return 0;
}