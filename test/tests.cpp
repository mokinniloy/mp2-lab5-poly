#include <gtest.h>
#include "polinom.h"

TEST(TDatList, can_push_back_elements) {
    TDatList a;
    for (int i = 0; i < 5; ++i) {
        TMonom *elem = new TMonom(i, 10 * i);
        a.InsLast(elem);
    }
    ASSERT_EQ(5, a.GetListLength());
}

TEST(TDatList, can_iterate_through_the_whole_list) {
    TDatList a;
    for (int i = 0; i < 5; ++i) {
        TMonom *elem = new TMonom(i, 10 * i);
        a.InsLast(elem);
    }
    int iterations = 0;
    for (a.Reset(); !a.IsListEnded(); a.GoNext())
        ++iterations;
    ASSERT_EQ(5, iterations);
}

TEST(TDatList, can_get_elements) {
    TDatList a;
    for (int i = 0; i < 5; ++i) {
        TMonom *elem = new TMonom(i, 10 * i);
        a.InsLast(elem);
    }
    std::vector <std::pair <int, int>> v, exp;
    for (a.Reset(); !a.IsListEnded(); a.GoNext()) {
        TMonom *elem = (TMonom *)a.GetDatValue();
        v.emplace_back(elem->GetCoeff(), elem->GetIndex());
    }
    for (int i = 0; i < 5; ++i)
        exp.emplace_back(i, 10 * i);
    ASSERT_EQ(exp, v);
}

TEST(TDatList, can_pop_front_elements) {
    TDatList a;
    for (int i = 0; i < 5; ++i) {
        TMonom *elem = new TMonom(i, 10 * i);
        a.InsLast(elem);
    }
    ASSERT_NO_THROW(
        for (int i = 0; i < 5; ++i)
            a.DelFirst();
    );
    ASSERT_EQ(0, a.GetListLength());
}

TEST(TDatList, cant_delete_elements_from_empty_list) {
    TDatList a;
    for (int i = 0; i < 5; ++i) {
        TMonom *elem = new TMonom(i, 10 * i);
        a.InsLast(elem);
    }
    ASSERT_NO_THROW(
        for (int i = 0; i < 5; ++i)
            a.DelFirst();
    );
    ASSERT_ANY_THROW(a.DelFirst());
}

TEST(TDatList, can_shift_positions) {
    TDatList a;
    for (int i = 0; i < 5; ++i) {
        TMonom *elem = new TMonom(i, 10 * i);
        a.InsLast(elem);
    }
    for (int i = 0; i < 3; ++i)
        a.GoNext();
    ASSERT_EQ(3, a.GetCurrentPos());
}

TEST(TDatList, can_reset_positions_after_shifting) {
    TDatList a;
    for (int i = 0; i < 5; ++i) {
        TMonom *elem = new TMonom(i, 10 * i);
        a.InsLast(elem);
    }
    for (int i = 0; i < 3; ++i)
        a.GoNext();
    a.Reset();
    ASSERT_EQ(0, a.GetCurrentPos());
}

TEST(TDatList, can_push_front_elements) {
    TDatList a;
    for (int i = 0; i < 5; ++i) {
        TMonom *elem = new TMonom(i, 10 * i);
        a.InsFirst(elem);
    }
    std::vector <std::pair <int, int>> v, exp;
    for (a.Reset(); !a.IsListEnded(); a.GoNext()) {
        TMonom *elem = (TMonom *)a.GetDatValue();
        v.emplace_back(elem->GetCoeff(), elem->GetIndex());
    }
    for (int i = 4; i > -1; --i)
        exp.emplace_back(i, 10 * i);
    ASSERT_EQ(exp, v);
}

TEST(TDatList, can_push_insert_elements_before_current) {
    TDatList a;
    {
        TMonom *elem = new TMonom(0, 0);
        a.InsFirst(elem);
        elem = new TMonom(1, 10);
        a.InsFirst(elem);
        a.GoNext();
    }
    for (int i = 2; i < 7; ++i) {
        TMonom *elem = new TMonom(i, 10 * i);
        a.InsCurrent(elem);
    }
    std::vector <std::pair <int, int>> v, exp;
    for (a.Reset(); !a.IsListEnded(); a.GoNext()) {
        TMonom *elem = (TMonom *)a.GetDatValue();
        v.emplace_back(elem->GetCoeff(), elem->GetIndex());
    }
    exp.emplace_back(1, 10);
    exp.emplace_back(6, 60);
    exp.emplace_back(5, 50);
    exp.emplace_back(4, 40);
    exp.emplace_back(3, 30);
    exp.emplace_back(2, 20);
    exp.emplace_back(0, 0);
    ASSERT_EQ(exp, v);
}

