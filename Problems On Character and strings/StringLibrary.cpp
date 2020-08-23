/*
*   Program containing all string library functions
*/

#include "StringLibrary.h"

// constructor
Strings::Strings()
{
    cSrc = NULL;
}

//////////////////////////////////////////////////////////////////////
//
//  Name        :StrLen
//  Input       :const char*
//  Returns     :int
//  Description :computes length of entered string
//  Author      :Pranav Choudhary
//  Date        :24 August 2020
//
//////////////////////////////////////////////////////////////////////
int StrLen(const char *cSrc)
{
    if(cSrc == NULL)
    {
        printf("Invalid Input\n");
        return -1;
    }
    int iLen = 0;
    char *cTemp = cSrc;
    while(*cTemp != '\0')
    {
        iLen++;
        cTemp++;
    }
    return iLen;
}

//////////////////////////////////////////////////////////////////////
//
//  Name        :StrLow
//  Input       :const char*
//  Returns     :void
//  Description :converts lower case of entered string
//  Author      :Pranav Choudhary
//  Date        :24 August 2020
//
//////////////////////////////////////////////////////////////////////
void StrLow(char* cSrc)
{
    if(NULL == cSrc)
    {
        printf("Invalid Input\n");
    }
    while(*cSrc !='\0')
    {
        if((*cSrc >= 'A') && (*cSrc <= 'Z'))
        {
            *cSrc = *cSrc + 32;
        }
        cSrc++;
    }
}

//////////////////////////////////////////////////////////////////////
//
//  Name        :StrUpr
//  Input       :const char*
//  Returns     :void
//  Description :converts upper case entered string
//  Author      :Pranav Choudhary
//  Date        :24 August 2020
//
//////////////////////////////////////////////////////////////////////
void StrUpr(char* cSrc)
{
    if(NULL == cSrc)
    {
        printf("Invalid Input\n");
    }
    while(*cSrc !='\0')
    {
        if((*cSrc >= 'a') && (*cSrc <= 'z'))
        {
            *cSrc = *cSrc - 32;
        }
        cSrc++;
    }
}

//////////////////////////////////////////////////////////////////////
//
//  Name        :StrTgl
//  Input       :const char*
//  Returns     :void
//  Description :Toggle case of entered string
//  Author      :Pranav Choudhary
//  Date        :24 August 2020
//
//////////////////////////////////////////////////////////////////////
void StrTgl(char* cSrc)
{
    if(NULL == cSrc)
    {
        printf("Invalid Input\n");
    }
    while(*cSrc !='\0')
    {
        if((*cSrc >= 'A') && (*cSrc <= 'Z'))
        {
            *cSrc = *cSrc + 32;
        }
        else if((*cSrc >= 'a') && (*cSrc <= 'z'))
        {
            *cSrc = *cSrc - 32;
        }
        cSrc++;
    }
}

////////////////////////////////////////////////////////////
//
//  Name        :StrCat
//  Input       :char*, char*
//  Returns     :void
//  Description :concate two strings
//  Author      :Pranav Choudhary
//  Date        :24 August 2020
//
////////////////////////////////////////////////////////////
void StrCat(char* cStr1, char* cStr2)
{
    if(cStr1 == NULL || cStr2 == NULL)
    {
        printf("Invalid Input\n");
        return;
    }
    while(*cStr1 != '\0')
    {
        cStr1++;
    }
    while(*cStr2 != '\0')
    {
        *cStr1 = *cStr2;
        cStr2++;
        cStr1++;
    }
    *cStr1 = '\0';
}

////////////////////////////////////////////////////////////
//
//  Name        :StrNCat
//  Input       :char*, char*, int
//  Returns     :void
//  Description :append N characters of second string after
//               first string(Implement strncat())
//  Author      :Pranav Choudhary
//  Date        :24 August 2020
//
////////////////////////////////////////////////////////////
void StrNCat(char* cStr1, char* cStr2, int iN)
{
    if(cStr1 == NULL || cStr2 == NULL)
    {
        printf("Invalid Input\n");
        return;
    }
    if(iN < 0)
    {
        iN = -iN;
    }

    while(*cStr1 != '\0')
    {
        cStr1++;
    }
    while(*cStr2 != '\0' && iN != 0)
    {
        *cStr1 = *cStr2;
        cStr2++;
        cStr1++;
        iN--;
    }
    *cStr1 = '\0';
}

