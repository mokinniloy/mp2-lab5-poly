#include "DatList.h"
#include "Polinom.h"
#include <gtest.h>
#include <iostream>

using namespace std;


 TEST(TDatList, can_create_list) {
    ASSERT_NO_THROW(TDatList tmp);
}

TEST(TDatList, is_empty_is_correct_when_list_empty)
{
	TDatList list;

	EXPECT_EQ(1, list.IsEmpty());
}

TEST(TDatList, is_empty_is_correct_when_list_no_empty)
{
	TDatList list;
	PTMonom pm = new TMonom(4, 312);
	list.InsFirst(pm);

	EXPECT_EQ(0, list.IsEmpty());
} 

TEST(TDatList, ListLen_is_correct)
{
	TDatList list;
	PTMonom pm;
	for (int i = 0; i < 3; ++i)
	{
		pm = new TMonom(i * 2, i * 10);
		list.InsLast(pm);
	}

	EXPECT_EQ(3, list.GetListLength());
}

 TEST(TDatList, GetCurrentPos_is_correct)
{
	TDatList list;
	PTMonom pm;
	for (int i = 0; i < 3; ++i)
	{
		pm = new TMonom(10 * i, 100 * i);
		list.InsLast(pm);
	}
	list.GoNext(); list.GoNext(); list.GoNext();

	EXPECT_EQ(3, list.GetCurrentPos());
}

TEST(TDatList, GoNext_is_correct)
{
	TDatList list;
	PTMonom pm;
	TMonom mon(3, 123);
	for (int i = 0; i < 5; i++) {
		pm = new TMonom(i, 123);
		list.InsLast(pm);
	}
	list.GoNext(); list.GoNext(); list.GoNext();

	EXPECT_EQ(1, (*((TMonom*)list.GetDatValue()))==mon);

}

TEST (TDatList, InsFirst_is_correct)
{
	TDatList list;
	PTMonom pm;
	TMonom mon(4, 123);
	for (int i = 0; i < 5; i++) {
		pm = new TMonom(i, 123);
		list.InsFirst(pm);
	}

 	EXPECT_EQ(1, (*((TMonom*)list.GetDatValue(BEGIN)))==mon);
}

TEST(TDatList, SetCurrentPos_is_correct)
{
	TDatList list;
	PTMonom pm;
	for (int i = 1; i < 5; i++)
	{
		pm = new TMonom(i, 123);
		list.InsLast(pm);
	}
	list.SetCurrentPos(3);

	EXPECT_EQ(4, ((TMonom*)list.GetDatValue())->GetCoeff() );

 }

TEST(TDatList, GetCurrentPos_is_correct_when_Reset)
{
	TDatList list;
	PTMonom pm;
	for (int i = 1; i < 5; i++)
	{
		pm = new TMonom(i, 123);
		list.InsLast(pm);
	}
	list.SetCurrentPos(3);
	list.Reset();

	EXPECT_EQ(0, list.GetCurrentPos());
 }

TEST(TDatList, Reset_is_correct)
{
	TDatList list;
	PTMonom pm;
	TMonom mon(1, 123);
	for (int i = 1; i < 5; ++i)
	{
		pm = new TMonom(i, 123);
		list.InsLast(pm);
	}
	list.SetCurrentPos(3);
	list.Reset();

	EXPECT_EQ(1, (*((TMonom*)list.GetDatValue(BEGIN)))==mon);
 }

TEST(TDatList, DelList_is_correct)
{
 	TDatList list;
	PTMonom pm;
	for (int i = 1; i < 5; i++)
	{
		pm = new TMonom(i, 123);
		list.InsLast(pm);
	}
	list.DelList();

	EXPECT_EQ(1, list.IsEmpty());
 }

TEST(TDatList, DelCurrent_is_correct)
{
	TDatList list;
	PTMonom pm;
	for (int i = 1; i < 5; i++)
	{
		pm = new TMonom(i, 123);
		list.InsLast(pm);
	}
	list.SetCurrentPos(2);
	list.DelCurrent();
	list.SetCurrentPos(2);

	EXPECT_EQ(4, ((TMonom*)list.GetDatValue())->GetCoeff());
 }

TEST(TDatList,DelFirst_is_correct)
{
	TDatList list;
	PTMonom pm;
	for (int i = 1; i < 5; i++)
	{
		pm = new TMonom(i*5, 5);
		list.InsLast(pm);
	}
	list.DelFirst();

	EXPECT_EQ(3, list.GetListLength());
	EXPECT_EQ(10, ((TMonom*)list.GetDatValue())->GetCoeff());
}

