#include "HeadRing.h"


THeadRing :: THeadRing () : TDatList () {
	InsLast();
	pHead = pFirst;
	pStop = pHead;
	Reset();
	pFirst -> SetNextLink(pFirst);
	ListLen = 0;
}

THeadRing :: ~THeadRing () {
	TDatList :: DelList();
	DelLink (pHead);
	pHead = nullptr;
}
   // вставка звеньев
void THeadRing :: InsFirst (PTDatValue pVal) { // после заголовка
	TDatList :: InsFirst (pVal);
	pHead -> SetNextLink (pFirst);
}
    // удаление звеньев
void THeadRing :: DelFirst (void) {                // удалить первое звено
	TDatList :: DelFirst ();
	pHead -> SetNextLink (pFirst);
}