////////////////////////////////////////////////////////////
//
//  Name        :StrCpy
//  Input       :const char*, char*
//  Returns     :void
//  Description :copy source string into destination string
//  Author      :Pranav Choudhary
//  Date        :24 August 2020
//
////////////////////////////////////////////////////////////
void StrCpy(const char* cSrc, char* cDest)
{
    if(cSrc == NULL || cDest == NULL)
    {
        printf("Invalid Input\n");
        return;
    }

    while(*cSrc != '\0')
    {
        *cDest = *cSrc;
        cSrc++;
        cDest++;
    }
    *cDest = '\0';
}

///////////////////////////////////////////////////////////////////////
//
//  Name        :StrNCpy
//  Input       :const char*, char*, int
//  Returns     :void
//  Description :copy source string's N chars into destination string
//  Author      :Pranav Choudhary
//  Date        :24 August 2020
//
///////////////////////////////////////////////////////////////////////
void StrNCpy(const char* cSrc, char* cDest, int iN)
{
    if(cSrc == NULL || cDest == NULL)
    {
        printf("Invalid Input\n");
        return;
    }
    if(iN < 0)
        iN = -iN;

    while(*cSrc != '\0' && iN != 0)
    {
        *cDest = *cSrc;
        cSrc++;
        cDest++;
        iN--;
    }
    *cDest = '\0';
}

////////////////////////////////////////////////////////////
//
//  Name        :StrCpyCap
//  Input       :const char*, char*
//  Returns     :void
//  Description :copy capital letters from source string 
//               into destination string
//  Author      :Pranav Choudhary
//  Date        :24 August 2020
//
////////////////////////////////////////////////////////////
void StrCpyCap(const char* cSrc, char* cDest)
{
    if(cSrc == NULL || cDest == NULL)
    {
        printf("Invalid Input\n");
        return;
    }

    while(*cSrc != '\0')
    {
        if(*cSrc >= 'A' && *cSrc <= 'Z')
        {
            *cDest = *cSrc;
            cDest++;
        }
        cSrc++;
    }
    *cDest = '\0';
}

////////////////////////////////////////////////////////////////////////////
//
//  Name        :StrCpyCapX
//  Input       :const char*, char*
//  Returns     :void
//  Description :convert small letters to capital letters from source string
//               into destination string
//  Author      :Pranav Choudhary
//  Date        :24 August 2020
//
/////////////////////////////////////////////////////////////////////////////
void StrCpyCapX(const char* cSrc, char* cDest)
{
    if(cSrc == NULL || cDest == NULL)
    {
        printf("Invalid Input\n");
        return;
    }

    while(*cSrc != '\0')
    {
        if(*cSrc >= 'a' && *cSrc <= 'z')
        {
            *cDest = *cSrc - 32;
            cDest++;
        }
        else
        {
            *cDest = *cSrc;
            cDest++;
        }        
        cSrc++;
    }
    *cDest = '\0';
}

////////////////////////////////////////////////////////////
//
//  Name        :StrCpyLwr
//  Input       :const char*, char*
//  Returns     :void
//  Description :copy lower letters from source string 
//               into destination string
//  Author      :Pranav Choudhary
//  Date        :24 August 2020
//
////////////////////////////////////////////////////////////
void StrCpyLwr(const char* cSrc, char* cDest)
{
    if(cSrc == NULL || cDest == NULL)
    {
        printf("Invalid Input\n");
        return;
    }

    while(*cSrc != '\0')
    {
        if(*cSrc >= 'a' && *cSrc <= 'z')
        {
            *cDest = *cSrc;
            cDest++;
        }
        cSrc++;
    }
    *cDest = '\0';
}

////////////////////////////////////////////////////////////////////////////
//
//  Name        :StrCpyLwrX
//  Input       :const char*, char*
//  Returns     :void
//  Description :convert capital letters to small letters from source string
//               into destination string
//  Author      :Pranav Choudhary
//  Date        :24 August 2020
//
/////////////////////////////////////////////////////////////////////////////
void StrCpyLwrX(const char* cSrc, char* cDest)
{
    if(cSrc == NULL || cDest == NULL)
    {
        printf("Invalid Input\n");
        return;
    }

    while(*cSrc != '\0')
    {
        if(*cSrc >= 'A' && *cSrc <= 'Z')
        {
            *cDest = *cSrc + 32;
            cDest++;
        }
        else
        {
            *cDest = *cSrc;
            cDest++;
        }        
        cSrc++;
    }
    *cDest = '\0';
}

