#include <iostream>
#include <cstring>

constexpr int PREFIX_LEN{9};

char *modifyCString(char *message, int messageSize)
{
    int originalLen{};
    char *tmpMsgPtr{message};

    while (*(tmpMsgPtr++))
        originalLen++;

    char msgPrefix[PREFIX_LEN]{"BEWARE: "};

    char *finalMsg = new char[originalLen + PREFIX_LEN];

    strcpy(finalMsg, msgPrefix);
    strcat(finalMsg, message);

    if (originalLen + PREFIX_LEN > messageSize)
    {
        finalMsg[messageSize - 4] = '.';
        finalMsg[messageSize - 3] = '.';
        finalMsg[messageSize - 2] = '.';
        finalMsg[messageSize - 1] = '\0';
    }

    strcpy(message, finalMsg);

    delete[] finalMsg;

    return message;
}

int main()
{
    char sampleCString[80]{"Be careful! ABCDEFGHIJKLMNOPQRSTUVWXYZABCDEFGHIJKLMNOPQRSTUVWXYZABCDEFGHIJKLMNO"};
    // char sampleCString[80]{"Be careful!"};
    std::cout << modifyCString(sampleCString, 80) << std::endl;

    return 0;
}