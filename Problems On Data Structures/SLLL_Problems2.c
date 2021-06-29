/*
*   Implementaion of Singly Linear Linked List
*/
#include<stdio.h>
#include<stdlib.h>

// structure of node of linked list
typedef struct node
{
    int             iData;
    struct node     *npNext;
} NODE, *PNODE, **PPNODE;

// global declarations
void InsertLast(PPNODE, int);
void DisplayList(PNODE);
void Deallocate(PPNODE);
void PerfectNums(PNODE);
void PrimeNums(PNODE);
int  SecMaximum(PNODE);
int  SecMinimum(PNODE);
void SumDigits(PNODE);

// Entry point
int main()
{
    printf("\n----------Singly Linear Linked List Problems 1----------\n\n");
    PNODE Head = NULL;
    int iRet = 0, i = 0, iNo = 0, iNum = 0;

    printf("Enter Number of elements\n");
    scanf("%d", &iNo);
    printf("Enter the numbers\n");
    for (i = 1; i <= iNo; i++)
    {
        scanf("%d", &iNum);
        InsertLast(&Head, iNum);
    }
    printf("Linked List:\n");
    DisplayList(Head);

    /* Prints Perfect numbers */
    printf("Perfect Numbers:\n");
    PerfectNums(Head);

    /* Prints Prime numbers */
    printf("Prime Numbers:\n");
    PrimeNums(Head);
    
    /* Prints second maximum number */
    iNo = SecMaximum(Head);
    printf("Second Maximum is:\n%d\n", iNo);

    /* Prints second minimum number */
    iNo = SecMinimum(Head);
    printf("Second Minimum is:\n%d\n", iNo);

    /* Sum of Digits */
    printf("Sum of Digits of entered elements are\n");
    SumDigits(Head);

    /* Deallocates all nodes in linked list */
    Deallocate(&Head);
    return 0;
}

////////////////////////////////////////////////////////////
//
//  Name        :DisplayList
//  Input       :PNODE
//  Returns     :void
//  Description :Displays elements in linked list
//  Author      :Pranav Choudhary
//  Date        :29 Aug 2020
//
////////////////////////////////////////////////////////////
void DisplayList(PNODE First)
{
    if(First == NULL)
    {
        printf("Linked List is NULL\n");
        return;
    }
    while(First != NULL)
    {
        printf("%d->", First->iData);
        First = First->npNext;
    }
    printf("NULL\n\n");
}// end of DisplayList

