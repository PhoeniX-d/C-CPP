/*
*   Program to create one dimensional array using dynamic memory allocation
*   using library function realloc()
*/
#include<stdio.h>
#include<stdlib.h>

void OneDimensional(int);
void TwoDimensional(int, int);
void ThreeDimensional(int, int, int);
void FourDimensional(int, int, int, int);
void FiveDimensional(int, int, int, int, int);
void SixDimensional(int, int, int, int, int, int);
void SevenDimensional(int, int, int, int, int, int, int);

int main()
{
    int ch = 0;
    int iFirst = 0, iSecond = 0, iThird = 0, iFourth = 0, iFifth = 0, iSixth = 0, iSeventh = 0;
    
    printf("Enter Choice 1-7\n");
    printf("1.OneDimensional\n");
    printf("2.TwoDimensional\n");
    printf("3.ThreeDimensional\n");
    printf("4.FourDimensional\n");
    printf("5.FiveDimensional\n");
    printf("6.SixDimensional\n");
    printf("7.SevenDimensional\n");
    scanf("%d", &ch);
    switch(ch)
    {
        case 1 :    printf("Enter number of elements\n");
                    scanf("%d", &iFirst);
                    OneDimensional(iFirst);
                    break;

        case 2 :    printf("Enter the number of rows and columns\n");
                    scanf("%d%d", &iFirst, &iSecond);
                    TwoDimensional(iFirst, iSecond);
                    break;

        case 3 :    printf("Enter size for 3D array\n");
                    scanf("%d%d%d", &iFirst, &iSecond, &iThird);
                    ThreeDimensional(iFirst, iSecond, iThird);
                    break;

        case 4 :    printf("Enter size for 4D array\n");
                    scanf("%d%d%d%d", &iFirst, &iSecond, &iThird, &iFourth);
                    FourDimensional(iFirst, iSecond, iThird, iFourth);
                    break;

        case 5 :    printf("Enter size for 5D array\n");
                    scanf("%d%d%d%d%d", &iFirst, &iSecond, &iThird, &iFourth, &iFifth);
                    FiveDimensional(iFirst, iSecond, iThird, iFourth, iFifth);
                    break;

        case 6 :    printf("Enter size for 6D array\n");
                    scanf("%d%d%d%d%d%d", &iFirst, &iSecond, &iThird, &iFourth, &iFifth, &iSixth);
                    SixDimensional(iFirst, iSecond, iThird, iFourth, iFifth, iSixth);
                    break;

        case 7 :    printf("Enter size for 7D array\n");
                    scanf("%d%d%d%d%d%d%d", &iFirst, &iSecond, &iThird, &iFourth, &iFifth, &iSixth, &iSeventh);
                    SevenDimensional(iFirst, iSecond, iThird, iFourth, iFifth, iSixth, iSeventh);
                    break;
        default:
            printf("Enter Valid option\n");
    }
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
                        int iFirst    // Max Elements
                    )
{
    if(iFirst == 0)
        return;
    int *iArr = NULL, i = 0;
    if(iFirst < 0)
        iFirst = -iFirst;

    // allocation
    iArr = (int *)realloc(NULL, sizeof(int) * iFirst);
    if(NULL == iArr)
    {
        printf("Memory Allocation Failed!\n");
        return;
    }
    // use
    printf("Enter the elements\n");
    for (i = 0; i < iFirst; i++)
    {
        scanf("%d", &iArr[i]);
    }
    printf("Enterd Elements are\n");
    for (i = 0; i < iFirst; i++)
    {
        printf("%d ", iArr[i]);
    }
    printf("\n");
    // deallocation
    realloc(iArr, 0);    
    /*  reallocs memory whose base address is stored in p and how many bytes to realloc
    *   is stored in UsedList on memory data structure
    */
}

