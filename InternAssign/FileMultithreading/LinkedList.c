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
    if (NULL == First->npNext)
    {
        printf("Error code %d : Linked List is Empty occured in CountEls()\n", GetLastError());
        return iCnt;
    }
    PNODE pTemp = First->npNext;
    while (pTemp != NULL)
    {
        iCnt++;
        pTemp = pTemp->npNext;
    }
    return iCnt;
} // end of CountEls()

////////////////////////////////////////////////////////////
//
//  Name        :InsertLast
//  Input       :PNODE, int
//  Returns     :void
//  Description :Insert element at last position
//  Author      :Pranav Choudhary
//  Date        :12 Oct 2020
//
////////////////////////////////////////////////////////////
void InsertLast(PNODE First, PCHAR szBuffer)
{
    PNODE newN = (PNODE)malloc(sizeof(NODE));
    if (newN == NULL)
    {
        printf("Error code %d : Memory Allocation Failed occured in InsertLast()\n", GetLastError());
        return;
    }
    newN->npNext = NULL;
    newN->szData = (PCHAR)malloc(sizeof(CHAR) * strlen(szBuffer) + 1);
    if (newN->szData == NULL)
    {
        printf("Error code %d : Memory Allocation Failed occured in InsertLast()\n", GetLastError());
        return;
    }
    memset(newN->szData, 0, strlen(szBuffer) + 1);
    strcpy(newN->szData, szBuffer);

    if (NULL == First->npNext)
    {
        First->npNext = newN;
    }
    else
    {
        PNODE nTemp = First->npNext;
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
//  Input       :PNODE
//  Returns     :void
//  Description :Deallocates all nodes in linked list
//  Author      :Pranav Choudhary
//  Date        :12 Oct 2020
//
////////////////////////////////////////////////////////////
void Deallocate(PNODE First)
{
    if (First == NULL)
    {
        printf("Error code %d : Linked List is Empty occured in Deallocate()\n", GetLastError());
        return;
    }

    PNODE nTemp = First->npNext;
    PNODE nTarget = NULL;
    while (nTemp != NULL)
    {
        nTarget = nTemp;
        nTemp = nTarget->npNext;
        free(nTarget);
    }
    First->npNext = NULL;
    First->szData = NULL;
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
    if (NULL == First->npNext)
    {
        printf("Error code %d : Linked List is Empty occured in DisplayList()\n", GetLastError());
        return;
    }
    PNODE nTemp = First->npNext;
    while (nTemp != NULL)
    {
        printf("%s\n", nTemp->szData);
        nTemp = nTemp->npNext;
    }
} // end of DisplayList()

////////////////////////////////////////////////////////////
//
//  Name        :InsertFirst
//  Input       :PNODE, int
//  Returns     :void
//  Description :Insert element at first position
//  Author      :Pranav Choudhary
//  Date        :12 Oct 2020
//
////////////////////////////////////////////////////////////
void InsertFirst(PNODE First, PCHAR szBuffer)
{
    PNODE newN = NULL;
    newN = (PNODE)malloc(sizeof(NODE));

    if (NULL == newN)
    {
        printf("Error code %d : Memory Allocation Failed occured in InsertFirst()\n", GetLastError());
        return;
    }

    newN->szData = (PCHAR)malloc(sizeof(CHAR) * strlen(szBuffer) + 1);
    if (newN->szData == NULL)
    {
        printf("Error code %d : Memory Allocation Failed occured in InsertFirst()\n", GetLastError());
        return;
    }
    memset(newN->szData, 0, strlen(szBuffer) + 1);
    strcpy(newN->szData, szBuffer);
    newN->npNext = NULL;

    /* If Linked List is empty */
    if (NULL == First->npNext)
    {
        First->npNext = newN;
    }
    else
    {
        newN->npNext = First->npNext;
        First->npNext = newN;
    }
} // End of InsertFirst()

////////////////////////////////////////////////////////////
//
//  Name        :DeleteFirst
//  Input       :PNODE
//  Returns     :void
//  Description :Deletes element at first position
//  Author      :Pranav Choudhary
//  Date        :12 Oct 2020
//
////////////////////////////////////////////////////////////
void DeleteFirst(PNODE First)
{
    if (NULL == First->npNext)
    {
        printf("Error : Linked List is already empty occured inf DeleteFirst()\n");
        return;
    }
    else
    {
        PNODE nTemp = First->npNext;
        First->npNext = nTemp->npNext;
        free(nTemp);
    }
} // End of DeleteFirst()

////////////////////////////////////////////////////////////
//
//  Name        :DeleteLast
//  Input       :PNODE
//  Returns     :void
//  Description :deletes element at last position
//  Author      :Pranav Choudhary
//  Date        :12 Oct 2020
//
////////////////////////////////////////////////////////////
void DeleteLast(PNODE First)
{
    if (NULL == First->npNext)
    {
        printf("Error : Linked List is Empty occured in DeleteLast\n");
        return;
    }
    else if ((First->npNext)->npNext == NULL)
    {
        free(First->npNext);
        First->npNext = NULL;
        First->szData = NULL;
    }
    else
    {
        PNODE nTemp = First->npNext;
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
//  Input       :PNODE, int, int
//  Returns     :void
//  Description :Insert element at desired position
//  Author      :Pranav Choudhary
//  Date        :12 Oct 2020
//
////////////////////////////////////////////////////////////
void InsertAtPos(PNODE First, PCHAR szBuffer, int iPos)
{
    int iSize = CountEls(First);
    if (iPos > iSize + 1 || iPos < 1)
    {
        printf("Error : Invalid Position Entered occured in InsertAtPos()\n");
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
        PNODE nTemp = First->npNext;
        int i = 0;
        newN = (PNODE)malloc(sizeof(NODE));
        if (NULL == newN)
        {
            printf("Error code %d : Memory Allocation Failed occured in InsertAtPos()\n", GetLastError());
            return;
        }

        newN->szData = (PCHAR)malloc(sizeof(CHAR) * strlen(szBuffer) + 1);
        if (newN->szData == NULL)
        {
            printf("Error code %d : Memory Allocation Failed occured in InsertAtPos()\n", GetLastError());
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
//  Input       :PNODE, int
//  Returns     :void
//  Description :Deletes element from desired position
//  Author      :Pranav Choudhary
//  Date        :12 Oct 2020
//
////////////////////////////////////////////////////////////
void DeleteAtPos(PNODE First, int iPos)
{
    int iSize = CountEls(First);
    if (iPos > iSize || iPos < 1 || NULL == First)
    {
        printf("Error : Invalid Position Entered or Linked list is empty occured in DeleteAtPos()\n");
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
        PNODE nTemp = First->npNext;
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