////////////////////////////////////////////////////////////
//
//  Name        :StrCpySpace
//  Input       :const char*, char*
//  Returns     :void
//  Description :copy source string into destination string
//               in Spaceerse
//  Author      :Pranav Choudhary
//  Date        :24 August 2020
//
////////////////////////////////////////////////////////////
void StrCpySpace(const char* cSrc, char* cDest)
{
    if(cSrc == NULL || cDest == NULL)
    {
        printf("Invalid Input\n");
        return;
    }
    int iCnt = 0;
    while(*cSrc != '\0')
    {
        iCnt++;
        cSrc++;
    }
    cSrc--;
    while(iCnt != 0)
    {
        *cDest = *cSrc;
        cSrc--;
        cDest++;
        iCnt--;
    }
    *cDest = '\0';
}

////////////////////////////////////////////////////////////
//
//  Name        :StrCpySpace
//  Input       :const char*, char*
//  Returns     :void
//  Description :copy source string into destination string
//  Author      :Pranav Choudhary
//  Date        :24 August 2020
//
////////////////////////////////////////////////////////////
void StrCpySpace(const char* cSrc, char* cDest)
{
    if(cSrc == NULL || cDest == NULL)
    {
        printf("Invalid Input\n");
        return;
    }

    while(*cSrc != '\0')
    {
        if(*cSrc != ' ')
        {
            *cDest = *cSrc;
            cDest++;
        }
        cSrc++;
    }
    *cDest = '\0';
}

////////////////////////////////////////////////////////////////////////////
//
//  Name        :StrCpyTgl
//  Input       :const char*, char*
//  Returns     :void
//  Description :toggle letters from source string into destination string
//  Author      :Pranav Choudhary
//  Date        :24 August 2020
//
/////////////////////////////////////////////////////////////////////////////
void StrCpyTgl(const char* cSrc, char* cDest)
{
    if(cSrc == NULL || cDest == NULL)
    {
        printf("Invalid Input\n");
        return;
    }

    while(*cSrc != '\0')
    {
        if(*cSrc >= 'a' && *cSrc <= 'z')
        {
            *cDest = *cSrc - 32;
            cDest++;
        }
        else if(*cSrc >= 'A' && *cSrc <= 'Z')
        {
            *cDest = *cSrc + 32;
            cDest++;
        }
        else
        {
            *cDest = *cSrc;
            cDest++;
        }      
        cSrc++;
    }
    *cDest = '\0';
}

//////////////////////////////////////////////////////////////////////
//
//  Name        :StrRev
//  Input       :char*
//  Returns     :void
//  Description :Reverses entered string
//  Author      :Pranav Choudhary
//  Date        :24 August 2020
//
//////////////////////////////////////////////////////////////////////
void StrRev(char* cSrc)
{
    if(cSrc == NULL)
    {
        printf("Invalid Input\n");
        return;
    }
    char cTemp = '\0';
    char *cStart = cSrc;
    char *cEnd = cSrc;

    while(*cEnd != '\0')
    {
        cEnd++;
    }
    cEnd--;
    while(cStart < cEnd)
    {
        cTemp = *cStart;
        *cStart = *cEnd;
        *cEnd = cTemp;
        cEnd--;
        cStart++;
    }
}

//////////////////////////////////////////////////////////////////////
//
//  Name        :StrNRevF
//  Input       :char*, int
//  Returns     :void
//  Description :reverse the string till first N characters without 
//               taking another string.
//  Author      :Pranav Choudhary
//  Date        :24 August 2020
//
//////////////////////////////////////////////////////////////////////
void StrNRevF(char* cSrc, int iN)
{
    if(cSrc == NULL)
    {
        printf("Invalid Input\n");
        return;
    }

    if(iN < 0)
    {
        iN = -iN;
    }

    char cTemp = '\0';
    char *cStart = cSrc;
    char *cEnd = cSrc;

    while(*cEnd != '\0' && iN != 1)
    {
        iN--;
        cEnd++;
    }
    if(iN != 1)
        cEnd--;
    while(cStart < cEnd)
    {
        cTemp = *cStart;
        *cStart = *cEnd;
        *cEnd = cTemp;
        cEnd--;
        cStart++;
    }
}

