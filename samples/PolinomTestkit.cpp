#include "TMonom.h"
#include "TDatList.h"
#include <iostream>
#include <vector>
#include "stdlib.h"
//#include "conio.h"
#include <stdio.h>
#include <string>
#include "TPolinom.h"
using namespace std;


int main()
{
	// тестирование Листа
	setlocale(LC_ALL, "Russian");
	/*TDatList st;
	TMonom *pVal;
	int temp;
	cout << "Тестирование списка" << endl;
	for (int i = 0; i < 5; ++i)
	{
		pVal = new TMonom(i, 10 * i);
		st.InsLast(pVal);
		cout << "Положили в список значение " << pVal->GetCaf() << ", " << pVal->GetIndex() << " Код " << endl;

	}
	// печать списка 
	for (st.Reset(); !st.IsListEnded(); st.GoNext())
	{
		pVal = (TMonom*)st.GetDatValue();
		cout << "Взяли из списка значение " << pVal->GetCaf() << "; " << pVal->GetIndex() << " Код " << endl;
	}
	st.DelList();
	cout << "Нажмите любую клавишу" << endl;
	getch();*/


	// Тестирование полиномов
	cout << "Тестирование полиномов " << endl;
	int ms1[][2] = { {1,543},{3,432},{5,321},{7,210},{9,100} };
	int mn1 = sizeof(ms1) / (2 * sizeof(int));
	Polinom p(ms1, mn1);
	cout << "1 полином " << endl << p;
	int ms2[][2] = { {2,643},{4,431},{-5,321},{8,110},{10,50} };
	int mn2 = sizeof(ms2) / (2 * sizeof(int));
	Polinom q(ms2, mn2);
	cout << "2 полином " << endl << q;
	Polinom r = p + q;
	cout << "Полином результат " << endl<<r;
	
	cout << "--------------------------------" << endl;
	auto f = freopen("file.txt", "r",stdin); // Ввод полиномов через файл
	string s1,s2;
	cout << "Введите полином 1 : " << endl;
	Polinom p1,p2;
	cin >> p1;
	cout << "1 полином " << endl << p1;
	cout << "Введите полином 2 : " << endl;
	cin >> p2;
	cout << "2 полином " << endl << p2;
	r = p1 + p2;
	cout << "Полином результат " << endl << r;
	cout << "--------------------------------" << endl;
	cout << "Введите значения x,y и z : " << endl;
	double x, y, z;
	//cin >> x >> y >> z;
	cout << "Значение полинома результата : "  << r.get(2,1,1)<<endl;
	cout << "--------------------------------" << endl;
	//сравнение 
	cout << (p1 == p2) << endl;
	cout << "-------------------------" << endl;
	int m[][2] = { { 1,344 },{ -3,233 },{ 6,23 } };
	int m1[][2] = { { -1,34 },{ 3,233 },{-1,23} };
	Polinom a(m, 3),b(m1, 3);
	PTMonom am,bm;
	a.DelFirst();
	cout<<a.GetMonom()->GetCaf();
	am = a.GetMonom(); bm = b.GetMonom();
	cout << am->GetCaf()<<" "<<bm->GetCaf()<<endl;
	am->SetCaf(0);
	
	a.DelCurrent();
	b.GoNext();
	am = a.GetMonom(); bm = b.GetMonom();
	am->GetIndex();
	//cout << am->GetCaf() << " " << bm->GetCaf();
	//getch();
	return 0;
}