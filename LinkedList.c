#include "LinkedList.h"

///////////////////////////////////////////////////////////
//
//  Name        :CountEls
//  Input       :PNODE
//  Returns     :int
//  Description :Displays elements in linked list
//  Author      :Pranav Choudhary
//  Date        :12 Oct 2020
//
////////////////////////////////////////////////////////////
int CountEls(PNODE First)
{
    int iCnt = 0;
    if (First == NULL)
    {
        printf("Linked List is NULL\n");
        return iCnt;
    }
    while (First != NULL)
    {
        iCnt++;
        First = First->npNext;
    }
    return iCnt;
} // end of CountEls()

////////////////////////////////////////////////////////////
//
//  Name        :InsertLast
//  Input       :PPNODE, int
//  Returns     :void
//  Description :Insert element at last position
//  Author      :Pranav Choudhary
//  Date        :12 Oct 2020
//
////////////////////////////////////////////////////////////
void InsertLast(PPNODE First, PCHAR szBuffer)
{
    //printf("Inside InsertLast\n");
    PNODE newN = (PNODE)malloc(sizeof(NODE));
    if (newN == NULL)
    {
        printf("Unable to allocate memory in InsertLast()\n");
        return;
    }
    newN->npNext = NULL;
    newN->szData = (PCHAR)malloc(sizeof(CHAR) * strlen(szBuffer) + 1);
    if (newN->szData == NULL)
    {
        printf("Memory Allocation Failed");
        return;
    }
    memset(newN->szData, 0, strlen(szBuffer) + 1);
    strcpy(newN->szData, szBuffer);

    if (*First == NULL)
    {
        *First = newN;
    }
    else
    {
        PNODE nTemp = *First;
        while (nTemp->npNext != NULL)
        {
            nTemp = nTemp->npNext;
        }
        nTemp->npNext = newN;
    }
} // end of InsertLast()

////////////////////////////////////////////////////////////
//
//  Name        :Deallocate
//  Input       :PPNODE
//  Returns     :void
//  Description :Deallocates all nodes in linked list
//  Author      :Pranav Choudhary
//  Date        :12 Oct 2020
//
////////////////////////////////////////////////////////////
void Deallocate(PPNODE First)
{
    if (First == NULL)
    {
        printf("Linked List is NULL\n");
        return;
    }

    PNODE nTemp = NULL;
    while (*First != NULL)
    {
        nTemp = *First;
        *First = nTemp->npNext;
        free(nTemp);
    }
} // end of Deallocate()

////////////////////////////////////////////////////////////
//
//  Name        :DisplayList
//  Input       :PNODE
//  Returns     :void
//  Description :Displays elements in linked list
//  Author      :Pranav Choudhary
//  Date        :12 Oct 2020
//
////////////////////////////////////////////////////////////
void DisplayList(PNODE First)
{
    if (First == NULL)
    {
        printf("Linked List is NULL\n");
        return;
    }
    while (First != NULL)
    {
        printf("%s\n", First->szData);
        First = First->npNext;
    }
} // end of DisplayList()

////////////////////////////////////////////////////////////
//
//  Name        :InsertFirst
//  Input       :PPNODE, int
//  Returns     :void
//  Description :Insert element at first position
//  Author      :Pranav Choudhary
//  Date        :12 Oct 2020
//
////////////////////////////////////////////////////////////
void InsertFirst(PPNODE First, PCHAR szBuffer)
{
    PNODE newN = NULL;
    newN = (PNODE)malloc(sizeof(NODE));

    if (NULL == newN)
    {
        printf("Memory Allocation Failed");
        return;
    }

    newN->szData = (PCHAR)malloc(sizeof(CHAR) * strlen(szBuffer) + 1);
    if (newN->szData == NULL)
    {
        printf("Memory Allocation Failed");
        return;
    }
    memset(newN->szData, 0, strlen(szBuffer) + 1);
    strcpy(newN->szData, szBuffer);
    newN->npNext = NULL;

    /* If Linked List is empty */
    if (*First == NULL)
    {
        *First = newN;
    }
    else
    {
        newN->npNext = *First;
        *First = newN;
    }
} // End of InsertFirst()

////////////////////////////////////////////////////////////
//
//  Name        :DeleteFirst
//  Input       :PPNODE
//  Returns     :void
//  Description :Deletes element at first position
//  Author      :Pranav Choudhary
//  Date        :12 Oct 2020
//
////////////////////////////////////////////////////////////
void DeleteFirst(PPNODE First)
{
    if (NULL == *First)
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
} // End of DeleteFirst()

////////////////////////////////////////////////////////////
//
//  Name        :DeleteLast
//  Input       :PPNODE
//  Returns     :void
//  Description :deletes element at last position
//  Author      :Pranav Choudhary
//  Date        :12 Oct 2020
//
////////////////////////////////////////////////////////////
void DeleteLast(PPNODE First)
{
    if (*First == NULL)
    {
        printf("Linked List is Empty\n");
        return;
    }
    else if ((*First)->npNext == NULL)
    {
        free(*First);
        *First = NULL;
    }
    else
    {
        PNODE nTemp = *First;
        while ((nTemp->npNext)->npNext != NULL)
        {
            nTemp = nTemp->npNext;
        }
        free(nTemp->npNext);
        nTemp->npNext = NULL;
    }

} // End of DeleteLast()

////////////////////////////////////////////////////////////
//
//  Name        :InsertAtPos
//  Input       :PPNODE, int, int
//  Returns     :void
//  Description :Insert element at desired position
//  Author      :Pranav Choudhary
//  Date        :12 Oct 2020
//
////////////////////////////////////////////////////////////
void InsertAtPos(PPNODE First, PCHAR szBuffer, int iPos)
{
    int iSize = CountEls(*First);
    if (iPos > iSize + 1 || iPos < 1)
    {
        printf("Invalid Position Entered\n");
    }
    else if (iPos == 1)
    {
        InsertFirst(First, szBuffer);
    }
    else if (iPos == iSize + 1)
    {
        InsertLast(First, szBuffer);
    }
    else
    {
        PNODE newN = NULL;
        PNODE nTemp = *First;
        int i = 0;
        newN = (PNODE)malloc(sizeof(NODE));
        if (NULL == newN)
        {
            printf("Memory Allocation Failed");
            return;
        }

        newN->szData = (PCHAR)malloc(sizeof(CHAR) * strlen(szBuffer) + 1);
        if (newN->szData == NULL)
        {
            printf("Memory Allocation Failed");
            return;
        }

        memset(newN->szData, 0, strlen(szBuffer) + 1);
        strcpy(newN->szData, szBuffer);
        newN->npNext = NULL;

        for (i = 1; i < iPos - 1; i++)
        {
            nTemp = nTemp->npNext;
        }
        newN->npNext = nTemp->npNext;
        nTemp->npNext = newN;
    }
} // End of InsertAtPos()

////////////////////////////////////////////////////////////
//
//  Name        :DeleteAtPos
//  Input       :PPNODE, int
//  Returns     :void
//  Description :Deletes element from desired position
//  Author      :Pranav Choudhary
//  Date        :12 Oct 2020
//
////////////////////////////////////////////////////////////
void DeleteAtPos(PPNODE First, int iPos)
{
    int iSize = CountEls(*First);
    if (iPos > iSize || iPos < 1 || NULL == *First)
    {
        printf("Invalid Position Entered or Linked list is empty\n");
    }
    else if (iPos == 1)
    {
        DeleteFirst(First);
    }
    else if (iPos == iSize)
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
} // End of DeleteAtPos()