//////////////////////////////////////////////////////////////////////
//
//  Name        :StrNRevL
//  Input       :char*, int
//  Returns     :void
//  Description :reverse the string till las    t N characters without 
//               taking another string.
//  Author      :Pranav Choudhary
//  Date        :24 August 2020
//
//////////////////////////////////////////////////////////////////////
void StrNRevL(char* cSrc, int iN)
{
    if(cSrc == NULL)
    {
        printf("Invalid Input\n");
        return;
    }

    if(iN < 0)
    {
        iN = -iN;
    }

    char cTemp = '\0';
    char *cStart = cSrc;
    char *cEnd = NULL;

    while(*cStart != '\0')
    {
        cStart++;
    }
    cEnd = cStart--;

    while(iN != 0 && cEnd != cSrc)
    {
        iN--;
        cEnd--;
    }

    while(cStart > cEnd)
    {
        cTemp = *cStart;
        *cStart = *cEnd;
        *cEnd = cTemp;
        cEnd++;
        cStart--;
    }
}

//////////////////////////////////////////////////////////////////////
//
//  Name        :StrRangeRev
//  Input       :char*, int, int
//  Returns     :void
//  Description :reverse the string in that range without
//               taking another string
//  Author      :Pranav Choudhary
//  Date        :24 August 2020
//
//////////////////////////////////////////////////////////////////////
void StrRangeRev(char* cSrc, int iS, int iE)
{
    if(iS < 0)
    {
        iS = -iS;
    }
    if(iE < 0)
    {
        iE = -iE;
    }
    if(cSrc == NULL || iS >= iE || StrLen(cSrc) < iS || StrLen(cSrc) < iE)
    {
        printf("Invalid Input\n");
        return;
    }

    char cTemp = '\0';
    char *cStart = cSrc;
    char *cEnd = cSrc;

    if(iS == 0)
    {
        cStart = cSrc + iS;
    }
    else
    {
        cStart = cSrc + (iS - 1);
    }    
    cEnd = cSrc + (iE - 1);

    while(cStart < cEnd)
    {
        cTemp = *cStart;
        *cStart = *cEnd;
        *cEnd = cTemp;
        cEnd--;
        cStart++;
    }
}

////////////////////////////////////////////////////////////
//
//  Name        :StrCmp
//  Input       :const char*, const char*
//  Returns     :int
//  Description :compare 2 strings
//  Author      :Pranav Choudhary
//  Date        :24 August 2020
//
////////////////////////////////////////////////////////////
int StrCmp(const char* cStr1, const char* cStr2)
{
    if(cStr1 == NULL || cStr2 == NULL)
    {
        printf("Invalid Input\n");
        return ERROR;
    }

    while(*cStr1 == *cStr2)
    {
        if(*cStr1 == '\0')
        {
            break;
        }
        cStr1++;
        cStr2++;
    }
    if(*cStr1 == *cStr2)
        return 0;
    else
        return *cStr1 - *cStr2;
}

////////////////////////////////////////////////////////////
//
//  Name        :StrCmpi
//  Input       :const char*, const char*
//  Returns     :int
//  Description :compare 2 strings case insensitive
//  Author      :Pranav Choudhary
//  Date        :24 August 2020
//
////////////////////////////////////////////////////////////
int StrCmpi(const char* cStr1, const char* cStr2)
{
    if(cStr1 == NULL || cStr2 == NULL)
    {
        printf("Invalid Input\n");
        return ERROR;
    }

    while(*cStr1 != '\0' && *cStr2 != '\0')
    {
        if((*cStr1 != *cStr2) && (*cStr1 != *cStr2 + 32) && (*cStr1 != *cStr2 - 32))
        {
            break;
        }
        cStr1++;
        cStr2++;
    }
    if(*cStr1 == *cStr2)
        return 0;
    else
        return *cStr1 - *cStr2;
}

////////////////////////////////////////////////////////////
//
//  Name        :StrNCmp
//  Input       :const char*, const char*
//  Returns     :int
//  Description :Implementation of strncmp()
//  Author      :Pranav Choudhary
//  Date        :24 August 2020
//
////////////////////////////////////////////////////////////
int StrNCmp(const char* cStr1, const char* cStr2, int iN)
{
    if(cStr1 == NULL || cStr2 == NULL)
    {
        printf("Invalid Input\n");
        return ERROR;
    }
    if(iN < 0)
    {
        iN = -iN;
    }
    while(*cStr1 == *cStr2 && iN != 0)
    {
        if(*cStr1 == '\0' && iN != 0)
        {
            break;
        }
        cStr1++;
        cStr2++;
        iN--;
    }
    if(*cStr1 == *cStr2)
        return 0;
    else
        return *cStr1 - *cStr2;
}// end of StrNCmp()

