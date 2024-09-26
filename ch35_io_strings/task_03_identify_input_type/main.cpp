#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <iomanip>

template <typename T>
void printVector(const std::vector<T> &v, std::ostream &out = std::cout)
{
    if (!v.size())
    {
        out << "{}" << std::endl;
        return;
    }

    out << "{" << v[0];
    for (int i{1}; i < v.size(); i++)
    {
        out << ", " << v[i];
    }
    out << "}" << std::endl;
}

std::string streamState(std::iostream &stream)
{
    if (stream.good())
        return "good";

    std::string state;
    if (stream.rdstate() & std::ios::eofbit)
        state += "eof ";

    if (stream.rdstate() & std::ios::failbit)
        state += "fail ";

    if (stream.rdstate() & std::ios::badbit)
        state += "bad ";

    return state.substr(0, state.size() - 1);
}

int main(int argc, char *argv[])
{
    std::vector<double> numbers;
    std::vector<std::string> nonNumbers;

    std::stringstream argStream;

    for (int i{1}; i < argc; i++)
    {
        double number{};
        std::string nonNumber;

        // std::cout << i << ") " << argv[i]; // DEBUG
        // std::cout << "\t" << streamState(argStream); // DEBUG

        argStream.clear(argStream.rdstate() & ~std::ios::eofbit);
        argStream.str(argv[i]);
        if (!(argStream >> number))
        {
            // This means that the current command line argument is not a number.
            argStream.clear(argStream.rdstate() & ~std::ios::failbit);
            argStream >> nonNumber;

            // std::cout << "\tnon-number: " << nonNumber << "\t" << streamState(argStream) << std::endl; // DEBUG

            nonNumbers.push_back(nonNumber);
            continue;
        }

        // std::cout << "\tnumber: " << number << std::endl; // DEBUG
        numbers.push_back(number);
    }

    std::cout << std::setw(15) << "NUMBERS: ";
    printVector(numbers);

    std::cout << std::setw(15) << "NON-NUMBERS: ";
    printVector(nonNumbers);

    return 0;
}
