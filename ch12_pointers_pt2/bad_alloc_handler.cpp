#include <iostream>
#include <cstdlib> // exit()
#include <new>     // set_new_handler()

#define NOTHROW_VERSION

void handlerFunction();
long reservationInstance;

// ************************************************

int main()
{
    std::set_new_handler(handlerFunction);

    try
    {
        while (true)
        {
#ifndef NOTHROW_VERSION
            // int *pReservation = new int[10000000];
            new int[10000000];

#else
            // std::nothrow makes the failed memory allocation return nullptr
            new (std::nothrow) int[10000000];
#endif // NOTHROW_VERSION
            reservationInstance++;
        }
    }
    catch (std::bad_alloc &e)
    {
        std::cout << "Caught exception std::bad_alloc." << std::endl;
    }

    return 0;
}

// ************************************************

void handlerFunction()
{
    std::cout << "[INSIDE HANDLER FUNCTION]" << std::endl;
    std::cout << "\tNo memory available during reservation instance #" << reservationInstance << std::endl;

#ifdef NOTHROW_VERSION
    exit(1);
#else
    throw std::bad_alloc();
#endif // NOTHROW_VERSION
}