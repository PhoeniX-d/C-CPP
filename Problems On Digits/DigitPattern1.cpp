/*
*   Program On Strings Patterns
*/

#include<iostream>
#include<stdio.h>

using namespace std;

class DigitPattern
{
    public:

        void Display1(long long);
        void Display2(long long);
        void Display3(long long);
        void Display4(long long);
        void Display5(long long);
};

//////////////////////////////////////////////////
//
//  Name        :Display1
//  Input       :long long
//  Returns     :void
//  Description :Prints following pattern
//               Input  :   7846
//               Output :   6 4 8 7
//                          6 4 8 7
//                          6 4 8 7
//                          6 4 8 7
//  Author      :Pranav Choudhary
//  Date        :29 Aug 2020
//
//////////////////////////////////////////////////
void DigitPattern::Display1(long long lNum)
{
    int i = 0, iLen = 0;
    long long lTemp = lNum;

    if(lNum < 0)
        lNum = -lNum;

    while(lTemp != 0)
    {
        iLen++;
        lTemp = lTemp/ 10;
    }

    for (i = 1; i <= iLen; i++)
    {
        for (lTemp = lNum; lTemp != 0; lTemp = lTemp / 10)
        {
            cout << lTemp % 10  << " ";
        }
        cout << endl;
    }
}

//////////////////////////////////////////////////
//
//  Name        :Display2
//  Input       :long long
//  Returns     :void
//  Description :Prints following pattern
//               Input  :   7846
//               Output :   7 8 4 6
//                          7 8 4 6
//                          7 8 4 6
//                          7 8 4 6
//  Author      :Pranav Choudhary
//  Date        :29 Aug 2020
//
//////////////////////////////////////////////////
void DigitPattern::Display2(long long lNum)
{
    int i = 0, iLen = 0;
    long long lTemp = lNum, lRev = 0L;
    
    if(lNum < 0)
        lNum = -lNum;
    
    while(lTemp != 0)
    {
        iLen++;
        lRev = lRev * 10 + (lTemp % 10);
        lTemp = lTemp/ 10;
    }
    for (i = 1; i <= iLen; i++)
    {
        for (lTemp = lRev; lTemp != 0; lTemp = lTemp / 10)
        {
            cout << lTemp % 10  << " ";
        }
        cout << endl;
    }
}

//////////////////////////////////////////////////
//
//  Name        :Display3
//  Input       :long long
//  Returns     :void
//  Description :Prints following pattern
//               Input  :   7846
//               Output :   7 8 4 6
//                          7 8 4
//                          7 8
//                          7
//  Author      :Pranav Choudhary
//  Date        :29 Aug 2020
//
//////////////////////////////////////////////////
void DigitPattern::Display3(long long lNum)
{
    int i = 0, j = 0, iLen = 0;
    long long lTemp = lNum, lRev = 0L;
    
    if(lNum < 0)
        lNum = -lNum;
    
    while(lTemp != 0)
    {
        iLen++;
        lRev = lRev * 10 + (lTemp % 10);
        lTemp = lTemp/ 10;
    }
    for (i = 1; i <= iLen; i++)
    {
        lTemp = lRev;
        for (j = 1; j <= iLen - i + 1; j++)
        {
            cout << lTemp % 10  << " ";
            lTemp = lTemp / 10;
        }
        cout << endl;
    }
}

//////////////////////////////////////////////////
//
//  Name        :Display4
//  Input       :long long
//  Returns     :void
//  Description :Prints following pattern
//               Input  :   7846
//               Output :   7
//                          7 8
//                          7 8 4
//                          7 8 4 6
//  Author      :Pranav Choudhary
//  Date        :29 Aug 2020
//
//////////////////////////////////////////////////
void DigitPattern::Display4(long long lNum)
{
    int i = 0, j = 0, iLen = 0;
    long long lTemp = lNum, lRev = 0L;
    
    if(lNum < 0)
        lNum = -lNum;
    
    while(lTemp != 0)
    {
        iLen++;
        lRev = lRev * 10 + (lTemp % 10);
        lTemp = lTemp/ 10;
    }
    for (i = 1; i <= iLen; i++)
    {
        lTemp = lRev;
        for (j = 1; j <= i; j++)
        {
            cout << lTemp % 10  << " ";
            lTemp = lTemp / 10;
        }
        cout << endl;
    }
}

//////////////////////////////////////////////////
//
//  Name        :Display5
//  Input       :long long
//  Returns     :void
//  Description :Prints following pattern
//               Input  :   7846
//               Output :   6
//                          6 4 
//                          6 4 8
//                          6 4 8 7
//  Author      :Pranav Choudhary
//  Date        :29 Aug 2020
//
//////////////////////////////////////////////////
void DigitPattern::Display5(long long lNum)
{
    int i = 0, j = 0, iLen = 0;
    long long lTemp = lNum;
    
    if(lNum < 0)
        lNum = -lNum;
    
    while(lTemp != 0)
    {
        iLen++;
        lTemp = lTemp/ 10;
    }
    for (i = 1; i <= iLen; i++)
    {
        lTemp = lNum;
        for (j = 1; j <= i; j++)
        {
            cout << lTemp % 10  << " ";
            lTemp = lTemp / 10;
        }
        cout << endl;
    }
}

int main()
{
    DigitPattern dpObj;
    long long lNo = 0L;

    cout << "Enter the number:" << endl;
    cin >> lNo;

    cout << "\nOutput:\n\n";
    dpObj.Display1(lNo);

    cout << "\nOutput:\n\n";
    dpObj.Display2(lNo);

    cout << "\nOutput:\n\n";
    dpObj.Display3(lNo);

    cout << "\nOutput:\n\n";
    dpObj.Display4(lNo);

    cout << "\nOutput:\n\n";
    dpObj.Display5(lNo);

    return 0;
}