//////////////////////////////////////////////////////////////////////
//
//  Name        :StrSet
//  Input       :char*, char
//  Returns     :void
//  Description :sets all characters in string to a specific character
//               (Implement strset())
//  Author      :Pranav Choudhary
//  Date        :24 August 2020
//
//////////////////////////////////////////////////////////////////////
void StrSet(char *cSrc, char ch)
{
    if(cSrc == NULL)
    {
        printf("Invalid Input\n");
        return;
    }
    while(*cSrc != '\0')
    {
        *cSrc = ch;
        cSrc++;
    }
}

//////////////////////////////////////////////////////////////////////
//
//  Name        :StrNSetF
//  Input       :char*, char
//  Returns     :void
//  Description :sets first N characters in string to a specific 
//               character (Implement strnset())
//  Author      :Pranav Choudhary
//  Date        :24 August 2020
//
//////////////////////////////////////////////////////////////////////
void StrNSetF(char *cSrc, char ch, int iN)
{
    if(cSrc == NULL)
    {
        printf("Invalid Input\n");
        return;
    }
    if(iN < 0)
    {
        iN = -iN;
    }
    while(*cSrc != '\0' && iN != 0)
    {
        *cSrc = ch;
        cSrc++;
        iN--;
    }
}

/////////////////////////////////////////////////////////////////////
//
//  Name        :StrNSetL
//  Input       :char*, char
//  Returns     :void
//  Description :sets last N characters in string to a specific 
//               character (Implement strnset())
//  Author      :Pranav Choudhary
//  Date        :24 August 2020
//
//////////////////////////////////////////////////////////////////////
void StrNSetL(char *cSrc, char ch, int iN)
{
    char *cEnd = cSrc;
    if(cSrc == NULL)
    {
        printf("Invalid Input\n");
        return;
    }
    if(iN < 0)
    {
        iN = -iN;
    }

    while(*(cEnd + 1) != '\0')
    {
        cEnd++;
    }
    while(cEnd != cSrc && iN != 0)
    {
        *cEnd = ch;
        cEnd--;
        iN--;
    }
    *cEnd = ch;
}

//////////////////////////////////////////////////////////////////////
//
//  Name        :WordCnt
//  Input       :char *
//  Returns     :int
//  Description :count words in given string
//  Author      :Pranav Choudhary
//  Date        :24 August 2020
//
//////////////////////////////////////////////////////////////////////
int WordCnt(const char *cSrc)
{
    int iCnt = 0;
    int iState = OUT;
    if(NULL == cSrc)
    {
        printf("Invalid Input\n");
        return ERROR;
    }
    while (*cSrc != '\0')
    {
        if(*cSrc == ' ' || *cSrc == '\n' || *cSrc == '\t')
        {
            iState = OUT;
        }
        else if(iState == OUT)
        {   
            iState = IN;
            iCnt++;
        }
        cSrc++;
    }
    return iCnt;
}

//////////////////////////////////////////////////////////////////////
//
//  Name        :WordRev
//  Input       :char*
//  Returns     :void
//  Description :reverse words from that string
//  Author      :Pranav Choudhary
//  Date        :24 August 2020
//
//////////////////////////////////////////////////////////////////////
void WordRev(char* cSrc)
{
    if(cSrc == NULL)
    {
        printf("Invalid Input\n");
        return;
    }
    char cTemp = '\0';
    char *cStart = cSrc;
    char *cEnd = cSrc;

    while(*cSrc != '\0')
    {
        cEnd = cStart;
        while(*cEnd != ' ' && *cEnd != '\t' && *cEnd != '\0')
        {
            cEnd++;
        }
        cSrc = cEnd;
        cEnd--;

        while(cStart < cEnd)
        {
            cTemp = *cStart;
            *cStart = *cEnd;
            *cEnd = cTemp;
            
            cEnd--;
            cStart++;
        }
        cStart = cSrc + 1;
    }    
}

