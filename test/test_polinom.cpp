#include "Polinom.h"
#include "gtest.h"

TEST(TPolinom, cant_create_monom_with_wrong_index_v1)
{
	ASSERT_ANY_THROW(PTMonom m = new TMonom(5, -231));
}

TEST(TPolinom, cant_create_monom_with_wrong_index_v2)
{
	ASSERT_ANY_THROW(PTMonom m = new TMonom(5, 1000));
}

TEST(TPolinom, can_create_polinom)
{
	int ms[][2] = { {-5,433}, {2,809}, {18,42}, {4,6} };

	ASSERT_NO_THROW(TPolinom t(ms, 4));
}

TEST(TPolinom, create_polinom_v1)
{
	int ms[][2] = { {-5,433}, {2,809}, {18,42}, {4,6} };
	TPolinom t(ms, 4);

	EXPECT_EQ(false, t.IsEmpty());
	EXPECT_EQ(4, t.GetListLeght());
}

TEST(TPolinom, create_polinom_v2)
{
	int i = 0;
	int ms[][2] = { {-5,433}, {2,809}, {18,6}, {4,42} };
	TPolinom t(ms, 4);

	for (t.Reset();!(t.IsListEnded());)
	{
		i = t.GetMonom()->GetIndex();
		t.GoNext();
		EXPECT_EQ(true, i >= t.GetMonom()->GetIndex());
	}
}

TEST(TPolinom, create_polinom_v3)
{
	int i = 0;
	int ms1[][2] = { {-5,433}, {2,809}, {18,6}, {4,42} };
	int ms2[][2] = { {2,809},{-5,433},{4,42},{18,6} };
	TPolinom t(ms1, 4);

	for (t.Reset();!(t.IsListEnded());t.GoNext(),i++)
	{
		EXPECT_EQ(ms2[i][0], t.GetMonom()->GetCoeff());
		EXPECT_EQ(ms2[i][1], t.GetMonom()->GetIndex());
	}
}

TEST(TPolinom, copy_constructor_v1)
{
	int ms[][2] = { {-5,433}, {2,809}, {18,6}, {4,42} };
	TPolinom p1(ms, 4);
	
	ASSERT_NO_THROW(TPolinom p2(p1));
}

TEST(TPolinom, copy_constructor_v2)
{
	int ms[][2] = { {-5,433}, {2,809}, {18,6}, {4,42} };
	TPolinom p1(ms, 4);
	TPolinom p2(p1);

	EXPECT_NE(&p1, &p2);
}

TEST(TPolinom, copy_constructor_v3)
{
	int ms[][2] = { {-5,433}, {2,809}, {18,6}, {4,42} };
	TPolinom p1(ms, 4);
	TPolinom p2(p1);

	EXPECT_EQ(p1.GetListLeght(), p2.GetListLeght());
}

TEST(TPolinom, copy_constructor_v4)
{
	int i = 0;
	int ms1[][2] = { {-5,433}, {2,809}, {18,6}, {4,42} };
	int ms2[][2] = { {2,809},{-5,433},{4,42},{18,6} };
	TPolinom p1(ms1, 4);
	TPolinom p2(p1);

	for (p2.Reset();!(p2.IsListEnded());p2.GoNext(), i++)
	{
		EXPECT_EQ(ms2[i][0], p2.GetMonom()->GetCoeff());
		EXPECT_EQ(ms2[i][1], p2.GetMonom()->GetIndex());
	}
}

TEST(TPolinom, assignment_operator_v1)
{
	int ms1[][2] = { {-5,433}, {2,809}, {18,6}, {4,42} };
	int ms2[][2] = { {2,405} };
	TPolinom p1(ms1, 4), p2(ms2, 1);

	ASSERT_NO_THROW(p2 = p1);
}

TEST(TPolinom, assignment_operator_v2)
{
	int ms1[][2] = { {-5,433}, {2,809}, {18,6}, {4,42} };
	int ms2[][2] = { {2,405} };
	TPolinom p1(ms1, 4), p2(ms2, 1);

	p2 = p1;

	EXPECT_NE(&p1, &p2);
}

TEST(TPolinom, assignment_operator_v3)
{
	int ms1[][2] = { {-5,433}, {2,809}, {18,6}, {4,42} };
	int ms2[][2] = { {2,405} };
	TPolinom p1(ms1, 4), p2(ms2, 1);

	p2 = p1;

	EXPECT_EQ(p1.GetListLeght(), p2.GetListLeght());
}

