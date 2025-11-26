#include<iostream>
#include"Stack.h"
using namespace std;
struct Pair{
	int i,j;
	Pair(int _i=0, int _j=0){
		i=_i;
		j=_j;
	}
};
void solvemaze(Pair s, Pair d, int ar[5][5],int row, int col){
	Stack<Pair> st(row*col);
	ar[s.i][s.j]=3;
	st.push(s);
	while (!st.isEmpty()){
		Pair cur = st.stackTop();
		if(cur.i==d.i && cur.j==d.j){
			cout << "Maze solved.\n";
			cout << "Path is: " << endl;
			while(!st.isEmpty()){
				cout << st.stackTop().i << "," << st.stackTop().j << " ";
				if(st.stackTop().i !=0 || st.stackTop().j != 0)
					cout  << "<-- ";
				st.pop();
			}
			return;
		}
		if(ar[cur.i][cur.j+1]==0 && cur.j+1<col){
			ar[cur.i][cur.j+1]=3;
			cur.j++;
			st.push(cur);
		}

		else if(ar[cur.i][cur.j-1]==0 && cur.j-1>=0){
			ar[cur.i][cur.j-1]=3;
			cur.j--;
			st.push(cur);
		}
		else if(ar[cur.i+1][cur.j]==0 && cur.i+1<row){
			ar[cur.i+1][cur.j]=3;
			cur.i++;
			st.push(cur);
		}
		else if(ar[cur.i-1][cur.j]==0 && cur.i-1>=0){
			ar[cur.i-1][cur.j]=3;
			cur.i--;
			st.push(cur);
		}
		else {
			st.pop();
		}
	}
	cout << "No path found.\n";
}
int main()
{
    int ar[5][5]={{0,0,0,0,0},{1,0,1,1,1},{0,0,0,0,0},{0,0,1,0,1},{0,1,1,0,1}};
    Pair s(0,0);
    Pair d(4,3);
    solvemaze(s,d,ar,5,5);
    return 0;
}

if (ar[cur.i+1][cur.j + 1] == 0 && cur.j + 1 < col && cur.i+1<row) {
	ar[cur.i+1][cur.j + 1] = 3;
	cur.j++;
	cur.i++;
	st.push(cur);
}