TEST(TDatList,IsListEnded_is_correct)
{
	TDatList list;
	PTMonom pm;
	for (int i = 1; i <= 5; i++)
	{
		pm = new TMonom(i*5, 5);
		list.InsLast(pm);
	}
	list.SetCurrentPos(4);

	EXPECT_EQ(0, list.IsListEnded());

	list.GoNext();

	EXPECT_EQ(1, list.IsListEnded());
}

TEST(TDatList,InsLast_is_correct)
{
	TDatList list;
	PTMonom pm;
	for (int i = 1; i <= 5; i++)
	{
		pm = new TMonom(i*5, 5);
		list.InsLast(pm);
	}
	pm = new TMonom(3, 333);
	EXPECT_EQ(25, ((TMonom*)list.GetDatValue(END))->GetCoeff() );

	list.InsLast(pm);

	EXPECT_EQ(3, ((TMonom*)list.GetDatValue(END))->GetCoeff());
}

TEST(TDatList,InsFirst_is_correct_2)
{
	TDatList list;
	PTMonom pm;
	for (int i = 1; i <= 5; i++)
	{
		pm = new TMonom(i*5, 5);
		list.InsFirst(pm);
	}
	pm = new TMonom(3, 333);
	EXPECT_EQ(25, ((TMonom*)list.GetDatValue(BEGIN))->GetCoeff());

	list.InsFirst(pm);

	EXPECT_EQ(3, ((TMonom*)list.GetDatValue(BEGIN))->GetCoeff());
}

TEST(TDatList,InsCurrent_is_correct)
{
	TDatList list;
	PTMonom pm;
	for (int i = 1; i <= 5; i++)
	{
		pm = new TMonom(i*5, 5);
		list.InsLast(pm);
	}
	list.SetCurrentPos(2);

	EXPECT_EQ(15,((TMonom*)list.GetDatValue())->GetCoeff());
	EXPECT_EQ(5, list.GetListLength());

	pm = new TMonom(3, 333);
	list.InsCurrent(pm);

	EXPECT_EQ(6, list.GetListLength());
	EXPECT_EQ(3, ((TMonom*)list.GetDatValue())->GetCoeff());
}

//////////////////////////////////////////////////////////////

TEST(TPolinom, can_create_polinom)
{
	int ms[][2] = {{1, 123}, {2, 234}, {3, 345}};

	ASSERT_NO_THROW(TPolinom p(ms, 3));
}


TEST(TPolinom, can_create_polinom_without_parameters)
{
	ASSERT_NO_THROW(TPolinom p);
}

 TEST(TPolinom, can_get_monom)
{
	int ms[][2] = {{1, 123}, {2, 234}, {3, 345}};
	TPolinom p(ms, 3);
	TMonom mon(1, 123);

	EXPECT_EQ(1, mon == *p.GetMonom());
}
TEST(TPolinom, can_add_polinoms)
{
	int ms1[][2] = {{1, 555}, {3,444}, {5,222}};
	TPolinom p(ms1, 3);
	int ms2[][2] = {{2, 666}, {4,333}};
	TPolinom q(ms2, 2);
	int ms[][2] = {{2,666}, {1,555}, {3,444}, {4,333}, {5,222}};
	TPolinom tmp(ms, 5);
	p = q + p;

	EXPECT_EQ(true, tmp == q);
}


 TEST(TPolinom, can_equate_two_polinom)
{
	int ms1[][2] = {{1,543},{2,432},{3,321}};
	TPolinom p(ms1, 3);
	TPolinom t;
	t = p;

	EXPECT_EQ(true, t==p);
}

 TEST(TPolinom, correct_delete_first_link)
{
	int m[][2] = {{1, 543}, {-3,362}, {6,23}};
	TPolinom p(m, 3);
	p.DelFirst();
	PTMonom t = p.GetMonom();

	EXPECT_EQ(-3, t->GetCoeff());
}
TEST(TPolinom, can_add_polinoms_2)
{
	int m[][2] = {{1,543}, {-2,333}, {-5,11}};
	int m1[][2] = {{-1,543}, {2,333}, {5,11}};
	TPolinom p1(m, 3);
	TPolinom p2(m1, 3);
	p1 = p1 + p2;
	TPolinom res;

	EXPECT_EQ(true, res == p1);
}



