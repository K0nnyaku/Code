#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<iostream>
using namespace std;
string Tower1, Tower2, Tower3;

void Move(int pos, string &tp, string &to);
void Solve(int x, string &from, string &tp, string &to);

int main() {
	freopen("In.in", "r", stdin);

	int x;
	cin >> x >> Tower1 >> Tower2 >> Tower3;
	
	Solve(x, Tower1, Tower2, Tower3);

	return 0;
}

void Solve(int x, string &from, string &tp, string &to) {
	if(x == 1) Move(1, from, to);
	else {
		Solve(x-1, from, to, tp);
		Move(x, from, to);
		Solve(x-1, tp, from, to);
	}
}

void Move(int pos, string &tp, string &to) {
	cout << pos << ":" << tp << "->" << to << endl;
}
