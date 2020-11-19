#include "Interpolation.h"

bool if_valid = true;

void simplify(string str, double *x, double *y)
{
    string s[2];
    if(if_valid)
    {
        // input valid: other worlds
        for (char k : str)
        {
            switch (k)
            {
                case '-':
                case '.':
                case ' ':
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
                default: if_valid = false; break;
            }
        }

        // cut string to 2 number
        int pos_space = str.find(' ');
        if(pos_space==-1)
        {
            if_valid = false;
        }
        else
        {
            int length_str = str.length();
            s[0] = str.substr(0, pos_space);
            s[1] = str.substr(pos_space+1, length_str-pos_space-1);
        }
    }

    // read number
    double result[2] = {0,0};
    if(if_valid)
    {
        for(int i=0; i<=1; i++)
        {
            int pos_dot = s[i].find('.');
            int len = s[i].length();
            int if_sign = s[i].find('-');
            double sign = 0;
            int n1 = 0;
            int n2 = 0;
            if(if_sign==-1)
            {
                sign = 1;
            }
            else if(if_sign==0)
            {
                sign = -1;
            }
            else
            {
                if_valid = false;
            }

            // formation error
            if(if_valid)
            {
                if_valid = false;
                if(pos_dot==-1)
                {
                    n1 = len-if_sign-1;
                    n2 = 0;
                    if(n1>=0)
                    {
                        if_valid = true;
                    }
                }
                else
                {
                    n1 = pos_dot-if_sign-1;
                    n2 = len-pos_dot-1;
                    if((n1>=0)&&(n2>=0)&&(n2<=4))
                    {
                        if_valid = true;
                    }
                }
            }

            // calculate
            if(if_valid)
            {
                double sum = 0;
                for (int j = 0; j < n1; j++)
                {
                    ifNumber(s[i][if_sign + j + 1]);
                    sum = sum + (pow(10, n1 - j - 1)) * double(s[i][if_sign + j + 1] - '0');
                }

                if (n2==0)
                {
                    result[i] = sign*sum;
                }
                else
                {
                    for (int j = 0; j < n2; j++)
                    {
                        ifNumber(s[i][pos_dot + j + 1]);
                        sum = sum + (pow(10, -1 - j)) * double(s[i][pos_dot + j + 1] - '0');
                    }
                    result[i] = sign*sum;
                }
            }
        }
    }

    *x = result[0];
    *y = result[1];
}

void simplify(string str, double *x)
{
    if(if_valid)
    {
        // input valid: other worlds
        for (char k : str)
        {
            switch (k)
            {
                case '-':
                case '.':
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
                default: if_valid = false; break;
            }
        }
    }

    // read number
    double result = 0;
    if(if_valid)
    {
        for(int i=0; i<=1; i++)
        {
            int pos_dot = str.find('.');
            int len = str.length();
            int if_sign = str.find('-');
            double sign = 0;
            int n1 = 0;
            int n2 = 0;
            if(if_sign==-1)
            {
                sign = 1;
            }
            else if(if_sign==0)
            {
                sign = -1;
            }
            else
            {
                if_valid = false;
            }

            // formation error
            if(if_valid)
            {
                if_valid = false;
                if(pos_dot==-1)
                {
                    n1 = len-if_sign-1;
                    n2 = 0;
                    if(n1>=0)
                    {
                        if_valid = true;
                    }
                }
                else
                {
                    n1 = pos_dot-if_sign-1;
                    n2 = len-pos_dot-1;
                    if((n1>=0)&&(n2>=0)&&(n2<=4))
                    {
                        if_valid = true;
                    }
                }
            }

            // calculate
            if(if_valid)
            {
                double sum = 0;
                for (int j = 0; j < n1; j++)
                {
                    ifNumber(str[if_sign + j + 1]);
                    sum = sum + (pow(10, n1 - j - 1)) * double(str[if_sign + j + 1] - '0');
                }

                if (n2==0)
                {
                    result = sign*sum;
                }
                else
                {
                    for (int j = 0; j < n2; j++)
                    {
                        ifNumber(str[pos_dot + j + 1]);
                        sum = sum + (pow(10, -1 - j)) * double(str[pos_dot + j + 1] - '0');
                    }
                    result = sign*sum;
                }
            }
        }
    }

    *x = result;
}

double rankUp(double *x, double *y, int n)
{
    // the number of point is n+1, h is step length
    // Bubble sort
    double temp_x, temp_y;
    for(int i=n; i>=1; i--)
    {
        for(int j=0; j<=i-1; j++)
        if(x[j]>x[j+1])
        {
            temp_x = x[j];
            x[j] = x[j+1];
            x[j+1] = temp_x;
            temp_y = y[j];
            y[j] = y[j+1];
            y[j+1] = temp_y;
        }
    }

    // if step euqal
    double h = x[1]-x[0];
    for(int i=2; i<=n; i++)
    {
        if(abs(x[i]-x[0]-double(i)*h)>1e-5)
        {
            if_valid = false;
        }
    }
    return h;
}

void coefficient(double *y, double h, int n, double *a)
{
    // number of point is n+1
    // difference
    for(int i=n; i>=1; i--)
    {
        for(int j=n; j>n-i; j--)
        {
            y[j] = y[j]-y[j-1];
        }
    }
    for(int i=0; i<=n; i++)
    {
        a[i] = y[i]/double(factorial(i))/pow(h,i);
    }
}

int factorial(int k)
{
    int result = 1; //k = 0
    for(int i=1; i<=k; i++)
    {
        result = result*i;
    }
    return result;
}

void ifNumber(char k)
{
    if(if_valid)
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
            default: if_valid = false; break;
        }
    }
}

double result(double *x, double *a, double x0, int n)
{
    // number of point is n+1
    double res = a[0];
    for(int i=1; i<=n; i++)
    {
        double temp = a[i];
        for(int j=0; j<i; j++)
        {
            temp = temp*(x0-x[j]);
        }
        res = res+temp;
    }
    return res;
}

double doubleCut(double x)
{
    if(x>0)
        x = x+1e-8;
    else
        x = x-1e-8;
    int x_w = 10000*x;
    double x_cut = double(x_w)/10000;
    return x_cut;
}