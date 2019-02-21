#include <datlist.hpp>
#include <stdexcept>

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

int TDatList::SetCurrentPos(int pos)
{
    if (pos < 0 || pos > ListLen)
        throw new std::out_of_range("Unexpected position.");
    for (int i = CurrPos; i < pos; i++)
    {
        
    }
}

int TDatList::GetCurrentPos(void) const
{
    return CurrPos;
}

int TDatList::Reset(void)
{
    CurrPos = 0;
    pCurrLink = pFirst;
    pPrevLink = NULL;

    return CurrPos;
}

int TDatList::IsListEnded(void) const
{

}

int TDatList::GoNext(void)
{
    pCurrLink = (PTDatLink)pCurrLink->pNext;
    pPrevLink->pNext = pCurrLink;
    CurrPos++;
}

void TDatList::InsFirst(PTDatValue pVal = NULL)
{
    if (ListLen == 0)
    {
        pFirst = GetLink(pVal);
        pCurrLink = pFirst;
        pLast = pFirst;
        CurrPos = 0;
        ListLen++;
    }
    else
    {
        pFirst = GetLink(pVal, pFirst);
        ListLen++;   
    }
}

void TDatList::InsLast(PTDatValue pVal = NULL)
{
    if (pFirst == NULL)
        throw std::logic_error("List is empty. Use InsFirst() instead.");
    
    PTDatLink elem = GetLink(pVal, pStop);

    pLast = elem;
    ListLen++;
}

void TDatList::InsCurrent(PTDatValue pVal = NULL)
{
    if (pFirst == NULL)
        throw std::logic_error("List is empty. Use InsFirst() instead.");
    
    PTDatLink elem = GetLink(pVal, (PTDatLink)pCurrLink->pNext);

    pPrevLink = pCurrLink;
    pCurrLink = elem;
    CurrPos++;
    ListLen++;

    if (CurrPos == ListLen)
    {
        pLast = pCurrLink;
        pLast->pNext = pStop;
    }
}

void TDatList::DelFirst(void)
{
    if (ListLen == 0)
        throw std::logic_error("List is empty.");
    if (ListLen == 1)
    {
        DelLink(pFirst);
        pFirst = NULL;
        pLast = NULL;
        pCurrLink = NULL;
        ListLen--;
        CurrPos = -1;
    }
    else
    {
        PTDatLink tempLink = (PTDatLink)pFirst->pNext;
        DelLink(pFirst);
        pFirst = tempLink;
        ListLen--;
    }
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

    pFirst = NULL;
    pLast = NULL;
    pCurrLink = NULL;
    pPrevLink = NULL;
    CurrPos = -1;
    ListLen = 0;
}

void TDatList::DelCurrent(void)
{
    if (ListLen == 0)
        throw std::logic_error("List is empty.");
    if (ListLen == 1)
        DelFirst();
    else
    {
        PTDatLink tempLink = (PTDatLink)pCurrLink->pNext;

        DelLink(pCurrLink);
        pCurrLink = tempLink;
        pPrevLink->pNext = pCurrLink;
        ListLen--;   
    }
}