#include "gtest.h"
#include "TDatList.h"
#include "THeadRing.h"
#include "TPolinom.h"

TEST(TDatList, crate_object)
{
    ASSERT_NO_THROW(TDatList a);
}

TEST(TDatList, insertions)
{
    TDatList a;
    EXPECT_NO_THROW(a.InsFirst());
    EXPECT_NO_THROW(a.InsLast());
    EXPECT_NO_THROW(a.InsCurrent());
}

TEST(TDatList, deletes)
{
    TDatList a;
    a.InsFirst();
    a.InsFirst();
    a.InsFirst();
    EXPECT_NO_THROW(a.DelFirst());
    EXPECT_NO_THROW(a.DelCurrent());
    EXPECT_NO_THROW(a.DelCurrent());
}

TEST(TDatList, correct_after_delete)
{
    TDatList a;
    a.InsFirst();
    a.InsFirst();
    a.InsFirst();
    a.DelFirst();
    a.DelFirst();
    a.DelFirst();
    EXPECT_EQ(0,a.GetListLength());
    EXPECT_ANY_THROW(a.GetDatValue());
}

TEST(TDatList, cant_delete_stop_elem)
{
    TDatList a;
    a.InsFirst();
    a.InsFirst();
    a.GoNext();
    a.GoNext();
    EXPECT_EQ(a.GetListLength(), a.GetCurrentPos());
    int b = a.GetListLength();
    a.DelCurrent();
    EXPECT_EQ(b, a.GetListLength());
}

TEST(TDatList, can_get_value)
{
    TDatList a;
    a.InsFirst();
    ASSERT_NO_THROW(a.GetDatValue());
}

TEST(THeadRing, crate_object)
{
    ASSERT_NO_THROW(THeadRing a);
}

TEST(THeadRing, insertions)
{
    THeadRing a;
    EXPECT_NO_THROW(a.InsFirst());
    EXPECT_NO_THROW(a.InsLast());
    EXPECT_NO_THROW(a.InsCurrent());
}

TEST(THeadRing, deletes)
{
    THeadRing a;
    a.InsFirst();
    a.InsFirst();
    a.InsFirst();
    EXPECT_NO_THROW(a.DelFirst());
    EXPECT_NO_THROW(a.DelCurrent());
    EXPECT_NO_THROW(a.DelCurrent());
}

TEST(THeadRing, correct_after_delete)
{
    THeadRing a;
    a.InsFirst();
    a.InsFirst();
    a.InsFirst();
    a.DelFirst();
    a.DelFirst();
    a.DelFirst();
    EXPECT_EQ(0,a.GetListLength());
    EXPECT_NO_THROW(a.GetDatValue());
}

TEST(THeadRing, can_get_value)
{
    THeadRing a;
    a.InsFirst();
    ASSERT_NO_THROW(a.GetDatValue());
}

TEST(TPolinom, create_object)
{
    ASSERT_NO_THROW(TPolinom a);
}

TEST(TPolinom, create_not_empty)
{
    int n[][2] = {{3, 105}, {1, 8}};
    EXPECT_NO_THROW(TPolinom a(n, 2));
}

TEST(TPolinom, created_is_equal_to_array)
{
    int n[][2] = {{3, 105}, {1, 8}};
    TPolinom a(n, 2);
    EXPECT_EQ(3, a.GetMonom()->GetCoeff());
    EXPECT_EQ(105, a.GetMonom()->GetIndex());
    a.GoNext();
    EXPECT_EQ(1, a.GetMonom()->GetCoeff());
    EXPECT_EQ(8, a.GetMonom()->GetIndex());
}

TEST(TPolinom, create_polinom_from_other)
{
    int n[][2] = {{3, 105}, {1, 8}};
    TPolinom a(n, 2);
    ASSERT_NO_THROW(TPolinom b=a);
}

