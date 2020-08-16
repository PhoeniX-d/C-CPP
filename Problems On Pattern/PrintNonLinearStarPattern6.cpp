/*
*   Program to print designated star patterns
*/
#include<iostream>
#include<iomanip>
#include<string.h>

using namespace std;
class Pattern
{
    private:
        int iRow;
      	char* cStr;
    
    public:
        Pattern(int iRows)
        {
            iRow = iRows;
        }

        void Updater(int);
        void PrintPattern1();
        void PrintPattern2();
        void PrintPattern3();
        void PrintPattern4();
        void PrintPattern5(char*);
        void PrintPattern6(char*);
        void PrintPattern7(char*);
        void PrintPattern8(char*);
};

////////////////////////////////////////////////////////////////////////
//
//	Name		:Updater
//	Input		:int
//	Returns		:void
//	Description	:Updates Wrong inputs
//	Author		:Pranav Choudhary
//	Date		:16 August 2020
//
////////////////////////////////////////////////////////////////////////
void Pattern::Updater(int iRow)
{
    if(this->iRow < 0)
        this->iRow = -this->iRow; 
}

////////////////////////////////////////////////////////////////////////
//
//	Name		:PrintPattern1
//	Input		:void
//	Returns		:void
//	Description	:print given pattern
//                       1
//                     1 1 1
//                   1 0 1 0 1
//                 1 0 0 1 0 0 1
//               1 0 0 0 1 0 0 0 1
//             1 1 1 1 1 1 1 1 1 1 1
//	Author		:Pranav Choudhary
//	Date		:16 August 2020
//
////////////////////////////////////////////////////////////////////////
void Pattern::PrintPattern1()
{
    int i = 0, j = 0, iRange = iRow * 2 - 1;
    Updater(this->iRow);
    for (i = 1; i <= this->iRow; i++)
    {
        for (j = 1; j <= iRange; j++)
        {
            if(j == iRow || i == iRow || j == iRow - i + 1 || j == iRow + i - 1)
                cout << "1 ";
            else if(j > iRow - i + 1 && j < iRow || j < iRow + i - 1 && j > iRow)
                cout << "0 ";
            else
                cout << "  ";
        }
        cout << endl;
    }
}

////////////////////////////////////////////////////////////////////////
//
//	Name		:PrintPattern2
//	Input		:void
//	Returns		:void
//	Description	:print given pattern
//					0
//					1  1
//					2  3  5
//					8 13 21 34
//	Author		:Pranav Choudhary
//	Date		:16 August 2020
//
////////////////////////////////////////////////////////////////////////
void Pattern::PrintPattern2()
{
    int i = 0, j = 0,iF = 0, iS = 1, iT = 0;
    Updater(this->iRow);
    for (i = 1; i <= this->iRow; i++)
    {
        for (j = 1; j <= i; j++)
        {
            cout << setw(4) << iF;
            iT = iF + iS;
            iF = iS;
            iS = iT;
        }
        cout << endl;
    }
}

////////////////////////////////////////////////////////////////////////
//
//	Name		:PrintPattern3
//	Input		:void
//	Returns		:void
//	Description	:print given pattern
//					1
//					1 1
//					1 2 3
//					1 2 3 6
//					1 2 3 4 10
//	Author		:Pranav Choudhary
//	Date		:16 August 2020
//
////////////////////////////////////////////////////////////////////////
void Pattern::PrintPattern3()
{
    int i = 0, j = 0, iSum = 1;
    Updater(this->iRow);
    for (i = 1; i <= this->iRow; i++)
    {
        for (j = 1; j <= i; j++)
        {
            if(i == j)
            {
                cout << setw(3) << iSum;
            }
            else
            {
            	cout << setw(3) << j;
            	iSum = iSum + j;
            }
        }
        iSum = 0;
        cout << endl;
    }
}

////////////////////////////////////////////////////////////////////////
//
//	Name		:PrintPattern4
//	Input		:void
//	Returns		:void
//	Description	:print given pattern
//					1
//					1 2
//					1 2 3
//					1 2 3 4
//					4 6 6 4 0
//	Author		:Pranav Choudhary
//	Date		:16 August 2020
//
////////////////////////////////////////////////////////////////////////
void Pattern::PrintPattern4()
{
    int i = 0, j = 0, iSum = 0;
    Updater(this->iRow);
    for (i = 1; i <= this->iRow; i++)
    {
        for (j = 1; j <= i; j++)
        {
            if(i == iRow)
                cout << setw(3) << (i - j) * j;
            else
                cout << setw(3) << j;
        }
        cout << endl;
    }
}

