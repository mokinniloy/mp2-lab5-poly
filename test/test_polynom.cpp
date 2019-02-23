#include "Polinom.h"
#include <gtest.h>
#include <iostream>
TEST(TDatLink, can_create_link)
{
    PTMonom pMonom = new TMonom(0, -1);
    ASSERT_NO_THROW(TDatLink temp(pMonom));
}
TEST(TDatLink, can_set_get_value)
{
    PTMonom pMonom = new TMonom(1, 120);
    TDatLink temp(pMonom);
    temp.SetDatValue(pMonom);
    EXPECT_EQ(pMonom, temp.GetDatValue());
}
//******* TDATLIST *****//
TEST(TDatList, can_insert_first)
{
    PTMonom pMonom = new TMonom(1, 111);
    TDatList temp;
    temp.InsFirst(pMonom);
    EXPECT_EQ(pMonom, temp.GetDatValue(FIRST));
}
TEST(TDatList, can_insert_last)
{
    PTMonom pMonom = new TMonom(1, 111);
    TDatList temp;
    temp.InsLast(pMonom);
    EXPECT_EQ(pMonom, temp.GetDatValue(LAST));
}
TEST(TDatList, can_insert_current)
{
    PTMonom pMonom = new TMonom(1, 111);
    PTMonom pMonom1 = new TMonom(2, 222);
    PTMonom pMonom2 = new TMonom(3, 3);
    TDatList temp;
    temp.InsLast(pMonom);
    temp.InsFirst(pMonom1);
    temp.InsCurrent(pMonom2);
    EXPECT_EQ(pMonom2, temp.GetDatValue());
}
TEST(TDatList, can_detect_if_list_empty)
{
    TDatList temp;
    EXPECT_TRUE(temp.IsEmpty());
}
TEST(TDatList, can_get_list_length)
{
    PTMonom pMonom = new TMonom(2, 414);
    PTMonom pMonom1 = new TMonom(3, 111);
    TDatList temp;
    temp.InsFirst(pMonom);
    temp.InsFirst(pMonom1);
    EXPECT_EQ(2, temp.GetListLength());
}
TEST(TDatList, can_set_get_current_position)
{
    PTMonom pMonom = new TMonom(2, 414);
    PTMonom pMonom1 = new TMonom(3, 111);
    TDatList temp;
    temp.InsFirst(pMonom);
    temp.InsFirst(pMonom1);
    temp.SetCurrentPos(0);
    EXPECT_EQ(0, temp.GetCurrentPos());
}
TEST(TDatList, can_reset_list)
{
    PTMonom pMonom = new TMonom(2, 414);
    PTMonom pMonom1 = new TMonom(3, 111);
    TDatList temp;
    temp.InsFirst(pMonom);
    temp.InsFirst(pMonom1);
    temp.Reset();
    EXPECT_EQ(pMonom1, temp.GetDatValue());
}
TEST(TDatList, can_go_next_list)
{
    PTMonom pMonom = new TMonom(2, 414);
    PTMonom pMonom1 = new TMonom(3, 111);
    PTMonom pMonom2 = new TMonom(2, 11);
    TDatList temp;
    temp.InsLast(pMonom);
    temp.InsLast(pMonom1);
    temp.InsLast(pMonom2);
    temp.Reset();
    temp.GoNext();
    EXPECT_EQ(pMonom1, temp.GetDatValue());
}
TEST(TDatList, can_detect_list_is_ended)
{
    PTMonom pMonom = new TMonom(2, 414);
    TDatList temp;
    temp.InsLast(pMonom);
    temp.GoNext();
    EXPECT_TRUE(temp.IsListEnded());
}
TEST(TDatList, can_delete_first)
{
    PTMonom pMonom = new TMonom(2, 414);
    PTMonom pMonom1 = new TMonom(3, 111);
    TDatList temp;
    temp.InsFirst(pMonom);
    temp.InsFirst(pMonom1);
    temp.DelFirst();
    EXPECT_EQ(pMonom, temp.GetDatValue());
}
TEST(TDatList, can_delete_current)
{
    PTMonom pMonom = new TMonom(2, 414);
    PTMonom pMonom1 = new TMonom(3, 111);
    TDatList temp;
    temp.InsLast(pMonom);
    temp.InsCurrent(pMonom1);
    temp.DelCurrent();
    EXPECT_EQ(pMonom, temp.GetDatValue());
}
TEST(TDatList, can_delete_list)
{
    PTMonom pMonom = new TMonom(2, 414);
    PTMonom pMonom1 = new TMonom(3, 111);
    TDatList temp;
    temp.InsLast(pMonom);
    temp.InsCurrent(pMonom1);
    temp.DelList();
    EXPECT_TRUE(temp.IsEmpty());
}
//******* TMONOM ******/
TEST(TMonom, can_create_monom)
{
    ASSERT_NO_THROW(PTMonom pMonom = new TMonom(2, 414));
}
TEST(TMonom, can_set_get_coeff)
{
    PTMonom pMonom = new TMonom(2, 414);
    pMonom->SetCoeff(12);
    EXPECT_EQ(12, pMonom->GetCoeff());
}
TEST(TMonom, can_set_get_index)
{
    PTMonom pMonom = new TMonom(2, 414);
    pMonom->SetIndex(122);
    EXPECT_EQ(122, pMonom->GetIndex());
}
TEST(TMonom, can_get_copy)
{
    PTMonom pMonom = new TMonom(4, 222);
    ASSERT_NO_THROW(pMonom->GetCopy());
}
TEST(TMonom, copy_has_its_own_memory)
{
    PTMonom pMonom = new TMonom(4, 222);
    PTMonom p2 = (PTMonom)pMonom->GetCopy();
    EXPECT_NE(&pMonom, &p2);
}
TEST(TMonom, can_assign_monom)
{
    PTMonom pMonom = new TMonom(4, 222);
    PTMonom p2 = new TMonom(12, 333);
    ASSERT_NO_THROW(pMonom = p2);
}
TEST(TMonom, can_detect_eq_monoms)
{
    PTMonom pMonom = new TMonom(4, 222);
    PTMonom p2 = new TMonom(4, 222);
    EXPECT_TRUE(*pMonom == *p2);
}
TEST(TMonom, can_detect_first_monom_less_than_second)
{
    PTMonom pMonom = new TMonom(1, 122);
    PTMonom p2 = new TMonom(4, 222);
    EXPECT_TRUE(*pMonom < *p2);
}
TEST(TMonom, can_print_monom)
{
    PTMonom pMonom = new TMonom(1, 122);
    ASSERT_NO_THROW(std::cout << *pMonom << std::endl);
}
//******* TPOLINOM ******/
TEST(TPolinom, throws_when_create_poly_with_wrong_index)
{
    int arrMn[][2] = {{2, -414}, {2, 111}, {3, 111}};
    ASSERT_ANY_THROW(TPolinom p(arrMn, 3));
}
TEST(TPolinom, can_create_copied_polinom)
{
    int arrMn[][2] = {{2, 414}, {2, 111}, {3, 111}};
    int size = sizeof(arrMn) / (2 * sizeof(int));
    TPolinom p(arrMn, size);
    ASSERT_NO_THROW(TPolinom p1(p));
}
TEST(TPolinom, copied_polinom_eq_to_source)
{
    int arrMn[][2] = {{2, 414}, {2, 111}, {3, 111}};
    int size = sizeof(arrMn) / (2 * sizeof(int));
    TPolinom p(arrMn, size);
    TPolinom p1(p);
    p.Reset();
    p1.Reset();
    bool okey = true;
    for (int i = 0; i < size; i++, p.GoNext(), p1.GoNext())
        if (p.GetMonom()->GetCoeff() != p1.GetMonom()->GetCoeff())
            okey = false;
    if (p.GetMonom()->GetIndex() != p1.GetMonom()->GetIndex())
        okey = false;
    EXPECT_TRUE(okey);
}
TEST(TPolinom, copied_polinom_has_its_own_memory)
{
    int arrMn[][2] = {{2, 414}, {2, 111}, {3, 111}};
    int size = sizeof(arrMn) / (2 * sizeof(int));
    TPolinom p(arrMn, size);
    TPolinom p1(p);
    EXPECT_NE(&p, &p1);
}
TEST(TPolinom, can_assign_polinom)
{
    int arrMn[][2] = {{2, 414}, {2, 111}, {3, 111}};
    int size = sizeof(arrMn) / (2 * sizeof(int));
    TPolinom p(arrMn, size);
    TPolinom p1;
    ASSERT_NO_THROW(p1 = p);
}
TEST(TPolinom, summ_of_polinoms)
{
    int arrMn[][2] = {{2, 414}, {2, 111}};
    int arrMn2[][2] = {{3, 414}, {2, 112}};
    int arrMnR[][2] = {5, 414, {2, 112}, {2, 111}};
    int size = sizeof(arrMn) / (2 * sizeof(int));
    TPolinom p(arrMn, size);
    TPolinom p1(arrMn2, size);
    TPolinom r(arrMnR, 3);
    TPolinom summ = p + p1;
    summ.Reset();
    r.Reset();
    bool okey = true;
    for (int i = 0; i < 3; r.GoNext(), summ.GoNext(), i++)
    {
        if (r.GetMonom()->GetIndex() != summ.GetMonom()->GetIndex())
            okey = false;
        if (r.GetMonom()->GetCoeff() != summ.GetMonom()->GetCoeff())
            okey = false;
    }
    EXPECT_TRUE(okey);
}
TEST(TPolinom, can_calculate_polinom)
{
    int arrMn[][2] = {{2, 414}, {2, 111}};
    TPolinom p(arrMn, 2);
    EXPECT_EQ(1040, p.CalculatePolinom(2, 2, 2));
}
TEST(TPolinom, can_print_polinom)
{
    int arrMn[][2] = {{2, 414}, {2, 111}};
    TPolinom p(arrMn, 2);
    ASSERT_NO_THROW(std::cout << p << std::endl);
}
TEST(TPolinom, can_integrate_polinom)
{
    int arrMn[][2] = {{200, 414}, {200, 111}};
    TPolinom p(arrMn, 2);
    ASSERT_NO_THROW(p.Integration());
}