////////////////////////////////////////////////////////////
//
//  Name        :CountEls
//  Input       :PNODE
//  Returns     :int
//  Description :Displays elements in linked list
//  Author      :Pranav Choudhary
//  Date        :29 Aug 2020
//
////////////////////////////////////////////////////////////
int CountEls(PNODE First)
{
    int iCnt = 0;
    if(First == NULL)
    {
        printf("Linked List is NULL\n");
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
//  Input       :PPNODE
//  Returns     :void
//  Description :Deallocates all nodes in linked list
//  Author      :Pranav Choudhary
//  Date        :29 Aug 2020
//
////////////////////////////////////////////////////////////
void Deallocate(PPNODE First)
{
    if(First == NULL)
    {
        printf("Linked List is NULL\n");
        return;
    }
    
    PNODE nTemp = NULL;
    while(*First != NULL)
    {
        nTemp = *First;
        *First = nTemp->npNext;
        free(nTemp);
    }
}// end of Deallocate

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
void InsertLast(PPNODE First, int iNum)
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

     /* if linked list is not empty */
    if(*First == NULL)
    {
        *First = NewN;
    }
    else
    {
        PNODE nTemp = *First;
        while(nTemp->npNext != NULL)
        {
            nTemp = nTemp->npNext;
        }
        nTemp->npNext = NewN;
    }    
}// End of InsertLast

///////////////////////////////////////////////////////
//
//  Name        :PerfectNums
//  Input       :PNODE
//  Returns     :void
//  Description :Displays Prfect numbers in linked list
//  Author      :Pranav Choudhary
//  Date        :30 Aug 2020
//
///////////////////////////////////////////////////////
void PerfectNums(PNODE First)
{
    if(NULL == First)
    {
        printf("Linked List Is Empty");
        return;
    }
    int i = 0, iTemp = 0, iSum = 0, iFlag = 0; 
    while(First != NULL)
    {
        iTemp = First->iData;
        iSum = 0;
        for (i = 1; i <= iTemp / 2; i++)
        {
            if(iTemp % i == 0)
            {
                iSum = iSum + i;
            }
        }
        if(iSum == iTemp)
        {
            printf("%d ", iTemp);
            iFlag = 1;
        }
        First = First->npNext;
    }
    if(iFlag == 0)
    {
        printf("There are no Perfect numbers in linked list\n");
    }
    else
    {
        printf("\n");
    }
}// end of PerfectNums

///////////////////////////////////////////////////////
//
//  Name        :PrimeNums
//  Input       :PNODE
//  Returns     :void
//  Description :Displays Prime numbers in linked list
//  Author      :Pranav Choudhary
//  Date        :30 Aug 2020
//
///////////////////////////////////////////////////////
void PrimeNums(PNODE First)
{
    if(NULL == First)
    {
        printf("Linked List Is Empty");
        return;
    }
    int i = 0, iTemp = 0, iFlag = 0; 
    while(First != NULL)
    {
        iTemp = First->iData;
        for (i = iTemp / 2; i > 1; i--)
        {
            if(iTemp % i == 0)
            {
                break;
            }
        }
        if(i == 1)
        {
            printf("%d ", iTemp);
            iFlag = 1;
        }
        First = First->npNext;
    }
    if(iFlag == 0)
    {
        printf("There are no Prime numbers in linked list\n");
    }
    else
    {
        printf("\n");
    }    
}// end of PrimeNums

//////////////////////////////////////////////////////////////
//
//  Name        :SecMaximum
//  Input       :PNODE
//  Returns     :int
//  Description :returns second largest element in linked list
//  Author      :Pranav Choudhary
//  Date        :29 Aug 2020
//
//////////////////////////////////////////////////////////////
int SecMaximum(PNODE First)
{
    int iMax1 = 0, iMax2 = 0;
    if(NULL == First)
    {
        printf("Linked list is Empty\n");
        return -1;
    }
    iMax1 = First->iData;
    First = First->npNext;
    while(First != NULL)
    {
        if(iMax1 < First->iData)
        {
            iMax2 = iMax1;
            iMax1 = First->iData;
        }
        else if(iMax2 < First->iData)
        {
            iMax2 = First->iData;
        }
        First = First->npNext;
    }
    return iMax2;
}// end of SecMaximum

//////////////////////////////////////////////////////////////
//
//  Name        :SecMinimum
//  Input       :PNODE
//  Returns     :int
//  Description :returns second smallest element in linked list
//  Author      :Pranav Choudhary
//  Date        :29 Aug 2020
//
//////////////////////////////////////////////////////////////
int SecMinimum(PNODE First)
{
    int iMin1 = 0, iMin2 = 0;
    if(NULL == First)
    {
        printf("Linked list is Empty\n");
        return -1;
    }
    iMin1 = First->iData;
    First = First->npNext;
    while(First != NULL)
    {
        if(iMin1 > First->iData)
        {
            iMin2 = iMin1;
            iMin1 = First->iData;
        }
        else if((iMin1 > iMin2 || iMin2 > First->iData) && iMin1 != iMin2)
        {
            iMin2 = First->iData;
        }
        First = First->npNext;
    }
    return iMin2;
}// end of SecMinimum

//////////////////////////////////////////////////////////////
//
//  Name        :SumDigits
//  Input       :PNODE
//  Returns     :void
//  Description :computes summation of elements digits
//  Author      :Pranav Choudhary
//  Date        :30 Aug 2020
//
//////////////////////////////////////////////////////////////
void SumDigits(PNODE First)
{
    if(NULL == First)
    {
        printf("Linked list is empty\n");
        return;
    }
    int iDigSum = 0, iTemp = 0;

    while(First != NULL)
    {
        iTemp = 0;
        iDigSum = 0;
        iTemp = First->iData;
        while(iTemp != 0)
        {
            iDigSum = iDigSum + iTemp % 10;
            iTemp = iTemp / 10;
        }
        printf("%d ", iDigSum);
        First = First->npNext;
    }
}// end of SumDigits