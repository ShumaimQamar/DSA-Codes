#include<iostream>
#include<string>
using namespace std;

int countSquare(int k, int c1, int c2, int i, int j)
{
	if (k < 1)
		return 0;

	int count = 0;

	if (i >= c1 - k && i <= c1 + k &&
		j >= c2 - k && j <= c2 + k)
		count = 1;
	
	if (k > 1)
	{
		int center = k / 2;
		count += countSquare(center, c1 + k, c2 + k, i, j);
		count += countSquare(center, c1 + k, c2 - k, i, j);
		count += countSquare(center, c1 - k, c2 + k, i, j);
		count += countSquare(center, c1 - k, c2 - k, i, j);
	}
	return count;
}
int main()
{
	int k, x, y;
	cin >> k >> x >> y;

	int num = countSquare(k, 1024, 1024, x, y);
	cout << num << endl;
	return 0;
}