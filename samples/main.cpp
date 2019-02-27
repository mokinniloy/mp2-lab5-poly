// тестирование списка
#include "Monom.h"
#include "DatList.h"
#include <iostream>
#include <conio.h>



int main()
{
    TDatList st;
    TMonom *pVal;
    int temp;
    cout << "TDatList testing" << endl;
    for (int i = 0; i < 5; i++)
    {
        pVal = new TMonom(i, 10*i);
        st.InsLast(pVal);
        cout << "The value is put to the list: " << pVal->GetCoeff() << "; " << pVal->GetIndex()
        << " Code " << st.GetRetCode() << endl;
    }
    // print list
    for (st.Reset(); !st.IsListEnded(); st.GoNext())
    {
        pVal = (TMonom*)st.GetDatValue();
        cout << "Got the value from the list: " << pVal->GetCoeff() << "; " << pVal->GetIndex()
        << "Code " << st.GetRetCode() << endl;
    }
    st.DelList();
    cout << "Press any key" << endl;
    getch();
    
    return 0;
}
