#include "StringLibrary.cpp"

int main()
{
    char cArr[MAXLEN] = {'\0'};

    cout << "Enter the string\n" ;    
    cin.get(cArr, MAXLEN, '\n');
    cout << cArr << endl;

    Strings sObj; 

    return 0;
}