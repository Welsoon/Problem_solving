#include "Question_1.h"
#include "Question_2.h"
#include "Question_3.h"
int main()
{
    int exercise = 3;

    //-------------------exercise 1---------------
    if (exercise==1)
    {
        boat P;
        P.input();
        P.fun();
        P.myprintf();
    }
    //-------------------exercise 2---------------
    else if (exercise==2)
    {
        sequ P;
        P.input();
        P.fun();
        P.myprintf();
    }
    //-------------------exercise 3---------------
    else if (exercise==3)
    {
        LPS P;
        P.input();
        P.fun();
        P.myprintf();
    }
    return 0;
}

// 40 
// 2 -1 -4 5 -2 -4 14 -5 -2 -11 25 45 -34 -2 100 -4 92 54 -43 -23 2 -1 -4 5 -2 -4 14 -5 -2 -11 25 45 -34 -2 100 -4 92 54 -43 -23
// 478 11 38

// void PrintLPS(unsigned char **pDir, const char *s, int i, int j, ostream &os)
// o rts  i, ns  sn ,i  str o

// ^&^&%^^()>>,.,^%&^&%$%&&^
// ^&&%^^,,^^%&&^