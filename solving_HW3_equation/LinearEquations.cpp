#include "LinearEquations.h"

void ifNumber(char k, bool *pif)
{
    if(!*pif)
    {
        switch (k)
        {
            case '0':
            case '1':
            case '2':
            case '3':
            case '4':
            case '5':
            case '6':
            case '7':
            case '8':
            case '9': break;
            default: *pif = false; break;
        }
    }
}

void simplify(string str, bool *pif, double *pequ, double *pval)
{
    // input valid: other worlds
    for (char k : str)
    {
        switch (k)
        {
            case '=':
            case '+':
            case '-':
            case '_':
            case '.':
            case 'x':
            case '0':
            case '1':
            case '2':
            case '3':
            case '4':
            case '5':
            case '6':
            case '7':
            case '8':
            case '9': break;
            default: *pif = false; break;
        }
    }

    // read cut
    if(*pif)
    {
        // read a cut
        int num_equ = str.find('=');    //replace '=' with '-'
        if(num_equ==-1)
            *pif = false;
        else
        {
            if(str[num_equ+1]=='-')     // =- to +
            {
                str[num_equ] = '+';
                str.erase(num_equ+1,1);
            }
            else
            {
                str[num_equ] = '-';
            }
        }
        if(str.find('=')!=-1)       // error: = ...=
            *pif = false;

        bool if_cut = true;     // if str_input is not empty
        string s;       // a cut: '-36.0012x_25'
        while(if_cut && *pif)
        {
            // get a cut of input str: cut str befor '+' or '-'
                // result: +36.2531x_35
            int num_p = str.find('+', 1);
            int num_n = str.find('-', 1);
            int cut_point;
            if (num_p ==-1)
                cut_point = num_n;
            else if (num_n == -1)
                cut_point = num_p;
            else
                cut_point = min(num_p, num_n);
            s = str.substr(0, cut_point);
            str.erase(0, cut_point);
            if_cut = !str.empty();

            int len = s.length();   // the length of a cut
            double coefficient = 0;
            int index = 0;
            int if_sign = 0;                // the sign position: -1 or 0
            double sign = 1;                   // 1 or -1
            int if_dot = s.find('.');       // the dot position
            int if_x = s.find('x');         // the x position
            int n1 = 0;                     // number before dot
            int n2 = 0;                     // number after dot
            int if_down = s.find('_');        // '_' position
            int n3 = 0;                     // number index

            // get the sign
            int sign_p = -1, sign_n = -1;
            sign_p = s.find('+');
            sign_n = s.find('-');
            if ((sign_p == -1) && (sign_n == 0))
                sign = -1;
            else if ((sign_p == 0) && (sign_n == -1))
                sign = 1;
            else
            {
                sign = 1;
                if_sign = -1;
            }

            // if input valid: formation of a cut
            *pif = false;
            if(if_dot!=-1 && if_x!=-1 && if_down!=-1)
            {
                n1 = if_dot-if_sign-1;
                n2 = if_x-if_dot-1;
                n3 = len-if_down-1;
                if(n1>0 && n2<=4 && n2>=1 && n3>=1 && n3<=2 && if_down-if_x==1)
                {
                    *pif = true;
                }
            }
            else if(if_dot==-1 && if_x!=-1 && if_down!=-1)
            {
                n1 = if_x-if_sign-1;
                n2 = 0;
                n3 = len-if_down-1;
                if(n1>=0 && n3>=1 && n3<=2 && if_down-if_x==1)
                {
                    *pif = true;
                }
            }
            else if(if_dot!=-1 && if_x==-1 && if_down==-1)
            {
                n1 = if_dot-if_sign-1;
                n2 = len-if_dot-1;
                n3 = 0;
                if(n1>0 && n2>=1 && n2<=4)
                {
                    *pif = true;
                }
            }
            else if(if_dot==-1 && if_x==-1 && if_down-1)
            {
                n1 = len-if_sign-1;
                n2 = 0;
                n3 = 0;
                if(n1>0)
                {
                    *pif = true;
                }
            }
            
            // get the coefficient and index
            if (*pif)
            {
                // coefficient
                double sum = 0;
                if (n1==0)      // x or -x
                {
                    sum = 1;
                    coefficient = sign*sum;
                }
                else
                {
                    for (int i = 0; i < n1; i++)
                    {
                        ifNumber(s[if_sign + i + 1], pif);
                        sum = sum + (pow(10, n1 - i - 1)) * double(s[if_sign + i + 1] - '0');
                    }
                    if (n2==0)
                    {
                        coefficient = sign*sum;
                    }
                    else
                    {
                        for (int i = 0; i < n2; i++)
                        {
                            ifNumber(s[if_dot + i + 1], pif);
                            sum = sum + (pow(10, -1 - i)) * double(s[if_dot + i + 1] - '0');
                        }
                        coefficient = sign*sum;
                    }
                }

                // index
                if(n3==0)
                    index = 0;
                else
                {
                    for (int i = 0; i < n3; i++)
                    {
                        ifNumber(s[if_down + i + 1], pif);
                        index = index + int(pow(10, n3 - i - 1)) * int(s[if_down + i + 1] - '0');
                    }
                }
                // save in equatin
                if (*pif)
                {
                    *(pequ+index) = *(pequ+index) + coefficient;
                }
            }
        }
    }
    *pval = -*pequ;
}

void exchange(double *pequ1, double *pval1, double *pequ2, double *pval2)
{
    double temp = 0;
    for(int i=0; i<=99; i++)
    {
        temp = *(pequ1+i);
        *(pequ1+i) = *(pequ2+i);
        *(pequ2+i) = temp;
    }
    temp = *pval1;
    *pval1 = *pval2;
    *pval2 = temp;
}

void rowAdd(double *pequ1, double *pval1, double *pequ2, double *pval2, double k)
// e1 = e1-k*e2
{
    for(int i=0; i<=99; i++)
    {
        *(pequ1+i) = *(pequ1+i)-k**(pequ2+i);
    }
    *pval1 = *pval1-k**pval2;
}

double doubleCut(double x, int n)
{
    // string x_str = to_string(x*1e15);
	// int dot = x_str.find('.');
	// x_str = x_str.substr(0, dot+n-15);
	// float x_cut = stod(x_str, 0)/pow(10, n);
    // return x_cut;

    // string x_str = to_string(x*pow(10,n));
	// int dot = x_str.find('.');
	// x_str = x_str.substr(0, dot+n+1);
	// float x_cut = stod(x_str, 0)/pow(10, n);
    // return x_cut;

    if(x>0)
        x = x+1e-8;
    else
        x = x-1e-8;
    int x_w = 10000*x;
    float x_cut = float(x_w)/10000;
    return x_cut;
}