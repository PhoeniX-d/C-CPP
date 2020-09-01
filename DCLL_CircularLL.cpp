/*
*   Implementation Of Doubly Circular Linked List Using C
*/
#include<stdio.h>
#include<stdlib.h>

/* Structure of node for Doubly Circular Linked List */
typedef struct dnode
{
    int iData;
    struct dnode *npNext;
    struct dnode *npPrev;
} DNODE, *PDNODE, **PPDNODE ;

class Doubly_CircularLL
{
    private:
        PDNODE Head;
        PDNODE Tail;
        int iCount;
    public:
        Doubly_CircularLL();
        ~Doubly_CircularLL();
        bool InsertFirst(int);
        bool InsertLast(int);
        bool InsertAtPos(int, int);
        bool DeleteFirst();
        bool DeleteLast();
        bool DeleteAtPos(int);
        bool DisplayListF();
        bool DisplayListB();
        int  Count();
};
////////////////////////////////////////////////////////////
//
//  Name        :Doubly_CircularLL
//  Input       :bool
//  Returns     :   -
//  Description :constructor
//  Author      :Pranav Choudhary
//  Date        :1 Sept 2020
//
////////////////////////////////////////////////////////////
Doubly_CircularLL::Doubly_CircularLL()
{
    Head = NULL;
    Tail = NULL;
    iCount = 0;
}// end of constructor
////////////////////////////////////////////////////////////
//
//  Name        :Doubly_CircularLL
//  Input       :bool
//  Returns     :   -
//  Description :constructor
//  Author      :Pranav Choudhary
//  Date        :1 Sept 2020
//
////////////////////////////////////////////////////////////
Doubly_CircularLL::~Doubly_CircularLL()
{
    if(NULL == Head && NULL == Tail)
    {
        printf("Linked List is Empty\n");
    }    
    do
    {
        Head = Head->npNext;
        Tail->npNext = Head;
        delete (Head->npPrev);
        Head->npPrev = Tail;

        if(Head == Tail)
        {
            delete Tail;
            Head = NULL;
            Tail = NULL;
            break;
        }

    } while (Head != Tail);
}// end of destructor

////////////////////////////////////////////////////////////
//
//  Name        :DisplayListF
//  Input       :void
//  Returns     :bool
//  Description :Displays elements in linked list
//  Author      :Pranav Choudhary
//  Date        :1 Sept 2020
//
////////////////////////////////////////////////////////////
bool Doubly_CircularLL::DisplayListF()
{
    if(NULL == Head && NULL == Tail)
    {
        printf("Linked List is Empty\n");
        return false;
    }
    PDNODE First = Head;
    do
    {
        printf("<-|%d|->", First->iData);
        First = First->npNext;
    } while (First != Tail->npNext);
    printf("\n\n");
    return true;
}// end of DisplayListF

////////////////////////////////////////////////////////////
//
//  Name        :DisplayListB
//  Input       :void
//  Returns     :bool
//  Description :Displays elements in linked list reverse
//  Author      :Pranav Choudhary
//  Date        :1 Sept 2020
//
////////////////////////////////////////////////////////////
bool Doubly_CircularLL::DisplayListB()
{
    
    if(NULL == Head && NULL == Tail)
    {
        printf("Linked List is Empty\n");
        return false;
    }
    PDNODE Last = Tail;
    do
    {
        printf("<-|%d|->", Last->iData);
        Last = Last->npPrev;
    } while (Last != Head->npPrev);
    printf("\n\n");
    return true;

}// end of DisplayListB

////////////////////////////////////////////////////////////
//
//  Name        :Count
//  Input       :bool
//  Returns     :int
//  Description :counts elements in linked list
//  Author      :Pranav Choudhary
//  Date        :1 Sept 2020
//
////////////////////////////////////////////////////////////
int Doubly_CircularLL::Count()
{
    return this->iCount;
}// end of Count

//////////////////////////////////////////////////////////////////
//
//  Name        :InsertFirst
//  Input       : int
//  Returns     :bool
//  Description :Inserts element in Linked list at first position
//  Author      :Pranav Choudhary
//  Date        :1 Sept 2020
//
//////////////////////////////////////////////////////////////////
bool Doubly_CircularLL::InsertFirst(int iNum)
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

    if(NULL == Head && NULL == Tail)
    {
        Head = NewN;
        Tail = NewN;
    }
    else
    {
        NewN->npNext = Head;
        Head->npPrev = NewN;
        Head = NewN;
    }
    Tail->npNext = Head;
    Head->npPrev = Tail;
    iCount++;
    return true;
}// end of InsertFirst

//////////////////////////////////////////////////////////////////
//
//  Name        :InsertLast
//  Input       :int
//  Returns     :bool
//  Description :Inserts element in Linked list at last position
//  Author      :Pranav Choudhary
//  Date        :1 Sept 2020
//
//////////////////////////////////////////////////////////////////
bool Doubly_CircularLL::InsertLast(int iNum)
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

    if(NULL == Head && NULL == Tail)
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
    Tail->npNext = Head;
    Head->npPrev = Tail;
    iCount++;
    return true;
}// end of InsertLast