///////////////////////////////////////////////////////////////////
//
//  Name        :TwoDimensional
//  Input       :int, int
//  Returns     :void
//  Description :Creates TwoDimensional array, uses it, deallocate
//               it
//  Author      :Pranav P. Choudhary
//  Date        :13 August 2020
//
//////////////////////////////////////////////////////////////////
void TwoDimensional(
                        int iFirst,
                        int iSecond    
                    )
{
    if(iFirst == 0 || iSecond == 0)
        return;

    int **iArr = NULL, i = 0, j = 0;
    if(iFirst < 0)
        iFirst = -iFirst;
    if(iSecond < 0)
        iSecond = -iSecond;

    // allocation
    iArr = (int **)realloc(NULL, sizeof(int*) * iFirst);
    if(NULL == iArr)
    {
        printf("Memory Allocation Failed!\n");
        return;
    }

    for (i = 0; i < iFirst; i++)
    {
        if((iArr[i] = (int *)realloc(NULL, iSecond * sizeof(int))) == NULL)
        {
            printf("Memory Allocation Failed\n");
            return;
        }
    }

    // use
    for (i = 0; i < iFirst; i++)
    {
        for (j = 0; j < iSecond; j++)
        {
            //scanf("%d", &iArr[i][j]);
            iArr[i][j] = 9;
        }
    }

    printf("Elements are\n\n");
    for (i = 0; i < iFirst; i++)
    {
        for (j = 0; j < iSecond; j++)
        {
            printf("%d ", iArr[i][j]);
        }
        printf("\n");
    }

    // deallocation
    for (i = 0; i < iFirst; i++)
    {
        realloc(iArr[i], 0);
    }
    realloc(iArr, 0);
}

///////////////////////////////////////////////////////////////////
//
//  Name        :ThreeDimensional
//  Input       :int, int, int
//  Returns     :void
//  Description :Creates ThreeDimensional array, uses it, deallocate
//               it
//  Author      :Pranav P. Choudhary
//  Date        :13 August 2020
//
//////////////////////////////////////////////////////////////////
void ThreeDimensional(
                            int iFirst,
                            int iSecond,
                            int iThird
                        )
{
    if(iFirst == 0 || iSecond == 0 || iThird == 0)
        return;
    if(iFirst < 0)
        iFirst = -iFirst;
    if(iSecond < 0)
        iSecond = -iSecond;
    if(iThird < 0)
        iThird = -iThird;

    int ***iArr = NULL, i = 0, j = 0, k = 0;
    
    // allocation
    iArr = (int ***)realloc(NULL, iFirst * sizeof(int **));
    for (i = 0; i < iFirst; i++)
    {
        iArr[i] = (int **)realloc(NULL, iSecond * sizeof(int *));
        for (j = 0; j < iSecond; j++)
        {
            iArr[i][j] = (int *)realloc(NULL, iThird * sizeof(int));
        }
    }

    // use
    for (i = 0; i < iFirst; i++)
    {
        for (j = 0; j < iSecond; j++)
        {
            for (k = 0; k < iThird; k++)
            {
                iArr[i][j][k] = 9;
            }
        }
    }
    
    printf("Elements are\n\n");
    for (i = 0; i < iFirst; i++)
    {
        for (j = 0; j < iSecond; j++)
        {
            for (k = 0; k < iThird; k++)
            {
                printf("%d ", iArr[i][j][k]);
            }
            printf("\n");
        }
        printf("\n");
    }

    // deallocation
    for (i = 0; i < iFirst; i++)
    {
        for (j = 0; j < iSecond; j++)
        {
            realloc(iArr[i][j], 0);
        }
        realloc(iArr[i], 0);
    }
    realloc(iArr, 0);
}
///////////////////////////////////////////////////////////////////
//
//  Name        :FourDimensional
//  Input       :int, int, int, int
//  Returns     :void
//  Description :Creates FourDimensional array, uses it, deallocate
//               it
//  Author      :Pranav P. Choudhary
//  Date        :13 August 2020
//
//////////////////////////////////////////////////////////////////
void FourDimensional(
                            int iFirst,
                            int iSecond,
                            int iThird,
                            int iFourth
                        )
{
    if(iFirst == 0 || iSecond == 0 || iThird == 0 || iFourth == 0)
        return;
    if(iFirst < 0)
        iFirst = -iFirst;
    if(iSecond < 0)
        iSecond = -iSecond;
    if(iThird < 0)
        iThird = -iThird;
    if(iFourth < 0)
        iFourth = -iFourth;

    int ****iArr = NULL, i = 0, j = 0, k = 0, l = 0;
    
    // allocation
    iArr = (int ****)realloc(NULL, iFirst * sizeof(int ***));
    for (i = 0; i < iFirst; i++)
    {
        iArr[i] = (int ***)realloc(NULL, iSecond * sizeof(int **));
        for (j = 0; j < iSecond; j++)
        {
            iArr[i][j] = (int **)realloc(NULL, iThird * sizeof(int *));
            for(k = 0; k < iThird; k++)
            {
                iArr[i][j][k] = (int *)realloc(NULL, iFourth * sizeof(int));
            }
        }
    }

    // use
    for (i = 0; i < iFirst; i++)
    {
        for (j = 0; j < iSecond; j++)
        {
            for (k = 0; k < iThird; k++)
            {
                for (l = 0; l < iFourth; l++)
                {
                    iArr[i][j][k][l] = 9;
                }
            }
        }
    }
    
    printf("Elements are\n\n");
    for (i = 0; i < iFirst; i++)
    {
        for (j = 0; j < iSecond; j++)
        {
            for (k = 0; k < iThird; k++)
            {
                for (l = 0; l < iFourth; l++)
                {
                    printf("%d ", iArr[i][j][k][l]);
                }
                printf("\n");
            }
            printf("\n");
        }
        printf("\n");
    }

    // deallocation
    for (i = 0; i < iFirst; i++)
    {
        for (j = 0; j < iSecond; j++)
        {
            for (k = 0; k < iThird; k++)
            {
                realloc(iArr[i][j][k], 0);
            }
            realloc(iArr[i][j], 0);
        }
        realloc(iArr[i], 0);
    }
    realloc(iArr, 0);
}

