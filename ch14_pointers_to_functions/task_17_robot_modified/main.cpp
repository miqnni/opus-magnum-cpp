#include <iostream>
#include <vector>

bool armBend(double degrees);
bool forearmBend(double degrees);
bool wristBend(double degrees);
bool armTurn(double degrees);
bool forearmTurn(double degrees);
bool wristTurn(double degrees);

struct Instruction
{
    bool (*operation)(double);
    double degrees;
};

// ************************************************

int main()
{
    std::vector<Instruction> robotInstructions;

    bool (*possibleInstructions[6])(double){&armBend, &forearmBend, &wristBend, &armTurn, &forearmTurn, &wristTurn};

    bool shouldRun{true};
    for (int instructionNo{}; shouldRun; instructionNo++)
    {
        char userChoice{};
        double numberOfDegrees{};
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

        if (userChoice >= '1' && userChoice <= '6')
        {
            std::cout << "Degrees: ";
            std::cin >> numberOfDegrees;
            Instruction newInstruction{
                possibleInstructions[userChoice - '1'],
                numberOfDegrees,
            };
            robotInstructions.push_back(newInstruction);
        }

        switch (userChoice)
        {
        case '1':
        case '2':
        case '3':
        case '4':
        case '5':
        case '6':
            break;
        case 'X':
            for (Instruction robotInstruction : robotInstructions)
                robotInstruction.operation(robotInstruction.degrees);
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

bool armBend(double degrees)
{
    std::cout << "arm bend" << " (" << degrees << " degrees)" << std::endl;
    return true;
}

// ************************************************

bool forearmBend(double degrees)
{
    std::cout << "forearm bend" << " (" << degrees << " degrees)" << std::endl;
    return true;
}

// ************************************************

bool wristBend(double degrees)
{
    std::cout << "wrist bend" << " (" << degrees << " degrees)" << std::endl;
    return true;
}

// ************************************************

bool armTurn(double degrees)
{
    std::cout << "arm turn" << " (" << degrees << " degrees)" << std::endl;
    return true;
}

// ************************************************

bool forearmTurn(double degrees)
{
    std::cout << "forearm turn" << " (" << degrees << " degrees)" << std::endl;
    return true;
}

// ************************************************

bool wristTurn(double degrees)
{
    std::cout << "wrist turn" << " (" << degrees << " degrees)" << std::endl;
    return true;
}
