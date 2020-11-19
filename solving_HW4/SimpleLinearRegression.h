// Author: Sun jiaze
// Date: 2020/10/8

#ifndef _simplelinearregression_h
#define _simplelinearregression_h

#include <iostream>
#include <cmath>
#include <string>

using namespace std;

void covCefficient(double *x, double *y, double *a, double *b, double *r, int n);
void printFunction(double a, double b);
double result2(double a, double b, double x);

#endif