///////////////////////////////////////////////////////////////////
//
//  Name        :FiveDimensional
//  Input       :int, int, int, int, int
//  Returns     :void
//  Description :Creates FiveDimensional array, uses it, deallocate
//               it
//  Author      :Pranav P. Choudhary
//  Date        :13 August 2020
//
//////////////////////////////////////////////////////////////////
void FiveDimensional(
                            int iFirst,
                            int iSecond,
                            int iThird,
                            int iFourth,
                            int iFifth
                        )
{
    if(iFirst == 0 || iSecond == 0 || iThird == 0 || iFourth == 0 || iFifth == 0)
        return;
    if(iFirst < 0)
        iFirst = -iFirst;
    if(iSecond < 0)
        iSecond = -iSecond;
    if(iThird < 0)
        iThird = -iThird;
    if(iFourth < 0)
        iFourth = -iFourth;
    if(iFifth < 0)
        iFifth = -iFifth;

    int *****iArr = NULL, i = 0, j = 0, k = 0, l = 0, m = 0;
    
    // allocation
    iArr = (int *****)realloc(NULL, iFirst * sizeof(int ****));
    for (i = 0; i < iFirst; i++)
    {
        iArr[i] = (int ****)realloc(NULL, iSecond * sizeof(int ***));
        for (j = 0; j < iSecond; j++)
        {
            iArr[i][j] = (int ***)realloc(NULL, iThird * sizeof(int **));
            for(k = 0; k < iThird; k++)
            {
                iArr[i][j][k] = (int **)realloc(NULL, iFourth * sizeof(int*));
                for (l = 0; l < iFourth; l++)
                {
                    iArr[i][j][k][l] = (int *)realloc(NULL, sizeof(int) * iFifth);
                }
            }
        }
    }

    // use
    for (i = 0; i < iFirst; i++)
    {
        for (j = 0; j < iSecond; j++)
        {
            for (k = 0; k < iThird; k++)
            {
                for (l = 0; l < iFourth; l++)
                {
                    for (m = 0; m < iFifth; m++)
                    {
                        iArr[i][j][k][l][m] = 9;
                    }
                }
            }
        }
    }
    
    printf("Elements are\n\n");
    for (i = 0; i < iFirst; i++)
    {
        for (j = 0; j < iSecond; j++)
        {
            for (k = 0; k < iThird; k++)
            {
                for (l = 0; l < iFourth; l++)
                {
                    for (m = 0; m < iFifth; m++)
                    {
                        printf("%d ", iArr[i][j][k][l][m]);
                    }
                    printf("\n");
                }
                printf("\n");
            }
            printf("\n");
        }
    }

    // deallocation
    for (i = 0; i < iFirst; i++)
    {
        for (j = 0; j < iSecond; j++)
        {
            for (k = 0; k < iThird; k++)
            {
                for (l = 0; l < iFourth; l++)
                {
                    realloc(iArr[i][j][k][l], 0);
                }
                realloc(iArr[i][j][k], 0);
            }
            realloc(iArr[i][j], 0);
        }
        realloc(iArr[i], 0);
    }
    realloc(iArr, 0);
}

