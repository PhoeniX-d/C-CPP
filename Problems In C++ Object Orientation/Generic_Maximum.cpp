/*
*    Write generic program to find max of 3 numbers.
*/
#include <iostream>
using namespace std;

template <class T>
T Maximum(T t1, T t2, T t3);

int main()
{
    int iNum1 = 0, iNum2 = 0, iNum3 = 0, iRet = 0;
    char ch1, ch2, ch3, cRet = '\0';

    cout << "Enter three numbers\n";
    cin >> iNum1>>iNum2>>iNum3;
    iRet = Maximum(iNum1, iNum2, iNum3);
    cout << "Maximum is\t\t:" << iRet <<endl;

    cout << "Enter three character\n";
    cin >> ch1 >> ch2 >> ch3;
    cRet = Maximum(ch1, ch2, ch3);
    cout << "Maximum is\t\t:" << cRet <<endl;

    return 0;
}

///////////////////////////////////////////////////////////////////
//
//  Name        :Maximum
//  Input       :T, T, T
//  Returns     :T
//  Description :Finds maximum of three entities
//  Author      :Pranav Choudhary
//  Date        :14 Sept 2020
//
///////////////////////////////////////////////////////////////////
template<class T>
T Maximum(T t1, T t2, T t3)
{
    if(t1 > t2)
    {
        if(t1 > t3)
        {
            return t1;
        }
        else 
        {
            return t3;
        }
    }
    else
    {
        if(t2 > t3)
        {
            return t2;
        }
        else
        {
            return t3;
        }
        
    } 
}