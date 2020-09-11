/*
*   Solved Problems on Doubly Linear Linked List Using C++
*/
#include<stdio.h>
#include<stdlib.h>
#include<iostream>
using namespace std;

#define SUCEESS         0x0000
#define EMPTY           0x1000
#define INVALID_POS     0x0100
#define NOTFOUND        0x0010
#define FAILURE         0x0001

/* Structure of node for Doubly Linear Linked List */
typedef class dNode
{
    public:
    int     iData;
    dNode   *npNext;
    dNode   *npPrev;
} DNODE, *PDNODE;

class Doubly_LinearLL
{
    private:
        PDNODE Head;
        PDNODE Tail;
        int iCount;

    public:
        Doubly_LinearLL();          /* Constructor to initialize fields */
        ~Doubly_LinearLL();         /* Destructor to deallocate List */
        bool InsertLast(int);       /* Insert elements in List */
        bool DisplayListF();        /* Displays els in List forward direction */
        bool DisplayListB();        /* Displays els in List reverse direction */
        int  Count();               /* Return counts of els in List */

        /* Problems */
        int     Occurances(int);
        int     FirstOccur(int);
        int     SecOccur(int);
        int     LastOccur(int);
        int     SecLastOccur(int);
        void    ListCat(Doubly_LinearLL &);
        void    ListCpy(Doubly_LinearLL &);
        void    ListCpyEven(Doubly_LinearLL &);
        void    ListCpyPrime(Doubly_LinearLL &);
        void    ListNCat(Doubly_LinearLL &, int);
        void    ListNCpy(Doubly_LinearLL &, int);
        void    ListLNCat(Doubly_LinearLL &, int);
        void    ListLNCpy(Doubly_LinearLL &, int);
        void    ListRangeCat(Doubly_LinearLL &, int, int);
        void    ListRangeCpy(Doubly_LinearLL &, int, int);
        void    ListAltCat(Doubly_LinearLL &);
        void    ListAltCpy(Doubly_LinearLL &);
        int     IsSublistF(Doubly_LinearLL&);
        int     IsSublistL(Doubly_LinearLL&);
        void    ListSortAsc();
        void    ListSortDesc();
};

////////////////////////////////////////////////////////////
//
//  Name        :Doubly_LinearLL
//  Input       :void
//  Returns     :   -
//  Description :constructor
//  Author      :Pranav Choudhary
//  Date        :11 Sept 2020
//
////////////////////////////////////////////////////////////
Doubly_LinearLL::Doubly_LinearLL()
{
    Head = NULL;
    Tail = NULL;
    iCount = 0;
}// end of constructor

////////////////////////////////////////////////////////////
//
//  Name        :~Doubly_LinearLL
//  Input       :   -
//  Returns     :   -
//  Description :desstructor
//  Author      :Pranav Choudhary
//  Date        :11 Sept 2020
//
////////////////////////////////////////////////////////////
Doubly_LinearLL::~Doubly_LinearLL()
{
    if(NULL != Head && Tail != NULL)
    {
        PDNODE nTemp = NULL;
        while(Head != NULL)
        {
            nTemp = Head;
            Head = nTemp->npNext;
            delete nTemp;
            iCount--;
        }   
    }
}// end of destructor

////////////////////////////////////////////////////////////
//
//  Name        :DisplayListF
//  Input       :void
//  Returns     :bool
//  Description :Displays elements in linked list forward
//  Author      :Pranav Choudhary
//  Date        :11 Sept 2020
//
////////////////////////////////////////////////////////////
bool Doubly_LinearLL::DisplayListF()
{
    if(NULL == Head && Tail == NULL)
    {
        printf("Linked List is Empty\n");
        return false;
    }
    PDNODE First = Head;
    printf("NULL");
    while(First != NULL)
    {
        printf("<-|%d|->", First->iData);
        First = First->npNext;
    }
    printf("NULL\n\n");
    return true;
}// end of DisplayListF

////////////////////////////////////////////////////////////
//
//  Name        :DisplayListB
//  Input       :void
//  Returns     :bool
//  Description :Displays elements in linked list reverse
//  Author      :Pranav Choudhary
//  Date        :11 Sept 2020
//
////////////////////////////////////////////////////////////
bool Doubly_LinearLL::DisplayListB()
{    
    if(NULL == Head && Tail == NULL)
    {
        printf("Linked List is Empty\n");
        return false;
    }
    PDNODE Last = Tail;
    printf("NULL");
    while(Last != NULL)
    {
        printf("<-|%d|->", Last->iData);
        Last = Last->npPrev;
    }
    printf("NULL\n\n");
    return true;
}// end of DisplayListB

