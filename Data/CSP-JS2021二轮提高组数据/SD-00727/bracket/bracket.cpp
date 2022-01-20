#include <iostream>
#include <cstdio>
#include <cstring>
#include <iomanip>
#include <utility>
#include <cmath>
using namespace std;
//--------------------------------------------------

//--------------------------------------------------
int n, k;
string T;
//--------------------------------------------------
int read() {
	int f = 0, x = 0; char ch = getchar();
	while (!isdigit(ch)) f |= (ch == '-'), ch = getchar();
	while (isdigit(ch)) x = x * 10 + (ch ^ 48), ch = getchar();
	return f ? -x : x;
}
int max(int a, int b) {
	return a > b ? a : b;
}
int min(int a, int b) {
	return a < b ? a : b;
}
bool check(string Yuan, int pos, string &Bian) {
	string tmp = "";
	for (int i = 0; i < pos; ++i) tmp += Yuan[i];
	tmp += Bian;
	for (int i = pos + 1; i < n; ++i) tmp += Yuan[i];
	Bian = tmp;
//	cout << Bian << endl;
	int cntk = 0, cntxh = 0, cntkxh = -1;
	for (int i = 0; i <= pos; ++i) {
		if (Bian[i] == '(') {
			++cntk;
			if (cntxh) {
				cntkxh = 1;
			}
			cntxh = 0;
		}
		else if (Bian[i] == ')') {
			--cntk;
			cntxh = 0;
			--cntkxh;
			if (cntk < 0) return 0;
		}
		else {
			if (cntxh == 0) {
				if (cntkxh == 0) return 0;
			}
			if (cntk == 0 && cntxh == 0) return 0;
			++cntxh;
			if (cntxh > k) return 0;
		}
	}
	return 1;
}
bool checkEnd(string s) {
	int cntk = 0, cntxh = 0;
	for (int i = 0; i < n; ++i) {
		if (s[i] == '(') {
			++cntk;
			cntxh = 0;
		}
		else if (s[i] == ')') {
			--cntk;
			cntxh = 0;
			if (cntk < 0) return 0;
		}
		else {
			++cntxh;
			if (cntxh > k) return 0;
		}
	}
	return (cntk == 0) && (cntxh == 0);
}
int dfs(int t, string s) {
//	cout << t << " " << s << endl;
	if (t == n) {
		int flag = checkEnd(s);
//		cout << flag << endl;
		return flag;
	}
	if (s[t] != '?') return dfs(t + 1, s);
	int sum = 0;
	string t1 = "(", t2 = ")", t3 = "*";
	if (check(s, t, t1))
		sum += dfs(t + 1, t1);
	if (check(s, t, t2))
		sum += dfs(t + 1, t2);
	if (check(s, t, t3))
		sum += dfs(t + 1, t3);
	return sum;
}
//--------------------------------------------------
int main() {
	freopen("bracket.in", "r", stdin);
	freopen("bracket.out", "w", stdout);
	n = read(); k = read();
	cin >> T;
	printf("%d\n", dfs(0, T));
	fclose(stdin); fclose(stdout); 
	return 0;
}
