
#include "Polynomial.h"

void Polynomial::polySimplify(Polynomial P)
{
    bool if_cut = true;     // if str_input is empty
    if_input_valid = true;  // if input is valid
    string s;       // a cut: '-36.0012x^25'

	// if input valid: other words
    for (char k : str)
    {
        switch (k)
        {
        case '+':
        case '-':
        case '^':
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
        default: if_input_valid = false; break;
        }
    }

	// read a cut
    while (if_cut && if_input_valid)
    {
        // get a cut of input str: cut str befor '+' or '-'
            // result: +36.2531x^35
        int num_p = str.find('+', 1);
        int num_n = str.find('-', 1);
        int cut_point;
        if (num_p == -1)
            cut_point = num_n;
        else if (num_n == -1)
            cut_point = num_p;
        else
            cut_point = min(num_p, num_n);
        s = str.substr(0, cut_point);
        str.erase(0, cut_point);
        if_cut = !str.empty();

        // init
        int len = s.length();   // the length of a cut
        double coefficient = 0;
        int index = 0;
        int if_sign = 0;                // the sign position: -1 or 0
        int sign = 1;                   // 1 or -1
        int if_dot = s.find('.');       // the dot position
        int if_x = s.find('x');         // the x position
        int n1 = 0;                     // number before dot
        int n2 = 0;                     // number after dot
        int if_up = s.find('^');        // '^' position
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
        if_input_valid = false;
        if (if_dot!=-1)
        {
            n1 = if_dot-if_sign-1;
            if (n1>0&&if_x!=-1)
            {
                n2 = if_x-if_dot-1;
                if (n2>=1&&if_up!=-1)
                {
                    n3 = len-if_up-1;
                    if (n3>=1&&(if_up-if_x==1))
                        if_input_valid = true;
                }
                else if (n2>=1&&if_up==-1)
                {
                    n3 = 0;
                    if(len-if_x==1)
                        if_input_valid = true;
                }
            }
            else if (n1>0&&if_x==-1)
            {
                n2 = len-if_dot-1;
                n3 = 0;
                if (n2>=1&&if_up==-1)
                    if_input_valid = true;
            }
        }
        else
        {
            if (if_x!=-1)
            {
                n1 = if_x-if_sign-1;
                n2 = 0;
                if (n1>=0&&if_up!=-1)
                {
                    n3 = len-if_up-1;
                    if (n3>=1&&(if_up-if_x==1))
                        if_input_valid = true;
                }
                else if (n1>=0&&if_up==-1)
                {
                    n3 = 0;
                    if (len-if_x==1)
                        if_input_valid = true;
                }
            }
            else
            {
                n1 = len-if_sign-1;
                n2 = 0;
                n3 = 0;
                if (n1>=1&&if_up==-1)
                    if_input_valid = true;   
            }
            
        }

        // get the coefficient and index
        if (if_input_valid)
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
                    sum = sum + (myPow(10, n1 - i - 1)) * double(s[if_sign + i + 1] - '0');
                }
                if (n2==0)
                {
                    coefficient = sign*sum;
                }
                else
                {
                    for (int i = 0; i < n2; i++)
                    {
                        sum = sum + (pow(10, -1 - i)) * double(s[if_dot + i + 1] - '0');
                    }
                    coefficient = sign*sum;
                }  
            }

            // index
            if (n3==0&&if_x==-1)
            {
                index = 0;
            }
            else if (n3==0&&if_x!=-1)
            {
                index = 1;
            }
            else
            {
                for (int i = 0; i < n3; i++)
                {
                    index = index + int(pow(10, n3 - i - 1)) * int(s[if_up + i + 1] - '0');
                }
            }
        }

        //save in array
        if (if_input_valid)
        {
            ploy_sim[index] = ploy_sim[index] + coefficient;
        }
    }

}