////////////////////////////////////////////////////////////
//
//  Name        :CountEls
//  Input       :void
//  Returns     :int
//  Description :counts elements in linked list
//  Author      :Pranav Choudhary
//  Date        :11 Sept 2020
//
////////////////////////////////////////////////////////////
int Doubly_LinearLL::Count()
{
    return iCount;
}// end of CountEls

//////////////////////////////////////////////////////////////////
//
//  Name        :InsertLast
//  Input       :int
//  Returns     :bool
//  Description :Inserts element in Linked list at last position
//  Author      :Pranav Choudhary
//  Date        :11 Sept 2020
//
//////////////////////////////////////////////////////////////////
bool Doubly_LinearLL::InsertLast(int iNum)
{
    PDNODE NewN = new DNODE;
    if(NULL == NewN)
    {
        printf("Memory Allocation failed\n");
        return false;
    }
    NewN->iData = iNum;
    NewN->npNext = NULL;
    NewN->npPrev = NULL;

    if(NULL == Head)
    {
        Head = NewN;
        Tail = NewN;
    }
    else
    {
        Tail->npNext = NewN;
        NewN->npPrev = Tail;
        Tail = NewN;
    }
    iCount++;
    return true;
}// end of InsertLast

//////////////////////////////////////////////////////////////////
//
//  Name        :Occurances
//  Input       :int
//  Returns     :int
//  Description :Searches all occurances of iNum in list
//  Author      :Pranav Choudhary
//  Date        :11 Sept 2020
//
//////////////////////////////////////////////////////////////////
int Doubly_LinearLL::Occurances(int iNum)
{
    if(Head == NULL && Tail == NULL)
    {
        return EMPTY;
    }
    PDNODE temp = Head;
    int iCnt = 0;
    while(temp != NULL)
    {
        if(temp->iData == iNum)
        {
            iCnt++;
        }
        temp = temp->npNext;
    }
    if(iCnt == 0)
    {
        return NOTFOUND;
    }
    else 
    {
        return iCnt;
    }
}// End of Occurances

//////////////////////////////////////////////////////////////////
//
//  Name        :FirstOccur
//  Input       :int
//  Returns     :int
//  Description :Searches first occurance of iNum in list
//  Author      :Pranav Choudhary
//  Date        :11 Sept 2020
//
//////////////////////////////////////////////////////////////////
int Doubly_LinearLL::FirstOccur(int iNum)
{
    if(Head == NULL && Tail == NULL)
    {
        return EMPTY;
    }
    PDNODE temp = Head;
    int iCnt = 0, iPos = -1;
    while(temp != NULL)
    {
        iCnt++;
        if(temp->iData == iNum)
        {
            iPos = iCnt;
            break;
        }
        temp = temp->npNext;
    }
    if(iPos == -1)
    {
        return NOTFOUND;
    }
    else 
    {
        return iPos;
    }
}// End of FirstOccur

//////////////////////////////////////////////////////////////////
//
//  Name        :SecOccur
//  Input       :int
//  Returns     :int
//  Description :Searches first occurance of iNum in list
//  Author      :Pranav Choudhary
//  Date        :11 Sept 2020
//
//////////////////////////////////////////////////////////////////
int Doubly_LinearLL::SecOccur(int iNum)
{
    if(Head == NULL && Tail == NULL)
    {
        return EMPTY;
    }
    PDNODE temp = Head;
    int iCnt1 = 0, iCnt2 = 0, iPos = -1;
    while(temp != NULL)
    {
        iCnt1++;
        if(temp->iData == iNum)
        {
            iCnt2++;
            if(iCnt2 == 1 || iCnt2 == 2)
            {
                iPos = iCnt1;
            }
        }
        temp = temp->npNext;
    }
    if(iPos == -1)
    {
        return NOTFOUND;
    }
    else 
    {
        return iPos;
    }
}// End of SecOccur

//////////////////////////////////////////////////////////////////
//
//  Name        :LastOccur
//  Input       :int
//  Returns     :int
//  Description :Searches last occurance of iNum in list
//  Author      :Pranav Choudhary
//  Date        :11 Sept 2020
//
//////////////////////////////////////////////////////////////////
int Doubly_LinearLL::LastOccur(int iNum)
{
    if(Head == NULL && Tail == NULL)
    {
        return EMPTY;
    }
    PDNODE temp = Tail;
    int iCnt = this->iCount, iPos = -1;
    while(temp != NULL)
    {
        if(temp->iData == iNum)
        {
            iPos = iCnt;
            break;
        }
        iCnt--;
        temp = temp->npPrev;
    }
    if(iPos == -1)
    {
        return NOTFOUND;
    }
    else 
    {
        return iPos;
    }
}// End of LastOccur