//////////////////////////////////////////////////////////////////
//
//  Name        :InsertAtPos
//  Input       :int, int
//  Returns     :bool
//  Description :Inserts element in Linked list at desired position
//  Author      :Pranav Choudhary
//  Date        :1 Sept 2020
//
//////////////////////////////////////////////////////////////////
bool Doubly_CircularLL::InsertAtPos(int iNum, int iPos)
{
    if(iPos < 1 || iPos > iCount + 1)
    {
        printf("Invalid Position enterd\n");
        return false;
    }
    else if(iPos == 1)
    {
        return InsertFirst(iNum);
    }
    else if(iPos == iCount + 1)
    {
        return InsertLast(iNum);
    }
    else
    {
        PDNODE nTemp = Head, NewN = NULL;
        int i = 0;
        NewN = new DNODE;
        if(NewN == NULL)
        {
            printf("Memory Allocation Failed!!\n");
            return false;
        }
        NewN->iData = iNum;
        NewN->npNext = NULL;
        NewN->npPrev = NULL;

        for (i = 1; i < iPos; i++)
        {
            nTemp = nTemp->npNext;
        }
        NewN->npPrev = nTemp->npPrev;
        NewN->npPrev->npNext = NewN;
        NewN->npNext = nTemp;      
        nTemp->npPrev = NewN;
        iCount++;
        return true;
    }
    
}// end of InsertAtPos

//////////////////////////////////////////////////////////////////
//
//  Name        :DeleteFirst
//  Input       :int
//  Returns     :bool
//  Description :Deletes element in Linked list at first position
//  Author      :Pranav Choudhary
//  Date        :1 Sept 2020
//
//////////////////////////////////////////////////////////////////
bool Doubly_CircularLL::DeleteFirst()
{
    if(NULL == Head && NULL == Tail)
    {
        printf("Linked List Is Empty\n");
        return false;
    }
    else if(Head == Tail)
    {
        delete Head;
        Head = NULL;
        Tail = NULL;
    }
    else
    {
        Head = Head->npNext;
        Tail->npNext = Head;
        delete (Head->npPrev);        
        Head->npPrev = Tail;
    }
    iCount--;
    return true;
}// end of DeleteFirst

//////////////////////////////////////////////////////////////////
//
//  Name        :DeleteLast
//  Input       :int
//  Returns     :bool
//  Description :Deletes element in Linked list at last position
//  Author      :Pranav Choudhary
//  Date        :1 Sept 2020
//
//////////////////////////////////////////////////////////////////
bool Doubly_CircularLL::DeleteLast()
{
    if(NULL == Head && NULL == Tail)
    {
        printf("Linked List Is Empty\n");
        return false;
    }
    else if(Head == Tail)
    {
        delete Tail;
        Head = NULL;
        Tail = NULL;
    }
    else
    {
        Tail = Tail->npPrev;
        delete (Tail->npNext);
        Tail->npNext = Head;
        Head->npPrev = Tail;
    }
    iCount--;
    return true;
}// end of DeleteLast

//////////////////////////////////////////////////////////////////
//
//  Name        :DeleteAtPos
//  Input       :int
//  Returns     :bool
//  Description :Deletes element in Linked list at desired position
//  Author      :Pranav Choudhary
//  Date        :1 Sept 2020
//
//////////////////////////////////////////////////////////////////
bool Doubly_CircularLL::DeleteAtPos(int iPos)
{
    if(NULL == Head && NULL == Tail)
    {
        printf("Linked List Is Empty\n");
        return false;
    }
    if(iPos < 1 || iPos > iCount)
    {
        printf("Invalid Position enterd\n");
        return false;
    }
    else if(iPos == 1)
    {
        return DeleteFirst();
    }
    else if(iPos == iCount)
    {
        return DeleteLast();
    }
    else
    {
        PDNODE nTemp = Head;
        int i = 0;

        for (i = 1; i < iPos; i++)
        {
            nTemp = nTemp->npNext;
        }
        nTemp->npPrev->npNext = nTemp->npNext;
        nTemp->npNext->npPrev = nTemp->npPrev;
        delete (nTemp);
        iCount--;
        return true;
    }    
}// end of DeleteAtPos

// Entry point
int main()
{
    printf("\n----------Doubly Circular Linked List----------\n\n");
    Doubly_CircularLL dcllObj;

    dcllObj.InsertFirst(12);
    dcllObj.InsertLast(97);
    dcllObj.InsertFirst(14);

    printf("\nLinked List:InsertFirst\n");
    dcllObj.DisplayListF();
    dcllObj.DisplayListB();
    printf("\nTotal Elements:\n%d\n", dcllObj.Count());

    dcllObj.InsertLast(57);
    dcllObj.InsertLast(97);
    dcllObj.InsertLast(76);
    dcllObj.InsertLast(37);

    printf("\nLinked List:InsertLast\n");
    dcllObj.DisplayListF();
    dcllObj.DisplayListB();
    printf("\nTotal Elements:\n%d\n", dcllObj.Count());

    dcllObj.InsertAtPos(745, 4);
    printf("\nLinked List:InsertAtPos\n");
    dcllObj.DisplayListF();
    dcllObj.DisplayListB();
    printf("\nTotal Elements:\n%d\n", dcllObj.Count());

    dcllObj.DeleteFirst();
    printf("\nLinked List:DeleteFirst\n");
    dcllObj.DisplayListF();
    dcllObj.DisplayListB();
    printf("\nTotal Elements:\n%d\n", dcllObj.Count());

    dcllObj.DeleteLast();
    printf("\nLinked List:DeleteLast\n");
    dcllObj.DisplayListF();
    dcllObj.DisplayListB();
    printf("\nTotal Elements:\n%d\n", dcllObj.Count());

    dcllObj.DeleteAtPos(3);
    printf("\nLinked List:DeleteAtPos\n");
    dcllObj.DisplayListF();
    dcllObj.DisplayListB();

    printf("\nTotal Elements:\n%d\n", dcllObj.Count());
    return 0;
 }