TEST(TPolinom, assignment_operator_v4)
{
	int i = 0;
	int ms1[][2] = { {-5,433}, {2,809}, {18,6}, {4,42} };
	int ms2[][2] = { {2,809},{-5,433},{4,42},{18,6} };
	int ms3[][2] = { {2,405} };
	TPolinom p1(ms1, 4), p2(ms3, 1);

	p2 = p1;

	for (p2.Reset();!(p2.IsListEnded());p2.GoNext(), i++)
	{
		EXPECT_EQ(ms2[i][0], p2.GetMonom()->GetCoeff());
		EXPECT_EQ(ms2[i][1], p2.GetMonom()->GetIndex());
	}
}

TEST(TPolinom, addition_operator_v1)
{
	int ms1[][2] = { {-5,433}, {7,351}, {3,525} };
	int ms2[][2] = { {-6,218}, {4,326} };
	TPolinom p1(ms1, 3), p2(ms2, 2);

	ASSERT_NO_THROW(p1 += p2);
}

TEST(TPolinom, addition_operator_v2)
{
	int i = 0;
	int ms1[][2] = { {-5,433}, {7,351}, {3,525} };
	int ms2[][2] = { {-6,218}, {4,326} };
	int ms3[][2] = { {3,525}, {-5,433}, {7,351}, {4,326}, {-6,218} };
	TPolinom p1(ms1, 3), p2(ms2, 2);

	p1 += p2;

	EXPECT_EQ(5, p1.GetListLeght());

	for (p1.Reset();!(p1.IsListEnded());p1.GoNext(),i++)
	{
		EXPECT_EQ(ms3[i][0], p1.GetMonom()->GetCoeff());
		EXPECT_EQ(ms3[i][1], p1.GetMonom()->GetIndex());
	}
}

TEST(TPolinom, addition_operator_v3)
{
	int i = 0;
	int ms1[][2] = { {-5, 433}, {7,351}, {3,525} };
	int ms2[][2] = { {-6,618}, {4,726} };
	int ms3[][2] = { {4,726}, {-6,618}, {3,525}, {-5, 433}, {7,351} };
	TPolinom p1(ms1, 3), p2(ms2, 2);

	p1 += p2;

	EXPECT_EQ(5, p1.GetListLeght());

	for (p1.Reset();!(p1.IsListEnded());p1.GoNext(), i++)
	{
		EXPECT_EQ(ms3[i][0], p1.GetMonom()->GetCoeff());
		EXPECT_EQ(ms3[i][1], p1.GetMonom()->GetIndex());
	}
}

TEST(TPolinom, addition_operator_v4)
{
	int i = 0;
	int ms1[][2] = { {-5, 433}, {7,351}, {3,525} };
	int ms2[][2] = { {5,433}, {4,525} };
	int ms3[][2] = { {7,525}, {7,351}};
	TPolinom p1(ms1, 3), p2(ms2, 2);

	p1 += p2;

	EXPECT_EQ(2, p1.GetListLeght());

	for (p1.Reset();!(p1.IsListEnded());p1.GoNext(), i++)
	{
		EXPECT_EQ(ms3[i][0], p1.GetMonom()->GetCoeff());
		EXPECT_EQ(ms3[i][1], p1.GetMonom()->GetIndex());
	}
}

TEST(TPolinom, addition_operator_v5)
{
	int i = 0;
	int ms1[][2] = { {-5, 433}, {7,751}, {3,525} };
	int ms2[][2] = { {-6,218}, {4,626} };
	int ms3[][2] = { {7,751}, {4,626},{3,525},{-5, 433},{-6,218} };
	TPolinom p1(ms1, 3), p2(ms2, 2);

	p1 += p2;

	EXPECT_EQ(5, p1.GetListLeght());

	for (p1.Reset();!(p1.IsListEnded());p1.GoNext(), i++)
	{
		EXPECT_EQ(ms3[i][0], p1.GetMonom()->GetCoeff());
		EXPECT_EQ(ms3[i][1], p1.GetMonom()->GetIndex());
	}
}

TEST(TPolinom, addition_operator_v6)
{
	int i = 0;
	int ms1[][2] = { {-5, 433}, {7,751}, {3,525} };
	int ms2[][2] = { {-7,751}, {5,433}, {-3,525} };
	TPolinom p1(ms1, 3), p2(ms2, 3);

	p1 += p2;

	EXPECT_EQ(0, p1.GetListLeght());
}

