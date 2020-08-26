
#include "StrLib.cpp"

int main()
{
    char cArr1[MAXLEN * 2] = {'\0'};
    char cArr2[MAXLEN] = {'\0'};
    char cStr[MAXLEN * 5] = {'\0'};
    char cInput[5][MAXLEN * 5] = {'\0'};
    Strings sObj;
    int iRet = 0, iN = 0, iCount = 0;
    char cFlag = 0;
    bool bRet = false, bRunning = true;

    while(bRunning)
    {
        fflush(stdin);
        sObj.StrCpy("", cStr);
        cout << "\nStrLib : >";
        fgets(cStr, 80, stdin);

        iCount = sscanf(cStr, "%s %[^\t] %[^\t] %s %s",
                        cInput[0], cInput[1], cInput[2], cInput[3], cInput[4]);
        if(iCount == 1)
        {
            if(sObj.StriCmp(cInput[0], "clear") == 0)
            {
                system("cls");
            }
            if(sObj.StriCmp(cInput[0], "exit") == 0)
            {
                bRunning = false;
            }
        }
        else if(iCount == 2)
        {
            if(sObj.StriCmp(cInput[0], "strlen") == 0)
            {
                iRet = sObj.StrLen(cInput[1]);
                cout << iRet;
            }
        }
        else
        {
            cout << "Enter Valid command (type \'help\'";
        }
        }
    return 0;
}