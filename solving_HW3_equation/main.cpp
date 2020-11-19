// Date: 2020.9.22
// Author: Jiaze Sun

#include <iostream>
#include <cmath>
#include <string>
#include "Polynomial.h"
#include "LinearEquations.h"

using namespace std;

int main()
{
    //----------------- test 1

    // // x^5+3x^3-6x^2 0.1 2   error
    // // 4x^2+8x-6 -3 -0.4444  error

    // Polynomial P;
    // float a, b;
    // float tor = 1e-7;       //precision
    // float x = 0;            //solution

    // getline(cin, P.str);
    // cin >> a >> b;
    // P.polySimplify();
    // P.polyDerivate();
    // P.polyDDerivate();
    // P.ifInputValidTest1(a, b);

    // bool if_iterate = true;
    // float x_0 = (a+b)/2;
    // float x_1 = x_0;
    // while(P.if_input_valid&&if_iterate)
    // {
    //     // iterate
    //     x_1 = x_0-P.polyResult(P.ploy_sim, 10, x_0)/P.polyResult(P.ploy_der, 10, x_0);

    //     // if iterate
    //     if(abs(x_1-x_0)<=tor)
    //     {
    //         if_iterate = false;
    //         x = x_1;
    //     }
    //     x_0 = x_1;
    // }

    // // print
    // x = P.doubleCut(x, 4);
    // if(P.if_input_valid)
    //     printf("%.4f",x);
    // else
    //     printf("error");
    
    //------------------ test 2

    bool if_input_valid = true;
    bool *pif = &if_input_valid;
    
    string str[100];        // input string
    double equation[100][100] = {0};        // Ax = b: A
    double value[100] = {0};                // Ax = b: b
    double *pequ[100];      // point to equation
    double *pval = &value[0];   // point to value

    int m = 0;      // m equations
    int n = 0;      // n variables
    double x[100] = {0};
    int pn[100] = {0};      // position of x
    bool if_input_continue = true;

    // while(getline(cin, str[m+1]))        // equ[1], equ[2], ..... equ[m]
    // {
    //         m = m+1;
    // }

    while(if_input_continue)        // equ[1], equ[2], ..... equ[m]
    {
        getline(cin, str[m+1]);
        if(str[m+1].empty())
            if_input_continue = false;
        else
            m = m+1;
    }

    for(int i=1; i<=m; i++)
    {
        pequ[i] = &equation[i][0];
        simplify(str[i], pif, pequ[i], pval+i);
    }
    
    // get variables number
    double sum[100] = {0};
    for(int i=1; i<=99; i++)
    {
        for(int j=1; j<=m; j++)
        {
            sum[i] = sum[i]+abs(equation[j][i]);
        }
        if(sum[i]>1e-10)
        {
            n = n+1;
            pn[n] = i;      // pn[1] = n_1, ... pn[n] = n_n
        }
    }

    //  Gauss
    if(if_input_valid)
    {
        if(m<n)
            if_input_valid = false;
        else
        {
            for(int i=1; i<=n; i++)     // colum: pn[1]-pn[n]
            {
                if_input_valid = false;
                for(int k=i; k<=m; k++) // exchange 0
                {
                    if(abs(equation[k][pn[i]])>1e-5)
                    {
                        exchange(pequ[k], pval+k, pequ[i], pval+i);
                        if_input_valid = true;
                        break;
                    }
                }

                if(if_input_valid)      // row: i+1 - m
                {
                    for(int k=i+1; k<=m; k++)
                    {
                        double temp = equation[k][pn[i]]/equation[i][pn[i]];
                        rowAdd(pequ[k], pval+k, pequ[i], pval+i, temp);
                    }
                }
            }

            if(if_input_valid)
            {
                for(int i=n; i>=1; i--)     // colum: pn[n] - pn[1]
                {
                    for(int k=i-1; k>=1; k--)
                    {
                        value[k] = value[k]-equation[k][pn[i]]/equation[i][pn[i]]*value[i];
                    }
                    x[i] = value[i]/equation[i][pn[i]];
                }

                if(m>n)
                {
                    double sumb = 0;
                    for(int i=n+1; i<=m; i++)
                    {
                        sumb = sumb+abs(value[i]);
                    }
                    if(sumb>1e-5)
                        if_input_valid = false;
                }
            }
        }
    }
    
    // print
    if(if_input_valid)
    {
        for(int i=1; i<=n; i++)
        {
            x[i] = doubleCut(x[i], 4);
            printf("%.4f ", x[i]);
        }
    }
    else
    {
        printf("error");
    }
    
    return 0;
}

// x_1+5=2
// x_1+x_2=3.56 x_1-x_2=3.32
// x_1-x_2=0 x_2-x_3=0 x_1+x_1+x_3=4.677