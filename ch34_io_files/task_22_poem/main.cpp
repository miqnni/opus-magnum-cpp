#include <iostream>
#include <fstream>
#include <string>

// Works 100% correctly in Visual Studio.
// Task D+E causes errors in Visual Studio Code with code runner extension.
int main()
{
    // TASK A: Alternating single characters.
    std::ifstream infile("poem.txt" /* , std::ios::binary */);
    std::ofstream outfile("result_a.txt");
    if (!infile)
    {
        std::cout << "File open error." << std::endl;
        return 1;
    }

    std::ios::pos_type readPosLeft;
    std::ios::pos_type readPosRight;

    infile.seekg(0);
    readPosLeft = infile.tellg();

    infile.seekg(-1, std::ios::end);
    readPosRight = infile.tellg();

    while (readPosLeft < readPosRight)
    {
        char currChar{};
        char *pCurrChar = &currChar;

        // From start
        infile.seekg(readPosLeft, std::ios::beg);
        // infile.read(pCurrChar, sizeof(char));
        currChar = infile.get();
        if (!infile)
            break;
        // std::cout << "S." << readPosLeft << "\t" << *pCurrChar << "\t | " << static_cast<int>(*pCurrChar) << std::endl; // DEBUG
        // std::cout << currChar << std::flush; // NON-DEBUG
        outfile << currChar << std::flush; // NON-DEBUG (output to file)

        // readPosLeft = infile.tellg();
        readPosLeft += 1;

        // From end
        infile.seekg(readPosRight, std::ios::beg);
        // infile.read(pCurrChar, sizeof(char));
        currChar = infile.get();
        if (!infile)
            break;

        // std::cout << "E." << readPosRight << "\t" << *pCurrChar << "\t | " << static_cast<int>(*pCurrChar) << std::endl; // DEBUG
        // std::cout << currChar << std::flush; // NON-DEBUG
        outfile << currChar << std::flush; // NON-DEBUG (output to file)

        // infile.seekg(-2, std::ios::cur);
        // readPosRight = infile.tellg();
        readPosRight -= 1;
    }

    // std::cout << "L" << readPosLeft << " R" << readPosRight << std::endl;
    if (readPosLeft == readPosRight)
    {
        char currChar{};
        char *pCurrChar = &currChar;

        // std::cout << "AAA" << std::endl;
        infile.seekg(readPosLeft, std::ios::beg);
        // infile.read(pCurrChar, sizeof(char));
        currChar = infile.get();
        // std::cout << "M." << readPosLeft << "\t" << *pCurrChar << std::endl; // DEBUG
        // std::cout << currChar << std::flush; // NON-DEBUG
        outfile << currChar << std::flush; // NON-DEBUG (output to file)

        // std::cout << "BBB" << std::endl;
    }
    outfile.close();

    // TASK B: Count the words.
    outfile.open("result_b.txt");
    infile.seekg(0);

    std::string currWord;
    int wordCount{};

    outfile << "(Word count is written in the last line.)" << std::endl;
    while (infile >> currWord)
    {
        outfile << wordCount << ". " << currWord << std::endl; // DEBUG (output to file)
        wordCount++;
    }
    infile.clear(infile.rdstate() & ~std::ios::eofbit & ~std::ios::failbit);

    // std::cout << "WORD COUNT: " << wordCount << std::endl; // NON-DEBUG
    outfile << "WORD COUNT: " << wordCount << std::endl; // NON-DEBUG (output to file)
    outfile.close();

    // TASK C: Replace whitespace with triple whitespace.
    outfile.open("result_c.txt");
    infile.seekg(0);

    while (1)
    {
        char currChar{};
        currChar = infile.get();
        if (!infile)
            break;
        // std::cout << currChar; // NON-DEBUG
        outfile << currChar; // NON-DEBUG (output to file)
        if (currChar == ' ')
        {
            // Print two extra whitespaces if the recently printed char is a whitespace.
            // std::cout << "  "; // NON-DEBUG
            outfile << "  "; // NON-DEBUG (output to file)
        }
    }
    infile.clear(infile.rdstate() & ~std::ios::eofbit & ~std::ios::failbit);

    outfile.close();

    // TASK D + E: Print lines in the reverse order.
    outfile.open("result_e.txt");

    // We start at the end of the input file.
    infile.seekg(-1, std::ios::end);

    // If we go to any position BEFORE the file (e.g. via seekg),
    // the fstream will receive the flag std::ios::failbit.
    while (infile)
    {
        char currChar{};
        // std::cout << "\t["; // DEBUG
        while (infile) // sweet[\n]home[\n]alabama[EOF]
        {
            currChar = infile.get();
            if (currChar == '\n')
            {
                // std::cout << "<\\n>" << "(" << static_cast<int>(currChar) << ") " << std::flush; // DEBUG
                break;
            }

            // std::cout << currChar << "(" << static_cast<int>(currChar) << ") " << std::flush; // DEBUG
            infile.seekg(-2, std::ios::cur);
        }
        // std::cout << "]\n" << std::flush; // DEBUG

        if (!infile)
        {
            // Handle first line of the input file (the last printed line).
            infile.clear(infile.rdstate() & ~std::ios::failbit);
            infile.seekg(0);
            if (!infile)
                break;
        }

        // Use getline.
        std::ios::pos_type posBeforeGetline{infile.tellg()}; // Save position.
        std::string currLine;
        std::getline(infile, currLine, '\n');
        std::cout << currLine << '\n'; // NON-DEBUG (task D)
        outfile << currLine << '\n';   // NON-DEBUG (task E, output to file)
        infile.seekg(static_cast<std::ios::off_type>(posBeforeGetline) - 3, std::ios::beg);
    }
    // if (infile.eof()) std::cout << "eof\n"; // DEBUG
    // if (infile.fail()) std::cout << "fail\n"; // DEBUG
    infile.seekg(0);
    infile.clear(infile.rdstate() & ~std::ios::eofbit & ~std::ios::failbit);

    outfile.close();

    // CLEAN-UP
    infile.close();

    std::cout << "ok" << std::endl;
    return 0;
}