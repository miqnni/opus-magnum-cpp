#include <iostream>
#include <vector>
#include <new>    // std::bad_alloc
#include <chrono> // For time measurement.

// #define USE_DEFAULT_NEW_DELETE
/*
#ifndef USE_DEFAULT_NEW_DELETE
#endif // USE_DEFAULT_NEW_DELETE
*/

// ************************************************

class Bubble
{
private:
    int radius;
    static int objectCount;
    static constexpr size_t BUBBLES_TO_ALLOCATE{3000};

    static bool *memoryForBubbleAvailable;
    static Bubble *existingBubbles;

public:
    Bubble(int radius) : radius{radius}
    {
        objectCount++;
    }

    Bubble() : Bubble{0} {}

    ~Bubble()
    {
        objectCount--;
    }

    int getRadius() { return radius; }

#ifndef USE_DEFAULT_NEW_DELETE
    static void *operator new(size_t bytes);
    static void operator delete(void *pBubble);

    static void removeAllBubbles();

    // Auxiliary, for debugging.
    static void memoryReport();
    static int getObjectCount() { return objectCount; }
#endif // USE_DEFAULT_NEW_DELETE

private:
#ifndef USE_DEFAULT_NEW_DELETE
    static Bubble *allocateMemory();
#endif // USE_DEFAULT_NEW_DELETE
};

// ************************************************
int Bubble::objectCount{0};
bool *Bubble::memoryForBubbleAvailable;
Bubble *Bubble::existingBubbles;

#ifndef USE_DEFAULT_NEW_DELETE
Bubble *Bubble::allocateMemory()
{
    existingBubbles = ::new Bubble[BUBBLES_TO_ALLOCATE];

    memoryForBubbleAvailable = ::new bool[BUBBLES_TO_ALLOCATE];
    memoryForBubbleAvailable[0] = false;
    for (int i{1}; i < BUBBLES_TO_ALLOCATE; i++)
        memoryForBubbleAvailable[i] = true;

    return existingBubbles;
}

void *Bubble::operator new(size_t bytes)
{
    if (existingBubbles == nullptr)
    {
        return allocateMemory();
    }

    if (objectCount == BUBBLES_TO_ALLOCATE)
        throw std::bad_alloc{}; // Too many Bubble objects!

    for (int i{0}; i < BUBBLES_TO_ALLOCATE; i++)
    {
        if (memoryForBubbleAvailable[i])
        {
            memoryForBubbleAvailable[i] = false;
            return &existingBubbles[i];
        }
    }

    // No free memory for a Bubble object has been found.
    // Should not happen because of `if (objectCount == BUBBLES_TO_ALLOCATE)...`
    throw std::bad_alloc{};
}

void Bubble::operator delete(void *pBubble)
{
    int deletedBubbleIndex{static_cast<Bubble *>(pBubble) - existingBubbles};
    memoryForBubbleAvailable[deletedBubbleIndex] = true;
}

void Bubble::removeAllBubbles()
{
    for (int i{0}; i < BUBBLES_TO_ALLOCATE; i++)
    {
        if (!memoryForBubbleAvailable[i])
        {
            existingBubbles[i].~Bubble();
        }
    }

    delete[] existingBubbles;
}

void Bubble::memoryReport()
{
    std::cout << "Currently reserved slots for bubbles: ";
    int foundBubbles{};
    for (int idx{}; idx < BUBBLES_TO_ALLOCATE && foundBubbles < objectCount; idx++)
    {
        if (!memoryForBubbleAvailable[idx])
        {
            std::cout << idx << " ";
            foundBubbles++;
        }
    }
    std::cout << "(total bubbles found: " << foundBubbles << ")" << std::endl;
}
#endif // USE_DEFAULT_NEW_DELETE

// ************************************************

int main()
{
    try
    {

        auto timeStart{std::chrono::high_resolution_clock::now()};

        {
            Bubble *b0 = new Bubble;
            Bubble *b1 = new Bubble;
            Bubble *b2 = new Bubble;
            Bubble *b3 = new Bubble;

#ifndef USE_DEFAULT_NEW_DELETE
            Bubble::memoryReport();
#endif // USE_DEFAULT_NEW_DELETE

            delete b2;

#ifndef USE_DEFAULT_NEW_DELETE
            Bubble::memoryReport();
#endif // USE_DEFAULT_NEW_DELETE

            Bubble *b2Replacement = new Bubble;
            Bubble *b4 = new Bubble;

#ifndef USE_DEFAULT_NEW_DELETE
            Bubble::memoryReport();
#endif // USE_DEFAULT_NEW_DELETE

            constexpr int BUBBLES_IN_LOCAL_ARRAY{2050};
            Bubble *bubblePtrArray[BUBBLES_IN_LOCAL_ARRAY];
            for (int i{}; i < BUBBLES_IN_LOCAL_ARRAY; i++)
            {
                bubblePtrArray[i] = new Bubble;
            }

#ifndef USE_DEFAULT_NEW_DELETE
            std::cout << "Bubble::getObjectCount(): " << Bubble::getObjectCount() << std::endl;

            Bubble::removeAllBubbles(); // Should be called at the end of the program.
//      Bubble::memoryReport();
#endif // USE_DEFAULT_NEW_DELETE
        }

        auto timeStop{std::chrono::high_resolution_clock::now()};
        auto durationInSeconds{std::chrono::duration_cast<std::chrono::microseconds>(timeStop - timeStart)};
        std::cout << "Measured execution time: " << durationInSeconds.count() << " [micro_s]" << std::endl;
    }
    catch (std::bad_alloc)
    {
        std::cout << "EXCEPTION: std::bad_alloc" << std::endl;
    }
    catch (std::runtime_error &e)
    {
        std::cout << "EXCEPTION:" << e.what() << std::endl;
    }
    catch (...)
    {
        std::cout << "EXCEPTION: (unknown)" << std::endl;
    }
    return 0;
}
