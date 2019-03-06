//datvalue
#include <iostream>

class TDatValue;
typedef TDatValue *PTDatValue;

class TDatValue {
public:
	virtual TDatValue * GetCopy() = 0; // создание копии
	~TDatValue() {}
};

