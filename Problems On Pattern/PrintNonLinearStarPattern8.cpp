/*
*   Program to print designated star patterns
*/
#include<iostream>
using namespace std;

class Pattern
{
    private:
        int iRow;
        int iCol;
    
    public:
        Pattern(int iRows, int iCols)
        {
            iRow = iRows;
            iCol = iCols;
        }
        bool Updater(int, int);
        void PrintPattern1();
        void PrintPattern2();
        void PrintPattern3();
        void PrintPattern4();
        void PrintPattern5();
        void PrintPattern6();
        void PrintPattern7();
        void PrintPattern8();
        void PrintPattern9();
        void PrintPattern10();
};

////////////////////////////////////////////////////////////////////////
//
//	Name		:Updater
//	Input		:void
//	Returns		:void
//	Description	:Updates Wrong inputs
//	Author		:Pranav Choudhary
//	Date		:20 August 2020
//
////////////////////////////////////////////////////////////////////////
bool Pattern::Updater(int iRow, int iCol)
{
    if(iRow != iCol)
    {
        cout << "Enter Equal number of rows nd columns\n";
        return false;
    }
    if(this->iRow < 0)
        this->iRow = -this->iRow;
    if(this->iCol < 0)
        this->iCol = -this->iCol;
    return true;
}