TEST(TPolinom, copyed_polinom_equal_to_original)
{
    int n[][2] = {{3, 105}, {1, 8}};
    TPolinom a(n, 2);
    TPolinom b(a);
    EXPECT_EQ(a.GetMonom()->GetCoeff(), b.GetMonom()->GetCoeff());
    EXPECT_EQ(a.GetMonom()->GetIndex(), b.GetMonom()->GetIndex());
    a.GoNext();
    b.GoNext();
    EXPECT_EQ(a.GetMonom()->GetCoeff(), b.GetMonom()->GetCoeff());
    EXPECT_EQ(a.GetMonom()->GetIndex(), b.GetMonom()->GetIndex());
}

TEST(TPolinom, can_add_polinoms)
{
    int n[][2] = {{3, 105}, {1, 8}};
    int m[][2] = {{-6, 65}, {43, 8}, {7, 4}};
    TPolinom a(n, 2);
    TPolinom b(m, 3);
    ASSERT_NO_THROW(a + b);
}

TEST(TPolinom, adding_polinoms_is_correct)
{
    int n[][2] = {{3, 105}, {1, 8}};
    int m[][2] = {{-6, 65}, {43, 8}, {7, 4}};
    int k[][2] = {{3, 105}, {-6, 65}, {44, 8}, {7, 4}};
    TPolinom a(n, 2);
    TPolinom b(m, 3);
    a + b;
    EXPECT_EQ(4, a.GetListLength());
    a.Reset();
    for (int i = 0; i < 4; ++i)
    {
        EXPECT_EQ(k[i][0], a.GetMonom()->GetCoeff());
        EXPECT_EQ(k[i][1], a.GetMonom()->GetIndex());
        a.GoNext();
    }
}

TEST(TPolinom, delete_0_value_coeff)
{
    int n[][2] = {{3, 105}, {1, 8}};
    int m[][2] = {{-6, 65}, {-1, 8}, {7, 4}};
    TPolinom a(n, 2);
    TPolinom b(m, 3);
    a + b;
    EXPECT_EQ(3, a.GetListLength());
}

TEST(TPolinom, can_add_3_polinoms)
{
    int n[][2] = {{3, 105}, {1, 8}};
    int m[][2] = {{-6, 65}, {5, 8}, {7, 4}};
    int k[][2] = {{-6, 8}};
    TPolinom a(n, 2);
    TPolinom b(m, 3);
    TPolinom c(k, 1);
    EXPECT_NO_THROW(a+b+c);
}

TEST(TPolinom, can_get_empty_polinom)
{
    int n[][2] = {{3, 105}, {1, 8}};
    int m[][2] = {{-3, 105}, {-1, 8}};
    TPolinom a(n, 2);
    TPolinom b(m, 2);
    a + b;
    EXPECT_EQ(0, a.GetListLength());
}

TEST(TPolinom, can_add_to_empty_polinom)
{
    int n[][2] = {{3, 105}, {1, 8}};
    TPolinom a;
    TPolinom b(n, 2);
    EXPECT_NO_THROW(a + b);
    EXPECT_EQ(2, a.GetListLength());
}

TEST(TPolinom, can_add_empty_polinom)
{
    int n[][2] = {{3, 105}, {1, 8}};
    TPolinom a(n, 2);
    TPolinom b;
    EXPECT_NO_THROW(a + b);
    EXPECT_EQ(2, a.GetListLength());
}

TEST(TPolinom, can_assign_other_value)
{
    int n[][2] = {{3, 105}, {1, 8}};
    int m[][2] = {{-6, 65}, {43, 8}, {7, 4}};
    TPolinom a(n, 2);
    TPolinom b(m, 3);
    EXPECT_NO_THROW(a = b);
    EXPECT_EQ(3, a.GetListLength());
    a.Reset();
    for (int i = 0; i < 3; ++i)
    {
        EXPECT_EQ(m[i][0], a.GetMonom()->GetCoeff());
        EXPECT_EQ(m[i][1], a.GetMonom()->GetIndex());
        a.GoNext();
    }
}
