#include <windows.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define FIRST 0
#define LAST 1

void FileChecker(LPCSTR, WIN32_FIND_DATA, LPSTR);
int StriNCmp(LPCSTR, LPCSTR, int, BOOL);
BOOL FindFile(LPSTR, LPCSTR);

int main(int argc, char *argv[])
{
	BOOL bRet = FALSE;
	if (argc != 3)
	{
		printf("Usage :\n[Program_Name] [Directory_Path] [File_Name(with extension)]\n");
		return (-1);
	}
	CHAR szPath[MAX_PATH] = {'\0'};
	strcpy(szPath, argv[1]);
	strcat(szPath, "\\*");
	bRet = FindFile(szPath, argv[2]);
	return (0);
}

/* FindFile() : Traverses the directory to find sepcified file */
BOOL FindFile(LPSTR szPath, LPCSTR szFileName)
{
	if (szFileName == NULL)
	{
		printf("Invalid inputs to FindFile()\n");
		return (FALSE);
	}
	WIN32_FIND_DATAA fdFileData;
	HANDLE hFind;
	hFind = FindFirstFileA(szPath, &fdFileData);
	if (hFind == INVALID_HANDLE_VALUE)
	{
		FindClose(hFind);
		return FALSE;
	}
	do
	{
		if (fdFileData.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)
		{
			if (fdFileData.cFileName[0] != '.')
			{
				szPath[strlen(szPath) - 1] = '\0';
				strcat(szPath, fdFileData.cFileName);
				strcat(szPath, "\\*");
				FindFile(szPath, szFileName);
				strset(szPath, 0);
				strcat(szPath, ".\\*");
			}
		}
		FileChecker(szFileName, fdFileData, szPath);
	} while (FindNextFileA(hFind, &fdFileData) != 0);
	FindClose(hFind);
	return (TRUE);
}

/* FileChecker() : Checks whether file is existing the current directory */
void FileChecker(LPCSTR szFileName, WIN32_FIND_DATAA fd, LPSTR szPath)
{
	if (szFileName == NULL)
	{
		printf("Invalid Inputs to FileChecker()\n");
		return;
	}
	CHAR szFilePath[MAX_PATH] = {'\0'};
	int iLen = strlen(szFileName), i = 0, j = 0, k = 0;
	PCHAR szTemp = NULL;
	szTemp = (PCHAR)malloc(sizeof(CHAR) * iLen);
	BOOL bFlag = FALSE, bIsData = FALSE;
	if (szTemp == NULL)
	{
		printf("Unable to allocate memory in FileChecker()\n");
		return;
	}

	if (szFileName[0] == '*' && szFileName[iLen - 1] == '*')
	{
		i = 1;
		while (szFileName[i] != '*')
		{
			szTemp[i - 1] = szFileName[i];
			i++;
		}
		szTemp[i - 1] = '\0';
		if (strstr(fd.cFileName, szTemp) != NULL)
		{
			bIsData = TRUE;
			if (!(fd.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY))
			{
				strcat(szFilePath, szPath);
				szFilePath[strlen(szFilePath) - 1] = '\0';
				strcat(szFilePath, fd.cFileName);
				printf("%s\n", szFilePath);
			}
		}
		return;
	}
	else if (szFileName[iLen - 1] == '*')
	{
		i = 0;
		while (szFileName[i] != '*')
		{
			szTemp[i] = szFileName[i];
			i++;
		}
		szTemp[i] = '\0';
		bFlag = FALSE;
	}
	else if (szFileName[0] == '*')
	{
		i = 1;
		while (szFileName[i] != '\0')
		{
			szTemp[i - 1] = szFileName[i];
			i++;
		}
		szTemp[i - 1] = '\0';
		bFlag = TRUE;
	}
	else
	{
		if (StriNCmp(szFileName, fd.cFileName, iLen - 1, bFlag) == 0)
		{
			bIsData = TRUE;
			if (!(fd.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY))
			{
				strcat(szFilePath, szPath);
				szFilePath[strlen(szFilePath) - 1] = '\0';
				strcat(szFilePath, fd.cFileName);
				printf("%s\n", szFilePath);
			}
		}
		return;
	}
	if (StriNCmp(szTemp, fd.cFileName, iLen - 1, bFlag) == 0)
	{
		bIsData = TRUE;
		if (!(fd.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY))
		{
			strcat(szFilePath, szPath);
			szFilePath[strlen(szFilePath) - 1] = '\0';
			strcat(szFilePath, fd.cFileName);
			printf("%s\n", szFilePath);
		}
	}
	return;
}

/* StriNCmp() : compare N characters between two strings where N may be first or last 
*  depend on bFlag value  */
int StriNCmp(LPCSTR cStr1, LPCSTR cStr2, int iN, BOOL bFlag)
{
	if (cStr1 == NULL || cStr2 == NULL)
	{
		printf("Invalid Input\n");
		return -1;
	}

	LPCSTR cEnd1 = cStr1;
	LPCSTR cEnd2 = cStr2;

	if (iN < 0)
	{
		iN = -iN;
	}
	if (bFlag == FIRST)
	{
		while (*cEnd1 != '\0' && *cEnd2 != '\0' && iN != 0)
		{
			if ((*cEnd1 != *cEnd2) && (*cEnd1 != *cEnd2 + 32) && (*cEnd1 != *cEnd2 - 32) && iN != 0)
			{
				break;
			}
			cEnd1++;
			cEnd2++;
			iN--;
		}
	}
	else if (bFlag == LAST)
	{
		while (*(cEnd1 + 1) != '\0')
		{
			cEnd1++;
		}
		while (*(cEnd2 + 1) != '\0')
		{
			cEnd2++;
		}

		while (*cEnd1 == *cEnd2 && iN != 0)
		{
			if ((*cEnd1 != *cEnd2) && (*cEnd1 != *cEnd2 + 32) && (*cEnd1 != *cEnd2 - 32) && iN != 0)
			{
				break;
			}
			cEnd1--;
			cEnd2--;
			iN--;
		}
	}
	if (*cEnd1 == *cEnd2 || iN == 0)
		return 0;
	else
		return *cEnd1 - *cEnd2;

} // end of StrNCmp()