//////////////////////////////////////////////////////////////////////
//
//  Name        :MaxOccur
//  Input       :const char *
//  Returns     :void
//  Description :find maximum occurring character in a string
//  Author      :Pranav Choudhary
//  Date        :24 August 2020
//
//////////////////////////////////////////////////////////////////////
void MaxOccur(const char *cSrc)
{
    int iChars[MAX_CHAR] = {0}, i = 0, iMax = 0;
    char ch = '\0';
    if(NULL == cSrc)
    {
        printf("Invalid Input\n");
        return;
    }
    while (*cSrc != '\0')
    {
        iChars[*cSrc]++;
        cSrc++;
    }
    iMax = iChars[0];
    for (i = 0; i < MAX_CHAR; i++)
    {
        if(i != 32)
        {
            if(iMax < iChars[i])
            {
                iMax = iChars[i];
                ch = i;
            }
        }
    }

    printf("Max occuring char \'%c\' with occurance %d\n", ch, iMax);
}

//////////////////////////////////////////////////////////////////////
//
//  Name        :FirstOccur
//  Input       :const char*, char
//  Returns     :int
//  Description :return position of first occurance of entered 
//               char in the entered string
//  Author      :Pranav Choudhary
//  Date        :24 August 2020
//
//////////////////////////////////////////////////////////////////////
int FirstOccur(const char *cSrc, char ch)
{
    int iCnt = -1;
    while(*cSrc != '\0')
    {
        if(*cSrc == ch)
        {
            iCnt++;
            break;
        }
        iCnt++;
        cSrc++;
    }
    if(*cSrc == '\0')
        return -1;
    else
        return iCnt;
}

//////////////////////////////////////////////////////////////////////
//
//  Name        :LastOccur
//  Input       :const char*, char
//  Returns     :int
//  Description :return position of last occurance of entered 
//               char in the entered string
//  Author      :Pranav Choudhary
//  Date        :24 August 2020
//
//////////////////////////////////////////////////////////////////////
int LastOccur(const char *cSrc, char ch)
{
    if(cSrc == NULL)
    {
        printf("Invalid Input\n");
        return -1;
    }
    int iCnt = 0;
    while(*cSrc != '\0')
    {
        iCnt++;
        cSrc++;
    }
    cSrc--;
    while(iCnt != -1)
    {
        if(*cSrc == ch)
        {
            iCnt--;
            break;
        }
        iCnt--;
        cSrc--;
    }
    if(iCnt == -1)
        return -1;
    else
        return iCnt;
}

