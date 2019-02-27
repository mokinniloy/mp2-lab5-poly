#include "HeadRing.h"


THeadRing :: THeadRing () : TDatList() {
	pHead = NULL;
}

THeadRing :: ~THeadRing () {
	TDatList :: DelList();
	DelLink (pHead);
	pHead = NULL;
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