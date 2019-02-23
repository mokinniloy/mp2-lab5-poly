#pragma once
#include <iostream>
#include "HeadRing.h"
#include "Monom.h"
class TPolinom : public THeadRing
{
public:
  TPolinom(int monoms[][2] = NULL, int km = 0); // конструктор
                                                // полинома из массива «коэффициент-индекс»
  TPolinom(/*const*/ TPolinom &q);                  // конструктор копирования
  PTMonom GetMonom() { return (PTMonom)GetDatValue(); }
  TPolinom &operator+(TPolinom &q);                                  // сложение полиномов
  TPolinom &operator=(/*const*/ TPolinom &q);                                  // присваивание
  int CalculatePolinom(int x, int y, int z);                         //Вычисление значения полинома
  TPolinom& Integration(bool x = true, bool y = true, bool z = true); //Интегрирование,по какой переменной
  friend std::ostream &operator<<(std::ostream &os, TPolinom &q);
  friend std::istream &operator>>(std::istream &is, TPolinom &q);
};