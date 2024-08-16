#include <iostream>
struct CustomException
{
};

int main()
{
    try
    {
        throw CustomException();
    }
    // catch (const CustomException)
    // {
    //     // warning: exception of type 'CustomException' will be caught by earlier handler for 'CustomException'
    //     std::cout << "catch (const CustomException)" << std::endl;
    // }
    catch (CustomException)
    {
        std::cout << "catch (CustomException)" << std::endl;
    }

    return 0;
}
