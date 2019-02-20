#include <monom.hpp>

TMonom::TMonom(int cval = 1, int ival = 0)
{
    Coeff = cval;
    Index = ival;
};

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