#ifndef __DATVALUE_H
#define __DATVALUE_H

class TDatValue
{
public:
	virtual TDatValue * GetCopy() = 0;
};
typedef TDatValue* PTDatValue;
#endif // !__DATVALUE_H
