/*
*   Implementaion of Singly Linear Linked List in C
*/
#include<stdio.h>
#include<stdlib.h>

// structure of node of linked list
typedef struct node
{
    int             iData;
    struct node     *npNext;
} NODE, *PNODE, **PPNODE;

// global declarations
void InsertFirst(PPNODE, int);
void DeleteFirst(PPNODE);
void InsertLast(PPNODE, int);
void DeleteLast(PPNODE);
void InsertAtPos(PPNODE, int, int);
void DeleteAtPos(PPNODE, int);
void DisplayList(PNODE);
void DisplayListRec(PNODE);
int  CountEls(PNODE);
void Deallocate(PPNODE);

// Entry point
int main()
{
    printf("\n----------Singly Linear Linked List----------\n\n");
    PNODE Head = NULL;
    int iRet = 0;

    InsertFirst(&Head, 40);
    InsertFirst(&Head, 50);
    InsertFirst(&Head, 10);
    InsertFirst(&Head, 20);

    printf("Linked List:InsertFirst\n");
    //DisplayList(Head);
    DisplayListRec(Head);
    printf("\n");

    InsertLast(&Head, 34);
    InsertLast(&Head, 56);
    InsertLast(&Head, 24);
    InsertLast(&Head, 900);

    printf("Linked List:InsertLast\n");
    DisplayListRec(Head);
    printf("\n");

    InsertAtPos(&Head, 233, 1);
    InsertAtPos(&Head, 2235, 3);

    printf("Linked List:InsertAtPos\n");
    DisplayListRec(Head);
    printf("\n");

    DeleteFirst(&Head);
    printf("Linked List:DeleteFirst\n");
    DisplayListRec(Head);
    printf("\n");

    DeleteLast(&Head);
    printf("Linked List:DeleteLast\n");
    DisplayListRec(Head);
    printf("\n");
    
    DeleteAtPos(&Head, 2);
    printf("Linked List:DeleteAtPos\n");
    DisplayListRec(Head);
    printf("\n");
    
    iRet = CountEls(Head);
    printf("Total Elements:\n%d\n", iRet);

    Deallocate(&Head);
    printf("\nLinked List Deallocated\n");

    iRet = CountEls(Head);
    printf("Total Elements:\n%d\n", iRet);
    return 0;
}

////////////////////////////////////////////////////////////
//
//  Name        :DisplayList
//  Input       :PNODE
//  Returns     :void
//  Description :Displays elements in linked list
//  Author      :Pranav Choudhary
//  Date        :29 Aug 2020
//
////////////////////////////////////////////////////////////
void DisplayList(PNODE First)
{
    if(First == NULL)
    {
        printf("Linked List is NULL\n");
        return;
    }
    while(First != NULL)
    {
        printf("|%4d|->", First->iData);
        First = First->npNext;
    }
    printf("NULL\n\n");
}// end of DisplayList

////////////////////////////////////////////////////////////
//
//  Name        :DisplayListRec
//  Input       :PNODE
//  Returns     :void
//  Description :Displays elements in linked list
//  Author      :Pranav Choudhary
//  Date        :29 Aug 2020
//
////////////////////////////////////////////////////////////
void DisplayListRec(PNODE First)
{
    if(First != NULL)
    {
        printf("|%4d|->", First->iData);
        DisplayListRec(First->npNext);
    }
}// end of DisplayListRec

////////////////////////////////////////////////////////////
//
//  Name        :CountEls
//  Input       :PNODE
//  Returns     :int
//  Description :Displays elements in linked list
//  Author      :Pranav Choudhary
//  Date        :29 Aug 2020
//
////////////////////////////////////////////////////////////
int CountEls(PNODE First)
{
    int iCnt = 0;
    if(First == NULL)
    {
        printf("Linked List is NULL\n");
        return iCnt;
    }
    while(First != NULL)
    {
        iCnt++;
        First = First->npNext;
    }
    return iCnt;
}// end of CountEls

////////////////////////////////////////////////////////////
//
//  Name        :Deallocate
//  Input       :PPNODE
//  Returns     :void
//  Description :Deallocates all nodes in linked list
//  Author      :Pranav Choudhary
//  Date        :29 Aug 2020
//
////////////////////////////////////////////////////////////
void Deallocate(PPNODE First)
{
    if(First == NULL)
    {
        printf("Linked List is NULL\n");
        return;
    }
    
    PNODE nTemp = NULL;
    while(*First != NULL)
    {
        nTemp = *First;
        *First = nTemp->npNext;
        free(nTemp);
    }
}// end of Deallocate

////////////////////////////////////////////////////////////
//
//  Name        :InsertFirst
//  Input       :PPNODE, int
//  Returns     :void
//  Description :Insert element at first position
//  Author      :Pranav Choudhary
//  Date        :29 Aug 2020
//
////////////////////////////////////////////////////////////
void InsertFirst(PPNODE First, int iNum)
{
    PNODE NewN = NULL;
    NewN = (PNODE)malloc(sizeof(NODE));
    
    if(NULL == NewN)
    {
        printf("Memory Allocation Failed");
        return;
    }
    
    NewN->iData = iNum;
    NewN->npNext = NULL;

    /* If Linked List is empty */
    if(*First == NULL)      
    {
        *First = NewN;
    }
    else
    {
        NewN->npNext = *First;
        *First = NewN;
    }   
}// End of InsertFirst

