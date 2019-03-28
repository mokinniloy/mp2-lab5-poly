#include <rootlink.hpp>

void TRootLink::InsNextLink(PTRootLink pLink)
{
    PTRootLink p = pNext;
    pNext = pLink;
    if (pLink != NULL)
        pLink->pNext = p;
}