///////////////////////////////////////////////////////////////////
//
//  Name        :SixDimensional
//  Input       :int, int, int, int, int
//  Returns     :void
//  Description :Creates FiveDimensional array, uses it, deallocate
//               it
//  Author      :Pranav P. Choudhary
//  Date        :13 August 2020
//
//////////////////////////////////////////////////////////////////
void SixDimensional(
                            int iFirst,
                            int iSecond,
                            int iThird,
                            int iFourth,
                            int iFifth,
                            int iSixth
                        )
{
    if(iFirst == 0 || iSecond == 0 || iThird == 0 || iFourth == 0 || iFifth == 0 || iSixth == 0)
        return;
    if(iFirst < 0)
        iFirst = -iFirst;
    if(iSecond < 0)
        iSecond = -iSecond;
    if(iThird < 0)
        iThird = -iThird;
    if(iFourth < 0)
        iFourth = -iFourth;
    if(iFifth < 0)
        iFifth = -iFifth;
    if(iSixth < 0)
        iSixth = -iSixth;

    int ******iArr = NULL, i = 0, j = 0, k = 0, l = 0, m = 0, n = 0;
    
    // allocation
    iArr = (int ******)realloc(NULL, iFirst * sizeof(int *****));
    for (i = 0; i < iFirst; i++)
    {
        iArr[i] = (int *****)realloc(NULL, iSecond * sizeof(int ****));
        for (j = 0; j < iSecond; j++)
        {
            iArr[i][j] = (int ****)realloc(NULL, iThird * sizeof(int ***));
            for(k = 0; k < iThird; k++)
            {
                iArr[i][j][k] = (int ***)realloc(NULL, iFourth * sizeof(int **));
                for (l = 0; l < iFourth; l++)
                {
                    iArr[i][j][k][l] = (int **)realloc(NULL, sizeof(int *) * iFifth);
                    for (m = 0; m < iFifth; m++)
                    {
                        iArr[i][j][k][l][m] = (int *)realloc(NULL, iSixth * sizeof(int));
                    }
                }
            }
        }
    }

    // use
    for (i = 0; i < iFirst; i++)
    {
        for (j = 0; j < iSecond; j++)
        {
            for (k = 0; k < iThird; k++)
            {
                for (l = 0; l < iFourth; l++)
                {
                    for (m = 0; m < iFifth; m++)
                    {
                        for (n = 0; n < iSixth; n++)
                        {
                            iArr[i][j][k][l][m][n] = 9;
                        }
                    }
                }
            }
        }
    }
    
    printf("Elements are\n\n");
    for (i = 0; i < iFirst; i++)
    {
        for (j = 0; j < iSecond; j++)
        {
            for (k = 0; k < iThird; k++)
            {
                for (l = 0; l < iFourth; l++)
                {
                    for (m = 0; m < iFifth; m++)
                    {
                        for (n = 0; n < iSixth; n++)
                        {
                            printf("%d ", iArr[i][j][k][l][m][n]);
                        }
                        printf("\n");
                    }
                    printf("\n");
                }
                printf("\n");
            }
            printf("\n");
        }
    }

    // deallocation
    for (i = 0; i < iFirst; i++)
    {
        for (j = 0; j < iSecond; j++)
        {
            for (k = 0; k < iThird; k++)
            {
                for (l = 0; l < iFourth; l++)
                {
                    for (m = 0; m < iFifth; m++)
                    {
                        realloc(iArr[i][j][k][l][m], 0);
                    }
                    realloc(iArr[i][j][k][l], 0);
                }
                realloc(iArr[i][j][k], 0);
            }
            realloc(iArr[i][j], 0);
        }
        realloc(iArr[i], 0);
    }
    realloc(iArr, 0);
}

