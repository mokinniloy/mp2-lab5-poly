#include "tpolinom.h"

TPolinom::TPolinom(int monoms[][2], int km)
{
	PTMonom pMonom = new TMonom(0, -1);
	pHead->SetDatValue(pMonom);

	for (int i = 0; i < km; ++i)
	{
		pMonom = new TMonom(monoms[i][0], monoms[i][1]);
		InsLast(pMonom);
	}
}


