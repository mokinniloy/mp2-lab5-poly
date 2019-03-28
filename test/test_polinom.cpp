#include <gtest.h>
#include <iostream>
#include <polinom.hpp>

#define TEMP_MONOM(cval, ival) PTMonom tempMonom = new TMonom(cval, ival)
#define TEMP_LINK_CONSTRUCT(obj) TDatLink tempLink(obj)
#define TEMP_LIST TDatList tempList

#define BAD_ARR int arr[][2] = {{2, -414}, {2, 111}, {3, 111}}
#define ARR int arr[][2] = {{2, 414}, {2, 111}, {3, 111}}
#define SIZE 3
#define TEMP_POLINOM(arr, size) TPolinom tempPolinom(arr, size)
#define TEMP_COPIED_POLINOM TPolinom copiedPolinom(tempPolinom)

//------------------------------------------ TDatLink testing

TEST(TDatLink, can_create_link)
{
    TEMP_MONOM(0, -1);

    ASSERT_NO_THROW(TDatLink tempLink(tempMonom));
}

TEST(TDatLink, can_set_get_value)
{
    TEMP_MONOM(32, 535);
    TEMP_LINK_CONSTRUCT(tempMonom);

    tempLink.SetDatValue(tempMonom);

    EXPECT_EQ(tempMonom, tempLink.GetDatValue());
}

//------------------------------------------ TDatLink testing


//------------------------------------------ TDatList testing

TEST(TDatList, can_insert_first)
{
    TEMP_MONOM(32, 235);
    TEMP_LIST;

    tempList.InsFirst(tempMonom);

    EXPECT_EQ(tempMonom, tempList.GetDatValue(FIRST));
}

TEST(TDatList, can_insert_last)
{
    TEMP_MONOM(2, 405);
    TEMP_LIST;

    tempList.InsLast(tempMonom);

    EXPECT_EQ(tempMonom, tempList.GetDatValue(LAST));
}

TEST(TDatList, can_insert_current)
{
    PTMonom monom1 = new TMonom(4, 235);
    PTMonom monom2 = new TMonom(22, 333);
    PTMonom monom3 = new TMonom(64, 666);

    TEMP_LIST;

    tempList.InsLast(monom1);
    tempList.InsFirst(monom2);
    tempList.InsCurrent(monom3);

    EXPECT_EQ(monom3, tempList.GetDatValue());
}

TEST(TDatList, can_detect_if_list_empty)
{
    TDatList temp;

    EXPECT_TRUE(temp.IsEmpty());
}

TEST(TDatList, can_get_list_length)
{
    PTMonom monom1 = new TMonom(55, 257);
    PTMonom monom2 = new TMonom(234, 573);


    TEMP_LIST;

    tempList.InsFirst(monom1);
    tempList.InsFirst(monom2);

    EXPECT_EQ(2, tempList.GetListLength());
}

TEST(TDatList, can_set_get_current_position)
{
    PTMonom monom1 = new TMonom(55, 257);
    PTMonom monom2 = new TMonom(234, 573);

    TEMP_LIST;

    tempList.InsFirst(monom1);
    tempList.InsFirst(monom2);
    tempList.SetCurrentPos(0);

    EXPECT_EQ(0, tempList.GetCurrentPos());
}

TEST(TDatList, can_reset_list)
{
    PTMonom monom1 = new TMonom(55, 257);
    PTMonom monom2 = new TMonom(234, 573);

    TEMP_LIST;

    tempList.InsFirst(monom1);
    tempList.InsFirst(monom2);
    tempList.Reset();

    EXPECT_EQ(monom2, tempList.GetDatValue());
}

TEST(TDatList, can_go_next_in_list)
{
    PTMonom monom1 = new TMonom(4, 235);
    PTMonom monom2 = new TMonom(22, 333);
    PTMonom monom3 = new TMonom(64, 666);

    TEMP_LIST;

    tempList.InsLast(monom1);
    tempList.InsLast(monom2);
    tempList.InsLast(monom3);
    tempList.Reset();
    tempList.GoNext();

    EXPECT_EQ(monom2, tempList.GetDatValue());
}

