#ifndef Polynomial_Class
#define Polynomial_Class

#include<iostream>
#include<string>
using namespace std;

class Polynomial {
private:
	float* coeff;
	int* power;
	int size;
	int capacity;

public:
	Polynomial();
	Polynomial(const Polynomial& p1);
	~Polynomial();
	void addTerm(const float& c, const int& p);
	int getDegree();
	float getCoefficient(const int& p);
	Polynomial& operator=(const Polynomial& other);
	Polynomial operator+(const Polynomial& other);
	Polynomial derivative() const;
	Polynomial antiDerivative();
	void addToCoefficient(const float& c, const int& p);
	void clear();
	void setCoefficient(const float& c, const int& p);
	Polynomial operator-(const Polynomial& other);
	Polynomial operator*(const Polynomial& other);
	float operator()(int& value);
	friend ostream& operator<<(ostream& out, Polynomial& p);
	void sortAndSimplify();
};

#endif
