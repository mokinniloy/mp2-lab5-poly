#ifndef _HEADRING_H_
#define _HEADRING_H_
#include "datlist.h"

class THeadRing : public TDatList {
protected:
    PTDatLink pHead;     // заголовок, pFirst - звено за pHead
public:
    THeadRing();
    ~THeadRing();
    // вставка звеньев
    virtual void InsFirst(PTDatValue pVal = nullptr); // после заголовка
    // удаление звеньев
    virtual void DelFirst();                 // удалить первое звено
};

#endif  // _HEADRING_H_
