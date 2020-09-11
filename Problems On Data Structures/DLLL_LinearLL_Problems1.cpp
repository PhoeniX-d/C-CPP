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
        int Occurances(int);
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
    if(NULL == Head && Tail == NULL)
    {
        printf("Linked List is Empty Destructor\n");
        return;
    }
    PDNODE nTemp = NULL;
    while(Head != NULL)
    {
        nTemp = Head;
        Head = nTemp->npNext;
        delete nTemp;
        iCount--;
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
    printf("Head->iData\tTail->iData\n", Head->iData, Tail->iData);
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
    printf("NULL\n");
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
}
// Entry point
int main()
{
    printf("\n----------Doubly Linear Linked List----------\n\n");
    Doubly_LinearLL dllObj1;
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

    
    /* Linked List 2 
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

    /* Linked List 2
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
        cout << "Element " << iNum << " with occurances \t:" << iRet << endl;
    }
    */
    return 0;
}