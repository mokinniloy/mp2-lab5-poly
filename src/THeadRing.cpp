#include "THeadRing.h"

THeadRing::THeadRing():TDatList()
{
	InsLast();
	ListLen = 0;
	pHead = pFirst;
	pStop = pHead;
	Reset();
	pFirst->SetNextLink(pFirst);
}

THeadRing ::~THeadRing()
{
	TDatList::DelList();
	DellLink(pHead);
	pHead = nullptr;
}

void THeadRing::InsFirst(PTDatValue pVal) // вставить после заголовка
{
	TDatList::InsFirst(pVal);
	pHead->SetNextLink(pFirst);
}

void THeadRing::DelFirst() // удалить первое звено
{
	TDatList::DelFirst();
	pHead->SetNextLink(pFirst);
}

