#include <bits/stdc++.h>
#define DBG if (debug)
#define ND if (!debug) 
using namespace std;

bool debug = false;

const int N = 510, MOD = 1e9 + 7;

int n, k, cnt;
char str[N];

inline bool valid(char a[]) {
	for (int i = 0; i < n; i++) {
		if (str[i] == '*') {
			int j = i + 1, cnt = 0, maxcnt = 0;
			while (j < n) {
				if (str[j] == '(') {
					cnt++;
					maxcnt = max(maxcnt, cnt);
				} else if (str[j] == ')') {
					cnt--;
					if (cnt < 0) {
						return true;
					}
				}
				if (str[j] == '*' && !cnt && maxcnt > cnt) {
					DBG printf("%s is not valid for having * at both %d and %d, which is at the same level\n", a, i, j); 
					return false;
				}
				j++;
			}
//			if (!cnt && maxcnt > cnt) {
////				DBG printf("There are %d unpaired brackets between %d and %d in %s.\n", cnt, i, j, a); 
//				return false;
//			} else {
//				i = j - 1;
//			}
		}
	}
	return true;
} 

void dfs(int pos, int stk, int llb, int lrb) {
	if (stk < 0) {
		return;
	}
	if (pos >= n) {
		if (!stk && valid(str)) {
			cnt++;
			DBG printf("%d %s\n", cnt, str);
		}
		return;
	}
	while (str[pos] != '?' && pos < n) {
		if (str[pos] == '(') {
			stk++;
			llb = pos;
//			DBG printf("LB found (stack = %d, llb = %d)\n", stk, llb);
		} else if (str[pos] == ')') {
			stk--;
			lrb = pos;
//			DBG printf("RB found (stack = %d, lrb = %d)\n", stk, lrb);
			if (stk < 0) {
//				DBG printf("stk < 0\n");
				return;
			}
		}
		pos++;
	}
	if (stk) {
		str[pos] = ')';
		dfs(pos + 1, stk - 1, llb, pos);
	}
	if (min(pos - llb, pos - lrb) < k && pos && pos < n - 1) {
		str[pos] = '*';
		dfs(pos + 1, stk, llb, lrb);
	}
	str[pos] = '(';
	dfs(pos + 1, stk + 1, pos, lrb);
	str[pos] = '?';
}

int main() {
	ND freopen("bracket.in", "r", stdin);
	ND freopen("bracket.out", "w", stdout);
	scanf("%d%d\n", &n, &k);
	scanf("%s", str);
	dfs(0, 0, 0, 0);
	printf("%d\n", cnt);
	return 0;
}
