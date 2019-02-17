#include "Monom.h"

PTDatValue TMonom :: GetCopy() { // изготовить копию
  PTDatValue temp = new TMonom(Coeff,Index);
  return temp;
}