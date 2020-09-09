/*
*   Implementaion of Singly CIrcular Linked List in C
*/
#include<stdio.h>

#define SUCCESS         0x0000
#define EMPTY           0x1000
#define NOTFOUND        0x0100
#define INVALID_POS     0x0010

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
    int ListCat(Singly_CircularLL &);
    int ListNCat(Singly_CircularLL &, int);
    bool IsPalindrome();
    void ListSortAsc();
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
int Singly_CircularLL::ListCat(Singly_CircularLL &List2)
{
    if(NULL == List2.Head)
    {
        return EMPTY;
    }

    PNODE npTemp1 = this->Tail;
    PNODE npTemp2 = List2.Head;
    
    do
    {
        this->InsertLast(npTemp2->iData);
        npTemp2 = npTemp2->npNext;
    } while (npTemp2 != List2.Tail->npNext);
    return SUCCESS;
}

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
int Singly_CircularLL::ListNCat(Singly_CircularLL &List2, int iN)
{
    if(NULL == List2.Head)
    {
        return EMPTY;
    }
    if(iN > List2.iCount || iN < 1)
    {
        return INVALID_POS;
    }

    PNODE npTemp1 = this->Tail;
    PNODE npTemp2 = List2.Head;
    
    do
    {
        this->InsertLast(npTemp2->iData);
        iN--;
        npTemp2 = npTemp2->npNext;
    } while (npTemp2 != List2.Tail->npNext && iN != 0);
    return SUCCESS;
}

///////////////////////////////////////////////////////////////////////
//
//  Name        :IsPalindrome
//  Input       :void
//  Returns     :bool
//  Description :Checks  whether list is palindrome or not
//  Author      :Pranav Choudhary
//  Date        :9 Sept 2020
//
///////////////////////////////////////////////////////////////////////
bool Singly_CircularLL::IsPalindrome()
{
    if(Head == NULL)
    {
        return false;
    }
    
    int *iArr = new int[iCount];
    int i = 0, j = 0;
    PNODE cTemp = Head;
    
    do
    {
        iArr[i++] = cTemp->iData;
        cTemp = cTemp->npNext;
    } while (cTemp != Tail->npNext);

    i--;
    j = 0;
    while(j < i)
    {
        if(iArr[i] != iArr[j])
        {
            break;
        }
        i--;
        j++;
    }
    if(j >= i)
        return true;
    else
        return false;
}

///////////////////////////////////////////////////////////////////////
//
//  Name        :ListSortAsc
//  Input       :void
//  Returns     :bool
//  Description :Sorts list in ascending order
//  Author      :Pranav Choudhary
//  Date        :9 Sept 2020
//
///////////////////////////////////////////////////////////////////////
void Singly_CircularLL::ListSortAsc()
{
    if(Head == NULL && Head->npNext == NULL)
    {
        printf("List is Empty");
        return;
    }

    PNODE npTemp1 = Head, npTemp2 = Head->npNext, npTemp3 = NULL;

    do
    {
        if(npTemp1->iData > npTemp2->iData)
        {
            if(npTemp1 == Head && npTemp2 == Head->npNext)
            {
                npTemp1->npNext = npTemp2->npNext;
                npTemp2->npNext = Head;
                Head = npTemp2;
                Tail->npNext = Head;
            }
            else
            {
                npTemp3 = Head;
                while(npTemp3->npNext != npTemp1)
                {
                    npTemp3 = npTemp3->npNext;
                }
                npTemp3->npNext = npTemp2;
                npTemp1->npNext = npTemp2->npNext;
                npTemp2->npNext = npTemp1;
            }
            npTemp1 = Head;
            npTemp2 = npTemp1->npNext;
        }
        else
        {
            npTemp1 = npTemp1->npNext;
            npTemp2 = npTemp1->npNext;
        }
    } while (npTemp2 != Head);
    Tail = npTemp1;
}


// Entry point
int main()
{
    printf("\n----------Singly Circular Linked List Problems 1----------\n\n");
    int iRet = 0, iNum = 0;
    bool bRet = false;
    Singly_CircularLL scllObj, scllObj1;
   
    /* List 1 */
    printf("-------------------------------------------------------------\n");
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

    /* List 2
    printf("-------------------------------------------------------------\n");
    printf("Enter elements [\'0\' to stop entering input]\n");
    while(true)
    {
        scanf("%d", &iNum);
        if(iNum == 0)
        {
            break;
        }
        scllObj1.InsertLast(iNum);
    }
    printf("Linked list:\n");
    scllObj1.DisplayList();

    iRet = scllObj1.CountEls();
    printf("Total Elements:\n%d\n", iRet);


    /* Occurances : Find  total occurance of iNum in list
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

    /* FirstOccur : Find first occurance of iNum in list
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
    

    /* LastOccur : Find last occurance of iNum in list
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

    /* SecOccur : Find second occurance of iNum in list
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

    /* SecLastOccur : Find  last occurance of iNum in list 
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

    
    /* ListCat:concats list2 at end of list1
    printf("-------------------------------------------------------------\n");
    iRet = scllObj.ListCat(scllObj1);
    if(iRet == EMPTY)
    {
        printf("list is empty\n");
    }
    else if(iRet == SUCCESS)
    {
        printf("List Concatinated:\n");
        scllObj.DisplayList();
        printf("Total Elements:\n%d\n", scllObj.CountEls());
    }

    /* ListNCat : Concats first N elements from List2 
    printf("-------------------------------------------------------------\n");
    printf("Enter number of elements to concat\t\t:");
    scanf("%d", &iNum);
    iRet = scllObj.ListNCat(scllObj1, iNum);
    if(iRet == EMPTY)
    {
        printf("list is empty\n");
    }
    else if(iRet == INVALID_POS)
    {
        printf("Invalid number entered[enter number upto size of List 2]\n");
    }
    else if(iRet == SUCCESS)
    {
        printf("List Concatinated:\n");
        scllObj.DisplayList();
        printf("Total Elements:\n%d\n", scllObj.CountEls());
    }

    /* IsPalindrome : Checks whether List is palindrome or not
    printf("-------------------------------------------------------------\n");
    bRet = scllObj.IsPalindrome();
    if(bRet == false)
    {
        printf("List is Not Palindrome\n");
    }
    else
    {
        printf("List is Palindrome\n");
    }

    /* ListSortAsc:Sorts list in ascending order */
    printf("------------------------------------------------------\n");
    printf("Linked In Sorted order\n");
    scllObj.ListSortAsc();
    scllObj.DisplayList();
    printf("Total Elements List 1\t:%d\n", scllObj.CountEls());

    printf("-------------------------------------------------------------\n");
    return 0;
 }
