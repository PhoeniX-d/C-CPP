/*
*   Implementaion of Singly Linear Linked List in C++
*/
#include<stdio.h>
#include<stdlib.h>

// structure of node of linked list
typedef struct node
{
    int             iData;
    struct node     *cpNext;
} NODE, *PNODE, **PPNODE;

class Singly_LinearLL
{
    private:
        PNODE Head;
        int   iCount;

    public:
        Singly_LinearLL();      /* constructor */
        ~Singly_LinearLL();     /* Destructor */

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
//  Name        :Singly_LinearLL a constructor
//
///////////////////////////////////////////////////////////
Singly_LinearLL::Singly_LinearLL()
{
    Head = NULL;
    iCount = 0;
}// end of constructor

////////////////////////////////////////////////////////////
//
//  Name        :~Singly_LinearLL a constructor
//
///////////////////////////////////////////////////////////
Singly_LinearLL::~Singly_LinearLL()
{
    if(Head != NULL)
    {
        PNODE nTemp = NULL;
        while(Head != NULL)
        {
            nTemp = Head;
            Head = Head->cpNext;
            delete nTemp;
            iCount--;
        }
    }
}// end of Destructor

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
        First = First->cpNext;
    }
    /* way 2
    int iCnt = 0;
    while(iCnt != iCount)
    {
        printf("%d->", First->iData);
        First = First->cpNext;
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
    NewN->cpNext = NULL;

    /* If Linked List is empty */
    if(Head == NULL)      
    {
        Head = NewN;
    }
    else
    {
        NewN->cpNext = Head;
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
        Head = nTemp->cpNext;
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
    NewN->cpNext = NULL;

     /* if linked list is empty */
    if(Head == NULL)
    {
        Head = NewN;
    }
    else
    {
        PNODE nTemp = Head;
        while(nTemp->cpNext != NULL)
        {
            nTemp = nTemp->cpNext;
        }
        nTemp->cpNext = NewN;
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
    else if((Head)->cpNext == NULL)
    {
        delete Head;
        Head = NULL;
    }
    else
    {
        PNODE nTemp = Head;
        while((nTemp->cpNext)->cpNext != NULL)
        {
            nTemp = nTemp->cpNext;
        }
        delete nTemp->cpNext;
        nTemp->cpNext = NULL;
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
        NewN->cpNext = NULL;

        for (i = 1; i < iPos - 1; i++)
        {
            nTemp = nTemp->cpNext;
        }
        NewN->cpNext = nTemp->cpNext;
        nTemp->cpNext = NewN;
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
            nTemp = nTemp->cpNext;
        }
        nTarget = nTemp->cpNext;
        nTemp->cpNext = nTarget->cpNext;
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
    int iRet = 0;

    sllObj.InsertFirst(40);
    sllObj.InsertFirst(50);
    sllObj.InsertFirst(10);
    sllObj.InsertFirst(20);

    printf("Linked List:InsertFirst\n");
    sllObj.DisplayList();

    sllObj.InsertLast(34);
    sllObj.InsertLast(56);
    sllObj.InsertLast(24);
    sllObj.InsertLast(900);

    printf("Linked List:InsertLast\n");
    sllObj.DisplayList();

    sllObj.InsertAtPos(233, 1);
    sllObj.InsertAtPos(2235, 3);

    printf("Linked List:InsertAtPos\n");
    sllObj.DisplayList();

    sllObj.DeleteFirst();
    printf("Linked List:DeleteFirst\n");
    sllObj.DisplayList();

    sllObj.DeleteLast();
    printf("Linked List:DeleteLast\n");
    sllObj.DisplayList();

    sllObj.DeleteAtPos(2);
    printf("Linked List:DeleteAtPos\n");
    sllObj.DisplayList();

    return 0;
}// end of main()