/*
*   Implementaion of Singly CIrcular Linked List in C
*/
#include<stdio.h>
#include<stdlib.h>

// structure of node of circular linked list
typedef struct node
{
    int             iData;
    struct node     *npNext;
} NODE, *PNODE, **PPNODE;

// global declarations
void InsertFirst(PPNODE, PPNODE, int);
void DeleteFirst(PPNODE, PPNODE);
void InsertLast(PPNODE, PPNODE, int);
void DeleteLast(PPNODE, PPNODE);
void InsertAtPos(PPNODE, PPNODE, int, int);
void DeleteAtPos(PPNODE, PPNODE, int);
void DisplayList(PNODE, PNODE);
int  CountEls(PNODE, PNODE);
void Deallocate(PPNODE, PPNODE);

// Entry point
int main()
{
    printf("\n----------Singly Circular Linked List----------\n\n");
    PNODE Head = NULL;
    PNODE Tail = NULL;
    int iRet = 0;

    InsertFirst(&Head, &Tail, 40);
    InsertFirst(&Head, &Tail, 50);
    InsertFirst(&Head, &Tail, 10);
    InsertFirst(&Head, &Tail, 20);

    printf("Linked List:InsertFirst\n");
    DisplayList(Head, Tail);   

    iRet = CountEls(Head, Tail);
    printf("Total Elements:\n%d\n", iRet);
    
    Deallocate(&Head, &Tail);
    printf("\nLinked List Deallocated\n");
    return 0;
}

////////////////////////////////////////////////////////////
//
//  Name        :DisplayList
//  Input       :PNODE, PNODE
//  Returns     :void
//  Description :Displays elements in linked list
//  Author      :Pranav Choudhary
//  Date        :31 Aug 2020
//
////////////////////////////////////////////////////////////
void DisplayList(PNODE First, PNODE Last)
{
    if(First == NULL || NULL == Last)
    {
        printf("Linked List is NULL\n");
        return;
    }
    printf("->");
    do
    {
        printf("%d->", First->iData);
        First = First->npNext;
    } while (First != Last->npNext);

    printf("\n\n");
}// end of DisplayList

////////////////////////////////////////////////////////////
//
//  Name        :CountEls
//  Input       :PNODE, PNODE
//  Returns     :int
//  Description :Displays elements in linked list
//  Author      :Pranav Choudhary
//  Date        :31 Aug 2020
//
////////////////////////////////////////////////////////////
int CountEls(PNODE First, PNODE Last)
{
    int iCnt = 0;
    if(NULL == First || NULL == Last)
    {
        printf("Linked List is NULL\n");
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
//  Input       :PPNODE, PPNODE
//  Returns     :void
//  Description :Deallocates all nodes in linked list
//  Author      :Pranav Choudhary
//  Date        :31 Aug 2020
//
////////////////////////////////////////////////////////////
void Deallocate(PPNODE First, PPNODE Last)
{
    if(NULL == First || NULL == Last)
    {
        printf("Linked List is NULL\n");
        return;
    }
    PNODE nFirst = (*Last)->npNext;
    PNODE nTemp = NULL;
    do
    {
        nTemp = *First;
        *First = nTemp->npNext;
        free(nTemp);
    } while ((*First) != nFirst);
}// end of Deallocate

////////////////////////////////////////////////////////////
//
//  Name        :InsertFirst
//  Input       :PPNODE, PPNODE, int
//  Returns     :void
//  Description :Insert element at first position
//  Author      :Pranav Choudhary
//  Date        :31 Aug 2020
//
////////////////////////////////////////////////////////////
void InsertFirst(PPNODE First, PPNODE Last, int iNum)
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
    if(*First == NULL && *Last == NULL)      
    {
        *First = NewN;
        *Last = NewN;
    }
    else
    {
        NewN->npNext = *First;
        *First = NewN;
    }

    (*Last)->npNext = *First;

}// End of InsertFirst
