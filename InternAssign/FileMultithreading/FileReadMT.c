#include "LinkedList.h"

typedef struct parameters
{
    PNODE Head;
    HANDLE hFile;
    int i;
} PARAM, * PPARAM;

CRITICAL_SECTION CriticalSection;
DWORD WINAPI ThreadProc(LPVOID);

int main()
{   
    PARAM pr;
    int iCnt = 0;
    HANDLE hThread[10] = { NULL };
    DWORD dwEvent = 0;
    DWORD dwThreadEC = 0;

    // code 
    /* Cleans the structures memory */
    ZeroMemory((void*)&pr, sizeof(pr));

    InitializeHead(&(pr.Head));

    // Initialize the critical section one time only.
    InitializeCriticalSection(&CriticalSection);

    // Get File handle
    pr.hFile = CreateFile(TEXT("FileGen.txt"), GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);
    if (pr.hFile == INVALID_HANDLE_VALUE)
    {
        printf("Error code %d : Unable to open file\n", GetLastError());
        return (-1);
    }

    // Create Threads
    for (iCnt = 0; iCnt < 10; iCnt++)
    {
        PPARAM param = (PPARAM)malloc(sizeof(PARAM));
        if (param == NULL)
        {
            printf("Error code %d : Unable to allocate memory in main\n", GetLastError());
            return (1);
        }
        param->i = iCnt;
        param->Head = pr.Head;
        param->hFile = pr.hFile;

        hThread[iCnt] = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)ThreadProc, (LPVOID)param, 0, NULL);
        if (hThread[iCnt] == NULL)
        {
            printf("Error Code %d : Unable to create thread\n", GetLastError());
            return (-1);
        }
    }

    // Wait untill all finished
    dwEvent = WaitForMultipleObjects(10, hThread, TRUE, INFINITE);
    if (dwEvent == WAIT_FAILED)
    {
        printf("Error code %d : Error in WaitForMultipleObjects()\n", GetLastError());
    }

    // Close file HANDLE
    CloseHandle(pr.hFile);

    SortList(pr.Head);

    // Display the linked list
    DisplayList((pr.Head));

    // Close hThread HANDLES
    for (iCnt = 0; iCnt < 10; iCnt++)
    {
        if (GetExitCodeThread(hThread[iCnt], &dwThreadEC) == 0)
        {
            printf("Error code %d : while GetExitCodeThread()\n", GetLastError());
            ExitThread(dwThreadEC);
        }
        CloseHandle(hThread[iCnt]);
    }

    // Release resources used by the critical section object.
    DeleteCriticalSection(&CriticalSection);

    // Display total number if nodes in a linked list
    //printf("Total nodes in List\t:%d\n", CountEls((pr.Head)));

    // Deallocate whole linked list
    Deallocate((pr.Head));
    UninitializeHead(&(pr.Head));
    return (0);
}

DWORD WINAPI ThreadProc(LPVOID lParam)
{
    DWORD dwRead = 0;
    PCHAR szBuffer = (PCHAR)malloc(BLOCKSIZE + 1);
    PPARAM param = (PPARAM)lParam;
    if (szBuffer == NULL)
    {
        printf("Error code %d : Unable to allocate memory in ThreadProc\n", GetLastError());
        return (1);
    }
    memset(szBuffer, 0, BLOCKSIZE + 1);

    // Request ownership of the critical section.
    EnterCriticalSection(&CriticalSection);

    if (SetFilePointer(param->hFile, (param->i) * BLOCKSIZE, NULL, FILE_BEGIN) == INVALID_SET_FILE_POINTER)
    {
        printf("Error code : %d , Invalid set file pointer\n", GetLastError());
        LeaveCriticalSection(&CriticalSection);
        memset(szBuffer, 0, BLOCKSIZE);
        free(szBuffer);
        return (1);
    }

    if (ReadFile(param->hFile, szBuffer, BLOCKSIZE, &dwRead, NULL) == FALSE)
    {
        printf("Error code %d : Unable to read data from file \n", GetLastError());
        CloseHandle(param->hFile);
        LeaveCriticalSection(&CriticalSection);
        memset(szBuffer, 0, BLOCKSIZE);
        free(szBuffer);
        return (1);
    }

    // Add node to linked list
    InsertLast(param->Head, szBuffer, param->i);

    // Release ownership of the critical section.
    LeaveCriticalSection(&CriticalSection);

    // Free allocated memory
    memset(szBuffer, 0, BLOCKSIZE);
    free(szBuffer);

    return (0);
}