////////////////////////////////////////////////////////////
//
//  Name        :DeleteFirst
//  Input       :PPNODE
//  Returns     :void
//  Description :Deletes element at first position
//  Author      :Pranav Choudhary
//  Date        :29 Aug 2020
//
////////////////////////////////////////////////////////////
void DeleteFirst(PPNODE First)
{
    if(NULL == *First)
    {
        printf("Linked List is already empty\n");
        return;
    }
    else
    {
        PNODE nTemp = *First;
        *First = nTemp->npNext;
        free(nTemp);
    }    
}// End of DeleteFirst

////////////////////////////////////////////////////////////
//
//  Name        :InsertLast
//  Input       :PPNODE, int
//  Returns     :void
//  Description :Insert element at last position
//  Author      :Pranav Choudhary
//  Date        :29 Aug 2020
//
////////////////////////////////////////////////////////////
void InsertLast(PPNODE First, int iNum)
{
    PNODE NewN = NULL;
    NewN = (PNODE)malloc(sizeof(NODE));
    
    if(NULL == NewN)
    {
        printf("Memory Allocation Failed");
        return;
    }
    
    NewN->iData = iNum;
    NewN->npNext = NULL;

     /* if linked list is not empty */
    if(*First == NULL)
    {
        *First = NewN;
    }
    else
    {
        PNODE nTemp = *First;
        while(nTemp->npNext != NULL)
        {
            nTemp = nTemp->npNext;
        }
        nTemp->npNext = NewN;
    }    
}// End of InsertLast

////////////////////////////////////////////////////////////
//
//  Name        :DeleteLast
//  Input       :PPNODE
//  Returns     :void
//  Description :deletes element at last position
//  Author      :Pranav Choudhary
//  Date        :29 Aug 2020
//
////////////////////////////////////////////////////////////
void DeleteLast(PPNODE First)
{
    if(*First == NULL)
    {
        printf("Linked List is Empty\n");
        return;
    }
    else if((*First)->npNext == NULL)
    {
        free(*First);
        *First = NULL;
    }
    else
    {
        PNODE nTemp = *First;
        while((nTemp->npNext)->npNext != NULL)
        {
            nTemp = nTemp->npNext;
        }
        free(nTemp->npNext);
        nTemp->npNext = NULL;
    }
    
}// End of DeleteLast

////////////////////////////////////////////////////////////
//
//  Name        :InsertAtPos
//  Input       :PPNODE, int, int
//  Returns     :void
//  Description :Insert element at desired position
//  Author      :Pranav Choudhary
//  Date        :29 Aug 2020
//
////////////////////////////////////////////////////////////
void InsertAtPos(PPNODE First, int iNum, int iPos)
{
    int iSize = CountEls(*First);
    if(iPos > iSize + 1 || iPos < 1)
    {
        printf("Invalid Position Entered\n");
    }
    else if(iPos == 1)
    {
        InsertFirst(First, iNum);
    }
    else if(iPos == iSize + 1)
    {
        InsertLast(First, iNum);
    }
    else
    {
        PNODE NewN = NULL;
        PNODE nTemp = *First;
        int i = 0;
        NewN = (PNODE)malloc(sizeof(NODE));        
        if(NULL == NewN)
        {
            printf("Memory Allocation Failed");
            return;
        }
        
        NewN->iData = iNum;
        NewN->npNext = NULL;

        for (i = 1; i < iPos - 1; i++)
        {
            nTemp = nTemp->npNext;
        }
        NewN->npNext = nTemp->npNext;
        nTemp->npNext = NewN;
    }   
}// End of InsertAtPos

////////////////////////////////////////////////////////////
//
//  Name        :DeleteAtPos
//  Input       :PPNODE, int
//  Returns     :void
//  Description :Deletes element from desired position
//  Author      :Pranav Choudhary
//  Date        :29 Aug 2020
//
////////////////////////////////////////////////////////////
void DeleteAtPos(PPNODE First, int iPos)
{
    int iSize = CountEls(*First);
    if(iPos > iSize || iPos < 1 || NULL == *First)
    {
        printf("Invalid Position Entered or Linked list is empty\n");
    }
    else if(iPos == 1)
    {
        DeleteFirst(First);
    }
    else if(iPos == iSize)
    {
        DeleteLast(First);
    }
    else
    {
        PNODE nTemp = *First;
        PNODE nTarget = NULL;
        int i = 0;

        for (i = 1; i < iPos - 1; i++)
        {
            nTemp = nTemp->npNext;
        }
        nTarget = nTemp->npNext;
        nTemp->npNext = nTarget->npNext;
        free(nTarget);
    }   
}// End of DeleteAtPos