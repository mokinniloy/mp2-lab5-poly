#include <gtest.h>
#include "TDatList.h"
#include "TPolinom.h"
TEST(TDatList, can_create_list) {
	ASSERT_NO_THROW(TDatList t);
}
TEST(TDatList, isEmpty_work_correct)
{
	TDatList t;
	EXPECT_EQ(1, t.IsEmpty());
}
TEST(TDatList, ListLen_is_correct)
{
	TDatList t;
	TMonom * tmp;
	for (int i = 0; i < 5; ++i)
	{
		tmp = new TMonom(i, i * 10);
		t.InsLast(tmp);
	}
	EXPECT_EQ(5, t.GetListLength());
}

TEST(TDatList, GetCurrentPos_is_correct)
{
	TDatList t;
	TMonom * tmp;
	for (int i = 0; i < 10; ++i)
	{
		tmp = new TMonom(i, 126 * i);
		t.InsLast(tmp);
	}
	t.GoNext(); t.GoNext();
	EXPECT_EQ(2, t.GetCurrentPos());
}
TEST(TDatList, GoNext_is_correct)
{
	TDatList t;
	TMonom * tmp;
	for (int i = 0; i < 10; ++i)
	{
		tmp = new TMonom(i, 126 * i);
		t.InsLast(tmp);
	}
	t.GoNext(); t.GoNext();
	TMonom q(2,252);
	EXPECT_EQ(1,(*((TMonom*)t.GetDatValue()))==q);
	
}
TEST (TDatList, InsFirst_is_correct)
{
	TDatList t;
	TMonom * tmp;
	for (int i = 0; i < 10; ++i)
	{
		tmp = new TMonom(i, 126 * i);
		t.InsFirst(tmp);
	}

	EXPECT_EQ(tmp, t.GetDatValue());
}
TEST(TDatList,SetCurrentPos_is_correct)
{
	TDatList t;
	TMonom* tmp;
	for (int i = 1; i <=10; ++i)
	{
		tmp = new TMonom(i, 2);
		t.InsLast((PTDatValue)tmp);
	}
	t.SetCurrentPos(8);
	EXPECT_EQ(9, ((TMonom*)t.GetDatValue())->GetCaf() );
	
}
TEST(TDatList,Reset_is_correct)
{
	TDatList t;
	TMonom* tmp;
	for (int i = 1; i <= 10; ++i)
	{
		tmp = new TMonom(i, 2);
		t.InsLast((PTDatValue)tmp);
	}
	t.SetCurrentPos(8);
	t.Reset();
	EXPECT_EQ(0, t.GetCurrentPos());

}
TEST(TDatList, DelList_is_correct)
{

	TDatList t;
	TMonom* tmp;
	for (int i = 1; i <= 10; ++i)
	{
		tmp = new TMonom(i, 2);
		t.InsLast((PTDatValue)tmp);
	}
	t.DelList();
	EXPECT_EQ(1, t.IsEmpty());

}
TEST(TDatList,DelCurrent_is_correct)
{
	TDatList t;
	TMonom* tmp;
	for (int i = 1; i <= 10; ++i)
	{
		tmp = new TMonom(i, 2);
		t.InsLast((PTDatValue)tmp);
	}
	t.SetCurrentPos(8);
	t.DelCurrent();
	EXPECT_EQ(10, ((TMonom*)t.GetDatValue())->GetCaf());
	
}
TEST(TDatList,DelFirst_is_correct)
{
	TDatList t;
	TMonom* tmp;
	for (int i = 1; i <= 10; ++i)
	{
		tmp = new TMonom(i, 2);
		t.InsLast((PTDatValue)tmp);
	}
	t.DelFirst();
	EXPECT_EQ(9, t.GetListLength());
	EXPECT_EQ(2, ((TMonom*)t.GetDatValue())->GetCaf());
}
TEST(TDatList,IsListEnded_is_correct)
{
	TDatList t;
	TMonom* tmp;
	for (int i = 1; i <= 10; ++i)
	{
		tmp = new TMonom(i, 2);
		t.InsLast((PTDatValue)tmp);
	}
	t.SetCurrentPos(9);
	EXPECT_EQ(0, t.IsListEnded());
	t.GoNext();
	EXPECT_EQ(1, t.IsListEnded());
}
TEST(TDatList,InsLast_is_correct)
{
	TDatList t;
	TMonom* tmp;
	for (int i = 1; i <= 10; ++i)
	{
		tmp = new TMonom(i, 2);
		t.InsLast((PTDatValue)tmp);
	}
	tmp = new TMonom(34, 242);
	EXPECT_EQ(10, ((TMonom*)t.GetDatValue(LAST))->GetCaf() );
	t.InsLast(tmp);
	EXPECT_EQ(34, ((TMonom*)t.GetDatValue(LAST))->GetCaf());
}
TEST(TDatList,InsFirst_is_correct_2)
{
	TDatList t;
	TMonom* tmp;
	for (int i = 1; i <= 10; ++i)
	{
		tmp = new TMonom(i, 2);
		t.InsFirst((PTDatValue)tmp);
	}
	tmp = new TMonom(34, 242);
	EXPECT_EQ(10, ((TMonom*)t.GetDatValue(FIRST))->GetCaf());
	t.InsFirst(tmp);
	EXPECT_EQ(34, ((TMonom*)t.GetDatValue(FIRST))->GetCaf());
}
TEST(TDatList,InsCurrent_is_correct)
{
	TDatList t;
	TMonom* tmp;
	for (int i = 1; i <= 10; ++i)
	{
		tmp = new TMonom(i, 2);
		t.InsLast((PTDatValue)tmp);
	}
	t.SetCurrentPos(5);
	EXPECT_EQ(6,((TMonom*)t.GetDatValue())->GetCaf());
	EXPECT_EQ(10, t.GetListLength());
	tmp = new TMonom(34, 242);
	t.InsCurrent(tmp);
	EXPECT_EQ(11, t.GetListLength());
	EXPECT_EQ(34, ((TMonom*)t.GetDatValue())->GetCaf());
}

