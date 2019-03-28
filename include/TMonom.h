#ifndef __MONOM_H
#define __MONOM_H

#include "TDatValue.h"
#include "iostream"

using namespace std;
class TMonom: public TDatValue
{
protected:
	int caf;// коэффициент перед мономом
	int index;//для свертки степеней
public:
	TMonom(int cval = 1, int ival = 1) { caf = cval; index = ival;}
	virtual TDatValue * GetCopy();// изготовить копию
	void SetCaf(int a) { caf = a; }
	int GetCaf() { return caf; }
	void SetIndex(int a) { index = a; }
	int GetIndex() { return index; }
	TMonom& operator=(const TMonom& t)
	{
		caf = t.caf;
		index = t.index;
		return *this;
	}
	bool operator==(const TMonom& t)
	{
		return ((caf == t.caf) && (index == t.index));
	}
	bool operator!=(const TMonom& t)
	{
		return !((caf == t.caf) && (index == t.index));
	}
	int operator<(const TMonom& t)
	{
		return (index < t.index);
	}
	friend ostream& operator<<(ostream &os, TMonom &tm)
	{
		os << tm.caf << " " << tm.index << endl;
		return os;
	}
	friend class Polinom;
};
typedef TMonom* PTMonom ;
#endif // !__DATVALUE_H
