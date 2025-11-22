#include<iostream>
#include<iomanip>
#include<ctime>
using namespace std;


class HashTable {
public:
	int* table;
	int S;
	int n;

	HashTable(int size)
	{
		S = size;
		n = 0;
		table = new int[S];
		for (int i = 0; i < S; i++)
		{
			table[i] = 0;
		}
	}
	~HashTable()
	{
		delete[] table;
	}
	int getsize()
	{
		return S;
	}
	bool isEmpty()
	{
		if (n == 0)
			return true;
		return false;
	}
	bool isFull()
	{
		if (n == S)
			return true;
		return false;
	}
	double loadFactor()
	{
		return n / S;
	}
	int getHashValue(int val)
	{
		return val % S;
	}
	bool insert(int val)
	{
		if (isFull())	return false;
		int index = getHashValue(val);
		if (table[index] == 0)
		{
			table[index] = val;
			n++;
			return true;
		}
		if (table[index] == val)
		{
			return true;
		}
		return false;

	}
	
};
int getRandomNumber(int start, int end) {
	return rand() % (end - start + 1) + start;
}


int experiment(int tableSize)
{
	HashTable h1(tableSize);
	int count = 0;
	for (int i = 0; i < h1.getsize() ; i++)
	{
		int val = getRandomNumber(1, 100);
		int index = h1.getHashValue(val);
		if (h1.table[index] == 0)
		{
			h1.table[index] = val;
			count++;
		}
		else
			return count;
	}
	return count;
}

int main() {
	srand(static_cast<unsigned>(time(0))); // seed random generator
	const int numExperiments = 50;
	cout << "Table Size\tAverage Inserted\n";
	cout << "-----------\t----------------\n";
	// Run experiments for table sizes 10, 20, 30, ..., 100
	for (int S = 10; S <= 100; S += 10) {
		double totalInserted = 0.0;
		for (int i = 0; i < numExperiments; i++)
			totalInserted += experiment(S);
		double averageInserted = totalInserted / numExperiments;
		cout << setw(5) << S << "\t\t" << fixed << setprecision(2)
			<< averageInserted << endl;
	}
}