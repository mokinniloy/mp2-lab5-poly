#include "gtest.h"
#include "DatList.h"
#include "Polinom.h"

TEST(TDatList, can_create_list)
{
	ASSERT_NO_THROW(TDatList list);
}

TEST(TDatList, is_empty)
{
	TDatList list;

	EXPECT_TRUE(list.IsEmpty());
}

TEST(TDatList, is_empty_2)
{
	TDatList list;
	list.InsFirst();

	EXPECT_FALSE(list.IsEmpty());
}

TEST(TDatList, can_insert_first)
{
	TDatList list;
	ASSERT_NO_THROW(list.InsFirst());
}

TEST(TDatList, can_insert_current)
{
	TDatList list;
	ASSERT_NO_THROW(list.InsCurrent());
}

TEST(TDatList, can_insert_last)
{
	TDatList list;
	ASSERT_NO_THROW(list.InsLast());
}

TEST(TDatList, get_list_length)
{
	TDatList list;
	EXPECT_EQ(0, list.GetListLength());
}

TEST(TDatList, get_list_length_2)
{
	TDatList list;
	list.InsCurrent();
	list.InsFirst();
	list.InsLast();

	EXPECT_EQ(3, list.GetListLength());
}

TEST(TDatList, can_set_current_position)
{
	TDatList list;
	ASSERT_NO_THROW(list.SetCurrentPos(3));
}

TEST(TDatList, DISABLED_is_set_current_position_correct)
{
	TDatList list;
	list.SetCurrentPos(3);

	EXPECT_EQ(3, list.GetCurrentPos());
}

TEST(TDatList, DISABLED_is_current_position_correct)
{
	TDatList list;
	list.InsLast();
	list.InsLast();

	EXPECT_EQ(2, list.GetCurrentPos());
}

TEST(TDatList, can_delete_first)
{
	TDatList list;
	ASSERT_NO_THROW(list.DelFirst());
}

TEST(TDatList, can_delete_last)
{
	TDatList list;
	ASSERT_NO_THROW(list.DelCurrent());
}

TEST(TDatList, can_delete_list)
{
	TDatList list;
	list.InsCurrent();
	list.InsCurrent();
	ASSERT_NO_THROW(list.DelList());
}

TEST(TDatList, does_deletefirst_decrease_listlen)
{
	TDatList list;
	list.InsCurrent();
	list.InsCurrent();
	list.DelFirst();
	EXPECT_EQ(1, list.GetListLength());
}

TEST(TPolinom, can_create_a_polinom)
{
	int monoms[3][2] = {(3, 301), (-2, 22), (3, 0)};

	ASSERT_NO_THROW(TPolinom(monoms, 3));
}

TEST(TPolinom, can_copy_the_polinom)
{
	int monoms[3][2] = { (3, 301), (-2, 22), (3, 0) };
	TPolinom p = TPolinom(monoms, 3);
	TPolinom q;

	ASSERT_NO_THROW(q = TPolinom(p));
}

TEST(TPolinom, can_assign_the_polinom)
{
	int monoms[3][2] = { (3, 301), (-2, 22), (3, 0) };
	TPolinom p = TPolinom(monoms, 3);
	TPolinom q;

	ASSERT_NO_THROW(q = p);
}

TEST(TPolinom, can_add_polinoms)
{
	int monoms_p[3][2] = { (3, 525), (-5, 433), (7, 351) };
	int monoms_q[2][2] = { (4, 326), (-6, 218)};

	TPolinom p = TPolinom(monoms_p, 3);
	TPolinom q = TPolinom(monoms_q, 3);

	ASSERT_NO_THROW(p + q);
}