//////////////////////////////////////////////////////////////////
//
//  Name        :SecLastOccur
//  Input       :int
//  Returns     :int
//  Description :Searches second last occurance of iNum in list
//  Author      :Pranav Choudhary
//  Date        :11 Sept 2020
//
//////////////////////////////////////////////////////////////////
int Doubly_LinearLL::SecLastOccur(int iNum)
{
    if(Head == NULL && Tail == NULL)
    {
        return EMPTY;
    }
    PDNODE temp = Tail;
    int iCnt1 = this->iCount, iCnt2 = 0, iPos = -1;
    while(temp != NULL)
    {
        if(temp->iData == iNum)
        {
            iCnt2++;
            if(iCnt2 == 1 || iCnt2 == 2)
            {
                iPos = iCnt1;
            }
            break;
        }
        iCnt1--;
        temp = temp->npPrev;
    }
    if(iPos == -1)
    {
        return NOTFOUND;
    }
    else 
    {
        return iPos;
    }
}// End of LastOccur

//////////////////////////////////////////////////////////////////
//
//  Name        :ListCat
//  Input       :Doubly_LinearLL &
//  Returns     :int
//  Description :Concates two linked lists
//  Author      :Pranav Choudhary
//  Date        :11 Sept 2020
//
//////////////////////////////////////////////////////////////////
void Doubly_LinearLL::ListCat(Doubly_LinearLL &List2)
{
    PDNODE temp = List2.Head;
    while(temp != NULL)
    {
        this->InsertLast(temp->iData);
        temp = temp->npNext;
    }
}// End of ListCat

//////////////////////////////////////////////////////////////////
//
//  Name        :ListNCat
//  Input       :Doubly_LinearLL &, int
//  Returns     :int
//  Description :Concates two linked lists upto first N els
//  Author      :Pranav Choudhary
//  Date        :11 Sept 2020
//
//////////////////////////////////////////////////////////////////
void Doubly_LinearLL::ListNCat(Doubly_LinearLL &List2, int iN)
{
    if(List2.Head == NULL && List2.Tail == NULL)
    {
        cout << "Linked List 2 is empty\n";
        return;
    }

    if(iN < 1 || iN > List2.iCount)
    {
        cout << "Invalid N entered\n";
        return;
    }

    PDNODE temp = List2.Head;
    while(temp != NULL && iN != 0)
    {
        this->InsertLast(temp->iData);
        temp = temp->npNext;
        iN--;
    };
}// End of ListNCat

//////////////////////////////////////////////////////////////////
//
//  Name        :ListLNCat
//  Input       :Doubly_LinearLL &, int
//  Returns     :int
//  Description :Concates two linked lists only last N els
//  Author      :Pranav Choudhary
//  Date        :11 Sept 2020
//
//////////////////////////////////////////////////////////////////
void Doubly_LinearLL::ListLNCat(Doubly_LinearLL &List2, int iN)
{
    if(List2.Head == NULL && List2.Tail == NULL)
    {
        cout << "Linked List 2 is empty\n";
        return;
    }
    
    if(iN < 1 || iN > this->iCount || iN > List2.iCount)
    {
        cout << "Invalid position entered\n";
        return;
    }

    PDNODE temp = List2.Tail;
    while(iN != 0 && temp != NULL)
    {
        temp = temp->npPrev;
        iN--;
    }
    while(temp != NULL)
    {
        this->InsertLast(temp->iData);
        temp = temp->npNext;
    }
}// End of ListLNCat

//////////////////////////////////////////////////////////////////
//
//  Name        :ListRangeCat
//  Input       :Doubly_LinearLL &, int, int
//  Returns     :void
//  Description :Concates List2 only els in range
//  Author      :Pranav Choudhary
//  Date        :11 Sept 2020
//
//////////////////////////////////////////////////////////////////
void Doubly_LinearLL::ListRangeCat(Doubly_LinearLL &List2, int iS, int iE)
{
    if(List2.Head == NULL && List2.Tail == NULL)
    {
        cout << "Linked List 2 is empty\n";
        return;
    }
    
    if(iS < 1 || iE > List2.iCount || iS > iE)
    {
        cout << "Invalid position entered\n";
        return;
    }

    PDNODE temp = List2.Head;
    int iCnt = iE - iS;
    while(iS != 1 && temp != NULL)
    {
        temp = temp->npNext;
        iS--;
    }
    while(temp != NULL && iCnt != -1)
    {
        this->InsertLast(temp->iData);
        temp = temp->npNext;
        iCnt--;
    }
}// End of ListRangeCat

