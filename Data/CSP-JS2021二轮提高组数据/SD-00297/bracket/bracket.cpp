#include <bits/stdc++.h>
using namespace std;

const int MAXN = 45;
int n, k, ans;
char s[MAXN];
vector<char> res;

inline bool chk() {
	char stk[MAXN];
	int top = 0;
	bool remainstar = 0;
	if (res.front() == '*' || res.back() == '*') return 0;
	for (int i = 0, cntst, remainkh; i < res.size(); ++i) {
		cntst = 0;
//		for (int j = 1; j <= top; ++j)
//			cerr << stk[j];
//		cerr << endl;
		if (res[i] != ')') {
			stk[++top] = res[i];
		} else {
			if (top <= 0) {
//				cerr << "Fail, no (." << endl;
				return 0;
			}
			while (stk[top--] != '(') {
				++cntst;
				if (top < 0) {
//					cerr << "Fail, no (." << endl;
					return 0;
				}
			}
			if (top != 0)
				remainstar = 1;
		}
		if (cntst >= k) {
//			cerr << "Fail, more than k." << endl;
			return 0;
		}
	}
	int cntst = 0;
	if (remainstar) {
		while (stk[top] == '*') {
			--top;
			++cntst;
		}
		if (cntst >= k)
			return 0;
	}
	if (top) {
//		cerr << "Fail, extra (, " << top << "." << endl;
		return 0;
	}
//	cerr << "Succeed." << endl;
//		for (auto i : res)
//		printf("%c", i);
//	printf("\n");
	return 1;
}

void dfs(int tot) {
	if (tot == n) {
		if (chk()) ++ans;
		return;
	}
	if (s[tot] != '?') {
		res.push_back(s[tot]); 
		dfs(tot + 1);
		res.pop_back();
	} else {
		res.push_back(')');
		dfs(tot + 1);
		res.pop_back();
		res.push_back('(');
		dfs(tot + 1);
		res.pop_back();
		res.push_back('*');
		dfs(tot + 1);
		res.pop_back();
	}
}

int main() {
	freopen("bracket.in", "r", stdin);
	freopen("bracket.out", "w", stdout);
	cin >> n >> k >> s;
	dfs(0);
	printf("%d\n", ans);
	return 0;
}
