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

// Global declarations
void InsertFirst(PPDNODE, PPDNODE, int);
void InsertLast(PPDNODE, PPDNODE,  int);
void InsertAtPos(PPDNODE, PPDNODE, int, int);
void DeleteFirst(PPDNODE, PPDNODE);
void DeleteLast(PPDNODE, PPDNODE);
void DeleteAtPos(PPDNODE, PPDNODE, int);
void DisplayListF(PDNODE, PDNODE);
void DisplayListB(PDNODE, PDNODE);
void Deallocate(PPDNODE, PPDNODE);
int  CountEls(PDNODE, PDNODE);

// Entry point
int main()
{
    printf("\n----------Doubly Circular Linked List----------\n\n");

    PDNODE Head = NULL;
    PDNODE Tail = NULL;
    int iRet = 0;

    InsertFirst(&Head, &Tail, 11);
    InsertFirst(&Head, &Tail, 21);
    InsertFirst(&Head, &Tail, 54);
    InsertFirst(&Head, &Tail, 78);

    printf("\nLinked List:\nInsertFirst\n");
    DisplayListF(Head, Tail);
    DisplayListB(Head, Tail);

    InsertLast(&Head, &Tail, 131);
    InsertLast(&Head, &Tail, 221);
    InsertLast(&Head, &Tail, 64);
    InsertLast(&Head, &Tail, 75);

    printf("\nLinked List:\nInsertLast\n");
    DisplayListF(Head, Tail);
    DisplayListB(Head, Tail);

    InsertAtPos(&Head, &Tail, 344, 4);
    InsertAtPos(&Head, &Tail, 891, 8);

    printf("\nLinked List:\nInsertAtPos\n");
    DisplayListF(Head, Tail);
    DisplayListB(Head, Tail);

    DeleteFirst(&Head, &Tail);
    printf("\nLinked List:\nDeleteFirst\n");
    DisplayListF(Head, Tail);
    DisplayListB(Head, Tail);

    DeleteLast(&Head, &Tail);
    printf("\nLinked List:\nDeleteLast\n");
    DisplayListF(Head, Tail);
    DisplayListB(Head, Tail);

    DeleteAtPos(&Head, &Tail, 3);
    DeleteAtPos(&Head, &Tail, 6);
    printf("\nLinked List:\nDeleteAtPos\n");
    DisplayListF(Head, Tail);
    DisplayListB(Head, Tail);

    printf("\nTotal Elements:\n%d\n", CountEls(Head, Tail));

    Deallocate(&Head, &Tail);
    printf("\nLinked List Deallocated\n");

    printf("\nTotal Elements:\n%d\n", CountEls(Head, Tail));

    return 0;
}// end of main

////////////////////////////////////////////////////////////
//
//  Name        :DisplayListF
//  Input       :PDNODE, PDNODE
//  Returns     :void
//  Description :Displays elements in linked list
//  Author      :Pranav Choudhary
//  Date        :1 Sept 2020
//
////////////////////////////////////////////////////////////
void DisplayListF(PDNODE First, PDNODE Last)
{
    if(NULL == First && NULL == Last)
    {
        printf("Linked List is Empty\n");
        return;
    }
    do
    {
        printf("<-|%d|->", First->iData);
        First = First->npNext;
    } while (First != Last->npNext);
    printf("\n\n");
}// end of DisplayListF

////////////////////////////////////////////////////////////
//
//  Name        :DisplayListB
//  Input       :PDNODE, PDNODE
//  Returns     :void
//  Description :Displays elements in linked list reverse
//  Author      :Pranav Choudhary
//  Date        :1 Sept 2020
//
////////////////////////////////////////////////////////////
void DisplayListB(PDNODE First, PDNODE Last)
{
    
    if(NULL == First && NULL == Last)
    {
        printf("Linked List is Empty\n");
        return;
    }
    do
    {
        printf("<-|%d|->", Last->iData);
        Last = Last->npPrev;
    } while (Last != First->npPrev);
    printf("\n\n");

}// end of DisplayListB

////////////////////////////////////////////////////////////
//
//  Name        :Count
//  Input       :PDNODE
//  Returns     :int
//  Description :counts elements in linked list
//  Author      :Pranav Choudhary
//  Date        :1 Sept 2020
//
////////////////////////////////////////////////////////////
int CountEls(PDNODE First, PDNODE Last)
{
    int iCnt = 0;
    if(NULL == First && NULL == Last)
    {
        printf("Linked List is Empty\n");
        return iCnt;
    }
    do
    {
        iCnt++;
        First = First->npNext;
    } while (First != Last->npNext);
    return iCnt;
}// end of CountEls