//////////////////////////////////////////////////////////////////
//
//  Name        :ListAltCat
//  Input       :Doubly_LinearLL &, int, int
//  Returns     :void
//  Description :Concates List2 only els in range
//  Author      :Pranav Choudhary
//  Date        :11 Sept 2020
//
//////////////////////////////////////////////////////////////////
void Doubly_LinearLL::ListAltCat(Doubly_LinearLL &List2)
{
    if(List2.Head == NULL && List2.Tail == NULL)
    {
        cout << "Linked List 2 is empty\n";
        return;
    }

    PDNODE temp = List2.Head;
    while(temp != NULL)
    {
        this->InsertLast(temp->iData);
        if(temp->npNext != NULL)
            temp = temp->npNext->npNext;
        else
            temp = temp->npNext;
    }
}// End of ListAltCat

//////////////////////////////////////////////////////////////////
//
//  Name        :ListCpy
//  Input       :Doubly_LinearLL &
//  Returns     :int
//  Description :Copies two List 1 into List 2
//  Author      :Pranav Choudhary
//  Date        :11 Sept 2020
//
//////////////////////////////////////////////////////////////////
void Doubly_LinearLL::ListCpy(Doubly_LinearLL &List2)
{
    if(List2.Head != NULL && List2.Tail != NULL)
    {
        cout << "Linked List 2 is not empty\n";
        return;
    }
    PDNODE temp = this->Head;
    while(temp != NULL)
    {
        List2.InsertLast(temp->iData);
        temp = temp->npNext;
    }
}// End of ListCpy

//////////////////////////////////////////////////////////////////
//
//  Name        :ListNCpy
//  Input       :Doubly_LinearLL &, int
//  Returns     :int
//  Description :Copies List1 to List2 upto first N els
//  Author      :Pranav Choudhary
//  Date        :11 Sept 2020
//
//////////////////////////////////////////////////////////////////
void Doubly_LinearLL::ListNCpy(Doubly_LinearLL &List2, int iN)
{
    if(List2.Head != NULL && List2.Tail != NULL)
    {
        cout << "Linked List 2 is not empty\n";
        return;
    }

    if(iN < 1 || iN > this->iCount)
    {
        cout << "Invalid N entered\n";
        return;
    }

    PDNODE temp = this->Head;
    while(temp != NULL && iN != 0)
    {
        List2.InsertLast(temp->iData);
        temp = temp->npNext;
        iN--;
    };
}// End of ListNCpy

//////////////////////////////////////////////////////////////////
//
//  Name        :ListLNCpy
//  Input       :Doubly_LinearLL &, int
//  Returns     :int
//  Description :Copies List1 into List2 only last N els
//  Author      :Pranav Choudhary
//  Date        :11 Sept 2020
//
//////////////////////////////////////////////////////////////////
void Doubly_LinearLL::ListLNCpy(Doubly_LinearLL &List2, int iN)
{
    if(List2.Head != NULL && List2.Tail != NULL)
    {
        cout << "Linked List 2 is not empty\n";
        return;
    }
    
    if(iN < 1 || iN > this->iCount)
    {
        cout << "Invalid position entered\n";
        return;
    }

    PDNODE temp = this->Tail;
    while(iN != 1 && temp != NULL)
    {
        temp = temp->npPrev;
        iN--;
    }
    while(temp != NULL)
    {
        List2.InsertLast(temp->iData);
        temp = temp->npNext;
    }
}// End of ListLNCpy

//////////////////////////////////////////////////////////////////
//
//  Name        :ListRangeCat
//  Input       :Doubly_LinearLL &, int, int
//  Returns     :void
//  Description :Concates List2 only els in range
//  Author      :Pranav Choudhary
//  Date        :11 Sept 2020
//
//////////////////////////////////////////////////////////////////
void Doubly_LinearLL::ListRangeCpy(Doubly_LinearLL &List2, int iS, int iE)
{
    if(List2.Head != NULL && List2.Tail != NULL)
    {
        cout << "Linked List 2 is not empty\n";
        return;
    }
    
    if(iS < 1 || iE > this->iCount || iS > iE)
    {
        cout << "Invalid position entered\n";
        return;
    }

    PDNODE temp = this->Head;
    int iCnt = iE - iS;
    while(iS != 1 && temp != NULL)
    {
        temp = temp->npNext;
        iS--;
    }
    while(temp != NULL && iCnt != -1)
    {
        List2.InsertLast(temp->iData);
        temp = temp->npNext;
        iCnt--;
    }
}// End of ListRangeCpy

