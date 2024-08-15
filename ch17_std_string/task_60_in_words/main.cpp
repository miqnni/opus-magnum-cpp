#include <iostream>
#include <string>
#include <iomanip>

constexpr int IN_WORDS_DISPLAY_WIDTH{55};

// ************************************************

std::string numberNamesEN[10]{
    "",
    "one",
    "two",
    "three",
    "four",
    "five",
    "six",
    "seven",
    "eight",
    "nine",
};

std::string numberNamesEN1X[10]{
    "",
    "eleven",
    "twelve",
    "thiteen",
    "fourteen",
    "fifteen",
    "sixteem",
    "seventeen",
    "eighteen",
    "nineteen",
};

std::string numberNamesENX0[10]{
    "",
    "",
    "twenty",
    "thirty",
    "forty",
    "fifty",
    "sixty",
    "seventy",
    "eighty",
    "ninety",
};

// ************************************************

std::string numberNamesPL[10]{
    "",
    "jeden",    // ascie
    "dwa",      // nascie
    "trzy",     // nascie
    "cztery",   // -(last) nascie
    "piec",     // -(last) +t nascie
    "szesc",    // -(last) nascie
    "siedem",   // nascie
    "osiem",    // nascie
    "dziewiec", // -(last) +t nascie
};

// std::string numberNamesPLAlt[10]{
//     "",
//     "jeden",
//     "dwa",
//     "trzy",
//     "czter", // alt
//     "piet",  // alt
//     "szesc",
//     "siedem",
//     "osiem",
//     "dziewiec",
// };

// std::string numberNamesPL1X[10]{
//     "",
//     "jedenascie",
//     "dwanascie",
//     "trzynascie",
//     "czternascie",
//     "pietnascie",
//     "szesnascie",
//     "siedemnascie",
//     "osiemnascie",
//     "dziewietnascie",
// };

// std::string numberNamesPLX0[10]{
//     "",
//     "",
//     "dwadziescia",
//     "trzydziesci",
//     "czterdziesci",
//     "piecdziesiat",
//     "szescdziesiat",
//     "siedemdziesiat",
//     "osiemdziesiat",
//     "dziewiecdziesiat",
// };

// ************************************************

std::string inWordsEN(int whatNumber)
{
    if (whatNumber < 0 || whatNumber > 9999)
        return std::string("(out of range)");

    if (!whatNumber)
        return std::string("zero");

    std::string asString(std::to_string(whatNumber));
    std::string inWords;

    int thousands = whatNumber / 1000;
    int hundreds = (whatNumber / 100) % 10;
    int tens = (whatNumber / 10) % 10;
    int lastDigit = whatNumber % 10;

    if (thousands)
        inWords += numberNamesEN[thousands] + " thousand";

    if (hundreds)
    {
        if (thousands)
            inWords += " ";
        inWords += numberNamesEN[hundreds] + " hundred";
    }

    if (tens)
    {
        if (thousands || hundreds)
            inWords += " ";

        inWords += numberNamesENX0[tens]; // numberNamesENX0[1] == ""

        if (tens == 1)
        {
            inWords += lastDigit ? numberNamesEN1X[lastDigit] : "ten";
            return inWords;
        }
    }

    if (lastDigit)
    {
        if (thousands || hundreds || tens)
            inWords += " ";
        inWords += numberNamesEN[lastDigit];
    }
    return inWords;
}

// ************************************************

std::string inWordsPL(int whatNumber)
{
    if (whatNumber < 0 || whatNumber > 9999)
        return std::string("(poza zakresem)");

    if (!whatNumber)
        return std::string("zero");

    std::string asString(std::to_string(whatNumber));
    std::string inWords;

    int thousands = whatNumber / 1000;
    int hundreds = (whatNumber / 100) % 10;
    int tens = (whatNumber / 10) % 10;
    int lastDigit = whatNumber % 10;

    // TYSIACE
    if (thousands >= 2)
        inWords += numberNamesPL[thousands] + (thousands >= 5 ? " tysiecy" : " tysiace");
    else if (thousands == 1)
        inWords += "tysiac";

    // SETKI
    if (thousands && hundreds)
        inWords += " ";

    if (hundreds >= 3)
        inWords += numberNamesPL[hundreds] + (hundreds >= 5 ? "set" : "sta");
    else if (hundreds == 2)
        inWords += "dwiescie";
    else if (hundreds == 1)
        inWords += "sto";

    // DZIESIATKI
    if ((thousands || hundreds) && tens)
        inWords += " ";

    if (tens >= 2)
    {
        inWords += numberNamesPL[tens];
        if (tens == 4)
            inWords.pop_back();

        inWords += tens >= 5 ? "dziesiat" : "dziesci";
        inWords += tens == 2 ? "a" : "";
    }
    else if (tens == 1)
    {
        if (!lastDigit)
        {
            inWords += "ten";
            return inWords;
        }

        inWords += numberNamesPL[lastDigit];
        if (lastDigit >= 4 && lastDigit <= 6 || lastDigit == 9)
        {
            inWords.pop_back();
            if (lastDigit == 5 || lastDigit == 9)
                inWords += "t";
        }

        inWords += lastDigit == 1 ? "ascie" : "nascie";

        return inWords;
    }

    // JEDNOSCI
    if (lastDigit)
    {
        if (thousands || hundreds || tens)
            inWords += " ";
        inWords += numberNamesPL[lastDigit];
    }
    return inWords;
}

int main()
{
    for (const auto &x : {1719, 2023, 2017, 600, 7, 0, 9999, 5746, 2004, 1111, 14, /*-1,*/ /*10000,*/ 30})
    {
        std::cout << std::setw(4) << x << ": "
                  << std::setw(IN_WORDS_DISPLAY_WIDTH) << inWordsEN(x)
                  << std::setw(IN_WORDS_DISPLAY_WIDTH) << inWordsPL(x)
                  << std::endl;
    }

    return 0;
}
