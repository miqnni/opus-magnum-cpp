#include <iostream>
#include <string>

int main()
{
    // Recommended method of string initialization
    std::string deviceA{"Camera"};

    // Older (not recommended) method of string initialization
    std::string deviceB("Flashlight");

    // Get player name (ONLY ONE WORD.
    std::string playerName;
    std::cout << "Player name: ";
    std::cin >> playerName;

    // Display the welcome message, according
    // to the name typed.
    if (playerName == "admin")
    {
        std::cout << "HELLO ADMIN!" << std::endl;
    }
    std::string welcomeMessage;
    welcomeMessage = "Welcome! Your name: " + playerName;
    std::cout << welcomeMessage << std::endl;

    if (playerName != "admin")
    {
        std::cout << "(You are an ordinary user.)" << std::endl;
    }

    // Selecting the device that is first in the alphabetical order.
    std::string chosenDevice{(deviceA < deviceB) ? deviceA : deviceB};

    // Print the messages "Checking if <device name> works...".
    std::string checkingIfPrefix;
    std::string checkingIfSuffix;
    checkingIfPrefix = "Checking if ";
    checkingIfSuffix = " works...";
    std::cout << checkingIfPrefix << chosenDevice << checkingIfSuffix << std::endl;
    std::cout << checkingIfPrefix << deviceB << checkingIfSuffix << std::endl;
    std::cout << "OK!" << std::endl;

    // Display loading progress of chosenDevice.
    std::string loadingBar;
    for (int i = 0; i <= 100; i += 10)
    {
        std::string iTxt = std::to_string(i);
        std::string loadingProgress = chosenDevice + " loading... " + iTxt + "%";

        std::cout << loadingProgress << std::endl;
        loadingBar += "OO";
    }

    // Display the string that was being appended.
    std::cout << "Full loading bar" << std::endl

              << loadingBar << std::endl
              << std::endl;

    // Alert message that will be put into a frame.
    std::string alertMessage = "READY!";

    // Display alert frame.
    int frameWidth = alertMessage.size() + 8;
    std::string alertFrameHorizontalPart(frameWidth, '=');
    std::string alertFullBlock = alertFrameHorizontalPart + '\n';
    alertFullBlock += "||| " + alertMessage + " |||\n";
    alertFullBlock += alertFrameHorizontalPart;

    std::cout << alertFullBlock << std::endl;

    return 0;
}