//////////////////////////////////////////////////////////////////
//
//  Name        :ListAltCpy
//  Input       :Doubly_LinearLL &
//  Returns     :void
//  Description :Concates List2's alternate els
//  Author      :Pranav Choudhary
//  Date        :11 Sept 2020
//
//////////////////////////////////////////////////////////////////
void Doubly_LinearLL::ListAltCpy(Doubly_LinearLL &List2)
{
    if(List2.Head != NULL && List2.Tail != NULL)
    {
        cout << "Linked List 2 is not empty\n";
        return;
    }

    PDNODE temp = this->Head;
    while(temp != NULL)
    {
        List2.InsertLast(temp->iData);
        if(temp->npNext != NULL)
            temp = temp->npNext->npNext;
        else
            temp = temp->npNext;
    }
}// End of ListAltCpy

/////////////////////////////////////////////////////////////////////////
//
//  Name        :ListCpyEven
//  Input       :Doubly_LinearLL &
//  Returns     :void
//  Description :Copies List1 els to List2 whose additionof digit is Even
//  Author      :Pranav Choudhary
//  Date        :11 Sept 2020
//
/////////////////////////////////////////////////////////////////////////
void Doubly_LinearLL::ListCpyEven(Doubly_LinearLL &List2)
{
    if(List2.Head != NULL && List2.Tail != NULL)
    {
        cout << "Linked List 2 is not empty\n";
        return;
    }

    PDNODE temp = this->Head;
    int iSum = 0, iTemp = 0;
    while(temp != NULL)
    {
        iTemp = temp->iData;
        iSum = 0;
        while(iTemp > 0)
        {
            iSum = iSum + iTemp % 10;
            iTemp = iTemp / 10;
        }
        if(iSum % 2 == 0)
        {
            List2.InsertLast(temp->iData);
        }
        temp = temp->npNext;
    }
    if(List2.Head == NULL && List2.Tail == NULL)
    {
        cout << "No element found with addition of digits even\n";
    }
}// End of ListCpyEven

////////////////////////////////////////////////////////////////////////////
//
//  Name        :ListCpyPrime
//  Input       :Doubly_LinearLL &
//  Returns     :void
//  Description :Copies List1 els to List2 whose addition of digit is prime
//  Author      :Pranav Choudhary
//  Date        :11 Sept 2020
//
////////////////////////////////////////////////////////////////////////////
void Doubly_LinearLL::ListCpyPrime(Doubly_LinearLL &List2)
{
    if(List2.Head != NULL && List2.Tail != NULL)
    {
        cout << "Linked List 2 is not empty\n";
        return;
    }

    PDNODE temp = this->Head;
    int iSum = 0, iTemp = 0, i = 0;
    while(temp != NULL)
    {
        iTemp = temp->iData;
        iSum = 0;
        while(iTemp > 0)
        {
            iSum = iSum + iTemp % 10;
            iTemp = iTemp / 10;
        }
        for (i = iSum / 2; i > 1; i--)
        {   
            if(iSum % i == 0)
            {
                break;
            }
        }
        if(i == 1)
        {
            List2.InsertLast(temp->iData);
        }
        temp = temp->npNext;
    }
    if(List2.Head == NULL && List2.Tail == NULL)
    {
        cout << "No element found with addition of digits prime\n";
    }
}// End of ListCpyPrime

