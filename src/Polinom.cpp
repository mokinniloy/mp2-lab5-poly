
#include "Polinom.h"

TPolinom::TPolinom(int monoms[][2], int km)
{
    PTMonom pMonom = new TMonom(0, -1);
    pHead->SetDatValue(pMonom);
    for (int i = 0; i < km; i++)
    {
        pMonom = new TMonom (monoms[i][0], monoms[i][1]);
        InsLast(pMonom);
    }
}

TPolinom & TPolinom::operator+ (TPolinom &q) // сложение полиномов // operator += !!!
{
    PTMonom pm, qm, rm;
    Reset();
    q.Reset();
    while(1)
    {
        pm = GetMonom();
        qm = q.GetMonom();
        if (pm->Index < qm->Index) // моном pm младше монома qm => добавление монома qm в полином p
        {
            rm = new TMonom(qm->Coeff, qm->Index);
            InsCurrent(rm);
            q.GoNext();
        }
        else if (pm->Index > qm->Index)
                GoNext();
        else // индексы мономов равны (но это могут быть головы)
        {
            if (pm -> Index == -1)
                break;
            pm->Coeff += qm->Coeff;
            if (pm->Coeff != 0)
            {
                GoNext();
                q.GoNext();
            }
            else // удаление монома с нулевым коэффициентом
            {
                DelCurrent();
                q.GoNext();
            }
        }
    }
    return *this;
}

TPolinom::TPolinom( TPolinom &q)
{
    PTMonom pMonom = new TMonom (0, -1);
    pHead->SetDatValue(pMonom);
    for(q.Reset(); !q.IsListEnded(); q.GoNext())
    {
        PTMonom pMonom = q.GetMonom();
        InsLast(pMonom->GetCopy());
    }
}

TPolinom & TPolinom::operator= (TPolinom &q) 
{
    DelList();
    for (q.Reset(); !q.IsListEnded(); q.GoNext())
    {
        PTMonom pMonom = q.GetMonom();
        InsLast(pMonom->GetCopy()); // delete pMonom;
    }
    return *this;
}

std::ostream& operator<< (ostream &os, TPolinom &q)
{
    for (q.Reset(); !q.IsListEnded(); q.GoNext())
        std::cout << *q.GetMonom() << endl;
    return os;
}