//////////////////////////////////////////////////////////////////////
//
//  Name        :IsPldrm
//  Input       :const char*
//  Returns     :BOOL
//  Description :check whether string is palindrome or not
//  Author      :Pranav Choudhary
//  Date        :24 August 2020
//
//////////////////////////////////////////////////////////////////////
bool IsPldrm(const char* cSrc)
{
    char *cStart = NULL;
    char *cEnd = NULL;

    if(cSrc == NULL)
    {
        printf("Invalid Input\n");
        return FALSE;
    }

    cStart = cSrc;
    cEnd = cSrc;
    
    while(*(cEnd + 1) != '\0')
    {
        cEnd++;
    }
    while(cStart < cEnd)
    {
        if(*cStart != *cEnd)
        {
            break;
        }
        cEnd--;
        cStart++;
    }
    if(cStart >= cEnd)
    {
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}

///////////////////////////////////////////////////////////////////////////
//
//  Name        :IsiPldrm
//  Input       :const char*
//  Returns     :BOOL
//  Description :check whether string is palindrome or not case insensitive
//  Author      :Pranav Choudhary
//  Date        :24 August 2020
//
///////////////////////////////////////////////////////////////////////////
bool IsiPldrm(const char* cSrc)
{
    char *cStart = NULL;
    char *cEnd = NULL;

    if(cSrc == NULL)
    {
        printf("Invalid Input\n");
        return FALSE;
    }

    cStart = cSrc;
    cEnd = cSrc;
    
    while(*(cEnd + 1) != '\0')
    {
        cEnd++;
    }
    while(cStart < cEnd)
    {
        if( (*cStart != *cEnd) && (*cStart != *cEnd + 32) && (*cStart != *cEnd - 32) )
        {
            break;
        }
        cEnd--;
        cStart++;
    }
    if(cStart >= cEnd)
    {
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}

//////////////////////////////////////////////////////////////////////
//
//  Name        :CharsCnt
//  Input       :const char *
//  Returns     :void
//  Description :count total number of alphabets,
//               digits and special characters in a string
//  Author      :Pranav Choudhary
//  Date        :24 August 2020
//
//////////////////////////////////////////////////////////////////////
void CharsCnt(const char *cSrc)
{
    int iA = 0, iSp = 0, iD = 0, iW = 0, iState = OUT;
    if(NULL == cSrc)
    {
        printf("Invalid Input\n");
        return;
    }
    while (*cSrc != '\0')
    {
        if(*cSrc == ' ' || *cSrc == '\n' || *cSrc == '\t')
        {
            iState = OUT;
        }
        else if(iState == OUT)
        {   
            iState = IN;
            iW++;
        }
        if(*cSrc >= 'A' && *cSrc <= 'Z' || *cSrc >= 'a' && *cSrc <= 'z')
        {
            iA++;
        }
        else if(*cSrc >= '0' && *cSrc <= '9')
        {
            iD++;
        }
        else
        {
            iSp++;
        }       
        cSrc++;
    }
    printf("\nTotal Alphabets:\t%d\n", iA);
    printf("Total Digits :\t % d\n", iD);
    printf("Total Special symbols:\t%d\n", iSp);
    printf("Total Words:\t%d\n", iW);
}

//////////////////////////////////////////////////////////////////////
//
//  Name        :CountUpr
//  Input       :char *
//  Returns     :int
//  Description :count capital letters in given string
//  Author      :Pranav Choudhary
//  Date        :24 August 2020
//
//////////////////////////////////////////////////////////////////////
int CountUpr(char *cSrc)
{
    int iCnt = 0;
    if(NULL == cSrc)
    {
        printf("Invalid Input\n");
        return ERROR;
    }
    
    while(*cSrc != '\0')
    {
        if (*cSrc >= 'A' && *cSrc <= 'Z')
        {
            iCnt++;
        }
        cSrc++;
    }

    return iCnt;
}

//////////////////////////////////////////////////////////////////////
//
//  Name        :CountLwr
//  Input       :char *
//  Returns     :int
//  Description :count small letters in given string
//  Author      :Pranav Choudhary
//  Date        :24 August 2020
//
//////////////////////////////////////////////////////////////////////
int CountLwr(char *cSrc)
{
    int iCnt = 0;
    if(NULL == cSrc)
    {
        printf("Invalid Input\n");
        return ERROR;
    }
    
    while(*cSrc != '\0')
    {
        if (*cSrc >= 'a' && *cSrc <= 'z')
        {
            iCnt++;
        }
        cSrc++;
    }

    return iCnt;
}

/////////////////////////////////////////////////////////////////////////
//
//  Name        :IsAgrm
//  Input       :const char*, const char*
//  Returns     :BOOL
//  Description :check whether given strings are Anagram strings or not.
//  Author      :Pranav Choudhary
//  Date        :24 August 2020
//
/////////////////////////////////////////////////////////////////////////
bool IsAgrm(const char* cStr1, const char* cStr2)
{
    char cChars[MAX_CAHR] = {0};
    int i = 0;
    if(cStr1 == NULL || cStr2 == NULL)
    {
        printf("Invalid Input\n");
        return ERROR;
    }

    while(*cStr1 != '\0' && *cStr2 != '\0')
    {
        cChars[*cStr1]++;
        cChars[*cStr2]--;
        cStr1++;
        cStr2++;
    }
    if(*cStr1 == '\0' && *cStr2 == '\0' )
    {
       for (i = 0; i < MAX_CAHR; i++)
        {
            if(cChars[i] != 0)
            {
                break;
            }
        }
    }
    if(i == MAX_CAHR)
    {
        return TRUE;
    }
    else
    {
        return FALSE;
    }    
}

//////////////////////////////////////////////////////////////////////
//
//  Name        :CountSpecials
//  Input       :const char *
//  Returns     :int
//  Description :count special characters in given string
//  Author      :Pranav Choudhary
//  Date        :24 August 2020
//
//////////////////////////////////////////////////////////////////////
int CountSpecials(const char *cSrc)
{
    int iCnt = 0;
    if(NULL == cSrc)
    {
        printf("Invalid Input\n");
        return ERROR;
    }
    
    while(*cSrc != '\0')
    {
        if ( !(*cSrc >= 'a' && *cSrc <= 'z') && 
             !(*cSrc >= 'A' && *cSrc <= 'Z') && 
             !(*cSrc >= '0' && *cSrc <= '9'))
        {
            iCnt++;
        }
        cSrc++;
    }

    return iCnt;
}