////////////////////////////////////////////////////////////////////////////
//
//  Name        :IsSublistF
//  Input       :Doubly_LinearLL &
//  Returns     :int
//  Description :Check either List is Sublist of other,  if yes then returns
//               first position(First occurance's first position)
//  Author      :Pranav Choudhary
//  Date        :11 Sept 2020
//
////////////////////////////////////////////////////////////////////////////
int Doubly_LinearLL::IsSublistF(Doubly_LinearLL &List2)
{
    if(List2.Head == NULL && this->Head == NULL && List2.Tail == NULL && this->Tail == NULL)
    {
        return EMPTY;
    }

    int iPos = 0;
    if(this->iCount >= List2.iCount)
    {
        PDNODE temp1 = this->Head;
        PDNODE temp2 = NULL;
        while(temp1 != NULL)
        {
            temp2 = List2.Head;
            while(temp1 != NULL && temp2 != NULL)
            {
                if(temp1->iData != temp2->iData)
                {
                    break;
                }
                temp1 = temp1->npNext;
                temp2 = temp2->npNext;
            }
            if(temp2 == NULL)
            {
                iPos++;
                break;
            }
            if(temp1 != NULL)
            {
                temp1 = temp1->npNext;
            }
            iPos++;
        }
        if(temp2 == NULL)
        {
            cout << "Linked List 2 is sublist of Linked List 1\n";
            return iPos;
        }
        else
        {
            return NOTFOUND;
        }
    }
    else if(this->iCount < List2.iCount)
    {
        PDNODE temp1 = List2.Head;
        PDNODE temp2 = NULL;
        while(temp1 != NULL)
        {
            temp2 = this->Head;
            while(temp1 != NULL && temp2 != NULL)
            {
                if(temp1->iData != temp2->iData)
                {
                    break;
                }
                temp1 = temp1->npNext;
                temp2 = temp2->npNext;
            }
            if(temp2 == NULL)
            {
                iPos++;
                break;
            }
            if(temp1 != NULL)
            {
                temp1 = temp1->npNext;
            }
            iPos++;
        }
        if(temp2 == NULL)
        {
            cout << "Linked List 1 is sublist of Linked List 2\n";
            return iPos;
        }
        else
        {
            return NOTFOUND;
        }
    }
    return -1;
}// end of IsSublistF

////////////////////////////////////////////////////////////////////////////
//
//  Name        :IsSublistB
//  Input       :Doubly_LinearLL &
//  Returns     :int
//  Description :Check either List is Sublist of other,  if yes then returns
//               first position(Last occurance's first position)
//  Author      :Pranav Choudhary
//  Date        :11 Sept 2020
//
////////////////////////////////////////////////////////////////////////////
int Doubly_LinearLL::IsSublistL(Doubly_LinearLL &List2)
{
    if(List2.Head == NULL && this->Head == NULL && List2.Tail == NULL && this->Tail == NULL)
    {
        return EMPTY;
    }

    int iPos = 0, iCnt = 1, iPos2 = 0;
    if(this->iCount >= List2.iCount)
    {
        PDNODE temp1 = this->Head;
        PDNODE temp2 = NULL;
        while(temp1 != NULL)
        {
            temp2 = List2.Head;
            iPos = iCnt;
            while(temp1 != NULL && temp2 != NULL)
            {
                if(temp1->iData != temp2->iData)
                {
                    break;
                }
                temp1 = temp1->npNext;
                temp2 = temp2->npNext;
                iCnt++;
            }
            if(temp2 == NULL)
            {
                iPos2 = iPos;
            }
            if(temp1 != NULL)
            {
                temp1 = temp1->npNext;
                iCnt++;
            }
        }
        if(temp2 == NULL)
        {
            cout << "Linked List 2 is sublist of Linked List 1\n";
            return iPos2;
        }
        else
        {
            return NOTFOUND;
        }
    }
    else if(this->iCount < List2.iCount)
    {
        PDNODE temp1 = List2.Head;
        PDNODE temp2 = NULL;
        while(temp1 != NULL)
        {
            temp2 = this->Head;
            iPos = iCnt;
            while(temp1 != NULL && temp2 != NULL)
            {
                if(temp1->iData != temp2->iData)
                {
                    break;
                }
                temp1 = temp1->npNext;
                temp2 = temp2->npNext;
                iCnt++;
            }
            if(temp2 == NULL)
            {
                iPos2 = iPos;
            }
            if(temp1 != NULL)
            {
                temp1 = temp1->npNext;
                iCnt++;
            }
        }
        if(temp2 == NULL)
        {
            cout << "Linked List 1 is sublist of Linked List 2\n";
            return iPos2;
        }
        else
        {
            return NOTFOUND;
        }
    }
    return -1;
}// end of IsSublistL

