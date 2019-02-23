#include <cmath>
#include <string>
#include "../include/Polinom.h"
TPolinom::TPolinom(int monoms[][2], int km)
{
    PTMonom pMonom = new TMonom(0, -1);
    pHead->SetDatValue(pMonom);
    for (int i = 0; i < km; i++)
    {
        if (monoms[i][1] > 999 || monoms[i][1] < 0)
            throw "Wrong power of value";
        pMonom = new TMonom(monoms[i][0], monoms[i][1]);
        InsLast(pMonom);
    }
}
TPolinom::TPolinom(/*const*/ TPolinom &q)
{
    PTMonom pMonom = new TMonom(0, -1);
    pHead->SetDatValue(pMonom);
    for (q.Reset(); !q.IsListEnded(); q.GoNext())
    {
        PTMonom pMonom = q.GetMonom();
        InsLast(pMonom->GetCopy()); //delete Pmonom
    }
}
TPolinom &TPolinom::operator=(/*const*/ TPolinom &q)
{
    DelList();
    for (q.Reset(); !q.IsListEnded(); q.GoNext())
    {
        PTMonom pMonom = q.GetMonom();
        InsLast(pMonom->GetCopy()); //delete Pmonom
    }
}
TPolinom &TPolinom::operator+(TPolinom &q)
{
    PTMonom pm, qm, rm;
    Reset();
    q.Reset();
    while (true)
    {
        pm = GetMonom();
        qm = q.GetMonom();
        if (pm->Index < qm->Index)
        { //моном pm младше монома qm => добавление монома qm в полином p
            rm = new TMonom(qm->Coeff, qm->Index);
            InsCurrent(rm);
            q.GoNext();
        }
        else if (pm->Index > qm->Index)
            GoNext();
        else // индексы мономов равны
        {
            if (pm->Index == -1)
                break;
            pm->Coeff += qm->Coeff;
            if (pm->Coeff != 0)
            {
                GoNext();
                q.GoNext();
            }
            else
            {
                DelCurrent();
                q.GoNext();
            }
        }
    }
    return *this;
}
std::ostream &operator<<(std::ostream &os, TPolinom &q)
{
    for (q.Reset(); !q.IsListEnded(); q.GoNext())
        std::cout << *q.GetMonom();
    return os;
}
std::istream &operator>>(std::istream &is, TPolinom &q) //Bad bad bad
{
    int coeff = 0;
    int amountOfMonom = 0;
    std::string indexStr;
    if (q.ListLen != 0)
        q.DelList();
    std::cout << "Введите количество мономов" << std::endl;
    is >> amountOfMonom;
    for (q.Reset(); q.CurrPos < amountOfMonom; q.GoNext())
    {
        std::cout << "Введите коэффициент" << std::endl;
        is >> coeff;
        if (coeff == 0)
            continue;
        std::cout << "Введите свёртку степеней(x,y,z)"
                  << std::endl
                  << "(3-ёх значное число,подряд без раздилителей" << std::endl;
        is >> indexStr;
        if (indexStr.length() > 3)
            throw "Wrong power index";
        for (int i = 0; i < indexStr.length(); i++)
        {
            if (isdigit(indexStr[i]) == 0)
                throw "Wrong power index";
        }

        PTMonom temp = new TMonom(coeff, atoi(indexStr.c_str()));
        q.InsLast(temp);
    }
    return is;
}
int TPolinom::CalculatePolinom(int x, int y, int z)
{
    int result = 0;
    int powX, powY, powZ;
    for (Reset(); !IsListEnded(); GoNext())
    {
        int powX = GetMonom()->Index / 100;
        int powY = (GetMonom()->Index / 10) % 10;
        int powZ = GetMonom()->Index % 10;
        result += GetMonom()->Coeff * pow(x, powX) * pow(y, powY) * pow(z, powZ);
    }
    return result;
}
TPolinom &TPolinom::Integration(bool x, bool y, bool z)
{
    for (Reset(); !IsListEnded(); GoNext())
    {
        if (x)
        {
            GetMonom()->Index += 100;
            GetMonom()->Coeff /= (GetMonom()->Index / 100);
        }
        if (y)
        {
            GetMonom()->Index += 10;
            GetMonom()->Coeff /= ((GetMonom()->Index / 10) % 10);
        }
        if (z)
        {
            GetMonom()->Index += 1;
            GetMonom()->Coeff /= GetMonom()->Index % 10;
        }
    }
    return *this;
}