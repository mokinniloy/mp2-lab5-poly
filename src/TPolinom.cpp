#include "TPolinom.h"
#include <string>
#include <algorithm>
#include <vector>
Polinom::Polinom(int monoms[][2], int km)
{
	PTMonom tmp = new TMonom(0, -1);
	pHead->SetDatValue(tmp);
	for (int i = 0; i < km; ++i)
	{
		tmp = new TMonom(monoms[i][0], monoms[i][1]);
		InsLast(tmp);
	}
}

Polinom& Polinom::operator+=(Polinom& q)
{
	PTMonom pm, qm, rm;
	Reset(); q.Reset();
	while (true)
	{
		pm = GetMonom(); qm = q.GetMonom();
		if (pm->index < qm->index)
		{
			// моном pm младше монома qm => добавление монома qm в полином р
			rm = new TMonom(qm->caf, qm->index);
			InsCurrent(rm);
			q.GoNext();
		}
		else if (pm->index > qm->index) GoNext();
		else
		{
			// индексы мономов равны (но это могут быть головы!)
			if (pm->index == -1) break;
			pm->caf += qm->caf;
			if (pm->caf != 0)
			{
				GoNext();
				q.GoNext();
			}
			else
			{
				// удаление монома с нулевым коэффициентом
				DelCurrent();
				q.GoNext();
			}
		}
	}
	return *this;
}
Polinom Polinom::operator+ (Polinom& q)
{
	Polinom tmp;
	Reset(); q.Reset();
	tmp = *this;
	tmp += q;
	return tmp;
}
Polinom::Polinom(Polinom&q)
{
	PTMonom tmp = new TMonom(0, -1);
	pHead->SetDatValue(tmp);
	for (q.Reset(); !q.IsListEnded(); q.GoNext())
	{
		tmp = q.GetMonom();
		InsLast(tmp->GetCopy());
	}
}

bool Polinom::operator==(Polinom&q) // оператор сравнения
{
	PTMonom pm, qm;
	Reset(); q.Reset();
	bool flag = true;
	while (!q.IsListEnded()||!IsListEnded())
	{
		pm = GetMonom(); qm = q.GetMonom();
		//cout << pm->caf << " " << pm->index << endl;
		//cout << qm->caf << " " << qm->index << endl;
		if (*pm!=*qm)
		{
			flag = false;
			break;
		}
		if (GoNext() != q.GoNext())
		{
			flag = false;
			break;
		}
	}
	return flag;
}

double Polinom::get(double x, double y, double z)
{
	double ans = 0.0;
	Reset();
	PTMonom tmp;
	while (!this->IsListEnded())
	{
		tmp = GetMonom();
		int st = tmp->index;
		ans += (double)(tmp->caf)*pow(x, double(st / 100))*pow(y, (st % 100) / 10)*pow(z, (st % 100) % 10);
		GoNext();
	}
	return ans;
}
Polinom& Polinom::operator=(Polinom& q) // присваивание 
{
	DelList();
	for (q.Reset(); !q.IsListEnded(); q.GoNext())
	{
		PTMonom tmp = q.GetMonom();
		InsLast(tmp->GetCopy());
	}
	return *this;
}

ostream& operator<<(ostream& os, Polinom& q)
{
	for (q.Reset(); !q.IsListEnded(); q.GoNext())
		os << *q.GetMonom() << endl;
	return os;
}

bool f(pair<int, int>a, pair<int, int>b)
{
	return a.second > b.second;
}
istream& operator>>(istream& os, Polinom& q)
{
	string s;
	os >> s;
	s += ' ';
	vector <pair<int, int>> v;
	PTMonom tmp = new TMonom(0, -1);
	q.pHead->SetDatValue(tmp);
	int st = 0;
	int k = 1;
	string temp = "";
	int p = -1;
	for (int i = 0; i < s.size(); ++i)
	{
		if (i==0&&s[i]=='-')
		{
			temp += '-';
			continue;
		}
		if (s[i] == 'x')
		{
			if (s[i + 1] >= '0'&&s[i + 1] <= '9')
			{
				st += 100 * (s[i + 1] - '0');
				i++;
			}
			else st += 100;
			continue;
		}

		if (s[i] == 'y')
		{
			if (s[i + 1] >= '0'&&s[i + 1] <= '9')
			{
				st += 10 * (s[i + 1] - '0');
				i++;
			}
			else st += 10;
			continue;
		}

		if (s[i] == 'z')
		{
			if (s[i + 1] >= '0'&&s[i + 1] <= '9')
			{
				st += 1 * (s[i + 1] - '0');
				i++;
			}
			else st += 1;
			continue;
		}
		
		if (s[i] == '+'||s[i]=='-')
		{
			if (temp == "-") k = -1;
			else k = (temp == "" ? 1 : atoi(temp.c_str()));
			if (s[i] == '+')
				temp = "";
			else
				temp = "-";
			v.push_back({ k,st });
			//tmp = new TMonom(k, st);
			//q.InsLast(tmp);
			k = 1;
			st = 0;
			continue;
		}
		if (s[i] == ' ') break;
		temp += s[i];
	}
	//cout << temp;
	if (temp == "-") k = -1;
	else k = (temp == "" ? 1 : atoi(temp.c_str()));
	v.push_back({ k,st });
	sort(v.begin(),v.end(),f);
	for (int i = 0; i < v.size(); ++i)
	{
		tmp = new TMonom(v[i].first, v[i].second);
		q.InsLast(tmp);
	}
	return os;
}
