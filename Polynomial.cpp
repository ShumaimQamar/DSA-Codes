#include "Polynomial.h"

#include<iostream>
#include<string>
#include<cmath>
using namespace std;
Polynomial::Polynomial()
{
	capacity = 50;
	coeff = new float[capacity];
	power = new int[capacity];
	size = 0;
}
Polynomial::Polynomial(const Polynomial& p1)
{
	capacity = p1.capacity;
	coeff = new float[capacity];
	power = new int[capacity];
	size = p1.size;

	for (int i = 0; i < size; i++)
	{
		coeff[i] = p1.coeff[i];
		power[i] = p1.power[i];
	}
}
Polynomial::~Polynomial()
{
	delete[] coeff;
	delete[] power;
}
void Polynomial::addTerm(const float& c, const int& p)
{
	if (p >= 0 && c != 0)
	{
		this->coeff[size] = c;
		this->power[size] = p;
		size++;
	}
	else
	{
		if (p < 0)
		{
			throw string("polynomial don't have a non positive exponent.");
		}
		if (c == 0)
		{
			throw string("coefficiant cannot be zero.");
		}
	}
}
void Polynomial::sortAndSimplify()
{
	for (int i = 0; i < size - 1; i++)
	{
		for (int j = 0; j < size - i - 1; j++)
		{
			if (power[j] < power[j + 1])
			{
				int temp1;
				temp1 = power[j];
				power[j] = power[j + 1];
				power[j + 1] = temp1;

				float temp2;
				temp2 = coeff[j];
				coeff[j] = coeff[j + 1];
				coeff[j + 1] = temp2;
			}
		}
	}
	for (int i = 0; i < size - 1; i++)
	{
		if (power[i] == power[i + 1])
		{
			coeff[i] += coeff[i + 1];
			for (int j = i + 1; j < size - 1; j++)
			{
				coeff[j] = coeff[j + 1];
				power[j] = power[j + 1];
			}
			size--;
		}
	}
}
int Polynomial::getDegree()
{
	int g = 0;
	for (int i = 0; i < size; i++)
	{
		if (this->power[i] > g)
		{
			g = power[i];
		}
	}
	return g;
}
float Polynomial::getCoefficient(const int& p)
{
	bool found = false;
	for (int i = 0; i < size; i++)
	{
		if (this->power[i] == p)
		{
			found = true;
			return this->coeff[i];
		}
	}
	if (!found)
	{
		throw string("The power you entered is not in the polynomial, so the coefficiant will be zero.");
	}

}

Polynomial& Polynomial::operator=(const Polynomial& other)
{
	if (this == &other) return *this;
	delete[] coeff;
	delete[] power;
	capacity = other.capacity;
	this->coeff = new float[capacity];
	this->power = new int[capacity];

	for (int i = 0; i < other.size; i++)
	{
		coeff[i] = other.coeff[i];
		power[i] = other.power[i];
	}
	size = other.size;
	return *this;
}
Polynomial Polynomial::operator+(const Polynomial& other)
{
	Polynomial p1;
	p1.capacity = capacity + other.capacity;
	for (int i = 0; i < size; i++)
	{
		p1.coeff[p1.size] = coeff[i];
		p1.power[p1.size] = power[i];
		p1.size++;
	}


	for (int j = 0; j < other.size; j++)
	{
		bool found = false;
		for (int k = 0; k < p1.size; k++)
		{
			if (p1.power[k] == other.power[j])
			{
				p1.coeff[k] += other.coeff[j];
				found = true;
				break;
			}
		}
		if (!found)
		{
			p1.coeff[p1.size] = other.coeff[j];
			p1.size++;
		}
	}
	return p1;
}
Polynomial Polynomial::derivative() const
{
	Polynomial p1;
	for (int i = 0; i < size; i++)
	{
		p1.coeff[p1.size] = coeff[i] * power[i];
		p1.power[p1.size] = power[i] - 1;
		p1.size++;
	}
	return p1;
}
Polynomial Polynomial::antiDerivative()
{
	Polynomial p1;
	for (int i = 0; i < size; i++)
	{
		p1.power[p1.size] = power[i] + 1;
		p1.coeff[p1.size] = coeff[i] / p1.power[i];
		p1.size++;
	}
	return p1;
}
void Polynomial::addToCoefficient(const float& c, const int& p)
{
	bool found = false;
	for (int i = 0; i < size; i++)
	{
		if (power[i] == p)
		{
			found = true;
			coeff[i] += c;
		}
	}
	if (!found)
	{
		throw string("power dont found to add coefficient.");
	}
}
void Polynomial::clear()
{
	for (int i = 0; i < size; i++)
	{
		coeff[i] = 0;
	}
}
void Polynomial::setCoefficient(const float& c, const int& p)
{
	bool count = false;
	for (int i = 0; i < size; i++)
	{
		if (power[i] == p)
		{
			coeff[i] = c;
			count = true;
		}
	}
	if (count == false)
	{
		coeff[size] = c;
		power[size] = p;
		size++;
	}
}
Polynomial Polynomial::operator-(const Polynomial& other)
{
	Polynomial p1;
	p1.capacity = capacity + other.capacity;
	for (int i = 0; i < size; i++)
	{
		p1.coeff[p1.size] = coeff[i];
		p1.power[p1.size] = power[i];
		p1.size++;
	}


	for (int j = 0; j < other.size; j++)
	{
		bool found = false;
		for (int k = 0; k < p1.size; k++)
		{
			if (p1.power[k] == other.power[j])
			{
				p1.coeff[k] -= other.coeff[j];
				found = true;
				break;
			}
		}
		if (!found)
		{
			p1.coeff[p1.size] = other.coeff[j];
			p1.size++;
		}
	}
	return p1;
}
Polynomial Polynomial::operator*(const Polynomial& other)
{
	Polynomial p1;
	p1.capacity = capacity + other.capacity;

	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < other.size; j++)
		{
			p1.coeff[p1.size] = coeff[i] * other.coeff[j];
			p1.power[p1.size] = power[i] + other.power[j];
			p1.size++;
		}
	}
	return p1;
}
float Polynomial::operator()(int& value)
{
	float cal = 0;
	for (int i = 0; i < size; i++)
	{
		if (this->power[i] != 0)
		{
			cal += this->coeff[i] * pow(value, this->power[i]);
		}
		else
		{
			cal += this->coeff[i];
		}
	}
	return cal;
}
ostream& operator<<(ostream& out, Polynomial& p)
{
	p.sortAndSimplify();
	if (p.size != 0)
	{
		out << p.coeff[0] << "x^" << p.power[0];
		for (int i = 1; i < p.size; i++)
		{
			if (p.power[i] != 0)
			{
				out << " + " << p.coeff[i];
				if (p.power[i] != 1)
				{
					out << "x^" << p.power[i];
				}
				else
				{
					out << "x";
				}
			}
			else
			{
				out << " + " << p.coeff;
			}
		}
	}
	else
	{
		throw string("The polynomial has zero terms, Output cannot be generated.");
	}
	return out;
}