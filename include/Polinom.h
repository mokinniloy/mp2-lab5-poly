#ifndef __POLINOM_H__
#define __POLINOM_H__
#include "HeadRing.h"
#include "Monom.h"
#include <iostream>

using namespace std;

class TPolinom : public THeadRing {
public:
	TPolinom(int monoms[][2] = nullptr, int km = 0); // конструктор
												  // полинома из массива «коэффициент-индекс»
	TPolinom(const TPolinom &q);      // конструктор копирования
	PTMonom  GetMonom() { return (PTMonom)GetDatValue(); }
	TPolinom operator+(TPolinom &q); // сложение полиномов
	TPolinom & operator=(TPolinom &q); // присваивание

	friend ostream& operator<<(ostream &out, TPolinom &p);
};

#endif
