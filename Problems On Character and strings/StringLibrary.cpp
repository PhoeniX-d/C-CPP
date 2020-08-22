/*
*   Program containing all string library functions
*/

// Headers
#include<stdlib.h>
#include<iostream>

#define MAXLEN      30

using namespace std;

class Strings
{
    public:
        const char *cSrc;
        Strings();
};

Strings::Strings()
{
    cSrc = NULL;
}
int main()
{
    char cArr[MAXLEN] = {'\0'};

    cout << "Enter the string\n" ;


    cin.get(cArr, MAXLEN, '\n');

    cout << cArr << endl;
    Strings sObj; 

    return 0;
}