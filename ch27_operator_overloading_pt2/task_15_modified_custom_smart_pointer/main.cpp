#include <iostream>
#include <vector>

// ************************************************

class CustomVector3D
{
private:
    double x, y, z;

public:
    CustomVector3D(double a, double b, double c) : x(a), y(b), z(c)
    {
    }
    void scaleAll(double scale = 2)
    {
        x *= scale;
        y *= scale;
        z *= scale;
    }

    void printAll()
    {
        std::cout << "{" << x << ", " << y << ", " << z << "}" << std::endl;
    }

    // friend std::ostream &operator<<(std::ostream &out, CustomVector3D v);
};

// ************************************************

// std::ostream &operator<<(std::ostream &out, CustomVector3D v)
// {
//     out << "{" << v.x << ", " << v.y << ", " << v.z << "}" << std::endl;
// }

// ************************************************

// A CustomSmartPointer object remembers what pointers have been inside `ptr` variable
// on any use of `->` operator
// and keeps those pointers in its log `smartPointerLog`.
class CustomSmartPointer
{
private:
    CustomVector3D *ptr;
    std::vector<CustomVector3D *> smartPointerLog;

public:
    CustomVector3D *operator=(CustomVector3D *pAssigned) // IMPORTANT MODIFICATION
    {
        ptr = pAssigned;
        return pAssigned; // IMPORTANT MODIFICATION
    }
    CustomSmartPointer(CustomVector3D *adr = nullptr) : ptr(adr)
    {
    }

    CustomVector3D *operator->();

    int getLogSize() { return smartPointerLog.size(); }
};

// ************************************************

CustomVector3D *CustomSmartPointer::operator->()
{
    smartPointerLog.push_back(ptr);
    return ptr;
}

// ************************************************

int main()
{
    CustomVector3D sample(1, 8, 2);
    CustomSmartPointer sptr1, sptr2, sptr3;

    sptr3 = sptr2 = sptr1 = &sample;
    // (sptr3) log size: 0

    // The operator `->` for class `CustomSmartPointer` is overloaded.
    // This means that we first call the operator `->` for the `CustomSmartPointer`
    // and only then we call the same operator `->` one more time for the result
    // of the previous operator `->` call.
    sptr3->printAll();  // log size: 1
    sptr3->scaleAll(3); // log size: 2
    sptr3->printAll();  // log size: 3
    std::cout << "sptr3.getLogSize(): " << sptr3.getLogSize() << std::endl;
}