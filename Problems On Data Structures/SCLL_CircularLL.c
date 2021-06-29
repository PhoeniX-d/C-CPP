/*
*   Implementaion of Singly CIrcular Linked List in C
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// structure of node of circular linked list
typedef struct node
{
    char*            sData;
    struct node     *npNext;
} NODE, *PNODE, **PPNODE;

// global declarations
char *StrDup(char *);
void InsertFirst(PPNODE, PPNODE, char*);
void DeleteFirst(PPNODE, PPNODE);
void InsertLast(PPNODE, PPNODE, char*);
void DeleteLast(PPNODE, PPNODE);
void InsertAtPos(PPNODE, PPNODE, char*, int);
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

    InsertFirst(&Head, &Tail, "To");
    InsertFirst(&Head, &Tail, "Welcome");

    printf("Linked List:InsertFirst\n");
    DisplayList(Head, Tail);   

    InsertLast(&Head, &Tail, "The");
    InsertLast(&Head, &Tail, "Programming");
    InsertLast(&Head, &Tail, "Language");
    InsertLast(&Head, &Tail, "By");
    InsertLast(&Head, &Tail, "Dennis");
    InsertLast(&Head, &Tail, "Ritchie");
    InsertLast(&Head, &Tail, "Sir");

    printf("Linked List:InsertLast\n");
    DisplayList(Head, Tail);

    InsertAtPos(&Head, &Tail, "C", 4);
    printf("Linked List:InsertAtPos\n");
    DisplayList(Head, Tail);
    
    DeleteFirst(&Head, &Tail);
    printf("Linked List:DeleteFirst\n");
    DisplayList(Head, Tail);

    DeleteLast(&Head, &Tail);
    printf("Linked List:DeleteLast\n");
    DisplayList(Head, Tail);

    DeleteAtPos(&Head, &Tail, 1);
    printf("Linked List:DeleteAtPos\n");
    DisplayList(Head, Tail);

    iRet = CountEls(Head, Tail);
    printf("Total Elements:\n%d\n", iRet);
    
    Deallocate(&Head, &Tail);
    printf("\nLinked List Deallocated\n");

    return 0;
}

////////////////////////////////////////////////////////////
//
//  Name        :StrDup
//  Input       :char*
//  Returns     :char*
//  Description :Copies source string into new string
//  Author      :Pranav Choudhary
//  Date        :31 Aug 2020
//
////////////////////////////////////////////////////////////
char* StrDup(char* cSrc)
{
    char *cDest = NULL;
    cDest = (char*)malloc(strlen(cSrc) + 1);
    if(cDest != NULL)
    {
        strcpy(cDest, cSrc);
    }
    return cDest;
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
        printf("%s->", First->sData);
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
    if(NULL == *First || NULL == *Last)
    {
        printf("Linked List is NULL\n");
        return;
    }
    PNODE nTemp = NULL;
    do
    {
        nTemp = *First;
        *First = (*First)->npNext;
        (*Last)->npNext = *First;
        free(nTemp);
        printf("Deleted\n");
        if(*Last == *First)
        {
            free(*First);
            *First = NULL;
            *Last = NULL;
            printf("Deleted\n");
            break;
        }
    } while ((*Last) != (*First));

}// end of Deallocate

////////////////////////////////////////////////////////////
//
//  Name        :InsertFirst
//  Input       :PPNODE, PPNODE, char*
//  Returns     :void
//  Description :Insert element at first position
//  Author      :Pranav Choudhary
//  Date        :31 Aug 2020
//
////////////////////////////////////////////////////////////
void InsertFirst(PPNODE First, PPNODE Last, char* cStr)
{
    PNODE NewN = NULL;
    NewN = (PNODE)malloc(sizeof(NODE));
    
    if(NULL == NewN)
    {
        printf("Memory Allocation Failed");
        return;
    }
    
    NewN->sData = StrDup(cStr);
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

////////////////////////////////////////////////////////////
//
//  Name        :InsertLast
//  Input       :PPNODE, PPNODE, int
//  Returns     :void
//  Description :Insert element at last position
//  Author      :Pranav Choudhary
//  Date        :31 Aug 2020
//
////////////////////////////////////////////////////////////
void InsertLast(PPNODE First, PPNODE Last, char* cStr)
{
    PNODE NewN = NULL;
    NewN = (PNODE)malloc(sizeof(NODE));
    
    if(NULL == NewN)
    {
        printf("Memory Allocation Failed");
        return;
    }
    
    NewN->sData = StrDup(cStr);
    NewN->npNext = NULL;

     /* if linked list is not empty */
    if(*First == NULL && *Last == NULL)
    {
        *First = NewN;
        *Last = NewN;
    }
    else
    {
        (*Last)->npNext = NewN;
        *Last = NewN;
    }
    (*Last)->npNext = *First;  
}// End of InsertLast

