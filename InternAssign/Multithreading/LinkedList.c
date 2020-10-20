#include "LinkedList.h"

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
        printf("Index\t:%d\n%s\n", nTemp->index, nTemp->szData);
        nTemp = nTemp->npNext;
    }
} // end of DisplayList()

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
    free(First->szData);
} // end of Deallocate()

////////////////////////////////////////////////////////////
//
//  Name        :InitializeHead
//  Input       :PPNODE
//  Returns     :void
//  Description :Iniitializes Head node
//  Author      :Pranav Choudhary
//  Date        :20 Oct 2020
//
////////////////////////////////////////////////////////////
void InitializeHead(PPNODE First)
{
    PNODE newN = NULL;
    newN = (PNODE)malloc(sizeof(NODE));
    if (NULL == newN)
    {
        printf("Error code %d : Memory Allocation Failed occured in InsertAtPos()\n", GetLastError());
        return;
    }

    newN->szData = (PCHAR)malloc(sizeof(CHAR) * strlen("Engine") + 1);
    if (newN->szData == NULL)
    {
        printf("Error code %d : Memory Allocation Failed occured in InsertAtPos()\n", GetLastError());
        return;
    }

    memset(newN->szData, 0, strlen("Engine") + 1);
    strcpy(newN->szData, "Engine");
    newN->npNext = NULL;
    *First = newN;
}

////////////////////////////////////////////////////////////
//
//  Name        :UninitializeHead
//  Input       :PPNODE
//  Returns     :void
//  Description :Uniniitializes Head node
//  Author      :Pranav Choudhary
//  Date        :20 Oct 2020
//
////////////////////////////////////////////////////////////
void UninitializeHead(PPNODE Head)
{
    free(*Head);
}


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
void InsertFirst(PNODE First, PCHAR szBuffer, INDEX index)
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
    newN->index = index;
    newN->npNext = NULL;

    newN->npNext = (First)->npNext;
    (First)->npNext = newN;

} // End of InsertFirst

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
//  Name        :InsertLast
//  Input       :PPNODE, int
//  Returns     :void
//  Description :Insert element at last position
//  Author      :Pranav Choudhary
//  Date        :29 Aug 2020
//
////////////////////////////////////////////////////////////
void InsertLast(PNODE First, PCHAR szBuffer, INDEX index)
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
    newN->index = index;
    newN->npNext = NULL;

    PNODE nTemp = First;
    while (nTemp->npNext != NULL)
    {
        nTemp = nTemp->npNext;
    }
    nTemp->npNext = newN;
} // End of InsertLast

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
void InsertAtPos(PNODE First, PCHAR szBuffer, int iPos, INDEX index)
{
    int iSize = CountEls(First);
    if (iPos > iSize + 1 || iPos < 1)
    {
        printf("Error : Invalid Position Entered occured in InsertAtPos()\n");
    }
    else if (iPos == 1)
    {
        InsertFirst(First, szBuffer, index);
    }
    else if (iPos == iSize + 1)
    {
        InsertLast(First, szBuffer, index);
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
        newN->index = index;
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
//  Date        :29 Aug 2020
//
////////////////////////////////////////////////////////////
void DeleteAtPos(PNODE First, int iPos)
{
    int iSize = CountEls(First);
    if (iPos > iSize || iPos < 1 || NULL == First)
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
} // End of DeleteAtPos

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
void SortList(PNODE First)
{
    if (NULL == First && (First->npNext)->npNext == NULL)
    {
        printf("Error code %d : Linked List is empty inside SortList()\n", GetLastError());
        return;
    }

    PNODE Temp1 = First->npNext;
    PNODE Temp2 = First->npNext->npNext;
    PNODE Temp3 = NULL;

    while (Temp2 != NULL)
    {
        if (Temp1->index > Temp2->index)
        {
            if (Temp1 == First->npNext && Temp2 == First->npNext->npNext)
            {
                Temp1->npNext = Temp2->npNext;
                Temp2->npNext = First->npNext;
                First->npNext = Temp2;
            }
            else
            {
                Temp3 = First->npNext;
                while (Temp3->npNext != Temp1)
                {
                    Temp3 = Temp3->npNext;
                }
                Temp3->npNext = Temp2;
                Temp1->npNext = Temp2->npNext;
                Temp2->npNext = Temp1;
            }
            Temp1 = First->npNext;
            Temp2 = Temp1->npNext;
        }
        else
        {
            Temp1 = Temp1->npNext;
            Temp2 = Temp1->npNext;
        }
    }
}
