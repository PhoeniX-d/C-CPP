#include <windows.h>
#include <stdio.h>
#include <stdlib.h>

#define MAXLIMIT 25
#define KILOBYTE 1024
#define MEGABYTE 1024 * 1024

BOOL IsNum(CHAR);
BOOL FileGenerator(const PCHAR, UINT);
void DataGenerator(PCHAR, UINT);

CHAR operators[] = {'%', '*', '+', '-', '=', '/', '(', ']', ')', '[', '}', '{', '.'};
CHAR specials[] = {'!', '@', '#', '$', '^', '&', ';', ':', '>', '?', '<'};
CHAR characters[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j',
                     'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u',
                     'v', 'w', 'x', 'y', 'z'};
CHAR numbers[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};

int main(int argc, char *argv[])
{
    int iSize = 0, i = 0;
    BOOL bFlag = TRUE;
    CHAR szUnit[3] = {'\0'};

    /* Default unit of size given by user is bytes */
    if (argc == 3)
    {
        i = 0;
        if (argv[2][0] == '-')
        {
            i++;
        }
        while (argv[2][i] != '\0')
        {
            if (IsNum(argv[2][i]) != TRUE)
            {
                printf("Please Enter size in numerical value\n");
                bFlag = FALSE;
                break;
            }
            i++;
        }
        if (bFlag == FALSE)
        {
            return (-1);
        }
        iSize = atoi(argv[2]);
    }
    else if (argc == 4)
    {
        i = 0;
        if (argv[2][0] == '-')
        {
            i++;
        }
        while (argv[2][i] != '\0')
        {
            if (IsNum(argv[2][i]) != TRUE)
            {
                printf("Please Enter size in numerical value\n");
                bFlag = FALSE;
                break;
            }
            i++;
        }
        if (bFlag == FALSE)
        {
            return (-1);
        }

        // Convert 3rd cmd arg to integer
        iSize = atoi(argv[2]);

        // Check if it is bytes, kb or mb
        if (_stricmp(argv[3], "kb") == 0)
        {
            iSize = iSize * KILOBYTE;
        }
        else if (_stricmp(argv[3], "mb") == 0)
        {
            if (iSize > MAXLIMIT)
            {
                printf("Please enter size upto 25MB\n");
                return (-1);
            }
            iSize = iSize * MEGABYTE;
        }
    }
    else	/* Invalid cmd args */
    {
        printf("\nUsage:\n");
        printf("Program_Name File_Name [integer]Size Unit[b/kb/mb]\n");
        return (-1);
    }

    /* Now everything is fine then create file with specified file */
    if (FileGenerator(argv[1], iSize) == TRUE)
    {
        printf("File Generated successfully\n");
    }
    else
    {
        printf("File Generation failed\n");
    }

    return (0);
}// end of Entry Point

/* IsNum: Function to check whether enterd char is a number or not */
BOOL IsNum(CHAR ch)
{
    if (ch >= '0' && ch <= '9')
    {
        return (TRUE);
    }
    return (FALSE);
}// end of IsNum()

/* DataGenerator : Function to generate random data */
void DataGenerator(PCHAR szData, UINT iSize)
{
    if (iSize < 0)
    {
        iSize = -iSize;
    }
    int i = 0, iNr = 0, iCh = 0, iCH = sizeof(characters) - 1, iOp = 0, iSp = 0;
    while (i < iSize)
    {
        szData[i] = characters[iCh];
        iCh++;
        if (iCh == sizeof(characters))
        {
            iCh = 0;
        }
        i++;

        szData[i] = operators[iOp];
        iOp++;
        if (iOp == sizeof(operators))
        {
            iOp = 0;
        }
        i++;
        if (i >= iSize)
        {
            break;
        }

        szData[i] = characters[iCH] - 32;
        iCH--;
        if (iCH == -1)
            iCH = sizeof(characters) - 1;
        i++;
        if (i >= iSize)
        {
            break;
        }

        szData[i] = numbers[iNr];
        iNr++;
        if (iNr == sizeof(numbers))
        {
            iNr = 0;
        }
        i++;
        if (i >= iSize)
        {
            break;
        }

        szData[i] = specials[iSp];
        iSp++;
        if (iSp == sizeof(specials))
        {
            iSp = 0;
        }
        i++;
    }
    szData[i] = '\0';
}// end of DataGenerator()

/* FilaGenerator : Function to Create a file */
BOOL FileGenerator(PCHAR szFileName, UINT iSize)
{
    if (szFileName == NULL)
    {
        printf("Invalid file name\n");
        return (FALSE);
    }

    if (iSize < 0)
    {
        iSize = -iSize;
    }

    HANDLE hFile = NULL;
    BOOL bResult = FALSE;
    DWORD dwBytesToWrite = iSize;
    DWORD dwBytesWritten = 0;
    PCHAR szData = (PCHAR)malloc(sizeof(CHAR) * iSize + 1);

    if (szData == NULL)
    {
        printf("Memory allocation failed in FileGenerator\n");
        return (FALSE);
    }
    memset(szData, 0, iSize + 1);

    /* 	OPEN_ALWAYS:will check if file exists or not ,if exists then overwrites its contents
     * 	but without truncating previous data in file
     * 	
     *	CREATE_ALWAYS : will always create a new file and if file exists and its writable then 
     * 	it will truncate old data and then enters new data
     */
    /* Now create file for writing */
    hFile = CreateFileA(szFileName, GENERIC_WRITE, 0, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);
    if (hFile == INVALID_HANDLE_VALUE)
    {
        printf("Error while creation of file : %d\n", GetLastError());
        return (FALSE);
    }

    /* Fill buffer with some random data */
    DataGenerator(szData, iSize);

    /* Now write buffer to specified file */
    bResult = WriteFile(hFile, szData, dwBytesToWrite, &dwBytesWritten, NULL);
    if (bResult == FALSE)
    {
        printf("Error while File Write : %d\n", GetLastError());
        return (FALSE);
    }
    CloseHandle(hFile);
    return (TRUE);
} // end of FileGenerator()
