#include "LinkedList.h"

CRITICAL_SECTION CriticalSection;
DWORD WINAPI ThreadProc(LPVOID);

int main()
{
    PNODE Head = NULL;
    int i = 0;
    HANDLE hThread[10] = {NULL};

    // Initialize the critical section one time only.
    if (!InitializeCriticalSectionAndSpinCount(&CriticalSection,
        0x00000400))
        return;

    for (i = 0; i < 10; i++)
    {
        hThread[i] = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)ThreadProc, (LPVOID)&Head, 0, NULL);
        if (hThread[i] == NULL)
        {
            printf("Error Code %d : Unable to create thread\n", GetLastError());
            return (-1);
        }
        //WaitForSingleObject(hThread[i], INFINITE);
    }

    WaitForMultipleObjects(10, hThread, FALSE, INFINITE);   
    DisplayList(Head);
    for (i = 0; i < 10; i++)
    {
        CloseHandle(hThread[i]);
    }

    // Release resources used by the critical section object.
    DeleteCriticalSection(&CriticalSection);

    printf("Total nodes in List\t:%d\n", CountEls(Head));
    Deallocate(&(Head));

    return (0);
}

DWORD WINAPI ThreadProc(LPVOID lParam)
{
    //printf("Inside ThreadProc\n");
    HANDLE hFile = NULL;
    DWORD dwRead = 0;
    PCHAR szBuffer = (PCHAR)malloc(BLOCKSIZE + 1);
    static int i = 0;

    if (szBuffer == NULL)
    {
        printf("Unable to allocate memory\n");
        return (-1);
    }

    memset(szBuffer, 0, BLOCKSIZE + 1);

    hFile = CreateFile(TEXT("FileGen.txt"), GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);
    if (hFile == INVALID_HANDLE_VALUE)
    {
        printf("Error code %d : Unable to open file\n", GetLastError());
        return (-1);
    }
    
    // Request ownership of the critical section.
    EnterCriticalSection(&CriticalSection);

    if (SetFilePointer(hFile, i * BLOCKSIZE, NULL, FILE_BEGIN) == INVALID_SET_FILE_POINTER)
    {
        printf("Error code : %d , Invalid set file pointer\n", GetLastError());
        return (-1);
    }

    //printf("Offset = %ld\n", i * BLOCKSIZE);
    i++;
       
    if (ReadFile(hFile, szBuffer, BLOCKSIZE, &dwRead, NULL) == FALSE)
    {
        printf("Error code %d : Unable to read data from file \n", GetLastError());
        CloseHandle(hFile);
        return (-1);
    }
    InsertLast((PPNODE)lParam, szBuffer);

    // Release ownership of the critical section.
    LeaveCriticalSection(&CriticalSection);
    
    memset(szBuffer, 0, BLOCKSIZE);
    CloseHandle(hFile);
    free(szBuffer);    
    return (0);
}
