#include "DatList.h"

	PTDatLink TDatList :: GetLink (PTDatValue pVal, PTDatLink pLink)  
{
	PTDatLink link = new TDatLink(pVal, pLink);
	return link;
}

    void TDatList :: DelLink (PTDatLink pLink)   // удаление звена
	{
		Reset(); //устанавливаем на начало списка
		while ((pCurrLink != pLink)&&(!IsListEnded()))
			GoNext();
		if (IsListEnded()) 
			throw -1;
		else {
			DelCurrent();
		}
	}
	TDatList :: TDatList()
	{
		pFirst = NULL;    // первое звено
		pLast = NULL;     // последнее звено
		pCurrLink = NULL; // текущее звено
		pPrevLink = NULL; // звено перед текущим
		pStop = NULL;     // значение указателя, означающего конец списка 
		CurrPos = -1;         // номер текущего звена (нумерация от 0)
		ListLen = 0;         // количество звеньев в списке
	}

    // доступ
    PTDatValue TDatList :: GetDatValue (TLinkPos mode) const  // значение
	{
		switch (mode) {
		case CURRENT: 
			return pCurrLink -> GetDatValue();
		case BEGIN:
			return pFirst -> GetDatValue();
		case END:
			return pLast -> GetDatValue();
		default: 
			throw -1;
		}
	}
    // навигация
    int TDatList :: SetCurrentPos (int pos)         // установить текущее звено
	{
		if ((pos<0)||(pos>=GetListLength()))
			throw -1;
		Reset();
		pCurrLink = pFirst;
		for (int i=0; i<pos-1; i++)
			pCurrLink = pCurrLink -> GetNextDatLink();
		pPrevLink = pCurrLink;
		pCurrLink = pCurrLink -> GetNextDatLink();
		CurrPos = pos;
		return 0;
	}
    int TDatList :: GetCurrentPos (void) const       // получить номер тек. звена
	{
		return CurrPos;
	}
    int TDatList :: Reset (void) { // установить на начало списка
		CurrPos = 0;
		pCurrLink = pFirst; 
		pPrevLink = NULL;
		return 0;
	}
	int TDatList :: IsListEnded (void) const { // список завершен ?
		return (pCurrLink == pStop);
	}
    int TDatList :: GoNext (void) {                   // сдвиг вправо текущего звена
                // (=1 после применения GoNext для последнего звена списка)
		if (pCurrLink == pStop)  //уже в конце списка
			return 1;
		else if (pCurrLink == pLast) { //на последнем элементе
			pPrevLink = NULL;
			pCurrLink = pCurrLink -> GetNextDatLink(); //NULL
			CurrPos = 0;
		}
		else {
			pPrevLink = pCurrLink;
			pCurrLink = pCurrLink -> GetNextDatLink();
			CurrPos++;
			return 0;
		}
	}
    // вставка звеньев
    void TDatList :: InsFirst (PTDatValue pVal) { // перед первым
		PTDatLink link = new TDatLink(pVal, pFirst);
		if ((pFirst == pCurrLink)&&(pFirst != NULL)) {
			pFirst = link;
			pPrevLink = link;
			pFirst -> SetNextLink(pCurrLink);
		}
		else {
			PTDatLink p = pFirst;
			pFirst = link;
			if (pFirst != NULL) pFirst -> SetNextLink (p);
		}
		if (pLast == NULL) {
			pLast = pFirst;
			pLast->SetNextLink(pStop);
		}
		if (pCurrLink == NULL) {
			pCurrLink = pFirst;
		}
		ListLen++;
		CurrPos++;
	}
    void TDatList :: InsLast (PTDatValue pVal) { // вставить последним 
		PTDatLink link = new TDatLink(pVal, pStop);
		if (pLast != NULL) pLast -> SetNextLink (link);
		pLast = link;
		pLast->SetNextLink(pStop);
		if (pFirst == NULL) pFirst = pLast;
		if (pCurrLink == NULL) {
			pCurrLink = pLast;
			CurrPos++;
		}
		ListLen++;
	}
    void TDatList :: InsCurrent (PTDatValue pVal) { // перед текущим 
		if ((pCurrLink == NULL)||(pPrevLink == NULL))
			InsFirst (pVal);
		else  {
			PTDatLink link = new TDatLink(pVal, pCurrLink);
			pPrevLink -> SetNextLink (link);
			pPrevLink = link;
			//pPrevLink -> SetNextLink (pCurrLink);
			ListLen++;
			CurrPos++;
		}
		
	}
    // удаление звеньев
    void TDatList :: DelFirst (void) {    // удалить первое звено 
		if (pFirst == NULL) throw -1;
		if (pFirst == pCurrLink) pCurrLink = NULL;
		if (pFirst == pLast) pLast = NULL;
		if (pFirst == pPrevLink) pPrevLink = NULL;
		PTDatLink link = pFirst;
		pFirst = pFirst -> GetNextDatLink();
		delete link;
		ListLen--;
		CurrPos--;
	}
    void TDatList :: DelCurrent (void) {    // удалить текущее звено 
		if (pCurrLink == NULL) throw -1;
		if (pCurrLink == pFirst) DelFirst();
		else {
			if (pCurrLink == pLast) {
				pLast = pPrevLink;
				pLast -> SetNextLink(pStop);
			}
			PTDatLink link = pCurrLink;
			pCurrLink = pCurrLink -> GetNextDatLink();
			pPrevLink -> SetNextLink(pCurrLink);
			delete link;
			if (pCurrLink == NULL) pPrevLink = NULL;
			ListLen--;
			CurrPos--;
		}
	}
    void TDatList :: DelList (void) {    // удалить весь список
		Reset();
		for (int i=0; i<GetListLength(); i++) {
			DelFirst();
		}
	}