TEST(Polinom,can_create_Polinom_without_parameters)
{
	ASSERT_NO_THROW(Polinom t);
}

TEST(Polinom,can_create_Polinom_with_parameters)
{
	int ms1[][2] = { { 1,543 },{ 3,432 },{ 5,321 } };
	ASSERT_NO_THROW(Polinom p(ms1, 3));
}

TEST(Polinom,GetMonom_is_correct)
{
	int ms1[][2] = { { 1,543 },{ 3,432 },{ 5,321 } };
	int size = sizeof(ms1) / (sizeof(int) * 2);
	Polinom t(ms1, size);
	t.GoNext();
	TMonom q(3, 432);
	EXPECT_EQ(1,q== *t.GetMonom());
}
TEST(Polinom,operator_plus_is_correct)
{
	int ms1[][2] = { { 1,543 },{ 3,432 },{ 5,321 } };
	int mn1 = sizeof(ms1) / (2 * sizeof(int));
	Polinom p(ms1, mn1);
	int ms2[][2] = { { 2,643 },{ 4,431 } };
	int mn2 = sizeof(ms2) / (2 * sizeof(int));
	Polinom q(ms2, mn2);
	int m[][2] = { {2,643},{1,543}, {3,432},{4,431}, {5,321} };
	Polinom tmp(m, 5);
	p+=q;
	EXPECT_EQ(1, tmp == q);
}

TEST(Polinom,operator_get_is_correct)
{
	int m[][2] = { {5,211},{6,31},{-4,4} };
	Polinom t(m, 3);
	EXPECT_EQ(-3314.5482182399996, t.get(5, -3.4, 3.78));
}

TEST(Polinom,operator_equal_is_correct)
{
	int ms1[][2] = { { 1,543 },{ 3,432 },{ 5,321 } };
	int mn1 = sizeof(ms1) / (2 * sizeof(int));
	Polinom p(ms1, mn1);
	Polinom t;
	t = p;
	EXPECT_EQ(1, t==p);
}

TEST(Polinom,operator_plusRavno_is_correct)
{
	int ms1[][2] = { { 1,543 },{ 3,432 },{ 5,321 } };
	int mn1 = sizeof(ms1) / (2 * sizeof(int));
	Polinom p(ms1, mn1);
	int m[][2] = { {4,5} };
	Polinom q(m, 1);
	int e[][2] = {{ 1,543 },{ 3,432 },{ 5,321 },{4,5}};
	Polinom z(e,4);
	//z = p + q;
	p += q;
	EXPECT_EQ(1, z==p);
}

TEST(Polinom,DelFirst_is_correct)
{
	int m[][2] = { {1,344},{-3,233},{6,23} };
	Polinom a(m, 3);
	a.DelFirst();
	PTMonom t = a.GetMonom();
	EXPECT_EQ(-3, t->GetCaf());
}
TEST(Polinom, operator_plus_v_0)
{
	int m[][2] = { { 1,344 },{ -3,233 },{ 6,23 } };
	int m1[][2] = { { -1,344 },{ 3,233 },{ -6,23 } };
	Polinom a(m, 3);
	Polinom b(m1, 3);
	a+=b;
	Polinom q;
	EXPECT_EQ(1, q == a);
}
TEST(Polinom,operator_plus_Ravno_2)
{
	int m0[][2] = { { 1,344 },{ -3,233 },{ 6,23 } };
	int m1[][2] = { { 6,342 },{ 3,33 }};
	int m2[][2] = { { 3,33 }};
	int m3[][2] = { { 1,344 },{6,342}, { -3,233 },{ 6,23 } };
	Polinom a(m0, 3), b(m1, 2), c(m2, 1), d(m3, 4);
	a+=b;
	c+=d;
	EXPECT_EQ(1, a == c);
}
