/*
*   Implementation Of Doubly Linear Linked List Using C
*/
#include<stdio.h>
#include<stdlib.h>

/* Structure of node for Doubly Linear Linked List */
typedef struct dnode
{
    int iData;
    struct dnode *npNext;
    struct dnode *npPrev;
} DNODE, *PDNODE, **PPDNODE ;

// Global declarations
void InsertFirst(PPDNODE, int);
void InsertLast(PPDNODE, int);
void InsertAtPos(PPDNODE, int, int);
void DeleteFirst(PPDNODE);
void DeleteLast(PPDNODE);
void DeleteAtPos(PPDNODE, int);
void DisplayListF(PDNODE);
void DisplayListB(PDNODE);
void Deallocate(PPDNODE);
int  CountEls(PDNODE);

// Entry point
int main()
{
    printf("\n----------Doubly Linear Linked List----------\n\n");

    PDNODE Head = NULL;
    int iRet = 0;

    InsertFirst(&Head, 11);
    InsertFirst(&Head, 21);
    InsertFirst(&Head, 54);
    InsertFirst(&Head, 78);

    printf("\nLinked List:\nInsertFirst\n");
    DisplayListF(Head);
    DisplayListB(Head);

    InsertLast(&Head, 131);
    InsertLast(&Head, 221);
    InsertLast(&Head, 64);
    InsertLast(&Head, 75);

    printf("\nLinked List:\nInsertLast\n");
    DisplayListF(Head);
    DisplayListB(Head);

    InsertAtPos(&Head, 344, 4);
    InsertAtPos(&Head, 891, 8);

    printf("\nLinked List:\nInsertAtPos\n");
    DisplayListF(Head);
    DisplayListB(Head);

    DeleteFirst(&Head);
    printf("\nLinked List:\nDeleteFirst\n");
    DisplayListF(Head);
    DisplayListB(Head);

    DeleteLast(&Head);
    printf("\nLinked List:\nDeleteLast\n");
    DisplayListF(Head);
    DisplayListB(Head);

    DeleteAtPos(&Head, 3);
    DeleteAtPos(&Head, 6);
    printf("\nLinked List:\nDeleteAtPos\n");
    DisplayListF(Head);
    DisplayListB(Head);

    printf("\nTotal Elements:\n%d\n", CountEls(Head));

    Deallocate(&Head);
    printf("\nLinked List Deallocated\n");

    printf("\nTotal Elements:\n%d\n", CountEls(Head));

    return 0;
}// end of main

////////////////////////////////////////////////////////////
//
//  Name        :DisplayListF
//  Input       :PDNODE
//  Returns     :void
//  Description :Displays elements in linked list
//  Author      :Pranav Choudhary
//  Date        :31 Aug 2020
//
////////////////////////////////////////////////////////////
void DisplayListF(PDNODE First)
{
    if(NULL == First)
    {
        printf("Linked List is Empty\n");
        return;
    }
    printf("NULL");
    while(First != NULL)
    {
        printf("<-|%d|->", First->iData);
        First = First->npNext;
    }
    printf("NULL\n\n");
}// end of DisplayListF

////////////////////////////////////////////////////////////
//
//  Name        :DisplayListB
//  Input       :PDNODE
//  Returns     :void
//  Description :Displays elements in linked list reverse
//  Author      :Pranav Choudhary
//  Date        :31 Aug 2020
//
////////////////////////////////////////////////////////////
void DisplayListB(PDNODE First)
{
    
    if(NULL == First)
    {
        printf("Linked List is Empty\n");
        return;
    }

    while(First->npNext != NULL)
    {
        First = First->npNext;
    }

    printf("NULL");
    while(First != NULL)
    {
        printf("<-|%d|->", First->iData);
        First = First->npPrev;
    }
    printf("NULL\n");

}// end of DisplayListF

