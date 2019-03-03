#include <monom.hpp>

TMonom::TMonom(int cval = 1, int ival = 0)
{
    Coeff = cval;
    Index = ival;
}

TDatValue *TMonom::GetCopy()
{
    PTDatValue tempValue = new TMonom(Coeff, Index);
    return tempValue;
}

TMonom &TMonom::operator=(const TMonom &tm)
{
    Coeff = tm.Coeff;
    Index = tm.Index;
    return *this;
}

int TMonom::operator==(const TMonom &tm)
{
    return (Coeff == tm.Coeff) && (Index == tm.Index);
}

int TMonom::operator<(const TMonom &tm)
{
    return Index < tm.Index;
}

void PrintPower(int pow, std::ostream &os, char var)
{
    if (pow != 0)
        os << var << "^" << pow;
}

std::ostream &operator<<(std::ostream &os,const TMonom &monom)
{
    if (monom.Coeff != 0)
    {
        int powX = monom.Index / 100;
        int powY = (monom.Index / 10) % 10;
        int powZ = monom.Index % 10;

        os << " " << monom.Coeff;

        PrintPower(powX, os, 'x');
        PrintPower(powY, os, 'y');
        PrintPower(powZ, os, 'z');
    }
    return os;
}