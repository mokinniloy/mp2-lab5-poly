
#ifndef __TMONOM_H__
#define __TMONOM_H__

#include "DatValue.h"

class TMonom;
typedef TMonom *PTMonom;

class TMonom : public TDatValue  {     protected:
    int Coeff; // коэффициент монома
    int Index; // индекс (свертка степеней)
  public:
    TMonom ( int cval=1, int ival=0 ) {
      Coeff = cval; Index = ival; 
    };
    virtual PTDatValue GetCopy(); // изготовить копию
    void SetCoeff(int cval) { Coeff = cval;   }
    int  GetCoeff(void)     { return Coeff; }
    void SetIndex(int ival) { Index = ival;   }
    int  GetIndex(void)     { return Index; }
    TMonom& operator=(const TMonom &tm) {
      Coeff = tm.Coeff; 
	  Index = tm.Index;
      return *this;
    }
    int operator==(const TMonom &tm) {
      return (Coeff==tm.Coeff) && (Index==tm.Index);
    }
    int operator<(const TMonom &tm) {
      return Index<tm.Index;
    }
    friend class TPolinom;
};

#endif
