/*
*   Implementaion of Singly Linear Linked List in C++
*/
#include<stdio.h>
#include<stdlib.h>

// structure of node of linked list
typedef struct node
{
    int             iData;
    struct node     *npNext;
} NODE, *PNODE;

class Singly_LinearLL
{
    private:
        PNODE Head;
        int   iCount;

    public:
        Singly_LinearLL();      /* constructor */
        ~Singly_LinearLL();     /* Destructor */
        inline int Count();
        bool InsertFirst(int);
        bool DeleteFirst();
        bool InsertLast(int);
        bool DeleteLast();
        bool InsertAtPos(int, int);
        bool DeleteAtPos(int);
        bool DisplayList();

};

////////////////////////////////////////////////////////////
//
//  Name        :Singly_LinearLL
//  Input       :void
//  Returns     :   -
//  Description :constructor
//  Author      :Pranav Choudhary
//  Date        :31 Aug 2020
//
////////////////////////////////////////////////////////////
Singly_LinearLL::Singly_LinearLL()
{
    Head = NULL;
    iCount = 0;
}// end of constructor

////////////////////////////////////////////////////////////
//
//  Name        :Singly_LinearLL
//  Input       :void
//  Returns     :   -
//  Description :constructor
//  Author      :Pranav Choudhary
//  Date        :31 Aug 2020
//
////////////////////////////////////////////////////////////
Singly_LinearLL::~Singly_LinearLL()
{
    if(Head != NULL)
    {
        PNODE nTemp = NULL;
        while(Head != NULL)
        {
            nTemp = Head;
            Head = Head->npNext;
            delete nTemp;
            iCount--;
        }
    }
}// end of Destructor

////////////////////////////////////////////////////////////
//
//  Name        :Count
//  Input       :void
//  Returns     :int
//  Description :returns count of elements
//  Author      :Pranav Choudhary
//  Date        :31 Aug 2020
//
////////////////////////////////////////////////////////////
int Singly_LinearLL::Count()
{
	return iCount;
}// end of Count

////////////////////////////////////////////////////////////
//
//  Name        :DisplayList
//  Input       :void
//  Returns     :bool
//  Description :Displays elements in linked list
//  Author      :Pranav Choudhary
//  Date        :31 Aug 2020
//
////////////////////////////////////////////////////////////
bool Singly_LinearLL::DisplayList()
{
    if(Head == NULL)
    {
        printf("Linked List is NULL\n");
        return false;
    }
    PNODE First = Head;
    /* way 1 */
    while(First != NULL)
    {
        printf("%d->", First->iData);
        First = First->npNext;
    }
    /* way 2
    int iCnt = 0;
    while(iCnt != iCount)
    {
        printf("%d->", First->iData);
        First = First->npNext;
        iCnt++;
    } 
    */
    printf("NULL\n\n");
    return true;
}// end of DisplayList

////////////////////////////////////////////////////////////
//
//  Name        :InsertFirst
//  Input       :int
//  Returns     :bool
//  Description :Insert element at first position
//  Author      :Pranav Choudhary
//  Date        :31 Aug 2020
//
////////////////////////////////////////////////////////////
bool Singly_LinearLL::InsertFirst(int iNum)
{
    PNODE NewN = new NODE;
    
    if(NULL == NewN)
    {
        printf("Memory Allocation Failed");
        return false;
    }
    
    NewN->iData = iNum;
    NewN->npNext = NULL;

    /* If Linked List is empty */
    if(Head == NULL)      
    {
        Head = NewN;
    }
    else
    {
        NewN->npNext = Head;
        Head = NewN;
    }
    iCount++;
    return true;
}// End of InsertFirst

////////////////////////////////////////////////////////////
//
//  Name        :DeleteFirst
//  Input       :void
//  Returns     :bool
//  Description :Deletes element at first position
//  Author      :Pranav Choudhary
//  Date        :31 Aug 2020
//
////////////////////////////////////////////////////////////
bool Singly_LinearLL::DeleteFirst()
{
    if(NULL == Head)
    {
        printf("Linked List is already empty\n");
        return false;
    }
    else
    {
        PNODE nTemp = Head;
        Head = nTemp->npNext;
        free(nTemp);
        iCount--;
        return true;
    }    
}// End of DeleteFirst

////////////////////////////////////////////////////////////
//
//  Name        :InsertLast
//  Input       :int
//  Returns     :bool
//  Description :Insert element at last position
//  Author      :Pranav Choudhary
//  Date        :31 Aug 2020
//
////////////////////////////////////////////////////////////
bool Singly_LinearLL::InsertLast(int iNum)
{
    PNODE NewN = new NODE;
    if(NULL == NewN)
    {
        printf("Memory Allocation Failed");
        return false;
    }
    
    NewN->iData = iNum;
    NewN->npNext = NULL;

     /* if linked list is empty */
    if(Head == NULL)
    {
        Head = NewN;
    }
    else
    {
        PNODE nTemp = Head;
        while(nTemp->npNext != NULL)
        {
            nTemp = nTemp->npNext;
        }
        nTemp->npNext = NewN;
    }
    iCount++;
    return true;
}// End of InsertLast

