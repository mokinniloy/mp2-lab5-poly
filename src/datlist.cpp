#include <datlist.hpp>

TDatList::TDatList()
{
    pFirst = NULL;
    pLast = NULL;
    pCurrLink = NULL;
    pPrevLink = NULL;
    pStop = NULL;

    CurrPos = -1;
    ListLen = 0;
}

PTDatLink TDatList::GetLink(PTDatValue pVal = NULL, PTDatLink pLink = NULL)
{
    return new TDatLink(pVal, pLink);
}

void TDatList::DelLink(PTDatLink pLink)
{
    delete pLink;
}

PTDatValue TDatList::GetDatValue(TLinkPos mode = CURRENT) const
{
    switch (mode)
    {
    case FIRST:
        return pFirst->pValue;
        break;
    case LAST:
        return pLast->pValue;
        break;
    case CURRENT:
        return pCurrLink->pValue;
        break;

    default:
        return NULL;
        break;
    }
}

void TDatList::InsFirst(PTDatValue pVal = NULL)
{
    pFirst = GetLink(pVal, pFirst);
}

void TDatList::InsLast(PTDatValue pVal = NULL)
{
    PTDatLink elem = GetLink(pVal);

    pLast->pNext = elem;
    pLast = elem;
}

void TDatList::InsCurrent(PTDatValue pVal = NULL)
{
    PTDatLink elem = GetLink(pVal, pCurrLink);

    pPrevLink->pNext = elem;
    pPrevLink = elem;
}

void TDatList::DelFirst(void)
{
    PTDatLink tempLink = (PTDatLink)pFirst->pNext;
    DelLink(pFirst);
    pFirst = tempLink;
}

void TDatList::DelList(void)
{
    while (pFirst->pNext != NULL)
    {
        PTDatLink tempLink = (PTDatLink)pFirst->pNext;
        DelLink(pFirst);
        pFirst = tempLink;
    }

    if (pFirst != NULL)
        DelLink(pFirst);
}

void TDatList::DelCurrent(void)
{
    PTDatLink tempLink = (PTDatLink)pPrevLink->pNext;
    DelLink(pCurrLink);
    pCurrLink = tempLink;
}