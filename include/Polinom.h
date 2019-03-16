#ifndef __TPOLINOM_H__
#define __TPOLINOM_H__

#include "HeadRing.h"
#include "Monom.h"


class TPolinom : public THeadRing {
  public:
    TPolinom ( int monoms[][2]=nullptr, int km=0 ); // конструктор
                     // полинома из массива «коэффициент-индекс»
    TPolinom (TPolinom &q);      // конструктор копирования
    PTMonom  GetMonom() const { return (PTMonom) GetDatValue(); }
    TPolinom operator+( TPolinom &q); // сложение полиномов
    TPolinom & operator=( TPolinom &q); // присваивание
	bool operator==(TPolinom &q); 
    bool operator!=(TPolinom &q); 
	friend std::ostream& operator<< (std::ostream &os, TPolinom &q);
};

#endif //__TPOLINOM_H__
