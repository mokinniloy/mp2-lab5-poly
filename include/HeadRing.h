#ifndef __THEADRING_H__
#define __THEADRING_H__

#include "DatList.h"

class THeadRing : public TDatList 
{
protected:
	PTDatLink pHead;     // ���������, pFirst - ����� �� pHead
public:
	THeadRing();
	~THeadRing();
	// ������� �������
	virtual void InsFirst(PTDatValue pVal = NULL); // ����� ���������
	// �������� �������
	virtual void DelFirst();                 // ������� ������ �����
};

#endif // __THEADRING_H__