////////////////////////////////////////////////////////////////////////
//
//	Name		:PrintPattern5
//	Input		:void
//	Returns		:void
//	Description	:print given pattern
//                  P
//                  P r
//                  P r a
//                  P r a n
//                  P r a n a
//                  P r a n a v
//	Author		:Pranav Choudhary
//	Date		:16 August 2020
//
////////////////////////////////////////////////////////////////////////
void Pattern::PrintPattern5(char *str)
{
    int i = 0, j = 0, iLen = strlen(str);
    for (i = 0; i < iLen; i++)
    {
        for (j = 0; j <= i; j++)
        {
            cout << str[j] << " ";
        }
        cout << endl;
    }
}

////////////////////////////////////////////////////////////////////////
//
//	Name		:PrintPattern6
//	Input		:void
//	Returns		:void
//	Description	:print given pattern
//                  P r a n a v
//                  P r a n a
//                  P r a n
//                  P r a
//                  P r
//                  P
//	Author		:Pranav Choudhary
//	Date		:16 August 2020
//
////////////////////////////////////////////////////////////////////////
void Pattern::PrintPattern6(char *str)
{
    int i = 0, j = 0, iLen = strlen(str);
    for (i = 0; i < iLen; i++)
    {
        for (j = 0; j < iLen; j++)
        {
            if(j < iLen - i)
                cout << str[j] << " ";
        }
        cout << endl;
    }
}

////////////////////////////////////////////////////////////////////////
//
//	Name		:PrintPattern7
//	Input		:void
//	Returns		:void
//	Description	:print given pattern
//                  P r A n A v
//                  P r A n A
//                  P r A n
//                  P r A
//                  P r
//                  P
//	Author		:Pranav Choudhary
//	Date		:16 August 2020
//
////////////////////////////////////////////////////////////////////////
void Pattern::PrintPattern7(char *str)
{
    int i = 0, j = 0, iLen = strlen(str);
    for (i = 0; i < iLen; i++)
    {
        for (j = 0; j < iLen - i; j++)
        {
            if(j % 2 == 0)
            {
                if(str[j] >= 'a' && str[j] <= 'z')
                    str[j] = str[j] - 32;
            }
            cout << str[j] << " ";
        }
        cout << endl;
    }
}

////////////////////////////////////////////////////////////////////////
//
//	Name		:PrintPattern8
//	Input		:void
//	Returns		:void
//	Description	:print given pattern
//                  1
//                  4  9
//                  16 25 36
//	Author		:Pranav Choudhary
//	Date		:16 August 2020
//
////////////////////////////////////////////////////////////////////////
void Pattern::PrintPattern8(char *str)
{
    int i = 0, j = 0, iNum = 1;
    Updater(this->iRow);
    for (i = 1; i <= iRow; i++)
    {
        for (j = 1; j <= i; j++, iNum++)
        {
            cout << setw(3) << iNum * iNum << " ";
        }
            cout << endl;
    }
}

int main()
{
    int iValue1 = 0, iValue2 = 0;
    char cStr[10];
    cout << "Enter the number of rows\n";
    cin >> iValue1;

    cout << "Enter the string\n";
    cin >> cStr;

    Pattern pObj(iValue1);
    cout << "\n-----Pattern 1-----\n";
    pObj.PrintPattern1();
    cout << "\n-----Pattern 2-----\n";
    pObj.PrintPattern2();
    cout << "\n-----Pattern 3-----\n";
    pObj.PrintPattern3();
    cout << "\n-----Pattern 4-----\n";
    pObj.PrintPattern4(); 
    cout << "\n-----Pattern 5-----\n";
    pObj.PrintPattern5(cStr);
    cout << "\n-----Pattern 6-----\n";
    pObj.PrintPattern6(cStr);
    cout << "\n-----Pattern 7-----\n";
    pObj.PrintPattern7(cStr);
    /*cout << "\n-----Pattern 8-----\n";
    pObj.PrintPattern8();*/

    return 0;
}
