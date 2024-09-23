#include <iostream>
using namespace std;

class MyVector
{
public:
    double x{-1}, y{-1}, z{-1};
};

ostream &operator<<(ostream &out, MyVector w) // 1
{
    out << w.x << " " << w.y << " " << w.z;
    return out;
}

istream &operator>>(istream &in, MyVector &w) // 2
{
    // MyVector past = w;
    double a = w.x, b = w.y, c = w.z;
    in >> w.x >> w.y >> w.z;
    if (!in)
    {
        // w = past;
        w.x = a;
        w.y = b;
        w.z = c;
    }
    return in;
}

int main()
{
    MyVector a, b;
    cout << "Vector a: ";
    cin >> a;
    cout << "Vector b: ";
    cin >> b;
    cout << "Vector a is: [" << a << "]" << endl;
    cout << "Vector b is: [" << b << "]";
}
