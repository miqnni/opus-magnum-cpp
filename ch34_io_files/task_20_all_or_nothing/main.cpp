// Program z paragrafu 33_07

#include <iostream>
using namespace std;
//////////////////////////////////////////////////////////////////////////////////////////////
class Twekt
{
public:
    double x, y, z;
};
//*******************************************************
// globalne funkcje operatorowe realizujące przeładowania  <<  oraz >> dla klasy Twekt
//*******************************************************
ostream &operator<<(ostream &strumien_wyj, Twekt w) // 1
{
    strumien_wyj << w.x << " " << w.y << " " << w.z;
    return strumien_wyj;
}
//*******************************************************
istream &operator>>(istream &strumien_wej, Twekt &w) // 2
{
    strumien_wej >> w.x >> w.y >> w.z;
    return strumien_wej;
}
//*******************************************************
int main()
{
    Twekt a, b;
    cout << "Podaj wspolrzedne wektora a: ";
    cin >> a;
    cout << "Podaj wspolrzedne wektora b: ";
    cin >> b;
    cout << "Wektor a ma wspolrzedne [" << a << "]" << endl;
    cout << "Wektor b ma wspolrzedne [" << b << "]";
}
