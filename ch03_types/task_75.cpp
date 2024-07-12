// #include <iostream>

class nic
{
};

void probnik(nic arg)
{
}

int main()
{
    volatile int x0;
    // probnik(x0); // ERROR: no suitable constructor exists to convert from "volatile int" to "nic"

    const int ctin = 10;
    constexpr int xin = 20;
    volatile int vtin = 37;

    auto h = ctin;
    h = 66;

    auto kkk = xin;
    kkk = 3;

    auto jjj = vtin;

    // probnik(jjj); // jjj -- int

    int in = 6;
    const auto cg = in;

    const auto ch = vtin;

    volatile auto vv = in;
    volatile auto vh = vtin;

    // probnik(vh); // vh -- volatile int
    // probnik(vv); // vw -- volatile int

    return 0;
}