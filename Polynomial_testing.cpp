#include "Polynomial.h"

#include<iostream>
#include<string>
using namespace std;

int main()
{
	try {
		Polynomial p1;
		p1.addTerm(-3, 5);
		p1.addTerm(2, 4);
		cout << p1 << endl;

		int degree;
		degree = p1.getDegree();
		cout << degree << endl;

		float coeff;
		coeff = p1.getCoefficient(5);
		cout << coeff << endl;

		Polynomial p2;
		p2 = p1.derivative();
		cout << p2 << endl;

		p1.addToCoefficient(2, 4);
		cout << p1 << endl;

		p1.setCoefficient(2, 2);
		cout << p1 << endl;

		p2 = p1;
		cout << p2 << endl;

		float value;
		int n = 3;
		value = p1(n);
		cout << value << endl;

		p2 = p1;
		p2 = p2.derivative();
		cout << p2 << endl;
		p2 = p2.antiDerivative();
		cout << p2 << endl;

		Polynomial p3;
		p3 = p1 + p2;
		cout << p3 << endl;

		Polynomial p4;
		p4 = p3 - p1;
		cout << p4 << endl;


		Polynomial p5;
		p5 = p2 * p3;
		cout << p5 << endl;

		Polynomial p6;
		p6.addTerm(3, 5);
		p6.addTerm(3, 1);
		cout << p6 << endl;
	}

	catch (string& e)
	{
		cout << "Error: " << e << endl;
	}
	return 0;
}