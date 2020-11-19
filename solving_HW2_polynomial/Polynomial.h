#ifndef polynomial_h
#define polynomial_h

#include <iostream>
#include <string>
#include <cmath>

using namespace std;

class Polynomial
{
public:
	string str;
	bool if_input_valid = true;
	double ploy_sim[100] = {0};		// simplified polynomial
	double ploy_der[100] = {0};		// derivative
	double ploy_que[100] = {0}; 	// quotient
	double ploy_rem[100] = {0};		// remainder

	void polySimplify(Polynomial P);
	void polyDerivate(Polynomial P);
	double polyResult(Polynomial P, double x);
	void printPolynomial(double *a);
	void polyDivide(Polynomial P1, Polynomial P2);
	double doubleCut(double x, int n);		// cut double 0.0852688 into 0.08520000
	double myPow(double a, int b);
};

#endif

