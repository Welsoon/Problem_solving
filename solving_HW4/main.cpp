#include <iostream>
#include <string>
#include <cmath>

#include "Interpolation.h"
#include "SimpleLinearRegression.h"

using namespace std;

int main()
{
    //---------------------exercise 1----------------

    // string str_x;
    // string str[100];
    // int n = 0;
    // getline(cin, str_x);
    // bool if_input_continue = true;

    // while(getline(cin, str[n]))
    // {
    //     n = n+1;
    // }
    // n = n-1;

    // // while(if_input_continue)        // x0, (x0,y0), (x1,y1), .... (xn,yn)
    // // {
    // //     getline(cin, str[n]);
    // //     if(str[n].empty())
    // //     {
    // //         if_input_continue = false;
    // //         n = n-1;
    // //     }
    // //     else
    // //         n = n+1;
    // // }

    // double x[100] = {0};
    // double y[100] = {0};
    // double a[100] = {0};
    // double x0 = 0;

    // simplify(str_x, &x0);
    // for(int i=0; i<=n; i++)
    // {
    //     simplify(str[i], &x[i], &y[i]);
    // }

    // double h = rankUp(&x[0], &y[0], n);
    // coefficient(&y[0], h, n, &a[0]);

    // double res = result(&x[0], &a[0], x0, n);
    // res = doubleCut(res);
    // if(if_valid)
    // {
    //     printf("%.4f", res);
    // }
    // else
    // {
    //     printf("error");
    // }

    //---------------------exercise 2----------------

    string str_x;
    string str[100];
    int n = 0;
    getline(cin, str_x);
    bool if_input_continue = true;

    while(getline(cin, str[n]))
    {
        n = n+1;
    }

    if(n<2)
    {
        if_valid = false;
    }

    // while(if_input_continue)        // x0, (x0,y0), (x1,y1), .... (xn,yn)
    // {
    //     getline(cin, str[n]);
    //     if(str[n].empty())
    //     {
    //         if_input_continue = false;
    //         // n = n-1;
    //     }
    //     else
    //         n = n+1;
    // }

    double x[100] = {0};
    double y[100] = {0};
    double a=0, b=0;
    double x0 = 0;
    double r = 0;

    simplify(str_x, &x0);
    for(int i=0; i<n; i++)
    {
        simplify(str[i], &x[i], &y[i]);
    }

    covCefficient(x, y, &a, &b, &r, n);
    result2(a, b, x0);
    if(!if_valid)
    {
        printf("error\n");
        printf("error\n");
        printf("error");
    }
    else
    {
        r = doubleCut(r);
        printf("%.4f\n",r);
        if(abs(r)>0.75)
        {
            double res = result2(a, b, x0);
            a = doubleCut(a);
            b = doubleCut(b);
            res = doubleCut(res);
            printFunction(a, b);
            printf("%.4f", res);
        }
        else
        {
            printf("error\n");
            printf("error");
        }
        
    }
    


    return 0;
}