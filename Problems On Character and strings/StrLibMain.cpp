
#include "StrLib.cpp"

int main()
{
    char cArr1[MAXLEN * 2] = {'\0'};
    char cArr2[MAXLEN] = {'\0'};
    int iRet = 0;
    bool bRet = false;

    cout << "Enter the string\n";
    scanf("%[^\n]", cArr1);

    cout << "Enter the string\n" ;
    scanf(" %[^\n]", cArr2);

    Strings sObj;

    iRet = sObj.StrLen(cArr1);
    cout << iRet << endl;

    iRet = sObj.StrLen(cArr2);
    cout << iRet << endl;

    return 0;
}