void Polynomial::polyDerivate(Polynomial P)
{
    if (if_input_valid)
    {
        for (int i=1; i<=99; i++)
        {
            ploy_der[i-1] = double(i)*ploy_sim[i];
        }
    }
}

double Polynomial::polyResult(Polynomial P, double x)
{
	double sum = 0;
	for (int i=0; i<=99; i++)
	{
		sum = sum+ploy_sim[i]*myPow(x,i);
	}
	return sum;
}

void Polynomial::printPolynomial(double *a)
{
    // if x zero
    bool if_zero = false;
    double sumAbs = 0;
    for (int i=0; i<=99; i++)
    {
        sumAbs = sumAbs+abs(a[i]);
    }
    if (sumAbs<0.001)
        if_zero = true;

     // if not valid: print error
	if (!if_input_valid)
    {
        printf("error\n");
    }
	else
    {
        if (if_zero)
            // print zero   
            printf("0.0000\n");
        else
        {
            // print polynomial
            for (int i=0; i<=99; i++)
            {
                a[i] = doubleCut(a[i],4);   // 4 number after dot
            }
            int count = 1;
            for (int i = 99; i >= 2; i--)   // print i>=2: 5x^3
            {
                if (a[i] > 0)
                {
                    if (count != 1)
                        printf("+");    // the first cut print without '+'
                    printf("%.4fx^%d", a[i], i);
                    count = count + 1;
                }
                if (a[i] < 0)
                {
                    printf("%.4fx^%d", a[i], i);
                    count = count + 1;
                }
            }

            if (a[1] > 0)           // print i=1: 5x
            {
                if (count != 1)
                    printf("+");
                printf("%.4fx", a[1]);
                count = count + 1;
            }
            else if (a[1] < 0)
            {
                printf("%.4fx", a[1]);
                count = count + 1;
            }

            if (a[0] > 0)       // print i=0: 5
            {
                if (count != 1)
                    printf("+");
                printf("%.4f", a[0]);
                count = count + 1;
            }
            else if (a[0] < 0)
            {
                printf("%.4f", a[0]);
                count = count + 1;
            }
            printf("\n");
        }
    }
}

void Polynomial::polyDivide(Polynomial P1, Polynomial P2)
{
	// P1 / P2
	int m1 = 0, m2 = 0;
	for (int i=0; i<=99; i++)   //get the highest index: m1 m2
	{
		if(P1.ploy_sim[i]!=0)
			m1 = i;
		if(P2.ploy_sim[i]!=0)
			m2 = i;
	}
	if ((m2==0)&&(P2.ploy_sim[0]==0))   //dividend is zero: error
		if_input_valid = false;
	else
	{
		for (int j=0; j<=m1; j++)   //get the que and rem
		{
			ploy_rem[j] = P1.ploy_sim[j];
		}
		for (int j=m1-m2; j>=0; j--)
		{
			ploy_que[j] = ploy_rem[m2+j]/P2.ploy_sim[m2];
			ploy_rem[m2+j] = 0;
			for (int k=j; k<=m2+j-1; k++)
			{
				ploy_rem[k] = ploy_rem[k]-ploy_que[j]*P2.ploy_sim[k-j];
			}
		}
	}
}

double Polynomial::doubleCut(double x, int n)
{
    // string x_str = to_string(x*1e15);
	// int dot = x_str.find('.');
	// x_str = x_str.substr(0, dot+n-15);
	// double x_cut = stod(x_str, 0)/pow(10, n);
    // return x_cut;

    // string x_str = to_string(x*pow(10,n));
	// int dot = x_str.find('.');
	// x_str = x_str.substr(0, dot+n+1);
	// double x_cut = stod(x_str, 0)/pow(10, n);
    // return x_cut;

    int x_w = 10000*x;
    double x_cut = double(x_w)/10000;
    return x_cut;
}

double Polynomial::myPow(double a, int b)
{
	double x = 1;
	int i = 1;
	while (i<=b)
	{
		x = x*a;
        i++;
	}
	return x;
}