TEST(TDatList, can_delete_current_element) {
    TDatList a;
    for (int i = 0; i < 5; ++i) {
        TMonom *elem = new TMonom(i, 10 * i);
        a.InsLast(elem);
    }
    a.GoNext();
    a.DelCurrent();
    std::vector <std::pair <int, int>> v, exp;
    for (a.Reset(); !a.IsListEnded(); a.GoNext()) {
        TMonom *elem = (TMonom *)a.GetDatValue();
        v.emplace_back(elem->GetCoeff(), elem->GetIndex());
    }
    exp.emplace_back(0, 0);
    exp.emplace_back(2, 20);
    exp.emplace_back(3, 30);
    exp.emplace_back(4, 40);
    ASSERT_EQ(exp, v);
}

TEST(TDatList, can_erase_list_by_using_delete_current_element) {
    TDatList a;
    for (int i = 0; i < 5; ++i) {
        TMonom *elem = new TMonom(i, 10 * i);
        a.InsLast(elem);
    }
    ASSERT_NO_THROW(
        for (int i = 0; i < 5; ++i)
            a.DelCurrent();
    );
    ASSERT_EQ(0, a.GetListLength());
}


TEST(TDatList, can_delete_whole_list) {
    TDatList a;
    for (int i = 0; i < 5; ++i) {
        TMonom *elem = new TMonom(i, 10 * i);
        a.InsLast(elem);
    }
    ASSERT_EQ(5, a.GetListLength());
    ASSERT_NO_THROW(a.DelList());
    ASSERT_EQ(0, a.GetListLength());
}

TEST(TPolinom, can_create_empty_polynom) {
    TPolinom p;
    std::vector <std::pair <int, int>> v;
    for (p.Reset(); !p.IsListEnded(); p.GoNext()) {
        TMonom *elem = (TMonom *)p.GetDatValue();
        v.emplace_back(elem->GetCoeff(), elem->GetIndex());
    }
    ASSERT_EQ(0, p.GetListLength());
    ASSERT_EQ(0u, v.size());
}

TEST(TPolinom, throws_an_error_with_indexes_more_than_999) {
    int monoms1[][2] = {{1, 543}, {3, 1005}};
    ASSERT_ANY_THROW(TPolinom p1(monoms1, 2));
}

TEST(TPolinom, throws_an_error_with_indexes_less_than_0) {
    int monoms1[][2] = {{1, 543}, {3, -1}};
    ASSERT_ANY_THROW(TPolinom p1(monoms1, 2));
}

TEST(TPolinom, example_test) {
    int monoms1[][2] = {{1, 543}, {3, 432}, {5, 321}, {7, 210}, {9, 100}};
    int monoms2[][2] = {{2, 643}, {4, 431}, {-5, 321}, {8, 110}, {10, 50}};
    int monoms3[][2] = {{2, 643}, {1, 543}, {3, 432}, {4, 431}, {7, 210}, {8, 110}, {9, 100}, {10, 50}};
    TPolinom p1(monoms1, 5);
    TPolinom p2(monoms2, 5);
    TPolinom p3(monoms3, 8);
    p1 += p2;
    ASSERT_TRUE(p3 == p1);
}

TEST(TPolinom, polinom_is_equal_to_itself) {
    int monoms1[][2] = {{-9, 999}, {-1, 230}, {-16, 180}, {7, 65}, {-10, 60}, {9, 0}};
    TPolinom p1(monoms1, 6);
    ASSERT_TRUE(p1 == p1);
}

TEST(TPolinom, two_empty_polinoms_are_equal) {
    TPolinom p1, p2;
    ASSERT_TRUE(p2 == p1);
}

TEST(TPolinom, can_plus_1) {
    int monoms1[][2] = {{1, 1}};
    int monoms2[][2] = {{2, 1}};
    int monoms3[][2] = {{3, 1}};
    TPolinom p1(monoms1, 1);
    TPolinom p2(monoms2, 1);
    TPolinom p3(monoms3, 1);
    p1 += p2;
    ASSERT_TRUE(p3 == p1);
}

