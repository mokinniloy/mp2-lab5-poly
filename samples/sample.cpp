#include "Monom.h"
#include "DatList.h"
#include "Polinom.h"
#include <iostream>

using namespace std;

int main ()
{
	TDatList st;
	TMonom *pVal;

	cout<<"Test of list "<<endl;
	for (int i = 0; i < 5; i++) {
		pVal = new TMonom (i, 10*i);
		st.TDatList::InsLast(pVal);
		cout<<"Put in list value "<<pVal->GetCoeff()<<"; "<<pVal->GetIndex()<<endl;
	}
	//Ïå÷àòü ñïèñêà
	for (st.Reset(); !st.IsListEnded(); st.GoNext()) {
		pVal = (TMonom*)st.GetDatValue();
		cout<<"Get of list value "<<pVal->GetCoeff()<<"; "<<pVal->GetIndex()<<endl;
	}
	st.DelList();

	cout<<"Testing TPolinom: "<<endl;
	int ms1[][2] = { {1, 543}, {3, 432}, {5, 321}, {7, 210}, {9, 100} };
	int mn1 = sizeof(ms1)/(2*sizeof(int));
	TPolinom pol1 (ms1, mn1);
	cout<<"First polinom\n"<<pol1<<endl;
	int ms2[][2] = { {2, 643}, {4, 432}, {-5, 321}, {8, 110}, {10, 50} };
	int mn2 = sizeof(ms2)/(2*sizeof(int));
	TPolinom pol2 (ms2, mn2);
	cout<<"Second polinom\n"<<pol2<<endl;
	TPolinom r;
	r = pol1 + pol2;
	cout<<"Result: \n"<<r<<endl;

	cout<<"Click enter..."<<endl;

	return 0;
}
