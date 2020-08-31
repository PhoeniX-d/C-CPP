/*
*   Implementaion of Singly Circular Linked List in C++
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<iostream>

using namespace std;

// structure of node of circular linked list
typedef struct node
{
     char* sData;
    struct node* npNext;
} NODE, *PNODE, **PPNODE;

// class for singly circular linked list
class Singly_CircularLL
{
private:
    PNODE Head;
    PNODE Tail;
    int iCount;

public:
    Singly_CircularLL();
    ~Singly_CircularLL();
    char* StrDup( char*);
    bool DisplayList();
    int CountEls();
    bool InsertFirst( char*);
    bool DeleteFirst();
    bool InsertLast( char*);
    bool DeleteLast();
    bool InsertAtPos( char*, int);
    bool DeleteAtPos(int);
};

////////////////////////////////////////////////////////////
//
//  Name        :Singly_CircularLL a ructor
//
///////////////////////////////////////////////////////////
Singly_CircularLL::Singly_CircularLL()
{
    Head = NULL;
    Tail = NULL;
    iCount = 0;
}// end of ructor

////////////////////////////////////////////////////////////
//
//  Name        :~Singly_CircularLL a destructor
//
///////////////////////////////////////////////////////////
Singly_CircularLL::~Singly_CircularLL()
{
    if((Head != NULL) && (Tail != NULL))
	{
        PNODE temp = NULL;
        do
		{
			temp = Head;
			Head = Head->npNext;
			Tail->npNext = Head;
			delete temp;
            iCount--;
            printf("Deleted\n");
            if(Head == Tail)
            {
                free(Head);
                Head = NULL;
                Tail = NULL;
                iCount--;
                printf("Deleted\n");
                break;
            }
        }while(Head != Tail);
	}
}// end of Destructor

////////////////////////////////////////////////////////////
//
//  Name        :StrDup
//  Input       : char*
//  Returns     : char*
//  Description :Copies source string into new string
//  Author      :Pranav Choudhary
//  Date        :31 Aug 2020
//
////////////////////////////////////////////////////////////
 char* Singly_CircularLL::StrDup( char* cSrc)
{
    char* cDest = NULL;
    cDest = new char[strlen(cSrc)];
    if (cDest != NULL)
    {
        strcpy(cDest, cSrc);
    }
    return cDest;
}

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
bool Singly_CircularLL::DisplayList()
{
    if (Head == NULL && NULL == Tail)
    {
        printf("Linked List is NULL\n");
        return false;
    }
    printf("->");
    PNODE nTemp = Head;
    do
    {
        printf("%s->", nTemp->sData);
        nTemp = nTemp->npNext;
    } while (nTemp != Tail->npNext);
    printf("\n\n");
    return true;
}// end of DisplayList

////////////////////////////////////////////////////////////
//
//  Name        :CountEls
//  Input       :void
//  Returns     :int
//  Description :Displays elements in linked list
//  Author      :Pranav Choudhary
//  Date        :31 Aug 2020
//
////////////////////////////////////////////////////////////
int Singly_CircularLL::CountEls()
{
    return iCount;
}// end of CountEls

////////////////////////////////////////////////////////////
//
//  Name        :InsertFirst
//  Input       : char*
//  Returns     :bool
//  Description :Insert element at first position
//  Author      :Pranav Choudhary
//  Date        :31 Aug 2020
//
////////////////////////////////////////////////////////////
bool Singly_CircularLL::InsertFirst( char* cStr)
{
    PNODE NewN = new NODE;
    if (NULL == NewN)
    {
        printf("Memory Allocation Failed");
        return false;
    }

    NewN->sData = StrDup(cStr);
    NewN->npNext = NULL;

    /* If Linked List is empty */
    if (Head == NULL && Tail == NULL)
    {
        Head = NewN;
        Tail = NewN;
    }
    else
    {
        NewN->npNext = Head;
        Head = NewN;
    }
    Tail->npNext = Head;
    iCount++;
    return true;

}// End of InsertFirst

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
bool Singly_CircularLL::InsertLast( char* cStr)
{
    PNODE NewN = new NODE;
    if (NULL == NewN)
    {
        printf("Memory Allocation Failed");
        return false;
    }

    NewN->sData = StrDup(cStr);
    NewN->npNext = NULL;

    /* if linked list is not empty */
    if (Head == NULL && Tail == NULL)
    {
        Head = NewN;
        Tail = NewN;
    }
    else
    {
        Tail->npNext = NewN;
        Tail = Tail->npNext;
    }
    Tail->npNext = Head;
    iCount++;
    return true;
}// End of InsertLast

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
bool Singly_CircularLL::InsertAtPos( char* cStr, int iPos)
{
    if (iPos > iCount + 1 || iPos < 1)
    {
        printf("Invalid Position Entered\n");
        return false;
    }
    else if (iPos == 1)
    {
        return InsertFirst(cStr);
    }
    else if (iPos == iCount + 1)
    {
        return InsertLast(cStr);
    }
    else
    {
        PNODE NewN = NULL;
        PNODE nTemp = Head;
        int i = 0;
        NewN = new NODE;
        if (NULL == NewN)
        {
            printf("Memory Allocation Failed");
            return false;
        }

        NewN->sData = StrDup(cStr);
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
//  Name        :DeleteFirst
//  Input       :void
//  Returns     :bool
//  Description :Deletes element at first position
//  Author      :Pranav Choudhary
//  Date        :31 Aug 2020
//
////////////////////////////////////////////////////////////
bool Singly_CircularLL::DeleteFirst()
{
    if (NULL == Head && NULL == Tail)
    {
        printf("Linked List is already empty\n");
        return false;
    }
    else if(Head == Tail)
    {
        delete Head;
        Head = NULL;
        Tail = NULL;
    }
    else
    {
        Head = Head->npNext;
        delete Tail->npNext;
        Tail->npNext = Head;
    }
    iCount--;
    return true;
}// End of DeleteFirst

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
bool Singly_CircularLL::DeleteLast()
{
    if (NULL == Head && NULL == Tail)
    {
        printf("Linked List is already empty\n");
        return false;
    }
    else if (Head == Tail)
    {
        delete Head;
        Head = NULL;
        Tail = NULL;
    }
    else
    {
        PNODE nTemp = Head;
        while (nTemp->npNext != Tail)
        {
            nTemp = nTemp->npNext;
        }
        delete Tail;
        Tail = nTemp;
        Tail->npNext = Head;
    }
    iCount--;
    return true;

}// End of DeleteLast

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
bool Singly_CircularLL::DeleteAtPos(int iPos)
{
    if (iPos > iCount || iPos < 1 || NULL == Head || NULL == Tail)
    {
        printf("Invalid Position Entered or Linked list is empty\n");
        return false;
    }
    else if (iPos == 1)
    {
        return DeleteFirst();
    }
    else if (iPos == iCount)
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
int main(int argc, char **argv)
{
    printf("\n----------Singly Circular Linked List----------\n\n");
    int iRet = 0;
    char s[10] = {'\0'};

    Singly_CircularLL scllObj;
    cout << "Enter the string:\n";
    scanf("%s", s);
    getchar();
    
    scllObj.InsertFirst(argv[1]);
    scllObj.InsertFirst(argv[2]);
    scllObj.InsertFirst(argv[3]);

    printf("Linked List:InsertFirst\n");
    scllObj.DisplayList();

    scllObj.InsertLast(argv[4]);
    scllObj.InsertLast(argv[5]);
    scllObj.InsertLast(argv[6]);

    printf("Linked List:InsertLast\n");
    scllObj.DisplayList();

    scllObj.InsertAtPos(s, 4);

    printf("Linked List:InsertAtPos\n");
    scllObj.DisplayList();

    scllObj.DeleteFirst();
    printf("Linked List:DeleteFirst\n");
    scllObj.DisplayList();

    scllObj.DeleteLast();
    printf("Linked List:DeleteLast\n");
    scllObj.DisplayList();

    scllObj.DeleteAtPos(3);
    printf("Linked List:DeleteAtPos\n");
    scllObj.DisplayList();

    iRet = scllObj.CountEls();
    printf("Total Elements:\n%d\n", iRet);

    return 0;
 }