// Class names in Polish
#include <iostream>

// ************************************************
// HIERARCHY 1

class UrzadzenieWyswietlajace
{
};

class WyswietlaczWskazowkowy : public UrzadzenieWyswietlajace
{
};

class WyswietlaczCyfrowy : public UrzadzenieWyswietlajace
{
};

// ************************************************
// HIERARCHY 2

class MiernikWielkosciFizycznej
{
};

class MiernikTemperatury : public MiernikWielkosciFizycznej
{
};

class MiernikTemperaturyRteciowy : public MiernikTemperatury
{
};

class MiernikTemperaturyTermopara : public MiernikTemperatury
{
};

class MiernikPradu : public MiernikWielkosciFizycznej
{
};

class Woltomierz : public MiernikPradu
{
};

class Amperomierz : public MiernikPradu
{
};

// ************************************************
// HIERARCHY 3

class UrzadzenieSterowalne
{
};

class UrzadzenieSterowaneGalkami : public UrzadzenieSterowalne
{
};

class UrzadzeniaSterowaneZdalnie : public UrzadzenieSterowalne
{
};

class UrzadzenieSterowaneLaczemUSB : public UrzadzeniaSterowaneZdalnie
{
};

class UrzadzenieSterowaneLaczemSzeregowym : public UrzadzeniaSterowaneZdalnie
{
};

class UrzadzenieSterowaneProtokolemSieciowymSOAP : public UrzadzeniaSterowaneZdalnie
{
};

// ************************************************
// (A)

class WoltomierzCyfrowySterowanyProtokolemSieciowymSOAP
    : public Woltomierz,
      public WyswietlaczCyfrowy,
      public UrzadzenieSterowaneProtokolemSieciowymSOAP
{
};

// ************************************************
// (B)

class MiernikTemperaturyTermoparowyWskazowkowySterowanyLaczemUSB
    : public MiernikTemperaturyTermopara,
      public WyswietlaczWskazowkowy,
      public UrzadzenieSterowaneLaczemUSB
{
};

// ************************************************
// (C)

class MiernikTemperaturyRteciowyWskazowkowy
    : public MiernikTemperaturyRteciowy,
      public WyswietlaczWskazowkowy
{
};

// ************************************************
// Obiekty klas (A), (B), (C)

WoltomierzCyfrowySterowanyProtokolemSieciowymSOAP objA;
MiernikTemperaturyTermoparowyWskazowkowySterowanyLaczemUSB objB;
MiernikTemperaturyRteciowyWskazowkowy objC;
