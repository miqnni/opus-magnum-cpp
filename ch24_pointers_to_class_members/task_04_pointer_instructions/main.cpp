#include <iostream>

class K
{
public:
    int a, b, c;
};

int main()
{
    // (1)
    K *pObject{new K{1, 2, 7}}; // wskobj

    // (2)
    int K::*pMember; // wskskl

    // (3)
    pMember = &K::b;

    // The pointer to a class member has changed.
    pMember = &K::c;

    // (4)
    std::cout << pObject->*pMember << std::endl;

    delete pObject;
    return 0;
}