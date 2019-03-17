#include "Polinom.h"


TPolinom :: TPolinom ( int monoms[][2], int km ) { // êîíñòðóêòîð ïîëèíîìà èç ìàññèâà «êîýôôèöèåíò-èíäåêñ»
	PTMonom pMonom = new TMonom (0, -1);
	pHead -> SetDatValue(pMonom);
	for (int i = 0; i < km; i++) {
		pMonom = new TMonom(monoms[i][0],monoms[i][1]);
		InsLast(pMonom);
	}
}
TPolinom :: TPolinom (TPolinom &q) {    // êîíñòðóêòîð êîïèðîâàíèÿ
	PTMonom pMonom = new TMonom (0, -1);
	pHead -> SetDatValue(pMonom);
	for (q.Reset(); !q.IsListEnded(); q.GoNext()) {
		pMonom = q.GetMonom();
		InsLast(pMonom -> GetCopy());
	}
}

TPolinom TPolinom :: operator+( TPolinom &q) { // ñëîæåíèå ïîëèíîìîâ
	PTMonom pm, qm, rm;
	Reset();
	q.Reset();
	while (1) {
		pm = GetMonom();
		qm = q.GetMonom();

		if (pm->Index < qm->Index) { //ìîíîì pm ìëàäøå ìîíîìà qm, òîãäà äîáàâëÿåì qm â p
			rm = new TMonom(qm->Coeff, qm->Index);
			InsCurrent(rm);
			q.GoNext();
		}
		else if (pm->Index > qm->Index) GoNext();
		else { //èíäåêñû ðàâíû
			if (pm->Index == -1) //ïðîâåðêà, íå ãîëîâà ëè?
				break;
			pm->Coeff += qm->Coeff;
			if (pm->Coeff != 0) {
				GoNext();
				q.GoNext();
			}
			else {
				DelCurrent();
				q.GoNext();
			}
		}
		if (IsListEnded()) {
			for (;!q.IsListEnded(); q.GoNext()) {
				rm = new TMonom(qm->Coeff, qm->Index);
				InsLast(rm);
			}
			break;
		}
	}
	return *this;

	}

TPolinom & TPolinom :: operator=( TPolinom &q) { // ïðèñâàèâàíèå
	PTMonom pMonom = new TMonom (0, -1);
	pHead -> SetDatValue (pMonom);
	for (q.Reset(); !q.IsListEnded(); q.GoNext()) {
		pMonom = q.GetMonom();
		InsLast(pMonom -> GetCopy());
	}
	//delete pMonom;
	return *this;
}

bool TPolinom :: operator==( TPolinom &q) { // ñðàâíåíèå
	PTMonom pm, qm;
	Reset();
	q.Reset();
	while (1) {
		pm = GetMonom();
		qm = q.GetMonom();

		if(pm -> Index != qm -> Index)
            return false;
        if(pm->Coeff != qm -> Coeff)
            return false;
        if((pm -> Coeff != 0 && qm -> Coeff == 0) || (pm -> Coeff == 0 && qm -> Coeff != 0))
            return false;
        else {
            if(pm -> Coeff == 0 && qm -> Coeff == 0)
                return true;
            GoNext();
            q.GoNext();
        }
    }
}

bool TPolinom :: operator!=( TPolinom &q) { 
	if (*this==q) return false;
	else return true;
}


std::ostream& operator<< (std::ostream &os, TPolinom &q) {
	for (q.Reset(); !q.IsListEnded(); q.GoNext()) {
		os<<*q.GetMonom()<<std::endl;
	}
	return os;
}