TEST(TPolinom, can_plus_2) {
    int monoms1[][2] = {{1, 1}};
    int monoms2[][2] = {{1, 10}};
    int monoms3[][2] = {{1, 100}};
    int monoms4[][2] = {{1, 100}, {1, 10}, {1, 1}};
    TPolinom p1(monoms1, 1);
    TPolinom p2(monoms2, 1);
    TPolinom p3(monoms3, 1);
    TPolinom p4(monoms4, 3);
    p1 += p2 += p3;
    ASSERT_TRUE(p4 == p1);
}

TEST(TPolinom, can_plus_3) {
    int monoms1[][2] = {{1, 1}};
    int monoms2[][2] = {{-1, 1}};
    TPolinom p1(monoms1, 1);
    TPolinom p2(monoms2, 1);
    TPolinom p3;
    p1 += p2;
    ASSERT_TRUE(p3 == p1);
}

TEST(TPolinom, can_plus_4) {
    int monoms1[][2] = {{1, 123}};
    int monoms2[][2] = {{-1, 321}};
    int monoms3[][2] = {{-1, 321}, {1, 123}};
    TPolinom p1(monoms1, 1);
    TPolinom p2(monoms2, 1);
    TPolinom p3(monoms3, 2);
    p1 += p2;
    ASSERT_TRUE(p3 == p1);
}

TEST(TPolinom, can_plus_5) {
    int monoms1[][2] = {{1, 254}, {1, 43}, {1, 10}, {1, 1}, {9, 0}};
    int monoms2[][2] = {{10, 354}, {9, 76}, {1, 43}, {-1, 1}, {8, 0}};
    int monoms3[][2] = {{10, 354}, {1, 254}, {9, 76}, {2, 43}, {1, 10}, {17, 0}};
    TPolinom p1(monoms1, 5);
    TPolinom p2(monoms2, 5);
    TPolinom p3(monoms3, 6);
    p1 += p2;
    ASSERT_TRUE(p3 == p1);
}

TEST(TPolinom, can_plus_6) {
    int monoms1[][2] = {{1, 1}, {9, 0}};
    int monoms2[][2] = {{-1, 1}, {8, 0}};
    int monoms3[][2] = {{17, 0}};
    TPolinom p1(monoms1, 2);
    TPolinom p2(monoms2, 2);
    TPolinom p3(monoms3, 1);
    p1 += p2;
    ASSERT_TRUE(p3 == p1);
}

TEST(TPolinom, can_plus_7) {
    int monoms1[][2] = {{1, 1}, {9, 0}};
    int monoms2[][2] = {{8, 0}};
    int monoms3[][2] = {{1, 1}, {17, 0}};
    TPolinom p1(monoms1, 2);
    TPolinom p2(monoms2, 1);
    TPolinom p3(monoms3, 2);
    p1 += p2;
    ASSERT_TRUE(p3 == p1);
}

TEST(TPolinom, can_plus_8) {
    int monoms1[][2] = {{1, 1}, {9, 0}};
    int monoms2[][2] = {{8, 0}};
    int monoms3[][2] = {{1, 1}, {17, 0}};
    TPolinom p1(monoms1, 2);
    TPolinom p2(monoms2, 1);
    TPolinom p3(monoms3, 2);
    p2 += p1;
    ASSERT_TRUE(p3 == p2);
}

TEST(TPolinom, can_plus_9) {
    int monoms1[][2] = {{1, 100}, {9, 10}, {2, 4}, {15, 0}};
    int monoms2[][2] = {{4, 100}, {-2, 4}, {4, 2}, {5, 0}};
    int monoms3[][2] = {{5, 100}, {9, 10}, {4, 2}, {20, 0}};
    TPolinom p1(monoms1, 4);
    TPolinom p2(monoms2, 4);
    TPolinom p3(monoms3, 4);
    p1 += p2;
    ASSERT_TRUE(p3 == p1);
}

TEST(TPolinom, can_plus_10) {
    int monoms2[][2] = {{-4, 100}, {5, 0}};
    int monoms3[][2] = {{-4, 100}, {5, 0}};
    TPolinom p1;
    TPolinom p2(monoms2, 2);
    TPolinom p3(monoms3, 2);
    p1 += p2;
    ASSERT_TRUE(p3 == p1);
}

TEST(TPolinom, can_plus_11) {
    TPolinom p1, p2, p3;
    p1 += p2;
    ASSERT_TRUE(p3 == p1);
}

