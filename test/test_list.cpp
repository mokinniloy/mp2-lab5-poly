#include "HeadRing.h"
#include "Monom.h"

#include "gtest.h"

TEST(THeadRing, can_create_list)
{
	ASSERT_NO_THROW(THeadRing l);
}

TEST(THeadRing, created_list_is_empty_v1)
{
	THeadRing l;
	
	EXPECT_EQ(true, l.IsEmpty());
	EXPECT_EQ(0, l.GetListLeght());
}

TEST(THeadRing, created_list_is_empty_v2)
{
	THeadRing l;

	EXPECT_EQ(0, l.GetListLeght());
}

TEST(THeadRing, can_insert_first_to_empty_list_v1)
{
	THeadRing l;
	PTMonom m = new TMonom(5, 345);

	ASSERT_NO_THROW(l.InsFirst(m));
}

TEST(THeadRing, can_insert_first_to_empty_list_v2)
{
	THeadRing l;
	PTMonom m = new TMonom(5, 345);

	l.InsFirst(m);

	EXPECT_EQ(false, l.IsEmpty());
	EXPECT_EQ(1, l.GetListLeght());
}

TEST(THeadRing, insert_first_to_empty_list)
{
	THeadRing l;
	PTMonom m = new TMonom(5, 345);

	l.InsFirst(m);
	PTMonom t = (PTMonom)l.GetDatValue(FIRST);

	EXPECT_EQ(5, t->GetCoeff());
	EXPECT_EQ(345, t->GetIndex());
}

TEST(THeadRing, insert_first_to_not_empty_list)
{
	THeadRing l;
	PTMonom m1 = new TMonom(5, 345);
	PTMonom m2 = new TMonom(2, 84);

	l.InsLast(m1);
	l.InsFirst(m2);
	PTMonom t = (PTMonom)l.GetDatValue(FIRST);

	EXPECT_EQ(2, l.GetListLeght());
	EXPECT_EQ(2, t->GetCoeff());
	EXPECT_EQ(84, t->GetIndex());
}

TEST(THeadRing, can_insert_last_to_empty_list_v1)
{
	THeadRing l;
	PTMonom m = new TMonom(5, 345);

	ASSERT_NO_THROW(l.InsLast(m));
}

TEST(THeadRing, can_insert_last_to_empty_list_v2)
{
	THeadRing l;
	PTMonom m = new TMonom(5, 345);

	l.InsLast(m);

	EXPECT_EQ(false, l.IsEmpty());
	EXPECT_EQ(1, l.GetListLeght());
}

TEST(THeadRing, insert_last_to_empty_list)
{
	THeadRing l;
	PTMonom m = new TMonom(5, 345);

	l.InsLast(m);
	PTMonom t = (PTMonom)l.GetDatValue(FIRST);

	EXPECT_EQ(5, t->GetCoeff());
	EXPECT_EQ(345, t->GetIndex());
}

TEST(THeadRing, insert_last_to_not_empty_list)
{
	THeadRing l;
	PTMonom m1 = new TMonom(5, 345);
	PTMonom m2 = new TMonom(2, 84);

	l.InsFirst(m1);
	l.InsLast(m2);
	PTMonom t = (PTMonom)l.GetDatValue(LAST);

	EXPECT_EQ(2, l.GetListLeght());
	EXPECT_EQ(2, t->GetCoeff());
	EXPECT_EQ(84, t->GetIndex());
}

TEST(THeadRing, can_set_and_get_current_position)
{
	THeadRing l;
	PTMonom m1 = new TMonom(5, 345);
	PTMonom m2 = new TMonom(2, 84);
	PTMonom m3 = new TMonom(-8, 107);

	l.InsLast(m1);
	l.InsLast(m2);
	l.InsLast(m3);

	l.SetCurrentPos(1);
	PTMonom t = (PTMonom)l.GetDatValue(CURRENT);

	EXPECT_EQ(2, t->GetCoeff());
	EXPECT_EQ(84, t->GetIndex());
}

TEST(THeadRing, any_throw_when_go_next_from_stop)
{
	THeadRing l;
	PTMonom m1 = new TMonom(5, 345);

	l.InsFirst();
	l.GoNext();
	
	ASSERT_ANY_THROW(l.GoNext());
}

TEST(THeadRing, can_go_next)
{
	THeadRing l;
	PTMonom m1 = new TMonom(5, 345);
	PTMonom m2 = new TMonom(2, 84);
	PTMonom m3 = new TMonom(-8, 107);

	l.InsLast(m1);
	l.InsLast(m2);
	l.InsLast(m3);
	l.SetCurrentPos(1);

	l.GoNext();
	PTMonom t = (PTMonom)l.GetDatValue(CURRENT);

	EXPECT_EQ(-8, t->GetCoeff());
	EXPECT_EQ(107, t->GetIndex());
}

TEST(THeadRing, function_is_list_ended)
{
	THeadRing l;
	PTMonom m1 = new TMonom(5, 345);
	PTMonom m2 = new TMonom(2, 84);
	PTMonom m3 = new TMonom(-8, 107);

	l.InsLast(m1);
	l.InsLast(m2);
	l.InsLast(m3);

	l.SetCurrentPos(2);
	l.GoNext();

	EXPECT_EQ(true, l.IsListEnded());
}

TEST(THeadRing, can_insert_current_to_empty_list_v1)
{
	THeadRing l;
	PTMonom m = new TMonom(5, 345);

	ASSERT_NO_THROW(l.InsCurrent(m));
}

TEST(THeadRing, can_insert_current_to_empty_list_v2)
{
	THeadRing l;
	PTMonom m = new TMonom(5, 345);

	l.InsCurrent(m);

	EXPECT_EQ(false, l.IsEmpty());
	EXPECT_EQ(1, l.GetListLeght());
}

