// Date: 2020.9.22
// Author: Jiaze Sun

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
	float ploy_sim[10] = {0};		// simplified polynomial
	float ploy_der[10] = {0};		// derivative
	float ploy_dder[10] = {0};		// dderivative

	void ifInputValidTest1(float a, float b);
	void polySimplify();
	void polyDerivate();
	void polyDDerivate();
	float polyResult(float ploy[], int size, float x);
	void printPolynomial(float *a);
	float doubleCut(float x, int n);		// cut float 0.0852688 into 0.08520000
	float myPow(float a, int b);
};

#endif

