/*
*   Implementation Of Doubly Linear Linked List Using C++
*/
#include<stdio.h>
#include<stdlib.h>

/* Structure of node for Doubly Linear Linked List */
typedef struct dnode
{
    int iData;
    struct dnode *npNext;
    struct dnode *npPrev;
} DNODE, *PDNODE;

class Doubly_LinearLL
{
    private:
        PDNODE Head;
        PDNODE Tail;
        int iCount;

    public:
        Doubly_LinearLL();
        ~Doubly_LinearLL();
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
//  Name        :Doubly_LinearLL
//  Input       :void
//  Returns     :   -
//  Description :constructor
//  Author      :Pranav Choudhary
//  Date        :1 Sept 2020
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
//  Date        :1 Sept 2020
//
////////////////////////////////////////////////////////////
Doubly_LinearLL::~Doubly_LinearLL()
{
    if(NULL == Head && Tail == NULL)
    {
        printf("Linked List is Empty\n");
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
//  Date        :1 Sept 2020
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
//  Date        :1 Sept 2020
//
////////////////////////////////////////////////////////////
bool Doubly_LinearLL::DisplayListB()
{    
    if(NULL == Head && Tail == NULL)
    {
        printf("Linked List is Empty\n");
        return false;
    }
    PDNODE First = Tail;
    printf("NULL");
    while(First != NULL)
    {
        printf("<-|%d|->", First->iData);
        First = First->npPrev;
    }
    printf("NULL\n");
    return true;
}// end of DisplayListF

////////////////////////////////////////////////////////////
//
//  Name        :CountEls
//  Input       :void
//  Returns     :int
//  Description :counts elements in linked list
//  Author      :Pranav Choudhary
//  Date        :1 Sept 2020
//
////////////////////////////////////////////////////////////
int Doubly_LinearLL::Count()
{
    return iCount;
}// end of CountEls

//////////////////////////////////////////////////////////////////
//
//  Name        :InsertFirst
//  Input       :int
//  Returns     :bool
//  Description :Inserts element in Linked list at first position
//  Author      :Pranav Choudhary
//  Date        :1 Sept 2020
//
//////////////////////////////////////////////////////////////////
bool Doubly_LinearLL::InsertFirst(int iNum)
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
        NewN->npNext = Head;
        Head->npPrev = NewN;
        Head = NewN;
    }
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
//  Name        :InsertAtPos
//  Input       :int, int
//  Returns     :bool
//  Description :Inserts element in Linked list at desired position
//  Author      :Pranav Choudhary
//  Date        :1 Sept 2020
//
//////////////////////////////////////////////////////////////////
bool Doubly_LinearLL::InsertAtPos(int iNum, int iPos)
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
        PDNODE nTemp = Head, NewN = new DNODE;
        int i = 0;
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
bool Doubly_LinearLL::DeleteFirst()
{
    if(NULL == Head && Tail == NULL)
    {
        printf("Linked List Is Empty\n");
        return false;
    }
    else if(Head->npNext == NULL)
    {
        delete Head;
        Head = NULL;
        Tail = NULL;
    }
    else
    {
        Head = Head->npNext;
        //Head->npPrev->npNext = NULL;
        delete Head->npPrev;
        Head->npPrev = NULL;
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
bool Doubly_LinearLL::DeleteLast()
{
    if(NULL == Head && NULL == Tail)
    {
        printf("Linked List Is Empty\n");
        return false;
    }
    else if(Head->npNext == NULL)
    {
        delete Tail;
        Head = NULL;
        Tail = NULL;
    }
    else
    {
        Tail = Tail->npPrev;
        delete Tail->npNext;
        Tail->npNext = NULL;
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
bool Doubly_LinearLL::DeleteAtPos(int iPos)
{
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
        nTemp->npNext = NULL;
        nTemp->npPrev = NULL;
        delete nTemp;
        iCount--;
        return true;
    }    
}// end of DeleteAtPos

// Entry point
int main()
{
    printf("\n----------Doubly Linear Linked List----------\n\n");
    Doubly_LinearLL dllObj;
    Doubly_LinearLL *dllObj2 = new Doubly_LinearLL;

    int iRet = 0;

    /* Linked List 1 */
    dllObj.InsertFirst(40);
    dllObj.InsertFirst(50);
    dllObj.InsertFirst(10);

    printf("\nLinked List 1:InsertFirst\n");
    printf("\nTotal %d elements\n", dllObj.Count());
    dllObj.DisplayListF();
    dllObj.DisplayListB();

    dllObj.InsertLast(34);
    dllObj.InsertLast(56);

    printf("\nLinked List 1:InsertLast\n");
    printf("\nTotal %d elements\n", dllObj.Count());
    dllObj.DisplayListF();
    dllObj.DisplayListB();

    dllObj.InsertAtPos(233, 1);

    printf("\nLinked List 1:InsertAtPos\n");
    printf("\nTotal %d elements\n", dllObj.Count());
    dllObj.DisplayListF();
    dllObj.DisplayListB();

    dllObj.DeleteFirst();

    printf("\nLinked List 1:DeleteFirst\n");
    printf("\nTotal %d elements\n", dllObj.Count());
    dllObj.DisplayListF();
    dllObj.DisplayListB();

    dllObj.DeleteLast();

    printf("\nLinked List 1:DeleteLast\n");
    printf("\nTotal %d elements\n", dllObj.Count());
    dllObj.DisplayListF();
    dllObj.DisplayListB();

    dllObj.DeleteAtPos(2);

    printf("\nLinked List 1:DeleteAtPos\n");
    printf("\nTotal %d elements\n", dllObj.Count());
    dllObj.DisplayListF();
    dllObj.DisplayListB();

    /* Linked List 2 */
    dllObj2->InsertFirst(54);
    dllObj2->InsertFirst(30);
    dllObj2->InsertFirst(89);

    printf("\nLinked List 2:InsertFirst\n");
    printf("\nTotal %d elements\n", dllObj2->Count());
    dllObj2->DisplayListF();
    dllObj2->DisplayListB();

    dllObj2->InsertLast(37);
    dllObj2->InsertLast(29);

    printf("\nLinked List 2:InsertLast\n");
    printf("\nTotal %d elements\n", dllObj2->Count());
    dllObj2->DisplayListF();
    dllObj2->DisplayListB();

    dllObj2->InsertAtPos(2235, 3);

    printf("\nLinked List 2:InsertAtPos\n");
    printf("\nTotal %d elements\n", dllObj2->Count());
    dllObj2->DisplayListF();
    dllObj2->DisplayListB();

    dllObj2->DeleteFirst();
    
    printf("\nLinked List 2:DeleteFirst\n");
    printf("\nTotal %d elements\n", dllObj2->Count());
    dllObj2->DisplayListF();
    dllObj2->DisplayListB();

    dllObj2->DeleteLast();

    printf("\nLinked List 2:DeleteLast\n");
    printf("\nTotal %d elements\n", dllObj2->Count());
    dllObj2->DisplayListF();
    dllObj2->DisplayListB();

    dllObj2->DeleteAtPos(2);

    printf("\nLinked List 2:DeleteAtPos\n");
    printf("\nTotal %d elements\n", dllObj2->Count());
    dllObj2->DisplayListF();
    dllObj2->DisplayListB();

    return 0;
}