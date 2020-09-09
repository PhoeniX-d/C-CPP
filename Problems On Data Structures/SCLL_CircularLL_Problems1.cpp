/*
*   Implementaion of Singly CIrcular Linked List in C
*/
#include<stdio.h>
#define EMPTY           0x1000
#define NOTFOUND        0x0100

// structure of node of circular linked list
typedef class Node
{
    public:
    int             iData;
    Node*          npNext;
} NODE, * PNODE;

// class for singly circular linked list
class Singly_CircularLL
{
private:
    PNODE Head;
    PNODE Tail;
    int iCount;

public:
    Singly_CircularLL();        /* constructor to initialize Head and Tail, iCount */
    ~Singly_CircularLL();       /* dealloctes linked list */
    bool DisplayList();         /* display els in list */
    int  CountEls();            /* counts els in list */
    bool InsertLast(int);       /* Insert els at last of list */

    /* Problems */
    int Occurances(int);
    int FirstOccur(int);
    int SecOccur(int);
    int LastOccur(int);
    int SecLastOccur(int);
};

////////////////////////////////////////////////////////////
//
//  Name        :Singly_CircularLL
//  Input       :void
//  Returns     :   -
//  Description :constructor
//  Author      :Pranav Choudhary
//  Date        :9 Sept 2020
//
////////////////////////////////////////////////////////////
Singly_CircularLL::Singly_CircularLL()
{
    Head = NULL;
    Tail = NULL;
    iCount = 0;
}// end of constructor

////////////////////////////////////////////////////////////
//
//  Name        :Singly_CircularLL
//  Input       :void
//  Returns     :   -
//  Description :constructor
//  Author      :Pranav Choudhary
//  Date        :9 Sept 2020
//
////////////////////////////////////////////////////////////
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
            if(Head == Tail)
            {
                delete Head;
                Head = NULL;
                Tail = NULL;
                break;
            }

        }while(Head != Tail);
	}
}// end of Destructor

////////////////////////////////////////////////////////////
//
//  Name        :DisplayList
//  Input       :void
//  Returns     :bool
//  Description :Displays elements in linked list
//  Author      :Pranav Choudhary
//  Date        :9 Sept 2020
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
        printf("%d->", nTemp->iData);
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
//  Date        :9 Sept 2020
//
////////////////////////////////////////////////////////////
int Singly_CircularLL::CountEls()
{
    return iCount;
}// end of CountEls

