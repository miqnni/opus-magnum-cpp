#include <iostream>
#include <string>

namespace myExceptions
{
    class GeneralCustomException
    {
    public:
        GeneralCustomException()
            : message("(no message)") {}

        GeneralCustomException(std::string message)
            : message(message) {}

        virtual ~GeneralCustomException()
        {
        }

        std::string getMessage() noexcept { return message; }

    private:
        std::string message;
    };

    // ****************

    class SpecificCustomException : public GeneralCustomException
    {
        using GeneralCustomException::GeneralCustomException;

    public:
        SpecificCustomException(std::string message, int errorCode)
            : GeneralCustomException(message), customErrorCode(errorCode) {}

        int getCustomErrorCode() noexcept { return customErrorCode; }

    private:
        int customErrorCode;
    };
}

int main()
{
    int userNumber{};

    try
    {
        std::cout << "Type in a number. Type 0 to throw an exception.\nYour number: ";
        std::cin >> userNumber;

        if (!userNumber)
            throw myExceptions::SpecificCustomException("(sample exception message)", 1);

        std::cout << "You have typed in number " << userNumber << ". No exception has been thrown." << std::endl;
    }
    // catch (...) // ERROR: handler is masked by default handler
    // {
    //     std::cout << "An unhandled exception has been thrown." << std::endl;
    // }
    // catch (myExceptions::GeneralCustomException &e) // WARNING: exception of type 'myExceptions::SpecificCustomException' will be caught by earlier handler for 'myExceptions::GeneralCustomException'
    // {
    //     std::cout << "A general custom exception has been thrown." << std::endl;
    //     std::cout << "ERROR MESSAGE: " << e.getMessage() << std::endl;
    // }
    catch (myExceptions::SpecificCustomException &e)
    {
        std::cout << "A specific custom exception has been thrown." << std::endl;
        std::cout << "ERROR MESSAGE: " << e.getMessage() << "; ERROR CODE: " << e.getCustomErrorCode() << std::endl;
    }
    catch (myExceptions::GeneralCustomException &e)
    {
        std::cout << "A general custom exception has been thrown." << std::endl;
        std::cout << "ERROR MESSAGE: " << e.getMessage() << std::endl;
    }
    catch (...)
    {
        std::cout << "An unhandled exception has been thrown." << std::endl;
    }

    return 0;
}