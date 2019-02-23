#include "../include/Monom.h"
TDatValue *TMonom::GetCopy()
{
    TDatValue *temp = new TMonom(Coeff, Index);
    return temp;
}
std::ostream &operator<<(std::ostream &os, TMonom &q)
{
    int powX = q.Index / 100;
    int powY = (q.Index / 10) % 10;
    int powZ = q.Index % 10;
    if (q.Coeff != 0)
    {
        os << " " << q.Coeff;
        if (powX != 0)
            os << "X^" << powX;
        if (powY != 0)
            os << "Y^" << powY;
        if (powZ != 0)
            os << "Z^" << powZ;
    }
    return os;
}