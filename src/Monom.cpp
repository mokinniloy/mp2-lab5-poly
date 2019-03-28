#include "Monom.h"

PTDatValue TMonom :: GetCopy() { // изготовить копию
  PTDatValue temp = new TMonom(Coeff,Index);
  return temp;
}

std::ostream& operator<< (std::ostream &os, TMonom &tm) {
	os<<tm.Coeff<<" x^"<<tm.Index/100<<" y^"<<(tm.Index/10)%10<<" z^"<<tm.Index%10; 
	return os;
}