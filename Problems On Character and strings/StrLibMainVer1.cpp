
#include "StrLib.cpp"

int main()
{
    char cArr1[MAXLEN * 2] = {'\0'};
    char cArr2[MAXLEN] = {'\0'};
    char cInput[MAXLEN] = {'\0'};
    Strings sObj;
    int iRet = 0, iN = 0;
    char cFlag = 0;
    bool bRet = false, bRunning = true;

    cout << "Enter the string\n";
    scanf("%[^\n]", cArr1);

    while(bRunning)
    {
        fflush(stdin);
        sObj.StrSet(cInput, '\0');
        cout << "\nStrLib : >";
        scanf(" %s", cInput);

        if(sObj.StriCmp(cInput, "StrLen") == 0)
        {
            iRet = sObj.StrLen(cArr1);
            cout << "Length is : >\t" << iRet;
        }
        else if(sObj.StriCmp(cInput, "StrLwr") == 0)
        {
            sObj.StrLwr(cArr1);
            cout << "Output : >\t" << cArr1 << endl;
        }
        else if(sObj.StriCmp(cInput, "StrNLwr") == 0)
        {
            cout << "Enter n : >\t";
            cin >> iN;
            cout << "Enter Position (0 = First, 1 = Last) :>\t";
            cin >> cFlag;

            sObj.StrNLwr(cArr1, iN, cFlag);
            cout << "Output : >\t" << cArr1 << endl;
        }
        /*else if(sObj.StriCmp(cInput, "StrUpr") == 0)
        {
            sObj.StrLwr(cArr1);
            cout << "Output :\t" << cArr1 << endl;            
        }
        else if(sObj.StriCmp(cInput, "StrTgl") == 0)
        {
            
        }
        else if(sObj.StriCmp(cInput, "StrCat") == 0)
        {
            
        }
        else if(sObj.StriCmp(cInput, "StrNCat") == 0)
        {
            
        }
        else if(sObj.StriCmp(cInput, "StrCpy") == 0)
        {
            
        }
        else if(sObj.StriCmp(cInput, "StrNCpy") == 0)
        {
            
        }
        else if(sObj.StriCmp(cInput, "StrCpyCap") == 0)
        {
            
        }
        else if(sObj.StriCmp(cInput, "StrCpyCapX") == 0)
        {
            
        }
        else if(sObj.StriCmp(cInput, "StrCpyLwr") == 0)
        {
            
        }
        else if(sObj.StriCmp(cInput, "StrCpyLwrX") == 0)
        {
            
        }
        else if(sObj.StriCmp(cInput, "StrCpySpace") == 0)
        {
            
        }
        else if(sObj.StriCmp(cInput, "StrCpyRev") == 0)
        {
            
        }
        else if(sObj.StriCmp(cInput, "StrCpyTgl") == 0)
        {
            
        }
        else if(sObj.StriCmp(cInput, "StrRev") == 0)
        {
            
        }
        else if(sObj.StriCmp(cInput, "StrNRevF") == 0)
        {
            
        }
        else if(sObj.StriCmp(cInput, "StrNRevL") == 0)
        {
            
        }*/
        else if(sObj.StriCmp(cInput, "exit") == 0)
        {
            bRunning = false;
        }
        else
        {
            cout << "Please enter valid Option or try \'help\'\n";
        }
    }
    return 0;
}