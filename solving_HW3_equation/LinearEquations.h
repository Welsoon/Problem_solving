// Date: 2020.9.22
// Author: Jiaze Sun

#ifndef linearequation_h
#define linearequation_h

#include <iostream>
#include <string>
#include <cmath>

using namespace std;

double doubleCut(double x, int n);
void ifNumber(char k, bool *pif);
void simplify(string str, bool *pif, double *pequ, double *pval);
void exchange(double *pequ1, double *pval1, double *pequ2, double *pval2);
void rowAdd(double *pequ1, double *pval1, double *pequ2, double *pval2, double k);

#endif