TEST(THeadRing, insert_current_to_empty_list)
{
	THeadRing l;
	PTMonom m = new TMonom(5, 345);

	l.InsCurrent(m);
	PTMonom t = (PTMonom)l.GetDatValue(FIRST);

	EXPECT_EQ(5, t->GetCoeff());
	EXPECT_EQ(345, t->GetIndex());
}

TEST(THeadRing, insert_current_to_not_empty_list_v1)
{
	THeadRing l;
	PTMonom m1 = new TMonom(5, 345);
	PTMonom m2 = new TMonom(2, 84);

	l.InsLast(m1);
	l.InsCurrent(m2);
	PTMonom t = (PTMonom)l.GetDatValue(FIRST);

	EXPECT_EQ(2, l.GetListLeght());
	EXPECT_EQ(2, t->GetCoeff());
	EXPECT_EQ(84, t->GetIndex());
}

TEST(THeadRing, insert_current_to_not_empty_list_v2)
{
	THeadRing l;
	PTMonom m1 = new TMonom(5, 345);
	PTMonom m2 = new TMonom(2, 84);
	PTMonom m3 = new TMonom(-8, 107);

	l.InsLast(m1);
	l.InsLast(m2);
	l.SetCurrentPos(1);
	l.InsCurrent(m3);
	l.SetCurrentPos(1);
	PTMonom t = (PTMonom)l.GetDatValue(CURRENT);

	EXPECT_EQ(3, l.GetListLeght());
	EXPECT_EQ(-8, t->GetCoeff());
	EXPECT_EQ(107, t->GetIndex());
}

TEST(THeadRing, any_throw_when_delete_first_from_empty_list)
{
	THeadRing l;

	ASSERT_ANY_THROW(l.DelFirst());
}

TEST(THeadRing, any_throw_when_delete_current_from_empty_list)
{
	THeadRing l;

	ASSERT_ANY_THROW(l.DelCurrent());
}

TEST(THeadRing, del_first_link_v1)
{
	THeadRing l;
	PTMonom m1 = new TMonom(5, 345);

	l.InsLast(m1);
	l.DelFirst();

	EXPECT_EQ(0, l.GetListLeght());
	EXPECT_EQ(true, l.IsEmpty());
}

TEST(THeadRing, del_first_link_v2)
{
	THeadRing l;
	PTMonom m1 = new TMonom(5, 345);
	PTMonom m2 = new TMonom(2, 84);
	PTMonom m3 = new TMonom(-8, 107);

	l.InsLast(m1);
	l.InsLast(m2);
	l.InsLast(m3);

	l.DelFirst();
	PTMonom t = (PTMonom)l.GetDatValue(FIRST);

	EXPECT_EQ(2, l.GetListLeght());
	EXPECT_EQ(2, t->GetCoeff());
	EXPECT_EQ(84, t->GetIndex());
}

TEST(THeadRing, del_current_link_v1)
{
	THeadRing l;
	PTMonom m1 = new TMonom(5, 345);

	l.InsLast(m1);
	l.DelCurrent();

	EXPECT_EQ(0, l.GetListLeght());
	EXPECT_EQ(true, l.IsEmpty());
}

TEST(THeadRing, del_current_link_v2)
{
	THeadRing l;
	PTMonom m1 = new TMonom(5, 345);
	PTMonom m2 = new TMonom(2, 84);
	PTMonom m3 = new TMonom(-8, 107);

	l.InsLast(m1);
	l.InsLast(m2);
	l.InsLast(m3);

	l.DelCurrent();
	PTMonom t = (PTMonom)l.GetDatValue(FIRST);

	EXPECT_EQ(2, l.GetListLeght());
	EXPECT_EQ(2, t->GetCoeff());
	EXPECT_EQ(84, t->GetIndex());
}

TEST(THeadRing, del_current_link_v3)
{
	THeadRing l;
	PTMonom m1 = new TMonom(5, 345);
	PTMonom m2 = new TMonom(2, 84);
	PTMonom m3 = new TMonom(-8, 107);

	l.InsLast(m1);
	l.InsLast(m2);
	l.InsLast(m3);
	l.SetCurrentPos(1);

	l.DelCurrent();
	l.GoNext();
	PTMonom t = (PTMonom)l.GetDatValue(CURRENT);

	EXPECT_EQ(2, l.GetListLeght());
	EXPECT_EQ(-8, t->GetCoeff());
	EXPECT_EQ(107, t->GetIndex());
}

TEST(THeadRing, del_current_link_v4)
{
	THeadRing l;
	PTMonom m1 = new TMonom(5, 345);
	PTMonom m2 = new TMonom(2, 84);
	PTMonom m3 = new TMonom(-8, 107);

	l.InsLast(m1);
	l.InsLast(m2);
	l.InsLast(m3);
	l.SetCurrentPos(2);

	l.DelCurrent();
	PTMonom t = (PTMonom)l.GetDatValue(LAST);

	EXPECT_EQ(2, l.GetListLeght());
	EXPECT_EQ(2, t->GetCoeff());
	EXPECT_EQ(84, t->GetIndex());
}

TEST(THeadRing, del_list_v1)
{
	THeadRing l;
	
	ASSERT_NO_THROW(l.DelList());
}

TEST(THeadRing, del_list_v2)
{
	THeadRing l;
	PTMonom m1 = new TMonom(5, 345);
	PTMonom m2 = new TMonom(2, 84);
	PTMonom m3 = new TMonom(-8, 107);

	l.InsLast(m1);
	l.InsLast(m2);
	l.InsLast(m3);

	l.DelList();

	EXPECT_EQ(0, l.GetListLeght());
	EXPECT_EQ(true, l.IsEmpty());

}




