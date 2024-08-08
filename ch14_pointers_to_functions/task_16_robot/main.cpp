#include <iostream>
#include <vector>

bool armBend();
bool forearmBend();
bool wristBend();
bool armTurn();
bool forearmTurn();
bool wristTurn();

// ************************************************

int main()
{
    std::vector<bool (*)()> robotInstructions;

    bool shouldRun{true};
    for (int instructionNo{}; shouldRun; instructionNo++)
    {
        char userChoice{};
        std::cout << "==========================" << std::endl;
        std::cout << "SELECT AN INSTRUCTION #" << instructionNo << " FOR THE ROBOT." << std::endl;
        std::cout << "-\t1\tBend the arm." << std::endl;
        std::cout << "-\t2\tBend the forearm." << std::endl;
        std::cout << "-\t3\tBend the wrist." << std::endl;
        std::cout << "-\t4\tTurn the arm." << std::endl;
        std::cout << "-\t5\tTurn the forearm." << std::endl;
        std::cout << "-\t6\tTurn the wrist." << std::endl;
        std::cout << "-\tX\tExecute all the selected instructions." << std::endl;
        std::cout << "-\tE\tExit the program." << std::endl;
        std::cout << "==========================" << std::endl;
        std::cout << "Your choice: ";
        std::cin >> userChoice;

        switch (userChoice)
        {
        case '1':
            robotInstructions.push_back(&armBend);
            break;
        case '2':
            robotInstructions.push_back(&forearmBend);
            break;
        case '3':
            robotInstructions.push_back(&wristBend);
            break;
        case '4':
            robotInstructions.push_back(&armTurn);
            break;
        case '5':
            robotInstructions.push_back(&forearmTurn);
            break;
        case '6':
            robotInstructions.push_back(&wristTurn);
            break;
        case 'X':
            for (bool (*robotInstruction)() : robotInstructions)
                robotInstruction();
            robotInstructions.clear();
            break;
        case 'E':
            shouldRun = false;
            break;
        default:
            std::cout << "Incorrect instruction." << std::endl;
            break;
        };
    }

    std::cout << std::endl;
    return 0;
}

// ************************************************

bool armBend()
{
    std::cout << "arm bend" << std::endl;
    return true;
}

// ************************************************

bool forearmBend()
{
    std::cout << "forearm bend" << std::endl;
    return true;
}

// ************************************************

bool wristBend()
{
    std::cout << "wrist bend" << std::endl;
    return true;
}

// ************************************************

bool armTurn()
{
    std::cout << "arm turn" << std::endl;
    return true;
}

// ************************************************

bool forearmTurn()
{
    std::cout << "forearm turn" << std::endl;
    return true;
}

// ************************************************

bool wristTurn()
{
    std::cout << "wrist turn" << std::endl;
    return true;
}
