#include "TPolinom.h"
#include <iostream>
using namespace std;

TPolinom::TPolinom ( int monoms[][2], int km ): THeadRing()
{
    pHead->SetDatValue(new TMonom(0, -1));
    for (int i = 0; i < km; ++i)
    {
        InsLast(new TMonom(monoms[i][0], monoms[i][1]));
    }
}

TPolinom::TPolinom(const TPolinom& q): THeadRing()
{
    pHead->SetDatValue(new TMonom(0, -1));
    PTDatLink p = q.pFirst;
    while (p != q.pStop)
    {
        this->InsLast(p->GetDatValue()->GetCopy());
        p = (PTDatLink)p->GetNextLink();
    }
    SetCurrentPos(q.GetCurrentPos());
}

TPolinom& TPolinom::operator+(TPolinom& q)
{
    Reset();
    q.Reset();
    while (!(*GetMonom() == *((PTMonom)pHead->GetDatValue())))
    {
        if (*q.GetMonom() == *((PTMonom)q.pHead->GetDatValue()))
            break;
        if (*q.GetMonom() < *GetMonom())
        {
            InsCurrent(q.GetMonom()->GetCopy());
            q.GoNext();
        }
        else if (q.GetMonom()->Index == GetMonom()->Index)
        {
            GetMonom()->Coeff += q.GetMonom()->Coeff;
            if (GetMonom()->Coeff == 0)
                DelCurrent();
            else
                GoNext();
            q.GoNext();
        }
        else
            GoNext();
    }
    while (!(*q.GetMonom() == *((PTMonom)q.pHead->GetDatValue())))
    {
        InsLast(q.GetMonom()->GetCopy());
        q.GoNext();
    }
    return *this;
}

TPolinom& TPolinom::operator=( TPolinom &q)
{
    if (this == &q)
        return *this;
    DelList();
    PTDatLink p = q.pFirst;
    while (p != q.pStop)
    {
        this->InsLast(p->GetDatValue()->GetCopy());
        p = (PTDatLink)p->GetNextLink();
    }
    SetCurrentPos(q.GetCurrentPos());
    return *this;
}