////////////////////////////////////////////////////////////////////////
//
//	Name		:PrintPattern1
//	Input		:void
//	Returns		:void
//	Description	:print given pattern
//                  A
//                  A B A
//                  A B C B A
//                  A B C D C B A
//                  A B C D E D C B A
//	Author		:Pranav Choudhary
//	Date		:20 August 2020
//
////////////////////////////////////////////////////////////////////////
void Pattern::PrintPattern1()
{
    int i = 0, j = 0, k = 0;
    char cAlp = '\0';
    if((Updater(this->iRow, this->iCol)) == false) return;

    for (i = 1; i <= this->iRow; i++)
    {
        for (j = 1, cAlp = 'A'; j <= 2 * i - 1; j++)
        {
            cout << cAlp << " ";
            if (j < i)
                cAlp++;
            else if (j >= i)
                --cAlp;            
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
//						1
//					  1 2 1
//					1 2 3 2 1
//                1 2 3 4 3 2 1
//              1 2 3 4 5 4 3 2 1
//	Author		:Pranav Choudhary
//	Date		:20 August 2020
//
////////////////////////////////////////////////////////////////////////
void Pattern::PrintPattern2()
{
    int i = 0, j = 0, iRange = 0, k = 0;
    if((Updater(this->iRow, this->iCol)) == false) return;
    iRange = (iCol * 2) - 1;
    for (i = 1; i <= this->iRow; i++)
    {
		for(j = 1, k = 1; j <= iRange; j++)
		{
			if(j >= iCol - i + 1 && j <= iCol + i - 1)
			{
				cout<< k << " ";
				if(j < iCol)
				{
					k++;
				}
				else if(j >= iCol)
				{
					--k;
				}
			}
			else
			{
				cout <<"  ";
			}
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
//                *******1*******
//                ******2*2******
//                *****3*3*3*****
//                ****4*4*4*4****
//                ***5*5*5*5*5***
//                **6*6*6*6*6*6**
//                *7*7*7*7*7*7*7*
//                8*8*8*8*8*8*8*8
//	Author		:Pranav Choudhary
//	Date		:20 August 2020
//
////////////////////////////////////////////////////////////////////////
void Pattern::PrintPattern3()
{
    int i = 0, j = 0, iRange = 0;
    if((Updater(this->iRow, this->iCol)) == false) return;
    iRange = (iCol * 2) - 1;
    for (i = 1; i <= this->iRow; i++)
    {
		for(j = 1; j <= iRange; j++)
		{
			if(j >= iCol - i + 1 && j <= iCol + i - 1 && iCol % 2 == 0)
			{
                if((j % 2 != 0 && i % 2 == 0) || (j % 2 == 0 && i % 2 != 0))
                {
                    cout << i;
                }
                else
                {
                    cout << "*";
                }
            }
            else if(j >= iCol - i + 1 && j <= iCol + i - 1 && iCol % 2 != 0)
			{
                if((j % 2 == 0 && i % 2 == 0) || (j % 2 != 0 && i % 2 != 0))
                {
                    cout << i;
                }
                else
                {
                    cout << "*";
                }
            }
            else
            {
                cout << "*";
            }
		}
        cout << endl;
    }
}

////////////////////////////////////////////////////////////////////////
//
//	Name		:PrintPattern4
//	Input		:void
//	Returns		:void
//	Description	:print given pattern
//                ********1********
//                *******2*2*******
//                ******3*3*3******
//                *****4*4*4*4*****
//                ****5*5*5*5*5****
//	Author		:Pranav Choudhary
//	Date		:20 August 2020
//
////////////////////////////////////////////////////////////////////////
void Pattern::PrintPattern4()
{
    int i = 0, j = 0, iRange = 0, k = 0;
    if((Updater(this->iRow, this->iCol)) == false) return;
    iRange = 8 * 2 + 1 ;
    k = iRange / 2 + 1;
    for (i = 1; i <= this->iRow; i++)
    {
		for(j = 1; j <= iRange; j++)
		{
			if(j >= k - i + 1 && j <= k + i - 1)
			{
                if((j % 2 == 0 && i % 2 == 0) || (j % 2 != 0 && i % 2 != 0))
                {
                    cout << i;
                }
                else
                {
                    cout << "*";
                }
            }
            else
            {
                cout << "*";
            }
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
//                 *
//                * *
//               * * *
//              * * * *
//	Author		:Pranav Choudhary
//	Date		:20 August 2020
//
////////////////////////////////////////////////////////////////////////
void Pattern::PrintPattern5()
{
    int i = 0, j = 0, iRange = 0;
    if((Updater(this->iRow, this->iCol)) == false) return;
    iRange = (iCol * 2) - 1;
    for (i = 1; i <= this->iRow; i++)
    {
		for(j = 1; j <= iRange; j++)
		{
			if(j >= iCol - i + 1 && j <= iCol + i - 1 && iCol % 2 == 0)
			{
                if((j % 2 != 0 && i % 2 == 0) || (j % 2 == 0 && i % 2 != 0))
                {
                    cout << "*";
                }
                else
                {
                    cout << " ";
                }
            }
            else if(j >= iCol - i + 1 && j <= iCol + i - 1 && iCol % 2 != 0)
			{
                if((j % 2 == 0 && i % 2 == 0) || (j % 2 != 0 && i % 2 != 0))
                {
                    cout << "*";
                }
                else
                {
                    cout << " ";
                }
            }
            else
            {
                cout << " ";
            }
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
//               * * * * *
//                * * * *
//                 * * *
//                  * *
//                   *
//	Author		:Pranav Choudhary
//	Date		:20 August 2020
//
////////////////////////////////////////////////////////////////////////
void Pattern::PrintPattern6()
{
    int i = 0, j = 0, iRange = 0;
    if((Updater(this->iRow, this->iCol)) == false) return;
    iRange = (iCol * 2) - 1;
    for (i = 1; i <= this->iRow; i++)
    {
		for(j = 1; j <= iRange; j++)
		{
			if(j >= i && j <= iRange - i + 1)
			{
                if((j % 2 != 0 && i % 2 != 0) || (j % 2 == 0 && i % 2 == 0))
                {
                    cout << "*";
                }
                else
                {
                    cout << " ";
                }
            }
            else
            {
                cout << " ";
            }
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
//                       *
//                     * * *
//                   * * * * *
//                 * * * * * * *
//                   * * * * *
//                     * * *
//                       *
//	Author		:Pranav Choudhary
//	Date		:20 August 2020
//
////////////////////////////////////////////////////////////////////////
void Pattern::PrintPattern7()
{
    int i = 0, j = 0, iRange = 0;
    if((Updater(this->iRow, this->iCol)) == false) return;

    iRange = (iRow * 2) - 1;
    
    for (i = 1; i <= iRange; i++)
    {
        if(i <= iRow)
        {
            for(j = 1; j <= iRange; j++)
            {
                if(j >= iCol - i + 1 && j <= iCol + i - 1)
                {
                    cout<<"* ";
                }
                else
                {
                    cout <<"  ";
                }
            }
		}
        else if( i > iRow)
        {
            for(j = 1; j <= iRange; j++)
            {
                if(j > i - iCol && j <= iRange - (i - iCol))
                {
                    cout<<"* ";
                }
                else
                {
                    cout <<"  ";
                }
            }
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
//                       *
//                     *   *
//                   *       *
//                 *           *
//                   *       *
//                     *   *
//                       *
//	Author		:Pranav Choudhary
//	Date		:20 August 2020
//
////////////////////////////////////////////////////////////////////////
void Pattern::PrintPattern8()
{
    int i = 0, j = 0, iRange = 0;
    if((Updater(this->iRow, this->iCol)) == false) return;

    iRange = (iRow * 2) - 1;
    
    for (i = 1; i <= iRange; i++)
    {
        if(i <= iRow)
        {
            for(j = 1; j <= iRange; j++)
            {
                if(j == iCol - i + 1 || j == iCol + i - 1)
                {
                    cout<<"* ";
                }
                else
                {
                    cout <<"  ";
                }
            }
		}
        else if( i > iRow)
        {
            for(j = 1; j <= iRange; j++)
            {
                if(j == i - iCol + 1 || j == iRange - (i - iCol))
                {
                    cout<<"* ";
                }
                else
                {
                    cout <<"  ";
                }
            }
        }        
        cout << endl;
    }
}

////////////////////////////////////////////////////////////////////////
//
//	Name		:PrintPattern9
//	Input		:void
//	Returns		:void
//	Description	:print given pattern
//                *
//                * *
//                * * *
//                * * * *
//                * * * * *
//                * * * *
//                * * *
//                * *
//                *
//	Author		:Pranav Choudhary
//	Date		:20 August 2020
//
////////////////////////////////////////////////////////////////////////
void Pattern::PrintPattern9()
{
    int i = 0, j = 0, iRange = 0;
    if((Updater(this->iRow, this->iCol)) == false) return;
    iRange = iRow * 2;
    for (i = 1; i <= iRange - 1; i++)
    {
        if(i <= iRow)
        {
            for (j = 1; j <= i; j++)
            {
                cout << "* ";
            }
        }
        else if(i > iRow)
        {
            for (j = 1; j <= iRange - i; j++)
            {
                cout << "* ";
            }
        }
        cout << endl;
    }
}

////////////////////////////////////////////////////////////////////////
//
//	Name		:PrintPattern10
//	Input		:void
//	Returns		:void
//	Description	:print given pattern
//
//	Author		:Pranav Choudhary
//	Date		:20 August 2020
//
////////////////////////////////////////////////////////////////////////
void Pattern::PrintPattern10()
{
    int i = 0, j = 0, iRange = 0;
    if((Updater(this->iRow, this->iCol)) == false) return;
    iRange = iRow * 2;
    for (i = 1; i <= iRange - 1; i++)
    {
        if(i <= iRow)
        {
            for (j = 1; j <= iCol; j++)
            {
                if(j > iCol - i)
                    cout << "* ";
                else
                    cout << "  ";
            }            
        }
        else if(i > iRow)
        {
            for (j = 1; j <= iCol; j++)
            {
                if(j > i - iCol)
                    cout << "* ";
                else
                {
                    cout << "  ";
                }
            }
        }
        cout << endl;
    }
}
int main()
{
    int iValue1 = 0, iValue2 = 0;
    cout << "Enter the number of rows\n";
    cin >> iValue1;
    cout << "Enter the number of columns\n";
    cin >> iValue2;

    Pattern pObj(iValue1, iValue2);

    cout << "\n-----Pattern 1-----\n";
    pObj.PrintPattern1();
    cout << "\n-----Pattern 2-----\n";
    pObj.PrintPattern2();
    cout << "\n-----Pattern 3-----\n";
    pObj.PrintPattern3();
    cout << "\n-----Pattern 4-----\n";
    pObj.PrintPattern4();    
    cout << "\n-----Pattern 5-----\n";
    pObj.PrintPattern5(); 
    cout << "\n-----Pattern 6-----\n";
    pObj.PrintPattern6(); 
    cout << "\n-----Pattern 7-----\n";
    pObj.PrintPattern7();
    cout << "\n-----Pattern 8-----\n";
    pObj.PrintPattern8();
    cout << "\n-----Pattern 9-----\n";
    pObj.PrintPattern9();
    cout << "\n-----Pattern 10-----\n";
    pObj.PrintPattern10();

    return 0;
}