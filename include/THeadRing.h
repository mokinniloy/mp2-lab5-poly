#ifndef  __HEADRING_H
#define  __HEADRING_H

#include "TDatList.h"

class THeadRing:public TDatList
{ 
public:
	PTDatLink pHead; // заголовок, звено  pFirst за pHead
public:
	THeadRing();
	~THeadRing();
	// вставка звеньев
	virtual void InsFirst(PTDatValue pVal = nullptr); // вставка после заголовка
	// удаление звеньев
	virtual void DelFirst(); // удалить первое звено
};
#endif // ! __HEADRING_H
