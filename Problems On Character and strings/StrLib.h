#include<iostream>

#define MAXLEN       30
#define ERROR      -999
#define IN            1
#define OUT           0
#define MAX_CHAR    127

using namespace std;

class Strings
{
    public:
        char *cStr;
        
        Strings();
        int  StrLen(const char*);
        void StrLwr(char*);
        void StrUpr(char*);
        void StrTgl(char*);
        void StrCat(char*, const char*);
        void StrNCat(char*, const char*, int);
        void StrCpy(const char*, char*);
        void StrNCpy(const char*, char*, int);
        void StrCpyCap(const char*, char*);
        void StrCpyCapX(const char*, char*);
        void StrCpyLwr(const char*, char*);
        void StrCpyLwrX(const char*, char*);
        void StrCpySpace(const char*, char*);
        void StrCpyRev(const char*, char*);
        void StrCpyTgl(const char*, char*);
        void StrRev(char*);
        void StrNRevF(char*, int);
        void StrNRevL(char*, int);
        void StrRangeRev(char*, int, int);
        int  StrCmp(const char*, const char*);
        int  StriCmp(const char*, const char*);
        int  StrNCmp(const char*, const char*, int);
        void StrSet(char*, char);
        void StrNSetF(char*, char, int);
        void StrNSetL(char*, char, int);
        int  WordCnt(const char*);
        void WordRev(char*);
        void MaxOccur(const char*);
        int  FirstOccur(const char *, char);
        int  LastOccur(const char *, char);
        bool IsPldrm(const char *);
        bool IsiPldrm(const char *);
        void CharsCnt(const char *);
        int  CountLow(const char *);
        int  CountCap(const char *);
        int  CountSpace(const char *);
        int  CountSpecials(const char *);
        bool IsAgrm(const char *, const char *);
};
