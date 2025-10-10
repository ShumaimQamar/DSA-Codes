#include<iostream>
#include<string>
#include<cmath>
using namespace std;

bool isPrime(int n)
{
	if (n < 2)
		return false;
	int i = 2;
	while (i <= sqrt(n))
	{
		if (n % i == 0)
			return false;
		i++;
	}
	return true;
}
bool isGoodNumber(const string& s, int index = 0)
{
	if (index == s.length())
		return true;

	int dec = s[index] - 48;
	if (index % 2 == 0) {
		if (dec % 2 != 0)
			return false;
	}
	else {
		if (isPrime(dec) == false)
			return false;
	}
	 
	isGoodNumber(s,index+1);
}

int main()
{
	string digit_strings[] = { "02468","23478","224365" };
	for (string digits : digit_strings) {
		bool is_good = isGoodNumber(digits, 0);
		cout << "Digit string: " << digits << " is " <<
			(is_good ? "good" : "not good") << endl;
	}
	return 0;
}