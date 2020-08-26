
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
            else if(sObj.StriCmp(cInput[0], "strlwr") == 0)
            {
                sObj.StrLwr(cInput[1]);
                cout << cInput[1] << endl;
            }
            else if(sObj.StriCmp(cInput[0], "strupr") == 0)
            {
                sObj.StrUpr(cInput[1]);
                cout << cInput[1] << endl;
            }
            else if(sObj.StriCmp(cInput[0], "strtgl") == 0)
            {
                sObj.StrTgl(cInput[1]);
                cout << cInput[1] << endl;
            }
            else if(sObj.StriCmp(cInput[0], "strrev") == 0)
            {
                sObj.StrRev(cInput[1]);
                cout << cInput[1] << endl;
            }
            else if(sObj.StriCmp(cInput[0], "ispldrm") == 0)
            {
                bRet = sObj.IsPldrm(cInput[1]);
                if(bRet == true)
                {
                    cout << "Palidrome String\n";
                }
                else
                {
                    cout << "Not Palindrome string\n";
                }
            }
            else if(sObj.StriCmp(cInput[0], "isipldrm") == 0)
            {
                bRet = sObj.IsiPldrm(cInput[1]);
                if(bRet == true)
                {
                    cout << "Palidrome String\n";
                }
                else
                {
                    cout << "Not Palindrome string\n";
                }
            }
            else if(sObj.StriCmp(cInput[0], "wordcnt") == 0)
            {
                iRet = sObj.WordCnt(cInput[1]);
                cout << "Word Count is:\t" << iRet;
            }
            else if(sObj.StriCmp(cInput[0], "wordrev") == 0)
            {
                sObj.WordRev(cInput[1]);
                cout << cInput[1] << endl;
            }
            else if(sObj.StriCmp(cInput[0], "maxoccur") == 0)
            {
                sObj.MaxOccur(cInput[1]);                
            }
            else if(sObj.StriCmp(cInput[0], "charscnt") == 0)
            {
                sObj.CharsCnt(cInput[1]);
            }
            else if(sObj.StriCmp(cInput[0], "countlwr") == 0)
            {
                iRet = sObj.CountLwr(cInput[1]);
                cout << iRet << endl;
            }
            else if(sObj.StriCmp(cInput[0], "countupr") == 0)
            {
                iRet = sObj.CountUpr(cInput[1]);
                cout << iRet << endl;
            }
            else if(sObj.StriCmp(cInput[0], "countspecial") == 0)
            {
                iRet = sObj.CountSpecials(cInput[1]);
                cout << iRet << endl;
            }
            else if(sObj.StriCmp(cInput[0], "countspace") == 0)
            {
                iRet = sObj.CountSpace(cInput[1]);
                cout << iRet << endl;
            }
        }
        else
        {
            cout << "Enter Valid command (type \'help\'";
        }
        }
    return 0;
}