////////////////////////////////////////////////////////////
//
//  Name        :Deallocate
//  Input       :PPDNODE
//  Returns     :void
//  Description :deallocates linked list
//  Author      :Pranav Choudhary
//  Date        :1 Sept 2020
//
////////////////////////////////////////////////////////////
void Deallocate(PPDNODE First, PPDNODE Last)
{
    if(NULL == *First && NULL == *Last)
    {
        printf("Linked List is Empty\n");
        return;
    }
    
    do
    {
        *First = (*First)->npNext;
        (*Last)->npNext = (*First);
        free((*First)->npPrev);
        (*First)->npPrev = *Last;

        if(*First == *Last)
        {
            free(*Last);
            *First = NULL;
            *Last = NULL;
            break;
        }

    } while (*First != *Last);

}// end of Deallocate

//////////////////////////////////////////////////////////////////
//
//  Name        :InsertFirst
//  Input       :PPDNODE, PPDNODE, int
//  Returns     :void
//  Description :Inserts element in Linked list at first position
//  Author      :Pranav Choudhary
//  Date        :1 Sept 2020
//
//////////////////////////////////////////////////////////////////
void InsertFirst(PPDNODE First, PPDNODE Last, int iNum)
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

    if(NULL == *First && NULL == *Last)
    {
        *First = NewN;
        *Last = NewN;
    }
    else
    {
        NewN->npNext = *First;
        (*First)->npPrev = NewN;
        *First = NewN;
    }
    (*Last)->npNext = *First;
    (*First)->npPrev = *Last;
}// end of InsertFirst

//////////////////////////////////////////////////////////////////
//
//  Name        :InsertLast
//  Input       :PPDNODE, PPDNODE, int
//  Returns     :void
//  Description :Inserts element in Linked list at last position
//  Author      :Pranav Choudhary
//  Date        :1 Sept 2020
//
//////////////////////////////////////////////////////////////////
void InsertLast(PPDNODE First, PPDNODE Last, int iNum)
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

    if(NULL == *First && NULL == *Last)
    {
        *First = NewN;
        *Last = NewN;
    }
    else
    {
        (*Last)->npNext = NewN;
        NewN->npPrev = (*Last);
        *Last = NewN;
    }
    (*Last)->npNext = *First;
    (*First)->npPrev = *Last; 
}// end of InsertLast

//////////////////////////////////////////////////////////////////
//
//  Name        :InsertAtPos
//  Input       :PPDNODE, int, int
//  Returns     :void
//  Description :Inserts element in Linked list at desired position
//  Author      :Pranav Choudhary
//  Date        :1 Sept 2020
//
//////////////////////////////////////////////////////////////////
void InsertAtPos(PPDNODE First, PPDNODE Last, int iNum, int iPos)
{
    int iSize = CountEls(*First, *Last);

    if(iPos < 1 || iPos > iSize + 1)
    {
        printf("Invalid Position enterd\n");
    }
    else if(iPos == 1)
    {
        InsertFirst(First, Last, iNum);
    }
    else if(iPos == iSize + 1)
    {
        InsertLast(First, Last, iNum);
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
//  Input       :PPDNODE, PPDNODE, int
//  Returns     :void
//  Description :Deletes element in Linked list at first position
//  Author      :Pranav Choudhary
//  Date        :1 Sept 2020
//
//////////////////////////////////////////////////////////////////
void DeleteFirst(PPDNODE First, PPDNODE Last)
{
    if(NULL == *First && NULL == *Last)
    {
        printf("Linked List Is Empty\n");
    }
    else if(*First == *Last)
    {
        free(*First);
        *First = NULL;
        *Last = NULL;
    }
    else
    {
        *First = (*First)->npNext;
        (*Last)->npNext = *First;
        free((*First)->npPrev);        
        (*First)->npPrev = (*Last);
    }    
}// end of DeleteFirst

//////////////////////////////////////////////////////////////////
//
//  Name        :DeleteLast
//  Input       :PPDNODE, PPDNODE, int
//  Returns     :void
//  Description :Deletes element in Linked list at last position
//  Author      :Pranav Choudhary
//  Date        :1 Sept 2020
//
//////////////////////////////////////////////////////////////////
void DeleteLast(PPDNODE First, PPDNODE Last)
{
    if(NULL == *First && NULL == *Last)
    {
        printf("Linked List Is Empty\n");
    }
    else if(*First == *Last)
    {
        free(*Last);
        *First = NULL;
        *Last = NULL;
    }
    else
    {
        *Last = (*Last)->npPrev;
        free((*Last)->npNext);
        (*Last)->npNext = *First;
        (*First)->npPrev = *Last;
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
void DeleteAtPos(PPDNODE First, PPDNODE Last, int iPos)
{
    int iSize = CountEls(*First, *Last);
    if(NULL == *First && NULL == *Last)
    {
        printf("Linked List Is Empty\n");
    }
    if(iPos < 1 || iPos > iSize)
    {
        printf("Invalid Position enterd\n");
    }
    else if(iPos == 1)
    {
        DeleteFirst(First, Last);
    }
    else if(iPos == iSize)
    {
        DeleteLast(First, Last);
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
        free(nTemp);
    }    
}// end of DeleteAtPos
