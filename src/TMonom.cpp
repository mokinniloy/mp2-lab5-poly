#include "TMonom.h"
#include <iostream>

TDatValue* TMonom::GetCopy()
{
	TDatValue* temp = new TMonom(caf,index);
	return temp;
}