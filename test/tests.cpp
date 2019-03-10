#include "gtest.h"
#include "tpolinom.h"


TEST(TDatList, can_create_list) {
	ASSERT_NO_THROW(TDatList t);
}

TEST(TDatList, empty_list_is_empty_1)
{
	TDatList t;
	EXPECT_EQ(true, t.IsEmpty());
}

TEST(TDatList, empty_list_is_empty_2)
{
	TDatList t;
	EXPECT_EQ(0, t.GetListLength());
}

TEST(TDatList, can_insert_first_elem_1)
{
	TDatList t;
	PTMonom mon = new TMonom(1, 2);

	ASSERT_NO_THROW(t.InsFirst(mon));
}

TEST(TDatList, can_insert_first_elem_2)
{
	TDatList t;
	PTMonom p = new TMonom(2, 3);
	PTMonom q = new TMonom(1, 4);

	t.InsFirst(p);
	t.InsFirst(q);

	EXPECT_EQ(2, t.GetListLength());
}

TEST(TDatList, can_insert_current_elem)
{
	TDatList t;
	PTMonom p = new TMonom(2, 3);
	PTMonom q = new TMonom(1, 4);

	t.InsCurrent(p);
	t.InsCurrent(q);

	EXPECT_EQ(2, t.GetListLength());
}

TEST(TDatList, can_insert_last_elem)
{
	TDatList t;
	PTMonom p = new TMonom(2, 3);
	PTMonom q = new TMonom(1, 4);

	t.InsLast(p);
	t.InsLast(q);

	EXPECT_EQ(2, t.GetListLength());
}

TEST(TDatList, can_delete_first)
{
	TDatList t;
	PTMonom p = new TMonom(2, 3);
	PTMonom q = new TMonom(1, 4);

	t.InsFirst(p);
	t.InsFirst(q);
	t.DelFirst();

	EXPECT_EQ(1, t.GetListLength());
}

TEST(TDatList, can_delete_current)
{
	TDatList t;
	PTMonom p = new TMonom(2, 3);
	PTMonom q = new TMonom(1, 4);

	t.InsFirst(p);
	t.InsFirst(q);
	t.DelCurrent();

	EXPECT_EQ(1, t.GetListLength());
}

TEST(TDatList, can_delete_list)
{
	TDatList t;
	PTMonom p = new TMonom(2, 3);
	PTMonom q = new TMonom(1, 4);

	t.InsFirst(p);
	t.InsFirst(q);

	ASSERT_NO_THROW(t.DelList());
}

TEST(TDatList, can_reset)
{
	TDatList t;
	PTMonom p = new TMonom(2, 3);
	PTMonom q = new TMonom(1, 4);

	t.InsFirst(p);
	t.InsFirst(q);
	t.Reset();

	EXPECT_EQ(0, t.GetCurrentPos());
}

TEST(TDatList, can_go_next)
{
	TDatList t;
	PTMonom p = new TMonom(2, 3);
	PTMonom q = new TMonom(1, 4);

	t.InsFirst(p);
	t.InsFirst(q);
	t.Reset();
	t.GoNext();

	EXPECT_EQ(1, t.GetCurrentPos());
}

TEST(TDatList, can_set_current_position)
{
	TDatList t;
	PTMonom p = new TMonom(2, 3);
	PTMonom q = new TMonom(1, 4);

	t.InsFirst(p);
	t.InsFirst(q);
	t.Reset();
	t.SetCurrentPos(1);

	EXPECT_EQ(1, t.GetCurrentPos());
}