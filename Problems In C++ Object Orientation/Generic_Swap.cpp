/*
*    Write generic program to swap two numbers.
*    1. Call By Reference
*    2. Call by Address
*/
#include <iostream>
using namespace std;

template <class T>
void SwapRef(T&, T&);

template <class T>
void SwapPtr(T*, T*);

int main()
{
    int iNum1 = 0, iNum2 = 0;
    float fNum1 = 0.0f, fNum2 = 0.0f;

    cout << "Enter integer 1\t\t:";
    cin >> iNum1;
    cout << "Enter integer 2\t\t:";
    cin  >> iNum2;
    SwapRef(iNum1, iNum2);
    cout << "After Swapping Call by Reference:" << endl;
    cout << "After swapped integer\t:"<< iNum1 << "\t" << iNum2<<endl;

    cout << "\nEnter float 1\t\t:";
    cin >> fNum1;
    cout << "Enter float 1\t\t:";
    cin >> fNum2;
    SwapPtr(&fNum1, &fNum2);
    cout << "After Swapping Call by Pointer:" <<  endl;
    cout << "After swapped float\t:" << fNum1 << "\t" << fNum2<<endl;
    return 0;
}

///////////////////////////////////////////////////////////////////
//
//  Name        :SwapRef
//  Input       :T&, T&
//  Returns     :void
//  Description :Swap two entities using call by reference
//  Author      :Pranav Choudhary
//  Date        :14 Sept 2020
//
///////////////////////////////////////////////////////////////////
template<class T>
void SwapRef(T &tNum1, T &tNum2)
{
    T tTemp;
    tTemp = tNum1;
    tNum1 = tNum2;
    tNum2 = tTemp;
}

///////////////////////////////////////////////////////////////////
//
//  Name        :SwapPtr
//  Input       :T*, T*
//  Returns     :void
//  Description :Swap two entities using call by address
//  Author      :Pranav Choudhary
//  Date        :14 Sept 2020
//
///////////////////////////////////////////////////////////////////
template<class T>
void SwapPtr(T *tNum1, T *tNum2)
{
    T tTemp;
    tTemp = *tNum1;
    *tNum1 = *tNum2;
    *tNum2 = tTemp;
}
