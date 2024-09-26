#include "helper.h"
#include <algorithm> // std::invalid_argument, std::out_of_range
#include <iostream>

//				                v-- TASK 21 --------v
double strhelper::loadParameter(std::ifstream &infile, std::string word)
{
    // TASK 21 (start)
    // Assumption: The file is already open.
    infile.clear(infile.rdstate() & ~std::ios::eofbit & ~std::ios::failbit); // !
    infile.seekg(0);                                                         // !

    std::string fileContent;
    std::string singleLine;
    while (getline(infile, singleLine, '\n'))
        fileContent += singleLine + '\n';
    // TASK 21 (end)

    size_t pos = strhelper::findKeyword(fileContent, word);
    std::string aux = fileContent.substr(pos);
    try
    {
        double wartosc = stod(aux);
        return wartosc;
    }
    catch (std::invalid_argument)
    {
        ValueException exc;
        exc.message = "Error while loading the value after keyword: " + word;
        throw exc;
    }
    catch (std::out_of_range)
    {
        ValueException exc;
        exc.message = "Error: the value after keyword \"" + word + "\"is too big for type double";
        throw exc;
    }
}

//                                        v---- TASK 20
size_t strhelper::findKeyword(std::string &fileContent, std::string word)
{
    // TASK 19 (start)
    deleteComments(fileContent); // <-- TASK 20

    for (char &ch : fileContent)
        ch = tolower(ch);

    for (char &ch : word)
        ch = tolower(ch);

    // TASK 19 (end)

    size_t position = fileContent.find(word);
    if (position != std::string::npos)
    {
        return position + word.size();
    }
    else
    {
        KeywordException exc;
        exc.message = "There is no such keyword as \'" + word + "\' in the given text.";
        throw exc;
    }
}

// TASK 20
void strhelper::deleteComments(std::string &fileContent)
{
    size_t commentStartPos{};
    while ((commentStartPos = fileContent.find("//")) != std::string::npos)
    {
        size_t commentEndPos{fileContent.find("\n", commentStartPos)}; // non-inclusve
        fileContent.erase(commentStartPos, commentEndPos - commentStartPos + 1);
    }

    // std::cout << "FILE CONTENT -------------------------\n" << fileContent << "\n------------------------" << std::endl; // DEBUG
}

//                                      v-- TASK 21 --v
double strhelper::loadOptionalParameter(std::ifstream &src, std::string word, double value)
{
    double p = 0;
    try
    {
        p = loadParameter(src, word);
    }
    catch (KeywordException &k)
    {
        p = value;
        std::cout << "There is no word '" << word
                  << "' in the string/file, so the following default value will apply: " << p << std::endl;
    }
    return p;
}
