#include<bits/stdc++.h>
using namespace std;

int n,k;
unsigned long long total;
char str[505];
char opt[3] = {'(',')','*'};
bool judge2()
{
	int rank = 0;
	for (int i = 2; i < n; i++) {
		if (str[i] == '*') 
		{
			rank++;
		} else {
			rank = 0;
		}
		if (rank >= k) return false;
	}
	return true;
}
bool judge() {
	int rank = 1;
	for (int i = 2; i <= n; i++) {
		if (str[i] == '(')
			rank++;
		else if (str[i] == ')')
			rank--;
	}
	if (rank == 0) return judge2();
	return false;
}
void dfs(int index) {
	if (index >= n) {
		if (judge()) total++;
		return;
	}
	if (str[index] == '?') {
		for (int i = 0; i < 3; i++) {
			str[index] = opt[i];
			dfs(index+1);
			str[index] = '?';
		}
	} else {
		dfs(index+1);
	}
}
int main() {
	ifstream fin("bracket.in");
	ofstream fout("bracket.out");
	fin >> n >> k;
	fin >> str;
	str[0] = '(';
	str[n - 1] = ')';
	dfs(1);
	fout << (total % 1000000007ll);
	fin.close();fout.close();
	return 0;
}
