#include <iostream>
#include "polinom.h"
using namespace std;

int main()
{
	int m1[][2] = { { 1, 594 },{ 5, 321 },{ 12, 132 },{ 2, 98 },{ 10, 19 },{ -5, 6 },{ -10, 0 } };
	int m2[][2] = { { 9, 786 },{ 3, 594 },{-5, 321},{ -12, 132 },{ 3, 97 },{ 15, 20 },{ -5, 6 },{ 20, 0 } };
	TPolinom p1(m1, 7), p2(m2, 8);
	cout << "First polinom: " << "\n" << p1 << endl;
	cout << "Second polinom: " << "\n" << p2 << endl;
	p1 += p2;
	cout << "Summary: \n" << p1;

	return 0;
}
