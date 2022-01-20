#include <iostream>
#include <cstdio>
#include <algorithm>
#include <queue>
#include <vector>
#include <cstring>
#include <stack>

using namespace std;

int n, k;
string s;
int ans = 0;
int a[10005];
stack<int> st;

int check() {
	if (s.front() == '*' || s.back() == '*') return false;
	for (int i = 0; i < s.length(); ++i) {
		if (s[i] == '(') {
			st.push(i);
		}
		else if (s[i] == ')') {
			a[st.top()] = i;
			a[i] = st.top();
			st.pop();
		}
	}
	for (int i = 1; i < s.length() - 1; ++i) {
		if (s[i] == '(') {
			if (s[i - 1] == '*' && (a[i] == s.length() - 1 ? false : s[a[i] + 1] == '*')) {
				return false;
			}
		}
	}
	return true;
}

void dfs(int pos, int dep, int c) {
	if (c > k) return;
	if (dep < 0) return;
	if (pos >= n) {
		if (dep) return;
		if (check()) {
			cout << s << endl;
			ans++;
		}
		return;
	}
	if (s[pos] == '?') {
		s[pos] = '(';
		dfs(pos + 1, dep + 1, c);
		s[pos] = ')';
		dfs(pos + 1, dep - 1, c);
		s[pos] = '*';
		dfs(pos + 1, dep, c + 1);
		s[pos] = '?';
	}
	else {
		if (s[pos] == '(') {
			dfs(pos + 1, dep + 1, c);
		}
		else if (s[pos] == ')') {
			dfs(pos + 1, dep - 1, c);
		}
		else {
			dfs(pos + 1, dep, c + 1);
		}
	}
}

int solve() {
	dfs(0, 0, 0);
	return ans;
}

int main() {
	freopen("bracket.in", "r", stdin);
	freopen("bracket.out", "w", stdout);
	cin >> n >> k >> s;
	cout << solve() << endl;
	return 0;
}


