#include<iostream>
#include<string>
using namespace std;

int countWays(int numStairs)
{
	if (numStairs == 2)
		return 2;
	if (numStairs == 1)
		return 1;
	return countWays(numStairs - 1) + countWays(numStairs - 2);
}

int main()
{
	int n;
	cout << "Enter any number to know number of ways to climb the stairs: ";
	cin >> n;

	int climb = countWays(n);
	cout << "The number of ways we can climb " << n << " stairs are: " << climb << endl;
	return 0;
}