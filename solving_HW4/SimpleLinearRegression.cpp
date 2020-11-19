#include "SimpleLinearRegression.h"

void covCefficient(double *x, double *y, double *a, double *b, double *r, int n)
{
    double aver_x, aver_y, Lxx=0, Lxy=0, Lyy=0;
    double sum_x=0, sum_y=0;
    for(int i=0; i<n; i++)
    {
        sum_x = sum_x+x[i];
        sum_y = sum_y+y[i];
    }
    aver_x = sum_x/double(n);
    aver_y = sum_y/double(n);
    
    for(int i=0; i<n; i++)
    {
        double temp_x = x[i]-aver_x;
        double temp_y = y[i]-aver_y;
        Lxx = Lxx+temp_x*temp_x;
        Lxy = Lxy+temp_x*temp_y;
        Lyy = Lyy+temp_y*temp_y;
    }
    *b = Lxy/Lxx;
    *a = aver_y-*b*aver_x;
    *r = Lxy/sqrt(Lxx*Lyy);
}

void printFunction(double a, double b)
{
    if(a>0)
        printf("y=%.4f*x+%.4f\n", b, a);
    else
        printf("y=%.4f*x%.4f\n", b, a);
}

double result2(double a, double b, double x)
{
    return b*x+a;
}