////////////////////////////////////////////////////////////
//
//  Name        :InsertLast
//  Input       :int
//  Returns     :bool
//  Description :Insert element at last position
//  Author      :Pranav Choudhary
//  Date        :9 Sept 2020
//
////////////////////////////////////////////////////////////
bool Singly_CircularLL::InsertLast(int iNum)
{
    PNODE NewN = new NODE;
    if (NULL == NewN)
    {
        printf("Memory Allocation Failed");
        return false;
    }

    NewN->iData = iNum;
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

/////////////////////////////////////////////////////////////////////
//
//  Name        :Occurances
//  Input       :int
//  Returns     :int
//  Description :Finds total occurance of iNum 
//  Author      :Pranav Choudhary
//  Date        :9 Sept 2020
//
/////////////////////////////////////////////////////////////////////
int Singly_CircularLL::Occurances(int iNum)
{
    if(Head == NULL && Tail == NULL)
    {
        printf("Linked list is empty\n");
        return EMPTY;
    }
    int iCnt = 0;
    PNODE npTemp = Head;
    
    do
    {
        if(npTemp->iData == iNum)
        {
            iCnt++;
        }
        npTemp = npTemp->npNext;
    } while (npTemp != Tail->npNext);
    if(iCnt == 0)
        return NOTFOUND;
    else
        return iCnt;
}// end of Occurances

/////////////////////////////////////////////////////////////////////
//
//  Name        :FirstOccur
//  Input       :int
//  Returns     :int
//  Description :Finds first occurance of el and returns its position
//  Author      :Pranav Choudhary
//  Date        :9 Sept 2020
//
/////////////////////////////////////////////////////////////////////
int Singly_CircularLL::FirstOccur(int iNum)
{
    if(Head == NULL && Tail == NULL)
    {
        printf("Linked list is empty\n");
        return EMPTY;
    }
    int iPos = -1, iCnt = 0;
    PNODE npTemp = Head;
    
    do
    {
        iCnt++;
        if(npTemp->iData == iNum)
        {
            iPos = iCnt;
            break;
        }
        npTemp = npTemp->npNext;
    } while (npTemp != Tail->npNext);
    if(iPos == -1)
        return NOTFOUND;
    else
        return iPos;
}// end of FirstOccur

/////////////////////////////////////////////////////////////////////
//
//  Name        :LastOccur
//  Input       :int
//  Returns     :int
//  Description :Finds last occurance of el and returns its position
//  Author      :Pranav Choudhary
//  Date        :9 Sept 2020
//
/////////////////////////////////////////////////////////////////////
int Singly_CircularLL::LastOccur(int iNum)
{
    if(Head == NULL && Tail == NULL)
    {
        printf("Linked list is empty\n");
        return EMPTY;
    }
    int iPos = -1, iCnt = 0;
    PNODE npTemp = Head;    
    do
    {
        iCnt++;
        if(npTemp->iData == iNum)
        {
            iPos = iCnt;
        }
        npTemp = npTemp->npNext;
    } while (npTemp != Tail->npNext);
    if(iPos == -1)
        return NOTFOUND;
    else
        return iPos;
}// end of LastOccur

///////////////////////////////////////////////////////////////////////
//
//  Name        :SecOccur
//  Input       :int
//  Returns     :int
//  Description :Finds second occurance of el and returns its position
//  Author      :Pranav Choudhary
//  Date        :9 Sept 2020
//
///////////////////////////////////////////////////////////////////////
int Singly_CircularLL::SecOccur(int iNum)
{
    if(Head == NULL && Tail == NULL)
    {
        printf("Linked list is empty\n");
        return EMPTY;
    }
    int iPos = -1, iCnt1 = 0, iCnt2 = 0;
    PNODE npTemp = Head;
    
    do
    {
        iCnt1++;
        if(npTemp->iData == iNum)
        {
            iCnt2++;
            if(iCnt2 < 3)
            {
                iPos = iCnt1;
            }
        }
        npTemp = npTemp->npNext;
    } while (npTemp != Tail->npNext);
    if(iPos == -1)
        return NOTFOUND;
    else
        return iPos;
}// end of SecOccur

///////////////////////////////////////////////////////////////////////////
//
//  Name        :SecLastOccur
//  Input       :int
//  Returns     :int
//  Description :Finds second last occurance of el and returns its position
//  Author      :Pranav Choudhary
//  Date        :9 Sept 2020
//
///////////////////////////////////////////////////////////////////////////
int Singly_CircularLL::SecLastOccur(int iNum)
{
    if(Head == NULL && Tail == NULL)
    {
        printf("Linked list is empty\n");
        return EMPTY;
    }
    int iPos1 = -1, iPos2 = -1, iCnt1 = 0;
    PNODE npTemp = Head;
    
    do
    {
        iCnt1++;
        if(npTemp->iData == iNum)
        {
            iPos2 = iPos1;
            iPos1 = iCnt1;
        }
        npTemp = npTemp->npNext;
    } while (npTemp != Tail->npNext);

    if(iPos1 == -1 && iPos2 == -1)
    {
        return NOTFOUND;
    }
    else if(iPos2 == -1)
    {
        return iPos1;
    }         
    else
    {
        return iPos2;
    }
}// end of SecLastOccur

// Entry point
int main()
{
    printf("\n----------Singly Circular Linked List----------\n\n");
    int iRet = 0, iNum = 0;
    Singly_CircularLL scllObj;

    printf("Enter elements [\'0\' to stop entering input]\n");
    while(true)
    {
        scanf("%d", &iNum);
        if(iNum == 0)
        {
            break;
        }
        scllObj.InsertLast(iNum);
    }
    printf("Linked list:\n");
    scllObj.DisplayList();

    iRet = scllObj.CountEls();
    printf("Total Elements:\n%d\n", iRet);

    /* Occurances : Find  total occurance of iNum in list */
    printf("-------------------------------------------------------------\n");
    printf("Enter number for total occurnces\t\t:");
    scanf("%d", &iNum);
    iRet = scllObj.Occurances(iNum);
    if(iRet == EMPTY)
    {
        printf("list is empty\n");
    }
    else if(iRet == NOTFOUND)
    {
        printf("Element not found\n");
    }
    else
    {
        printf("Total occurances of %d is\t\t\t:%d\n", iNum, iRet);
    }

    /* FirstOccur : Find first occurance of iNum in list */
    printf("-------------------------------------------------------------\n");
    printf("Enter number for first occurance\t\t:");
    scanf("%d", &iNum);
    iRet = scllObj.FirstOccur(iNum);
    if(iRet == EMPTY)
    {
        printf("list is empty\n");
    }
    else if(iRet == NOTFOUND)
    {
        printf("Element not found\n");
    }
    else
    {
        printf("First occurance of %d is at position\t\t:%d\n", iNum, iRet);
    }
    

    /* LastOccur : Find last occurance of iNum in list */
    printf("-------------------------------------------------------------\n");
    printf("Enter number for last occurnce\t\t\t:");
    scanf("%d", &iNum);
    iRet = scllObj.LastOccur(iNum);
    if(iRet == EMPTY)
    {
        printf("list is empty\n");
    }
    else if(iRet == NOTFOUND)
    {
        printf("Element not found\n");
    }
    else
    {
        printf("Last occurance of %d is at position\t\t:%d\n", iNum, iRet);
    }

    /* SecOccur : Find second occurance of iNum in list */
    printf("-------------------------------------------------------------\n");
    printf("Enter number for second occurnce\t\t:");
    scanf("%d", &iNum);
    iRet = scllObj.SecOccur(iNum);
    if(iRet == EMPTY)
    {
        printf("list is empty\n");
    }
    else if(iRet == NOTFOUND)
    {
        printf("Element not found\n");
    }
    else
    {
        printf("Second occurance of %d is at position\t\t:%d\n", iNum, iRet);
    }

    /* SecLastOccur : Find  last occurance of iNum in list */
    printf("-------------------------------------------------------------\n");
    printf("Enter number for second last occurnce\t\t:");
    scanf("%d", &iNum);
    iRet = scllObj.SecLastOccur(iNum);
    if(iRet == EMPTY)
    {
        printf("list is empty\n");
    }
    else if(iRet == NOTFOUND)
    {
        printf("Element not found\n");
    }
    else
    {
        printf("Second last occurance of %d is at position\t:%d\n", iNum, iRet);
    }
    printf("-------------------------------------------------------------\n");
    return 0;
 }
