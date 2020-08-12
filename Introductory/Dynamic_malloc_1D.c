/*
*   Program to create one dimensional array using dynamic memory allocation
*   using library function malloc() and free()
*/
#include<stdio.h>
#include<stdlib.h>

void OneDimensional(int);

int main()
{
    int iNum = 0;
    printf("%d", sizeof(&iNum));
    printf("Enter number of elements\n");
    scanf("%d", &iNum);
    OneDimensional(iNum);
    return 0;
}
///////////////////////////////////////////////////////////////////
//
//  Name        :OneDimensional
//  Input       :int
//  Returns     :void
//  Description :Creates OneDimensional array, uses it, deallocate
//               it
//  Author      :Pranav P. Choudhary
//  Date        :13 August 2020
//
//////////////////////////////////////////////////////////////////
void OneDimensional(
                        int iNum    // Max Elements
                    )
{
    if(iNum == 0)
        return;
    int *iArr = NULL, i = 0;
    if(iNum < 0)
        iNum = -iNum;

    // allocation
    iArr = (int *)malloc(sizeof(int) * iNum);
    if(NULL == iArr)
    {
        printf("Memory Allocation Failed!\n");
        return;
    }
    // use
    printf("Enter the elements\n");
    for (i = 0; i < iNum; i++)
    {
        scanf("%d", &iArr[i]);
    }
    printf("Enterd Elements are\n");
    for (i = 0; i < iNum; i++)
    {
        printf("%d\n", iArr[i]);
    }

    // deallocation
    free(iArr);    
    /*  frees memory whose base address is stored in p and how many bytes to free
    *   is stored in UsedList on memory data structure
    */
}