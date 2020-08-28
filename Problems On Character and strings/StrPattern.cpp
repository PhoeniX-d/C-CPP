/*
*   Program On Strings Patterns
*/

#include<iostream>
#include<stdio.h>

#define MAXLEN      30

using namespace std;

class StrPattern
{
    public:
        void Display1(const char *);
        void Display2(const char *);
        void Display3(const char *);
        void Display4(const char *);
        void Display5(const char *);
};

//////////////////////////////////////////////////
//
//  Name        :Display1
//  Input       :const char*
//  Returns     :void
//  Description :Prints following pattern
//               Input : “Marvellous”
//               Output : M a r v e l l o u s
//                        M a r v e l l o u s
//                        M a r v e l l o u s
//                        M a r v e l l o u s
//                        M a r v e l l o u s
//                        M a r v e l l o u s
//                        M a r v e l l o u s
//                        M a r v e l l o u s
//                        M a r v e l l o u s
//                        M a r v e l l o u s
//  Author      :Pranav Choudhary
//  Date        :28 Aug 2020
//
//////////////////////////////////////////////////
void StrPattern::Display1(const char* cStr)
{
    if(NULL == cStr)
    {
        printf("Invalid Input\n");
        return;
    }

    int iRow = 0, iCol = 0;
    for (iRow = 0; cStr[iRow] != '\0'; iRow++)
    {
        for (iCol = 0; cStr[iCol] != '\0'; iCol++)
        {
            cout << cStr[iCol] << " ";
        }
        cout << endl;
    }
}

//////////////////////////////////////////////////
//
//  Name        :Display2
//  Input       :const char*
//  Returns     :void
//  Description :Prints following pattern
//               Input : “Marvellous”
//               Output : M a r v e l l o u s
//                        M a r v e l l o u
//                        M a r v e l l o
//                        M a r v e l l
//                        M a r v e l
//                        M a r v e
//                        M a r v
//                        M a r
//                        M a
//                        M
//  Author      :Pranav Choudhary
//  Date        :28 Aug 2020
//
//////////////////////////////////////////////////
void StrPattern::Display2(const char* cStr)
{
    if(NULL == cStr)
    {
        printf("Invalid Input\n");
        return;
    }

    int iLen = strlen(cStr) - 1, iRow = 0, iCol = 0;
    for (iRow = 0; iRow <= iLen; iRow++)
    {
        for (iCol = 0; iCol <= iLen - iRow; iCol++)
        {
            cout << cStr[iCol] << " ";
        }
        cout << endl;
    }
}

//////////////////////////////////////////////////
//
//  Name        :Display3
//  Input       :const char*
//  Returns     :void
//  Description :Prints following pattern
//               Input : “Marvellous”
//               Output : M
//                        M a
//                        M a r
//                        M a r v
//                        M a r v e
//                        M a r v e l
//                        M a r v e l l
//                        M a r v e l l o
//                        M a r v e l l o u
//                        M a r v e l l o u s
//  Author      :Pranav Choudhary
//  Date        :28 Aug 2020
//
//////////////////////////////////////////////////
void StrPattern::Display3(const char* cStr)
{
    if(NULL == cStr)
    {
        printf("Invalid Input\n");
        return;
    }

   int iLen = strlen(cStr) - 1, iRow = 0, iCol = 0;
    for (iRow = 0; iRow <= iLen; iRow++)
    {
        for (iCol = 0; iCol <= iRow; iCol++)
        {
            cout << cStr[iCol] << " ";
        }
        cout << endl;
    }
}

//////////////////////////////////////////////////
//
//  Name        :Display4
//  Input       :const char*
//  Returns     :void
//  Description :Prints following pattern
//               Input : “Marvellous”
//               Output : M A R V E L L O U S
//                        M A R V E L L O U S
//                        M A R V E L L O U S
//                        M A R V E L L O U S
//                        M A R V E L L O U S
//                        M A R V E L L O U S
//                        M A R V E L L O U S
//                        M A R V E L L O U S
//                        M A R V E L L O U S
//                        M A R V E L L O U S
//  Author      :Pranav Choudhary
//  Date        :28 Aug 2020
//
//////////////////////////////////////////////////
void StrPattern::Display4(const char* cStr)
{
    if(NULL == cStr)
    {
        printf("Invalid Input\n");
        return;
    }

    int iRow = 0, iCol = 0;
    for (iRow = 0; cStr[iRow] != '\0'; iRow++)
    {
        for (iCol = 0; cStr[iCol] != '\0'; iCol++)
        {
            if(cStr[iCol] >= 'a' && cStr[iCol] <= 'z')
                printf("%c ", cStr[iCol] - 32);
            else 
                printf("%c ", cStr[iCol]);
        }
        cout << endl;
    }
}

//////////////////////////////////////////////////
//
//  Name        :Display5
//  Input       :const char*
//  Returns     :void
//  Description :Prints following pattern
//               Input : “Marvellous”
//               Output : m a r v e l l o u s
//                        m a r v e l l o u s                        
//                        m a r v e l l o u s                        
//                        m a r v e l l o u s                        
//                        m a r v e l l o u s                        
//                        m a r v e l l o u s                        
//                        m a r v e l l o u s                        
//                        m a r v e l l o u s                        
//                        m a r v e l l o u s
//  Author      :Pranav Choudhary
//  Date        :28 Aug 2020
//
//////////////////////////////////////////////////
void StrPattern::Display5(const char* cStr)
{
    if(NULL == cStr)
    {
        printf("Invalid Input\n");
        return;
    }

    int iRow = 0, iCol = 0;
    for (iRow = 0; cStr[iRow] != '\0'; iRow++)
    {
        for (iCol = 0; cStr[iCol] != '\0'; iCol++)
        {
            if(cStr[iCol] >= 'A' && cStr[iCol] <= 'Z')
                printf("%c ", cStr[iCol] + 32);
            else 
                printf("%c ", cStr[iCol]);
        }
        cout << endl;
    }
}

int main()
{
    StrPattern spObj;
    char cArr[MAXLEN] = {'\0'};

    cout << "Enter the string:\n";
    scanf("%[^\n]", cArr);

    cout << "\nOutput:\n\n";
    spObj.Display1(cArr);

    cout << "\nOutput:\n\n";
    spObj.Display2(cArr);

    cout << "\nOutput:\n\n";
    spObj.Display3(cArr);

    cout << "\nOutput:\n\n";
    spObj.Display4(cArr);

    cout << "\nOutput:\n\n";
    spObj.Display5(cArr);

    return 0;
}
