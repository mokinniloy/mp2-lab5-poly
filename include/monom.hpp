#pragma once

#include <datvalue.hpp>
#include <iostream>

class TMonom;
typedef TMonom *PTMonom;

class TMonom : public TDatValue
{
  protected:
    int Coeff; // коэффициент монома
    int Index; // индекс (свертка степеней)
  public:
    TMonom(int cval = 1, int ival = 0);

    virtual TDatValue *GetCopy(); // изготовить копию

    void SetCoeff(int cval) { Coeff = cval; }
    int GetCoeff(void) { return Coeff; }

    void SetIndex(int ival) { Index = ival; }
    int GetIndex(void) { return Index; }

    TMonom &operator=(const TMonom &tm);
    int operator==(const TMonom &tm);
    int operator<(const TMonom &tm);

    friend void PrintPower(int pow, std::ostream &os, char var);
    friend std::ostream &operator<<(std::ostream &os,const TMonom &monom);
    friend class TPolinom;
};