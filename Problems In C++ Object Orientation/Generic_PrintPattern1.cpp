/*
*   Write generic program which accept one value and one number from user. Print
*   that value that number of times on screen
*/

#include<iostream>
using namespace std;

template<class T>
void Display(T, int);

int main()
{
    int iNum = 0, iValue = 0;
    char cValue = '\0';
    float fValue = 0.0;

    cout << "Enter a integer\t\t:";
    cin >> iValue;

    cout << "Enter a real number\t:";
    cin >> fValue;

    cout << "Enter a character\t:";
    cin >> cValue;

    cout << "Enter number of times\t:";
    cin >> iNum;

    cout << "Output" << endl;
    Display(iValue, iNum);
    Display(fValue, iNum);
    Display(cValue, iNum);

    return 0;
}

//////////////////////////////////////////////////////////////////
//  Name        :ArraySum
//  Input       :T, int
//  Returns     :void
//  Description :Print T value that iN  times on screen
//  Author      :Pranav Choudhary
//  Date        :14 Sept 2020
//
///////////////////////////////////////////////////////////////////
template<class T>
void Display(T tVal, int iN)
{
    int i = 0;
    if(iN < 0)
    {
        iN = -iN;
    }

    for(i = 1; i <= iN; i++)
    {
        cout << tVal << " ";
    }
    cout << endl;
}
