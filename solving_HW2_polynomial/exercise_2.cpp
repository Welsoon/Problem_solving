
#include <iostream>
#include <cmath>
#include <string>

#include "Polynomial.h"

using namespace std;

int main()
{
	// task 1

	Polynomial P;
	double x;
	getline(cin, P.str);
	cin >> x;
	x = P.doubleCut(x, 4);
	P.polySimplify(P);
	//P.polyDerivate(P);
	double res = P.polyResult(P,x);
	res = P.doubleCut(res, 4);
	P.printPolynomial(P.ploy_sim);
	P.printPolynomial(P.ploy_der);
	if (!P.if_input_valid)
		printf("error\n");
	else
	printf("%.4f", res);

	// task 2

	// Polynomial P1, P2, P3;
	// getline(cin, P1.str);
	// getline(cin, P2.str);
	// P1.polySimplify(P1);
	// P2.polySimplify(P2);
	// P3.polyDivide(P1, P2);
	// P3.printPolynomial(P3.ploy_que);
	// P3.printPolynomial(P3.ploy_rem);

	// Polynomial P;
	// double x = 0.0099999;
	// x = P.doubleCut(x, 4);
	// printf("%.4f", x);

	// double a = pow(5,2);
	// cout<<a;

	// return 0;
}
