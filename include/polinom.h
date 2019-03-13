#include "monom.h"
#include "headring.h"

class TPolinom : public THeadRing {
public:
	TPolinom(int monoms[][2] = NULL, int km = 0); // конструктор
												  // полинома из массива «коэффициент-индекс»
	TPolinom(TPolinom &q);      // конструктор копирования
	PTMonom  GetMonom() { return (PTMonom)GetDatValue(); }
	TPolinom & operator+=(TPolinom &q); // сложение полиномов
	TPolinom & operator=(TPolinom &q); // присваивание
	bool operator==(TPolinom &q);
	friend std::ostream& operator<<(std::ostream &os, TPolinom & q);	
};