TEST(TPolinom, can_plus_12) {
    int monoms1[][2] = {{9, 999}, {1, 230}, {16, 180}, {-7, 65}, {10, 60}, {-9, 0}};
    int monoms2[][2] = {{-9, 999}, {4, 170}, {7, 65}, {3, 64}, {-10, 60}, {8, 0}};
    int monoms3[][2] = {{1, 230}, {16, 180}, {4, 170}, {3, 64}, {-1, 0}};
    TPolinom p1(monoms1, 6);
    TPolinom p2(monoms2, 6);
    TPolinom p3(monoms3, 5);
    p1 += p2;
    ASSERT_TRUE(p3 == p1);
}

TEST(TPolinom, can_plus_13) {
    int monoms1[][2] = {{9, 999}, {1, 230}, {16, 180}, {-7, 65}, {10, 60}, {-9, 0}};
    int monoms2[][2] = {{-9, 999}, {-1, 230}, {-16, 180}, {7, 65}, {-10, 60}, {9, 0}};
    TPolinom p1(monoms1, 6);
    TPolinom p2(monoms2, 6);
    TPolinom p3;
    p1 += p2;
    ASSERT_TRUE(p3 == p1);
}

TEST(TPolinom, can_plus_14) {
    int monoms1[][2] = {{-9, 0}};
    int monoms2[][2] = {{100, 1}};
    int monoms3[][2] = {{100, 1}, {-9, 0}};
    TPolinom p1(monoms1, 1);
    TPolinom p2(monoms2, 1);
    TPolinom p3(monoms3, 2);
    p1 += p2;
    ASSERT_TRUE(p3 == p1);
}

TEST(TPolinom, can_plus_15) {
    int monoms1[][2] = {{-9, 0}};
    int monoms2[][2] = {{100, 1}};
    int monoms3[][2] = {{100, 1}, {-9, 0}};
    TPolinom p1(monoms1, 1);
    TPolinom p2(monoms2, 1);
    TPolinom p3(monoms3, 2);
    p1 += p2;
    ASSERT_TRUE(p3 == p1);
}

TEST(TPolinom, not_equal_1) {
    int monoms1[][2] = {{-9, 0}};
    int monoms2[][2] = {{100, 0}};
    int monoms3[][2] = {{91, 0}, {0, 1}};
    TPolinom p1(monoms1, 1);
    TPolinom p2(monoms2, 1);
    TPolinom p3(monoms3, 2);
    p1 += p2;
    ASSERT_FALSE(p3 == p1);
}

TEST(TPolinom, not_equal_2) {
    int monoms1[][2] = {{-9, 0}};
    int monoms2[][2] = {{100, 0}};
    int monoms3[][2] = {{90, 0}};
    TPolinom p1(monoms1, 1);
    TPolinom p2(monoms2, 1);
    TPolinom p3(monoms3, 1);
    p1 += p2;
    ASSERT_FALSE(p3 == p1);
}

TEST(TPolinom, not_equal_3) {
    int monoms1[][2] = {{10, 7}, {-9, 0}};
    int monoms2[][2] = {{-10, 7}, {100, 0}};
    int monoms3[][2] = {{0, 7}, {91, 0}};
    TPolinom p1(monoms1, 2);
    TPolinom p2(monoms2, 2);
    TPolinom p3(monoms3, 2);
    p1 += p2;
    ASSERT_FALSE(p3 == p1);
}

TEST(TPolinom, not_equal_4) {
    int monoms1[][2] = {{10, 7}, {-9, 0}};
    int monoms2[][2] = {{10, 7}, {100, 0}};
    int monoms3[][2] = {{91, 0}, {20, 7}};
    TPolinom p1(monoms1, 2);
    TPolinom p2(monoms2, 2);
    TPolinom p3(monoms3, 2);
    p1 += p2;
    ASSERT_FALSE(p3 == p1);
}

TEST(TPolinom, not_equal_5) {
    int monoms1[][2] = {{10, 7}, {-100, 0}};
    int monoms2[][2] = {{10, 7}, {100, 0}};
    int monoms3[][2] = {{20, 7}, {0, 0}};
    TPolinom p1(monoms1, 2);
    TPolinom p2(monoms2, 2);
    TPolinom p3(monoms3, 2);
    p1 += p2;
    ASSERT_FALSE(p3 == p1);
}
