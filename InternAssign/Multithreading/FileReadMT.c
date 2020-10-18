#include "LinkedList.h"

CRITICAL_SECTION CriticalSection;
DWORD WINAPI ThreadProc(LPVOID);
typedef struct parameters
{
    NODE Head;
    HANDLE hFile;
    int i;
} PARAM;

int main()
{
    PARAM pr;
    ZeroMemory((void *)&pr, sizeof(pr));
    int iCnt = 0;
    HANDLE hThread[10] = {NULL};
    DWORD dwEvent = 0;

    // Initialize the critical section one time only.
    InitializeCriticalSection(&CriticalSection);

    pr.hFile = CreateFile(TEXT("FileGen.txt"), GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);
    if (pr.hFile == INVALID_HANDLE_VALUE)
    {
        printf("Error code %d : Unable to open file\n", GetLastError());
        return (-1);
    }
    for (iCnt = 0; iCnt < 10; iCnt++)
    {
        pr.i = iCnt;
        //printf("Offset = %ld\n", pr.i);
        hThread[iCnt] = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)ThreadProc, (LPVOID)&pr, 0, NULL);
        if (hThread[iCnt] == NULL)
        {
            printf("Error Code %d : Unable to create thread\n", GetLastError());
            return (-1);
        }
        //WaitForSingleObject(hThread[i], INFINITE);
    }
    dwEvent = WaitForMultipleObjects(10, hThread, TRUE, INFINITE);
    if (dwEvent == WAIT_FAILED)
    {
        printf("Error code %d : Error in WaitForMultipleObjects()\n", GetLastError());
    }

    // Close file HANDLE
    CloseHandle(pr.hFile);

    // Display the linked list
    DisplayList(&(pr.Head));

    // Close hThread HANDLES
    for (iCnt = 0; iCnt < 10; iCnt++)
    {
        CloseHandle(hThread[iCnt]);
    }

    // Release resources used by the critical section object.
    DeleteCriticalSection(&CriticalSection);

    // Display total number if nodes in a linked list
    printf("Total nodes in List\t:%d\n", CountEls(&(pr.Head)));
    
    // Deallocate whole linked list
    Deallocate(&(pr.Head));
    
    return (0);
}

DWORD WINAPI ThreadProc(LPVOID lParam)
{
    DWORD dwRead = 0;
    PCHAR szBuffer = (PCHAR)malloc(BLOCKSIZE + 1);
    PARAM *param = (PARAM *)lParam;
    static int i = 0;
    if (szBuffer == NULL)
    {
        printf("Error code %d : Unable to allocate memory in ThreadProc\n", GetLastError());
        return (1);
    }
    memset(szBuffer, 0, BLOCKSIZE + 1);

    // Request ownership of the critical section.
    EnterCriticalSection(&CriticalSection);

    if (SetFilePointer(param->hFile, i * BLOCKSIZE, NULL, FILE_BEGIN) == INVALID_SET_FILE_POINTER)
    {
        printf("Error code : %d , Invalid set file pointer\n", GetLastError());
        LeaveCriticalSection(&CriticalSection);
        memset(szBuffer, 0, BLOCKSIZE);
        free(szBuffer);
        ExitThread(0);
    }
   
    i++;

    if (ReadFile(param->hFile, szBuffer, BLOCKSIZE, &dwRead, NULL) == FALSE)
    {
        printf("Error code %d : Unable to read data from file \n", GetLastError());
        CloseHandle(param->hFile);
        LeaveCriticalSection(&CriticalSection);
        memset(szBuffer, 0, BLOCKSIZE);
        free(szBuffer);
        ExitThread(0);
    }

    // Add node to linked list
    InsertLast(&(param->Head), szBuffer);

    // Release ownership of the critical section.
    LeaveCriticalSection(&CriticalSection);

    // Free allocated memory
    memset(szBuffer, 0, BLOCKSIZE);
    free(szBuffer);

    return (0);
}
