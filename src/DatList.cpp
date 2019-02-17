#include "DatList.h"

	PTDatLink TDatList :: GetLink ( PTDatValue pVal, PTDatLink pLink)  
{
	return pLink->GetNextDatLink(); //??????????????????????????
}

    void TDatList :: DelLink ( PTDatLink pLink )   // удаление звена
	{
		Reset(); //устанавливаем на начало списка
		while (pCurrLink != pLink && !IsListEnded())
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
    PTDatValue TDatList :: GetDatValue (TLinkPos mode = CURRENT) const  // значение
	{
		switch (mode) {
		case CURRENT: 
			return pCurrLink -> GetDatValue();
		case FIRST:
			return pFirst -> GetDatValue();
		case LAST:
			return pLast -> GetDatValue();
		default: 
			throw -1;
		}
	}
    // навигация
    int TDatList :: SetCurrentPos ( int pos )         // установить текущее звено
	{
		if ((pos<0)||(pos>=GetListLength()))
			throw -1;
		Reset();
		PTDatLink link = pFirst;
		for (int i=0; i<pos-1; i++)
			link = link -> GetNextDatLink();
		pPrevLink = link;
		pCurrLink = link -> GetNextDatLink();
		CurrPos = pos;
		return 0;
	}
    int TDatList :: GetCurrentPos ( void ) const       // получить номер тек. звена
	{
		return CurrPos;
	}
    int TDatList :: Reset ( void ) { // установить на начало списка
		CurrPos = 0;
		pCurrLink = pFirst;
		pPrevLink = NULL;
		return 0;
	}
	int TDatList :: IsListEnded ( void ) const { // список завершен ?
		return (pCurrLink == pLast);
	}
    int TDatList :: GoNext ( void ) {                   // сдвиг вправо текущего звена
                // (=1 после применения GoNext для последнего звена списка)
		if (IsListEnded()) 
			return 1;
		else {
			pPrevLink = pCurrLink;
			pCurrLink = pCurrLink -> GetNextDatLink();
			CurrPos++;
			return 0;
		}
	}
    // вставка звеньев
    void TDatList :: InsFirst  ( PTDatValue pVal=NULL ) { // перед первым
		PTDatLink link = new TDatLink(pVal, pFirst);
		pFirst = link;



		CurrPos++;
		
	}
    void TDatList :: InsLast   ( PTDatValue pVal=NULL ) { // вставить последним 
		PTDatLink link = new TDatLink(pVal, pLast);
		pLast = link;



		CurrPos++;
	}
    void TDatList :: InsCurrent( PTDatValue pVal=NULL ) { // перед текущим 
		PTDatLink link = new TDatLink(pVal, pCurrLink);
		pCurrLink = link;



		CurrPos++;
	}
    // удаление звеньев
    void TDatList :: DelFirst  ( void ) {    // удалить первое звено 
		if (pFirst == NULL) throw -1;

		PTDatLink link = pFirst;
		pFirst = pFirst -> GetNextDatLink();

		
	}
    void TDatList :: DelCurrent( void ) {    // удалить текущее звено 
		PTDatLink link = pCurrLink;
		pCurrLink = pCurrLink -> GetNextDatLink();
		DelLink (pCurrLink);
	}
    void TDatList :: DelList   ( void ) {    // удалить весь список
		Reset();
		for (int i=0; i<GetListLength(); i++) {
			DelCurrent();
		}

	}