// Entry point
int main()
{
    printf("\n----------Doubly Linear Linked List----------\n\n");
    Doubly_LinearLL dllObj1, dllObj2, dllObj3, dllObj4;
    int iNum = 0, iRet = 0, iStart = 0, iEnd = 0;

    /* Linked List 1 */
    printf("----------------------------------------------------------------\n");
    cout << "Enter numbers [\'0\' to stop entering input]\n";
    while(true)
    {
        cin >> iNum; 
        if(iNum == 0)
        {
            break;
        }
        dllObj1.InsertLast(iNum);
    }
    cout << "Linked list 1" << endl;
    dllObj1.DisplayListF();
    dllObj1.DisplayListB();
    cout << "Total elements in list 1\t\t:" << dllObj1.Count() << endl;

    
    /* Linked List 2 */
    printf("----------------------------------------------------------------\n");
    cout << "Enter numbers [\'0\' to stop entering input]\n";
    while(true)
    {
        cin >> iNum; 
        if(iNum == 0)
        {
            break;
        }
        dllObj2.InsertLast(iNum);
    }
    cout << "Linked list 2" << endl;
    dllObj2.DisplayListF();
    cout << "Total elements in list 2\t\t:" << dllObj2.Count() << endl;

    /* Occurances: Searches all occurances of particular element
    printf("----------------------------------------------------------------\n");
    cout << "Enter number for occurance search\t:";
    cin >> iNum;
    iRet = dllObj1.Occurances(iNum);
    if(iRet == EMPTY)
    {
        cout << "Linked List is empty\n";
    }
    else if(iRet == NOTFOUND)
    {
        cout << "Element not found\n";
    }
    else
    {
        cout << "Element " << iNum << " with occurances\t\t:" << iRet << endl;
    }

    /* FirstOccur: Searches first occurances of particular element
    printf("----------------------------------------------------------------\n");
    cout << "Enter number for first occurance\t:";
    cin >> iNum;
    iRet = dllObj1.FirstOccur(iNum);
    if(iRet == EMPTY)
    {
        cout << "Linked List is empty\n";
    }
    else if(iRet == NOTFOUND)
    {
        cout << "Element not found\n";
    }
    else
    {
        cout << "Element " << iNum << " first occured at\t\t:" << iRet << endl;
    }

    /* LastOccur: Searches last occurance of particular element
    printf("----------------------------------------------------------------\n");
    cout << "Enter number for last occurance\t\t:";
    cin >> iNum;
    iRet = dllObj1.LastOccur(iNum);
    if(iRet == EMPTY)
    {
        cout << "Linked List is empty\n";
    }
    else if(iRet == NOTFOUND)
    {
        cout << "Element not found\n";
    }
    else
    {
        cout << "Element " << iNum << " last occured at\t\t:" << iRet << endl;
    }
    
    /* SecOccur: Searches second occurance of particular element
    printf("----------------------------------------------------------------\n");
    cout << "Enter number for second occurance\t:";
    cin >> iNum;
    iRet = dllObj1.SecOccur(iNum);
    if(iRet == EMPTY)
    {
        cout << "Linked List is empty\n";
    }
    else if(iRet == NOTFOUND)
    {
        cout << "Element not found\n";
    }
    else
    {
        cout << "Element " << iNum << " second occured at\t\t:" << iRet << endl;
    }

    /* SecLastOccur: Searches second last occurance of particular element
    printf("----------------------------------------------------------------\n");
    cout << "Enter number for second last occurance\t:";
    cin >> iNum;
    iRet = dllObj1.SecLastOccur(iNum);
    if(iRet == EMPTY)
    {
        cout << "Linked List is empty\n";
    }
    else if(iRet == NOTFOUND)
    {
        cout << "Element not found\n";
    }
    else
    {
        cout << "Element " << iNum << " second last occured at\t:" << iRet << endl;
    }
    
    /* ListCat : Concats two linked list 
    printf("----------------------------------------------------------------\n");
    dllObj1.ListCat(dllObj2);
    cout << "Linked List 1 after concat\n";
    dllObj1.DisplayListF();

    /* ListNCat : Concats two linked list upto first N els
    printf("----------------------------------------------------------------\n");
    cout << "Enter number els to concat\t\t:";
    cin >> iNum;
    dllObj1.ListNCat(dllObj2, iNum);
    cout << "Linked List 1 after N concat\n";
    dllObj1.DisplayListF();

    /* ListLNCat : Concats two linked list only last N els
    printf("----------------------------------------------------------------\n");
    cout << "Enter number els to concat\t\t:";
    cin >> iNum;
    dllObj1.ListLNCat(dllObj2, iNum);
    cout << "Linked List 1 after N concat\n";
    dllObj1.DisplayListF();

    /* ListRangeCat : Concats List 2 els from Range
    printf("----------------------------------------------------------------\n");
    cout << "Enter position of start\t\t:";
    cin >> iStart;
    cout << "Enter position of end\t\t:";
    cin >> iEnd;
    dllObj1.ListRangeCat(dllObj2, iStart, iEnd);
    cout << "Linked List 1 after range concat\n";
    dllObj1.DisplayListF();
    cout << "Total elements in list 2\t\t:" << dllObj4.Count() << endl;
    
    /* ListCpy : Copiets List1 into List2 
    printf("----------------------------------------------------------------\n");
    dllObj1.ListCpy(dllObj2);
    cout << "Linked List 2 after copy\n";
    dllObj2.DisplayListF();
    cout << "Total elements in list 2\t\t:" << dllObj2.Count() << endl;

    /* ListNCpy : Copiets List1 into List2 upto first N els 
    printf("----------------------------------------------------------------\n");
    cout << "Enter number els to concat\t\t:";
    cin >> iNum;
    dllObj1.ListNCpy(dllObj3, iNum);
    cout << "Linked List 3 after N copy\n";
    dllObj3.DisplayListF();
    cout << "Total elements in list 2\t\t:" << dllObj3.Count() << endl;

    /* ListLNCpy : Copiets List1 into List2 only last N els 
    printf("----------------------------------------------------------------\n");
    cout << "Enter number els to concat\t\t:";
    cin >> iNum;
    dllObj1.ListLNCpy(dllObj4, iNum);
    cout << "Linked List 4 after N copy\n";
    dllObj4.DisplayListF();
    cout << "Total elements in list 2\t\t:" << dllObj4.Count() << endl;
    */
    
    /* ListRangeCat : Concats List 2 els from Range
    printf("----------------------------------------------------------------\n");
    cout << "Enter position of start\t\t:";
    cin >> iStart;
    cout << "Enter position of end\t\t:";
    cin >> iEnd;
    dllObj1.ListRangeCpy(dllObj2, iStart, iEnd);
    cout << "Linked List 1 after range copy\n";
    dllObj2.DisplayListF();
    cout << "Total elements in list 2\t\t:" << dllObj2.Count() << endl;

    /* ListAltCpy : Copies List1 els into List2 alternately
    printf("----------------------------------------------------------------\n");
    dllObj1.ListAltCpy(dllObj2);
    cout << "Linked List 1 after alternate copy\n";
    dllObj2.DisplayListF();
    cout << "Total elements in list 2\t\t:" << dllObj2.Count() << endl;

    /* ListCpyEven :copies contents of List1 whose addition of digits is even
    printf("----------------------------------------------------------------\n");
    dllObj1.ListCpyEven(dllObj2);
    cout << "Linked List 1 after evens copy\n";
    dllObj2.DisplayListF();
    cout << "Total elements in list 2\t\t:" << dllObj2.Count() << endl;

    /* ListCpyPrime :copies contents of List1 whose addition of digits is prime
    printf("----------------------------------------------------------------\n");
    dllObj1.ListCpyPrime(dllObj2);
    cout << "Linked List 1 after primes copy\n";
    dllObj2.DisplayListF();
    cout << "Total elements in list 2\t\t:" << dllObj2.Count() << endl;

    /* ListAltCat : Comacats List2 els into List1 alternately
    printf("----------------------------------------------------------------\n");
    dllObj1.ListAltCat(dllObj2);
    cout << "Linked List 1 after alternate copy\n";
    dllObj1.DisplayListF();
    cout << "Total elements in list 1\t\t:" << dllObj1.Count() << endl;
    */

    /* IsSublist: Checks whether Lists are have sublist of each other
    printf("----------------------------------------------------------------\n");
    iRet = dllObj1.IsSublistF(dllObj2);
    if(iRet == NOTFOUND)
    {
        cout << "Either Linked list is not sublist in other Linked list\n";
    }
    else if(iRet == EMPTY)
    {
        cout << "Either Linked list is empty\n";
    }
    else
    {
        cout << "Sublist found at position\t\t" << iRet << endl;
    }

    /* IsSublist: Checks whether Lists are have sublist of each other */
    printf("----------------------------------------------------------------\n");
    iRet = dllObj1.IsSublistL(dllObj2);
    if(iRet == NOTFOUND)
    {
        cout << "Either Linked list is not sublist in other Linked list\n";
    }
    else if(iRet == EMPTY)
    {
        cout << "Either Linked list is empty\n";
    }
    else
    {
        cout << "Sublist found at position\t\t" << iRet << endl;
    }

    printf("----------------------------------------------------------------\n");
    return 0;
}