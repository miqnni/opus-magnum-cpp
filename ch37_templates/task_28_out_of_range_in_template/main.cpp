// Program z paragrafu 37_09


#include <iostream>
#include <string>
using namespace std;

#define OPERATOR_W_CIELE_SZABLONU   false   	// lub true 			// 1

#if OPERATOR_W_CIELE_SZABLONU == false
// dwie deklaracje zapowiadające
template <typename T, int ILOPAK> struct Tzestaw; 				   		// 2
template <typename TT, int ROZM>
ostream& operator<< (ostream& strum, Tzestaw<TT, ROZM>& zest); 		 // 3
#endif
//////////////////////////////////////////////////////////////////////////////////////////////////
template <typename T, int ILOPAK> 										// 4
struct Tzestaw
{
    T tab[ILOPAK];   													// 5
    string nazwa;

    Tzestaw(string nazwa);								// konstruktor
    ~Tzestaw();										// destruktor
    void fun_zwykla(unsigned int nr, T obj);	// zwykła funkcja składowa

    static char symbol;   			// dane statyczne (czyli wspólne) 		// 6
    static T  ostatnio;				 									// 7
    static void funstat();	 	  	// przykładowa statyczna funkcja składowa

    using iterator = T*;  												// 8

    // iterator 	begin() 	{ return &tab[0];  }									// 9
    // iterator 	end() 	{ return &tab[ILOPAK]; }   							// 10
    iterator 	begin();													// 11
    iterator 	end(); 	   												// 12

    // zaprzyjaźniony operator<< zrealizowany na dwa (wykluczające się) sposoby
#if OPERATOR_W_CIELE_SZABLONU == true
//  A ) łącznie z deklaracją przyjaźni wolno dodać definicję tego operatora
    friend
        ostream& operator<< (ostream& strum, Tzestaw<T, ILOPAK>& zest) 		// 13
    {
        strum << zest.nazwa << ": ";
        for (int i = 0; i < ILOPAK; ++i)
        {
            strum << zest.tab[i] << ", ";
        }
        return strum;
    }
#else//  B ) można też w ciele umieścić samą dekl. przyjaźni z odrębną funkcją szablonową
    friend
        ostream& operator<< < > (ostream& strum, Tzestaw<T, ILOPAK>& zest); 		// 14
#endif
};
//********************************************************************
template <typename T, int ILOPAK>										// 15
void Tzestaw<T, ILOPAK>::fun_zwykla(unsigned int nr, T obj)
{
    ostatnio = obj;
    if (nr < ILOPAK) 	tab[nr] = obj;
    // else ... (dobra sytuacja na rzuce<$M[m_szabl_rzuc_wyj_przyklad]>nie wyjątku)
    else
    {
        throw std::out_of_range("Error: The provided index is out of range!");
    }
}
//********************************************************************
template <typename T, int ILOPAK> 										// 16
Tzestaw<T, ILOPAK>::Tzestaw(string n) : tab{ }, nazwa(n)
{
    cout << "Konstrukcja obj. '" << nazwa << "'. (" << ILOPAK << "-pak.) " << endl;  		 // 17
}
//********************************************************************
template <typename T, int ILOPAK>
Tzestaw<T, ILOPAK>::~Tzestaw() 										// 18
{
    // cout <<  "Destruktor Tzestawu:" << nazwa << ".  (To byl "<< ILOPAK << "-pak.) " <<  endl;
}
//********************************************************************
template <typename T, int ILOPAK>										// 19
typename Tzestaw<T, ILOPAK>::iterator 	Tzestaw<T, ILOPAK>::begin()
{
    return &tab[0];
}
//********************************************************************
template <typename T, int ILOPAK>										// 20
auto  Tzestaw<T, ILOPAK>::end()  ->iterator
{
    return &tab[ILOPAK];
}
//********************************************************************
//							 Szablony statycznych danych składowych tego szablonu
template <typename T, int ILOPAK>
char 	Tzestaw<T, ILOPAK>::symbol = '!';  								// 21

template <typename T, int ILOPAK>
T 	  Tzestaw<T, ILOPAK>::ostatnio; 										// 22
//********************************************************************
template <typename T, int ILOPAK>
void Tzestaw<T, ILOPAK>::funstat() 										// 23
{
    cout << "F. statyczna (" << ILOPAK << "-pak), symbol [" << symbol
        << "], ostatnio= " << ostatnio << endl;
}
//********************************************************************
#if OPERATOR_W_CIELE_SZABLONU == false
template <typename TT, int ROZM>
ostream& operator<< (ostream& strum, Tzestaw<TT, ROZM>& zest) 		// 24
{
    strum << zest.nazwa << ": ";
    for (int i = 0; i < ROZM; ++i)
    {
        strum << zest.tab[i] << ", ";
    }
    return strum;
}
#endif
//********************************************************************
int  main()
{
    try {
        Tzestaw<double, 3> 	dunajec("Dunajec"); 	 						// 25
        dunajec.fun_zwykla(0, 2.55); 										// 26
        dunajec.fun_zwykla(2, 3.20);

        Tzestaw<double, 2 + 1> poprad("Poprad");								// 27
        poprad.fun_zwykla(0, 1.5);
        poprad.fun_zwykla(1, 1.6);
        poprad.fun_zwykla(2, 1.8);

        dunajec.symbol = '%';  												// 28

        poprad.funstat();  					 // wywołanie funkcji statycznej 		// 29
        cout << "kolejne fun_zwykla, czy zmieni się stat. składnik // ostatnio// ?" << endl;
        dunajec.fun_zwykla(1, 3.1); 											// 30
        Tzestaw<double, 3>::funstat(); 										// 31

        Tzestaw<int, 7>::symbol = '#';
        // jawne wywołanie konstruktora
        Tzestaw<int, 7>* tygA = new Tzestaw<int, 7>("tydzien lipca");  			 // 32
        tygA->funstat();

        using Tgwzb = Tzestaw<string, 5>;  									// 33

        Tgwzb* gw = new Tgwzb("Gwiazdozbiory");  							// 34
        auto* gw2 = new Tgwzb("Gwiazdozbiory2");  							// 35

        gw->fun_zwykla(0, "Orion");
        gw->fun_zwykla(1, "Kasjopea");
        gw->fun_zwykla(2, "Pegaz");
        gw->fun_zwykla(3, "Andromeda");
        gw->fun_zwykla(4, "Perseusz");
        gw->funstat();
        // korzystamy z wewnętrznego aliasu iterator
        Tgwzb::iterator   it = gw->begin();   									// 36
        for (; it != gw->end(); ++it) 										// 37
        {
            cout << "iterator pokazuje na:   " << *it << endl;
        }

        // mając w klasie szablonowej funkcje składowe begin i end, możemy korzystać
        // z zakresowego for
        for (auto x : dunajec) cout << "zakresowo... " << x << endl;					// 38

        cout << "Stan wody rzeki " << dunajec << endl; 							// 39
        cout << *gw << endl;   												// 40

        cout << "Tak sie robi jawne wywolanie destruktora\n";
        dunajec.~Tzestaw();												// 41
        poprad.Tzestaw<double, 3>::~Tzestaw();								// 42
        gw->Tzestaw<string, 5>::~Tzestaw();
        gw->Tgwzb::~Tgwzb();

        delete tygA;
        delete gw;
        delete gw2;
    }
    catch (std::out_of_range& e)
    {
        std::cerr << "Exception caught: std::out_of_range.\n\t" << e.what() << std::endl;
    }
}

