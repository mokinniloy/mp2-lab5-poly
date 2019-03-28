#include <datlist.hpp>
#include <stdexcept>

#define LIST_NO_MEM throw new std::logic_error("Unallocated list.");
#define LINK_NO_MEM throw new std::logic_error("Unallocated link.");
#define POS_ERR throw new std::out_of_range("Unexpected position.");
#define LIST_EMPTY throw std::logic_error("List is empty. Use InsFirst() instead.");

#define TEMP_LINK PTDatLink tempLink
#define GET_TEMP_LINK(val, link) PTDatLink tempLink = new TDatLink(val, link)


TDatList::TDatList()
{
    pFirst = pLast = pStop = NULL;
    ListLen = 0;

    Reset();
}

PTDatLink TDatList::GetLink(PTDatValue pVal, PTDatLink pLink)
{
    GET_TEMP_LINK(pVal, pLink);
    if (tempLink == NULL) LINK_NO_MEM

    return tempLink;
}

void TDatList::DelLink(PTDatLink pLink)
{
    if (pLink != NULL)
    {
        if (pLink->pValue != NULL)
            delete pLink->pValue;
        delete pLink;
    }
}

PTDatValue TDatList::GetDatValue(TLinkPos mode) const
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
    if (pos < 0 || pos > (ListLen - 1)) POS_ERR
    
    Reset();
    for (int i = 0; i < pos; i++, GoNext());
    return CurrPos;
}

int TDatList::GetCurrentPos(void) const
{
    return CurrPos;
}

int TDatList::Reset(void)
{
    pPrevLink = pStop;
    if (IsEmpty())
    {
        pCurrLink = pStop;
        CurrPos = -1;
    }
    else
    {
        pCurrLink = pFirst;
        CurrPos = 0;
    }
    return 1;
}

int TDatList::IsListEnded(void) const
{
    return pCurrLink == pStop;
}

int TDatList::GoNext(void)
{
    if (pCurrLink != pStop)
    {
        pPrevLink = pCurrLink;
        pCurrLink = pCurrLink->GetNextDatLink();
        CurrPos++;

        return 1;
    }
    else return 0;
}

void TDatList::InsFirst(PTDatValue pVal)
{
    GET_TEMP_LINK(pVal, pFirst);
    if (tempLink != NULL)
    {
        pFirst = tempLink;
        ListLen++;

        if (ListLen == 1)
        {
            pLast = tempLink;
            Reset();
        }
        else if (CurrPos == 0) pCurrLink = tempLink;
        else CurrPos++;
    }
    else LIST_NO_MEM
}

void TDatList::InsLast(PTDatValue pVal)
{
    GET_TEMP_LINK(pVal, pStop);
    if (tempLink != NULL)
    {
        if (pLast != NULL) pLast->SetNextLink(tempLink);

        pLast = tempLink;
        ListLen++;

        if (ListLen == 1)
        {
            pFirst = tempLink;
            Reset();
        }
        if (IsListEnded()) pCurrLink = tempLink;
    }
    else
        LIST_NO_MEM
}

void TDatList::InsCurrent(PTDatValue pVal)
{
    if (IsEmpty() || pCurrLink == pFirst) InsFirst(pVal);
    else if (IsListEnded()) InsLast(pVal);
    else if (pPrevLink == pStop) LIST_NO_MEM
    else
    {
        GET_TEMP_LINK(pVal, pCurrLink);
        if (tempLink != NULL)
        {
            pCurrLink = tempLink;
            pPrevLink->SetNextLink(tempLink);
            ListLen++;
        }
        else LIST_NO_MEM
    }
    
}

void TDatList::DelFirst(void)
{
    if (IsEmpty()) LIST_EMPTY
    else
    {
        TEMP_LINK = pFirst;
        pFirst = pFirst->GetNextDatLink();
        ListLen--;
        DelLink(tempLink);

        if (IsEmpty())
        {
            pLast = pStop;
            Reset();
        }
        else if (CurrPos == 0) pCurrLink = pFirst;
        else if (CurrPos == 1) pPrevLink = pStop;

        if (CurrPos > 0) CurrPos--;
    }
}

void TDatList::DelCurrent(void)
{
    if (pCurrLink == pStop) POS_ERR
    else if (pCurrLink == pFirst) DelFirst();
    else
    {
        TEMP_LINK = pCurrLink;
        pCurrLink = pCurrLink->GetNextDatLink();
        pPrevLink->SetNextLink(pCurrLink);
        ListLen--;
        DelLink(tempLink);

        if (pCurrLink == pLast)
        {
            pLast = pPrevLink;
            pCurrLink = pStop;
        }
    }
}

void TDatList::DelList(void)
{
    while (!IsEmpty()) DelFirst();
    pFirst = pLast = pStop = pCurrLink = pPrevLink = NULL;
    CurrPos = -1;
}