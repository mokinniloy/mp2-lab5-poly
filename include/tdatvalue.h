#ifndef __DATVALUE_H
#define __DATVALUE_H

class TDatValue;
typedef TDatValue *PTDatValue;

class TDatValue {
public:
	virtual PTDatValue GetCopy() = 0; // создание копии
	~TDatValue() {}
};



#endif
