#include <iostream>
#include <cmath>

// #define TASK_38_VERSION

// ************************************************

namespace settings
{
    constexpr int sequenceArraySize{10};
}
namespace set = settings;
using SequenceSize = unsigned long long;

// ************************************************

class Sequence
{
protected:
    double initialTerm;

public:
    Sequence() : initialTerm{0} {}
    Sequence(double initialTerm) : initialTerm{initialTerm} {}

    virtual double sumOfFirstTerms(SequenceSize n) = 0;
    virtual Sequence *createNew(double a0 = 0, double rq = 0) = 0;
    double getInitialTerm() { return initialTerm; }
    virtual double getDifferenceOrRatio() = 0;
};

// ************************************************

class ArithmeticSequence : public Sequence
{
private:
    double termDifference;

public:
    ArithmeticSequence() : Sequence{}, termDifference{0} {}
    ArithmeticSequence(double initialTerm, double termDifference)
        : Sequence{initialTerm}, termDifference{termDifference} {}

    double sumOfFirstTerms(SequenceSize n) override
    {
        if (n == 0)
            return 0;

        double finalTerm = initialTerm + ((n - 1) * termDifference);
        return ((initialTerm + finalTerm) / 2.) * n;
    }

    ArithmeticSequence *createNew(double a0, double rq) override
    {
        return new ArithmeticSequence(a0, rq);
    }

    double getDifferenceOrRatio() override { return termDifference; }
};

// ************************************************

class GeometricSequence : public Sequence
{
private:
    double termRatio;

public:
    GeometricSequence() : Sequence{}, termRatio{0} {}
    GeometricSequence(double initialTerm, double termRatio)
        : Sequence{initialTerm}, termRatio{termRatio} {}

    double sumOfFirstTerms(SequenceSize n) override
    {
        if (termRatio == 1)
            return initialTerm * n;

        return initialTerm * (1 - pow(termRatio, n)) / (1 - termRatio);
    }

    GeometricSequence *createNew(double a0, double rq) override
    {
        return new GeometricSequence(a0, rq);
    }

    double getDifferenceOrRatio() override { return termRatio; }
};

// ************************************************

int main()
{
    // Task 37
    Sequence *mySequences[set::sequenceArraySize];

#ifdef TASK_38_VERSION
    ArithmeticSequence sequenceA;
    GeometricSequence sequenceG;
#endif // TASK_38_VERSION

    for (int i{}; i < set::sequenceArraySize; i++)
    {
        std::cout << "Sequence (" << i << "/" << set::sequenceArraySize - 1 << ")" << std::endl;
        char sequenceOption;
        bool optionChosen{false};
        do
        {
            std::cout << "\tArithmetic ('a') or geometric ('g')? Option: ";
            std::cin >> sequenceOption;
            sequenceOption = tolower(sequenceOption);
            if (sequenceOption == 'a' || sequenceOption == 'g')
                optionChosen = true;
            else
                std::cout << "\tIncorrect option. Try again ('a'/'g'): " << std::endl;
        } while (!optionChosen);

        double userInitialTerm;
        std::cout << "\tInitial sequence term: ";
        std::cin >> userInitialTerm;

#ifndef TASK_38_VERSION
        // TASK 37 VERSION
        if (sequenceOption == 'a')
        {
            double userDifference;
            std::cout << "\tDifference between terms: ";
            std::cin >> userDifference;
            mySequences[i] = new ArithmeticSequence(userInitialTerm, userDifference);
        }
        else
        {
            double userRatio;
            std::cout << "\tRatio between terms: ";
            std::cin >> userRatio;
            mySequences[i] = new GeometricSequence(userInitialTerm, userRatio);
        }
#endif // TASK 38 VERSION

#ifdef TASK_38_VERSION
        // TASK 38 VERSION

        Sequence *pChosenSequenceType;
        if (sequenceOption == 'a')
        {
            std::cout << "\tDifference between terms: ";
            pChosenSequenceType = &sequenceA;
        }
        else
        {
            std::cout << "\tRatio between terms: ";
            pChosenSequenceType = &sequenceG;
        }
        double differenceOrRatio;
        std::cin >> differenceOrRatio;
        mySequences[i] = pChosenSequenceType->createNew(userInitialTerm, differenceOrRatio);

#endif // TASK 38 VERSION
    }

    std::cout << "==========================" << std::endl
              << std::endl;
    std::cout << "(S_i sum of first i terms of i-th sequence)" << std::endl;
    std::cout << "i\tS_i\t(a0)\t(r/q)" << std::endl;
    for (int i{0}; i < set::sequenceArraySize; i++)
    {
        std::cout << i << "\t"
                  << mySequences[i]->sumOfFirstTerms(i) << "\t"
                  << mySequences[i]->getInitialTerm() << "\t"
                  << mySequences[i]->getDifferenceOrRatio() << "\t"
                  << std::endl;
    }

    // Task 38 test
    GeometricSequence sampleGeom = GeometricSequence();
    Sequence *pSampleGeom = &sampleGeom;
    GeometricSequence *pNewGeom = dynamic_cast<GeometricSequence *>(pSampleGeom->createNew());
    if (pNewGeom)
        std::cout << "Geom. OK" << std::endl;

    ArithmeticSequence sampleArithm = ArithmeticSequence();
    Sequence *pSampleArithm = &sampleArithm;
    ArithmeticSequence *pNewArithm = dynamic_cast<ArithmeticSequence *>(pSampleArithm->createNew());
    if (pNewArithm)
        std::cout << "Arithm. OK" << std::endl;

    // Cleaning up
    for (int i{}; i < set::sequenceArraySize; i++)
    {
        delete mySequences[i];
    }

    delete pNewGeom;
    delete pNewArithm;

    return 0;
}
