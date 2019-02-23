#include <iostream>
#include "Polinom.h"
using namespace std;
#define USE_POLINOM // использовать класс TPolinom
#ifndef USE_POLINOM
int main()
{
    TDatList list;
    TMonom *pVal;
    int temp;
    cout << "Testing list" << endl;
    for (int i = 0; i < 5; i++)
    {
        pVal = new TMonom(i, 10 * i);
        list.InsLast(pVal);
        cout << "Inserted value in List" << pVal->GetCoeff()
             << ";" << pVal->GetIndex() << endl;
    }
    for (list.Reset(); !list.IsListEnded(); list.GoNext())
    {
        pVal = (TMonom *)list.GetDatValue();
        cout << "Get value form list"
             << pVal->GetCoeff() << ";" << pVal->GetIndex() << endl;
    }
    list.DelList();
    getchar();
    return 0;
}
#else
int main() // Polinom testing
{
    int input = 0;
    int x, y, z;
    cout << "Polinom testing" << endl;
    cout << "1.Input from keyboard\n2.Test Sample" << endl;
    cin >> input;
    TPolinom *p;
    TPolinom *p1;
    if (input == 1)
    {
        p = new TPolinom();
        p1 = new TPolinom();
        cout << "input Polinom 1:" << endl;
        cin >> *p;
        cout << "input Polinom 2:" << endl;
        cin >> *p1;
    }
    else
    {
        int arrCoeff1[][2] = {{1, 543}, {3, 432}, {5, 321}, {7, 210}, {9, 100}};
        int mnSize1 = sizeof(arrCoeff1) / (2 * sizeof(int));
        p = new TPolinom(arrCoeff1, mnSize1);
        int arrCoeff2[][2] = {{2, 643}, {4, 431}, {-5, 321}, {8, 110}, {10, 50}};
        int mnSize2 = sizeof(arrCoeff2) / (2 * sizeof(int));
        p1 = new TPolinom(arrCoeff2, mnSize2);
    }
    cout << "1 Polinom" << endl
         << *p << endl;
    cout << "2 Polinom" << endl
         << *p1 << endl;
    cout << "Summ of Polinom :" << endl
         << (*p + *p1);
    cout << "\nCalculate Polinom" << endl;
    cout << "Input x" << endl;
    cin >> x;
    cout << "Input y" << endl;
    cin >> y;
    cout << "Input z" << endl;
    cin >> z;
    cout << "Polinom 1 = " << p->CalculatePolinom(x, y, z) << endl;
    cout << "Polinom 2 = " << p1->CalculatePolinom(x, y, z) << endl;
    cout << "Integrate Polinom" << endl;
    cout << "Choose arguments for integration:" << endl;
    char inputCh = 0;
    cout << "x?(y/n)" << endl;
    cin >> inputCh;
    if (inputCh == 'y')
        x = 1;
    else
        x = 0;
    cout << "y?(y/n)" << endl;
    cin >> inputCh;
    if (inputCh == 'y')
        y = 1;
    else
        y = 0;
    cout << "z?(y/n)" << endl;
    cin >> inputCh;
    if (inputCh == 'y')
        z = 1;
    else
        z = 0;
    TPolinom r;
    r = p->Integration(x, y, z);
    cout << "Polinom 1 = " << r << endl;
    r = p1->Integration(x, y, z);
    cout << "Polinom 2 = " << r << endl;
}
#endif