///////////////////////////////////////////////////////////////////
//
//  Name        :SevenDimensional
//  Input       :int, int, int, int, int, int, int
//  Returns     :void
//  Description :Creates SevenDimensional array, uses it, deallocate
//               it
//  Author      :Pranav P. Choudhary
//  Date        :13 August 2020
//
//////////////////////////////////////////////////////////////////
void SevenDimensional(
                            int iFirst,
                            int iSecond,
                            int iThird,
                            int iFourth,
                            int iFifth,
                            int iSixth,
                            int iSeventh
                        )
{
    if(iFirst == 0 || iSecond == 0 || iThird == 0 || iFourth == 0 || iFifth == 0 || iSixth == 0 || iSeventh == 0)
        return;
    if(iFirst < 0)
        iFirst = -iFirst;
    if(iSecond < 0)
        iSecond = -iSecond;
    if(iThird < 0)
        iThird = -iThird;
    if(iFourth < 0)
        iFourth = -iFourth;
    if(iFifth < 0)
        iFifth = -iFifth;
    if(iSixth < 0)
        iSixth = -iSixth;
    if(iSeventh < 0)
        iSeventh = -iSeventh;

    int *******iArr = NULL, i = 0, j = 0, k = 0, l = 0, m = 0, n = 0, a = 0;
    
    // allocation
    iArr = (int *******)realloc(NULL, iFirst * sizeof(int ******));
    for (i = 0; i < iFirst; i++)
    {
        iArr[i] = (int ******)realloc(NULL, iSecond * sizeof(int *****));
        for (j = 0; j < iSecond; j++)
        {
            iArr[i][j] = (int *****)realloc(NULL, iThird * sizeof(int ****));
            for(k = 0; k < iThird; k++)
            {
                iArr[i][j][k] = (int ****)realloc(NULL, iFourth * sizeof(int ***));
                for (l = 0; l < iFourth; l++)
                {
                    iArr[i][j][k][l] = (int ***)realloc(NULL, sizeof(int **) * iFifth);
                    for (m = 0; m < iFifth; m++)
                    {
                        iArr[i][j][k][l][m] = (int **)realloc(NULL, iSixth * sizeof(int *));
                        for (n = 0; n < iSixth; n++)
                        {
                            iArr[i][j][k][l][m][n] = (int *)realloc(NULL, iSeventh * sizeof(int));
                        }
                    }
                }
            }
        }
    }

    // use
    for (i = 0; i < iFirst; i++)
    {
        for (j = 0; j < iSecond; j++)
        {
            for (k = 0; k < iThird; k++)
            {
                for (l = 0; l < iFourth; l++)
                {
                    for (m = 0; m < iFifth; m++)
                    {
                        for (n = 0; n < iSixth; n++)
                        {
                            for (a = 0; a < iSeventh; a++)
                            {
                                iArr[i][j][k][l][m][n][a] = 9;
                            }
                        }
                    }
                }
            }
        }
    }
    
    printf("Elements are\n\n");
    for (i = 0; i < iFirst; i++)
    {
        for (j = 0; j < iSecond; j++)
        {
            for (k = 0; k < iThird; k++)
            {
                for (l = 0; l < iFourth; l++)
                {
                    for (m = 0; m < iFifth; m++)
                    {
                        for (n = 0; n < iSixth; n++)
                        {
                            for (a = 0; a < iSeventh; a++)
                            {
                                printf("%d ", iArr[i][j][k][l][m][n][a]);
                            }
                            printf("\n");
                        }
                        printf("\n");
                    }
                    printf("\n");
                }
                printf("\n");
            }
            printf("\n");
        }
    }

    // deallocation
    for (i = 0; i < iFirst; i++)
    {
        for (j = 0; j < iSecond; j++)
        {
            for (k = 0; k < iThird; k++)
            {
                for (l = 0; l < iFourth; l++)
                {
                    for (m = 0; m < iFifth; m++)
                    {
                        for (n = 0; n < iSixth; n++)
                        {
                            realloc(iArr[i][j][k][l][m][n], 0);
                        }
                        realloc(iArr[i][j][k][l][m], 0);
                    }
                    realloc(iArr[i][j][k][l], 0);
                }
                realloc(iArr[i][j][k], 0);
            }
            realloc(iArr[i][j], 0);
        }
        realloc(iArr[i], 0);
    }
    realloc(iArr, 0);
}