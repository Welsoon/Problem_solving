// Author: Sun jiaze
// Date: 2020/10/8

#ifndef _interpolation_h
#define _interpolation_h

#include <iostream>
#include <cmath>
#include <string>

using namespace std;

// global variable: if input valid
extern bool if_valid;

// simplify input string into (x,y) or x0
void simplify(string str, double *x, double *y);
void simplify(string str, double *x);

// rank up by x, return the step size
double rankUp(double *x, double *y, int n);

// calculate the Newton's coefficient
void coefficient(double *y, double h, int n, double *a);

int factorial(int k);

// if char k is number 0 ~ 9
void ifNumber(char k);

// calculate the result
double result(double *x, double *a, double x0, int n);

double doubleCut(double x);

#endif