#include <iostream>
#include <cstring> // strcpy, strncpy

constexpr int CHAR_ARRAY_SIZE{85};

void myStrcpy(char destination[], char source[]);
void myStrcpyUsingWhile(char destination[], char source[]);
void myStrcpyUsingDoWhile(char destination[], char source[]);

int main()
{
    // char myText[CHAR_ARRAY_SIZE] = {"sentence"};

    char initializedWithCString[] = {"Sentence"};                           // Using double quotes automatically inserts NULL char '\0' at the end.
    char initializedWithChars[] = {'S', 'e', 'n', 't', 'e', 'n', 'c', 'e'}; // No NULL char '\0' at the end. DO NOT use this array as a string.

    std::cout << "sizeof(initializedWithCString): " << sizeof(initializedWithCString) << std::endl;
    std::cout << "sizeof(initializedWithChars): " << sizeof(initializedWithChars) << std::endl;

    char newString[] = {"Sweet Home Alabama"};
    // myStrcpy(initializedWithCString, newString);
    // myStrcpyUsingWhile(initializedWithCString, newString);
    // myStrcpyUsingDoWhile(initializedWithCString, newString);

    // strcpy(initializedWithCString, newString);
    // strcpy(initializedWithCString, "Alternative ending.");
    strncpy(initializedWithCString, newString, 100);
    // strncpy(initializedWithCString, newString, 5);

    std::cout
        << initializedWithCString << std::endl;

    return 0;
}

void myStrcpy(char destination[], char source[])
{
    for (int i{};; i++)
    {
        destination[i] = source[i];
        if (destination[i] == 0)
            break;
    }
}

void myStrcpyUsingWhile(char destination[], char source[])
{
    int i{};
    while ((destination[i] = source[i]))
    {
        i++;
    }
}

void myStrcpyUsingDoWhile(char destination[], char source[])
{
    int i{};
    do
    {
        destination[i] = source[i];
    } while (destination[i++] != 0);
}