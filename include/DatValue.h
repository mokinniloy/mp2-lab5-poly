#ifndef __TDATVALUE_H__
#define __TDATVALUE_H__

#include <iostream>

class TDatValue
{
public:
	virtual TDatValue * GetCopy() = 0; // �������� �����
	~TDatValue() {}
};
typedef TDatValue *PTDatValue;

#endif // __TDATVALUE_H__