TEST(TDatList, can_detect_if_list_is_ended)
{
    TEMP_MONOM(4, 253);
    TEMP_LIST;

    tempList.InsLast(tempMonom);
    tempList.GoNext();

    EXPECT_TRUE(tempList.IsListEnded());
}

TEST(TDatList, can_delete_first)
{
    PTMonom monom1 = new TMonom(55, 257);
    PTMonom monom2 = new TMonom(234, 573);

    TEMP_LIST;

    tempList.InsFirst(monom1);
    tempList.InsFirst(monom2);
    tempList.DelFirst();

    EXPECT_EQ(monom1, tempList.GetDatValue());
}

TEST(TDatList, can_delete_current)
{
    PTMonom monom1 = new TMonom(55, 257);
    PTMonom monom2 = new TMonom(234, 573);

    TEMP_LIST;

    tempList.InsFirst(monom1);
    tempList.InsFirst(monom2);
    tempList.DelCurrent();

    EXPECT_EQ(monom1, tempList.GetDatValue());
}

TEST(TDatList, can_delete_list)
{
    PTMonom monom1 = new TMonom(55, 257);
    PTMonom monom2 = new TMonom(234, 573);

    TEMP_LIST;

    tempList.InsFirst(monom1);
    tempList.InsFirst(monom2);
    tempList.DelList();

    EXPECT_TRUE(tempList.IsEmpty());
}

//------------------------------------------ TDatList testing


//------------------------------------------ TPolinom testing

TEST(TPolinom, throws_when_create_monom_with_wrong_index)
{
    BAD_ARR;

    ASSERT_ANY_THROW(TEMP_POLINOM(arr, SIZE));
}

TEST(TPolinom, can_create_copied_polinom)
{
    ARR;
    TEMP_POLINOM(arr, SIZE);

    ASSERT_NO_THROW(TPolinom copiedPolinom(tempPolinom));
}

TEST(TPolinom, copied_polinom_eq_to_source)
{
    ARR;
    TEMP_POLINOM(arr, SIZE);
    TEMP_COPIED_POLINOM;

    tempPolinom.Reset();
    copiedPolinom.Reset();
    
    int i = 0;
    for (; i <= SIZE; i++, tempPolinom.GoNext(), copiedPolinom.GoNext())
        if (tempPolinom.GetMonom()->GetCoeff() != copiedPolinom.GetMonom()->GetCoeff())
            break;

    EXPECT_TRUE(i == SIZE + 1);
}

TEST(TPolinom, copied_polinom_has_its_own_memory)
{
    ARR;
    TEMP_POLINOM(arr, SIZE);
    TEMP_COPIED_POLINOM;

    EXPECT_NE(&tempPolinom, &copiedPolinom);
}

TEST(TPolinom, can_assign_polinom)
{
    ARR;
    TEMP_POLINOM(arr, SIZE);
    TEMP_COPIED_POLINOM;

    ASSERT_NO_THROW(copiedPolinom = tempPolinom);
}

TEST(TPolinom, summ_of_polinoms)
{
    int fstArr[][2] = {{2, 414}, {2, 111}};
    int secArr[][2] = {{3, 414}, {2, 112}};
    int chkArr[][2] = {5, 414, {2, 112}, {2, 111}};
    int size = 2;

    TPolinom fstPolinom(fstArr, size);
    TPolinom secPolinom(secArr, size);
    TPolinom chkPolinom(chkArr, 3);
    TPolinom summ = fstPolinom + secPolinom;
    
    summ.Reset();
    chkPolinom.Reset();

    bool check = true;
    for (int i = 0; i < 3; chkPolinom.GoNext(), summ.GoNext(), i++)
    {
        if (chkPolinom.GetMonom()->GetIndex() != summ.GetMonom()->GetIndex())
            check = false;
        if (chkPolinom.GetMonom()->GetCoeff() != summ.GetMonom()->GetCoeff())
            check = false;
    }
    EXPECT_TRUE(check);
}

TEST(TPolinom, can_print_polinom)
{
    ARR;
    TEMP_POLINOM(arr, SIZE);

    ASSERT_NO_THROW(std::cout << tempPolinom << std::endl);
}

//------------------------------------------ TPolinom testing