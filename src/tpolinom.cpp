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

TPolinom & TPolinom::operator += (TPolinom& q)
{
	PTMonom pm, qm, rm;
	Reset();
	q.Reset();
	while (1)
	{
		pm = GetMonom();
		qm = q.GetMonom();
		if (pm->Index < qm->Index)
		{
			rm = new TMonom(qm->Coeff, qm->Index);
			InsCurrent(rm); q.GoNext();
		}
		else if (pm->Coeff > qm->Coeff)
			GoNext();
		else 
		{
			if (pm->Index == -1)
				break;
			pm->Coeff += qm->Coeff;
			if (pm->Coeff != 0)
				GoNext();
			else
				DelCurrent();
			q.GoNext();
		}
	}
	return *this;
}