////////////////////////////////////////////////////////////
//
//  Name        :DeleteLast
//  Input       :void
//  Returns     :bool
//  Description :deletes element at last position
//  Author      :Pranav Choudhary
//  Date        :31 Aug 2020
//
////////////////////////////////////////////////////////////
bool Singly_LinearLL::DeleteLast()
{
    if(Head == NULL)
    {
        printf("Linked List is Empty\n");
        return false;
    }
    else if((Head)->npNext == NULL)
    {
        delete Head;
        Head = NULL;
    }
    else
    {
        PNODE nTemp = Head;
        while((nTemp->npNext)->npNext != NULL)
        {
            nTemp = nTemp->npNext;
        }
        delete nTemp->npNext;
        nTemp->npNext = NULL;
    }
    iCount--;
    return true;
}// End of DeleteLast

////////////////////////////////////////////////////////////
//
//  Name        :InsertAtPos
//  Input       :int, int
//  Returns     :bool
//  Description :Insert element at desired position
//  Author      :Pranav Choudhary
//  Date        :31 Aug 2020
//
////////////////////////////////////////////////////////////
bool Singly_LinearLL::InsertAtPos(int iNum, int iPos)
{
    if(iPos > iCount + 1 || iPos < 1)
    {
        printf("Invalid Position Entered\n");
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
        PNODE NewN = new NODE;
        PNODE nTemp = Head;
        int i = 0;

        if(NULL == NewN)
        {
            printf("Memory Allocation Failed");
            return false;
        }
        
        NewN->iData = iNum;
        NewN->npNext = NULL;

        for (i = 1; i < iPos - 1; i++)
        {
            nTemp = nTemp->npNext;
        }
        NewN->npNext = nTemp->npNext;
        nTemp->npNext = NewN;
        iCount++;
        return true;
    }   
}// End of InsertAtPos

////////////////////////////////////////////////////////////
//
//  Name        :DeleteAtPos
//  Input       :int
//  Returns     :bool
//  Description :Deletes element from desired position
//  Author      :Pranav Choudhary
//  Date        :31 Aug 2020
//
////////////////////////////////////////////////////////////
bool Singly_LinearLL::DeleteAtPos(int iPos)
{
    if(iPos > iCount || iPos < 1 || NULL == Head)
    {
        printf("Invalid Position Entered or Linked list is empty\n");
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
        PNODE nTemp = Head;
        PNODE nTarget = NULL;
        int i = 0;

        for (i = 1; i < iPos - 1; i++)
        {
            nTemp = nTemp->npNext;
        }
        nTarget = nTemp->npNext;
        nTemp->npNext = nTarget->npNext;
        delete nTarget;
        iCount--;
        return true;
    }   
}// End of DeleteAtPos

// Entry point
int main()
{
    printf("\n----------Singly Linear Linked List----------\n\n");
    Singly_LinearLL sllObj;
    Singly_LinearLL *sllObj2 = new Singly_LinearLL;

    int iRet = 0;

    /* Linked List 1 */
    sllObj.InsertFirst(40);
    sllObj.InsertFirst(50);
    sllObj.InsertFirst(10);

    printf("Linked List 1:InsertFirst\n");
    printf("Total %d elements\n", sllObj.Count());
    sllObj.DisplayList();

    sllObj.InsertLast(34);
    sllObj.InsertLast(56);

    printf("Linked List 1:InsertLast\n");
    printf("Total %d elements\n", sllObj.Count());
    sllObj.DisplayList();

    /* Linked List 2 */
    sllObj2->InsertFirst(54);
    sllObj2->InsertFirst(30);
    sllObj2->InsertFirst(89);

    printf("Linked List 2:InsertFirst\n");
    printf("Total %d elements\n", sllObj2->Count());
    sllObj2->DisplayList();

    sllObj2->InsertLast(37);
    sllObj2->InsertLast(29);

    printf("Linked List 2:InsertLast\n");
    printf("Total %d elements\n", sllObj2->Count());
    sllObj2->DisplayList();

    sllObj.InsertAtPos(233, 1);
    sllObj2->InsertAtPos(2235, 3);

    printf("Linked List 1:InsertAtPos\n");
    printf("Total %d elements\n", sllObj.Count());
    sllObj.DisplayList();

    printf("Linked List 2:InsertAtPos\n");
    printf("Total %d elements\n", sllObj2->Count());
    sllObj2->DisplayList();

    sllObj.DeleteFirst();
    printf("Linked List 1:DeleteFirst\n");
    printf("Total %d elements\n", sllObj.Count());
    sllObj.DisplayList();

    sllObj2->DeleteFirst();
    printf("Linked List 2:DeleteFirst\n");
    printf("Total %d elements\n", sllObj2->Count());
    sllObj2->DisplayList();

    sllObj.DeleteLast();
    printf("Linked List 1:DeleteLast\n");
    printf("Total %d elements\n", sllObj.Count());
    sllObj.DisplayList();

    sllObj.DeleteAtPos(2);
    printf("Linked List 1:DeleteAtPos\n");
    printf("Total %d elements\n", sllObj.Count());
    sllObj.DisplayList();

    sllObj2->DeleteLast();
    printf("Linked List 2:DeleteLast\n");
    printf("Total %d elements\n", sllObj2->Count());
    sllObj2->DisplayList();

    sllObj2->DeleteAtPos(2);
    printf("Linked List 2:DeleteAtPos\n");
    printf("Total %d elements\n", sllObj2->Count());
    sllObj2->DisplayList();

    return 0;
}