////////////////////////////////////////////////////////////
//
//  Name        :CountEls
//  Input       :PDNODE
//  Returns     :int
//  Description :counts elements in linked list
//  Author      :Pranav Choudhary
//  Date        :31 Aug 2020
//
////////////////////////////////////////////////////////////
int CountEls(PDNODE First)
{
    int iCnt = 0;
    if(NULL == First)
    {
        printf("Linked List is Empty\n");
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
//  Input       :PPDNODE
//  Returns     :void
//  Description :deallocates linked list
//  Author      :Pranav Choudhary
//  Date        :31 Aug 2020
//
////////////////////////////////////////////////////////////
void Deallocate(PPDNODE First)
{
    if(NULL == First)
    {
        printf("Linked List is Empty\n");
        return;
    }
    PDNODE nTemp = NULL;
    while(*First != NULL)
    {
        nTemp = *First;
        *First = nTemp->npNext;
        free(nTemp);
    }
   
}// end of Deallocate

//////////////////////////////////////////////////////////////////
//
//  Name        :InsertFirst
//  Input       :PPDNODE, int
//  Returns     :void
//  Description :Inserts element in Linked list at first position
//  Author      :Pranav Choudhary
//  Date        :31 Aug 2020
//
//////////////////////////////////////////////////////////////////
void InsertFirst(PPDNODE First, int iNum)
{
    PDNODE NewN = NULL;
    NewN = (PDNODE)malloc(sizeof(DNODE));
    if(NULL == NewN)
    {
        printf("Memory Allocation failed\n");
        return;
    }
    NewN->iData = iNum;
    NewN->npNext = NULL;
    NewN->npPrev = NULL;

    if(NULL == *First)
    {
        *First = NewN;
    }
    else
    {
        NewN->npNext = *First;
        (*First)->npPrev = NewN;
        *First = NewN;
    }    
}// end of InsertFirst

//////////////////////////////////////////////////////////////////
//
//  Name        :InsertLast
//  Input       :PPDNODE, int
//  Returns     :void
//  Description :Inserts element in Linked list at last position
//  Author      :Pranav Choudhary
//  Date        :31 Aug 2020
//
//////////////////////////////////////////////////////////////////
void InsertLast(PPDNODE First, int iNum)
{
    PDNODE NewN = NULL;
    NewN = (PDNODE)malloc(sizeof(DNODE));
    if(NULL == NewN)
    {
        printf("Memory Allocation failed\n");
        return;
    }
    NewN->iData = iNum;
    NewN->npNext = NULL;
    NewN->npPrev = NULL;

    if(NULL == *First)
    {
        *First = NewN;
    }
    else
    {
        PDNODE nTemp = *First;
        while(nTemp->npNext != NULL)
        {
            nTemp = nTemp->npNext;
        }

        nTemp->npNext = NewN;
        NewN->npPrev = nTemp;
    }    
}// end of InsertLast

//////////////////////////////////////////////////////////////////
//
//  Name        :InsertAtPos
//  Input       :PPDNODE, int, int
//  Returns     :void
//  Description :Inserts element in Linked list at desired position
//  Author      :Pranav Choudhary
//  Date        :31 Aug 2020
//
//////////////////////////////////////////////////////////////////
void InsertAtPos(PPDNODE First, int iNum, int iPos)
{
    int iSize = CountEls(*First);

    if(iPos < 1 || iPos > iSize + 1)
    {
        printf("Invalid Position enterd\n");
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
        PDNODE nTemp = *First, NewN = NULL;
        int i = 0;
        NewN = (PDNODE)malloc(sizeof(DNODE));
        if(NewN == NULL)
        {
            printf("Memory Allocation Failed!!\n");
            return;
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
    }
    
}// end of InsertAtPos

//////////////////////////////////////////////////////////////////
//
//  Name        :DeleteFirst
//  Input       :PPDNODE, int
//  Returns     :void
//  Description :Deletes element in Linked list at first position
//  Author      :Pranav Choudhary
//  Date        :31 Aug 2020
//
//////////////////////////////////////////////////////////////////
void DeleteFirst(PPDNODE First)
{
    if(NULL == *First)
    {
        printf("Linked List Is Empty\n");
    }
    else if((*First)->npNext == NULL)
    {
        free(*First);
        *First = NULL;
    }
    else
    {
        *First = (*First)->npNext;
        (*First)->npPrev->npNext = NULL;
        free((*First)->npPrev);
        (*First)->npPrev = NULL;
    }    
}// end of DeleteFirst

//////////////////////////////////////////////////////////////////
//
//  Name        :DeleteLast
//  Input       :PPDNODE, int
//  Returns     :void
//  Description :Deletes element in Linked list at last position
//  Author      :Pranav Choudhary
//  Date        :31 Aug 2020
//
//////////////////////////////////////////////////////////////////
void DeleteLast(PPDNODE First)
{
    if(NULL == *First)
    {
        printf("Linked List Is Empty\n");
    }
    else if((*First)->npNext == NULL)
    {
        free(*First);
        *First = NULL;
    }
    else
    {
        PDNODE nTemp = *First;
        while(nTemp->npNext->npNext != NULL)
        {
            nTemp = nTemp->npNext;
        }
        nTemp->npNext->npPrev = NULL;
        free(nTemp->npNext);
        nTemp->npNext = NULL;
    }    
}// end of DeleteLast

//////////////////////////////////////////////////////////////////
//
//  Name        :DeleteAtPos
//  Input       :PPDNODE, int
//  Returns     :void
//  Description :Deletes element in Linked list at desired position
//  Author      :Pranav Choudhary
//  Date        :1 Sept 2020
//
//////////////////////////////////////////////////////////////////
void DeleteAtPos(PPDNODE First, int iPos)
{
    int iSize = CountEls(*First);

    if(iPos < 1 || iPos > iSize)
    {
        printf("Invalid Position enterd\n");
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
        PDNODE nTemp = *First;
        int i = 0;

        for (i = 1; i < iPos; i++)
        {
            nTemp = nTemp->npNext;
        }
        nTemp->npPrev->npNext = nTemp->npNext;
        nTemp->npNext->npPrev = nTemp->npPrev;
        nTemp->npNext = NULL;
        nTemp->npPrev = NULL;
        free(nTemp);
    }    
}// end of DeleteAtPos