////////////////////////////////////////////////////////////
//
//  Name        :InsertAtPos
//  Input       :PPNODE, PPNODE, int, int
//  Returns     :void
//  Description :Insert element at desired position
//  Author      :Pranav Choudhary
//  Date        :31 Aug 2020
//
////////////////////////////////////////////////////////////
void InsertAtPos(PPNODE First, PPNODE Last, char* cStr, int iPos)
{
    int iSize = CountEls(*First, *Last);
    if(iPos > iSize + 1 || iPos < 1)
    {
        printf("Invalid Position Entered\n");
        return;
    }
    else if(iPos == 1)
    {
        InsertFirst(First, Last, cStr);
        return;
    }
    else if(iPos == iSize + 1)
    {
        InsertLast(First, Last, cStr);
        return;
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
        
        NewN->sData = StrDup(cStr);
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
//  Name        :DeleteFirst
//  Input       :PPNODE, PPNODE
//  Returns     :void
//  Description :Deletes element at first position
//  Author      :Pranav Choudhary
//  Date        :31 Aug 2020
//
////////////////////////////////////////////////////////////
void DeleteFirst(PPNODE First, PPNODE Last)
{
    if(NULL == *First || NULL == *Last)
    {
        printf("Linked List is already empty\n");
        return;
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
        free((*Last)->npNext);
        (*Last)->npNext = *First;
    }
}// End of DeleteFirst

////////////////////////////////////////////////////////////
//
//  Name        :DeleteLast
//  Input       :PPNODE, PPNODE
//  Returns     :void
//  Description :deletes element at last position
//  Author      :Pranav Choudhary
//  Date        :31 Aug 2020
//
////////////////////////////////////////////////////////////
void DeleteLast(PPNODE First, PPNODE Last)
{
    if(NULL == *First || NULL == *Last)
    {
        printf("Linked List is already empty\n");
        return;
    }
    else if(*First == *Last)
    {
        free(*Last);
        *First = NULL;
        *Last = NULL;
    }
    else
    {
        PNODE nTemp = *First;
        while(nTemp->npNext != *Last)
        {
            nTemp = nTemp->npNext;
        }
        free(*Last);
        *Last = nTemp;
        (*Last)->npNext = *First;
    }
    
}// End of DeleteLast

////////////////////////////////////////////////////////////
//
//  Name        :DeleteAtPos
//  Input       :PPNODE, PPNODE, int
//  Returns     :void
//  Description :Deletes element from desired position
//  Author      :Pranav Choudhary
//  Date        :31 Aug 2020
//
////////////////////////////////////////////////////////////
void DeleteAtPos(PPNODE First, PPNODE Last, int iPos)
{
    int iSize = CountEls(*First, *Last);
    if(iPos > iSize || iPos < 1 || NULL == *First || NULL == *Last)
    {
        printf("Invalid Position Entered or Linked list is empty\n");
        return;
    }
    else if(iPos == 1)
    {
        DeleteFirst(First, Last);
        return;
    }
    else if(iPos == iSize)
    {
        DeleteLast(First, Last);
        return;
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