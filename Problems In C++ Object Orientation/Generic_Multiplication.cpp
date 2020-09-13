/*
*    Write generic program to multiply two numbers.
*/
#include <iostream>
using namespace std;

template <class T>
T Multiply(T tNum1, T tNum2);

int main()
{
    int iNum1 = 0, iNum2 = 0;
    float fNum1 = 0.0f, fNum2 = 0.0f;

    cout << "Enter integer 1\t\t:";
    cin >> iNum1;
    cout << "Enter integer 2\t\t:";
    cin  >> iNum2;
    cout << "Multiplication is\t:" << Multiply(iNum1, iNum2) << endl;

    cout << "Enter float 1\t\t:";
    cin >> fNum1;
    cout << "Enter float 1\t\t:";
    cin >> fNum2;
    cout << "Multiplication is\t:" << Multiply(fNum1, fNum2) << endl;

    return 0;
}

///////////////////////////////////////////////////////////////////
//
//  Name        :Multiply
//  Input       :T, T
//  Returns     :T
//  Description :Adds two entities of type T
//  Author      :Pranav Choudhary
//  Date        :13 Sept 2020
//
///////////////////////////////////////////////////////////////////
template<class T>
T Multiply(T tNum1, T tNum2)
{
    T tAnswer;
    tAnswer = tNum1 * tNum2;
    return tAnswer;
}