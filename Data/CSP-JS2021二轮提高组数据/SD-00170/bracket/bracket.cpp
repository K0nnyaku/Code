#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;

const int N = 500 + 10;
const int MOD = 1e9 + 7;

int n, k;

char s1[N], s2[N];// = "\0(*()**)\0";
bool hl[N], hc[N];
int ans;
inline void INC(int &a) {
	if(a == MOD - 1) a = 0;
	else ++a;
}
//inline void ADD(int &a, const int b) {
//	a += b;
//	if()
//}
void dfs(int x) {
	if(x > n) {
		if(s2[1] != '(' || s2[n] != ')') return;
		int lc = 0, sc = 0;
		memset(hc, 0, sizeof hc);
		for(int i = 1; i <= n; ++i) {
			if(s2[i] == '(') {
				hc[lc] = true;
				++lc;
				sc = 0;
				hl[lc] = (s2[i + 1] == '*');
				hc[lc] = false;
			}
			else if(s2[i] == ')') {
				if(hl[lc] && hc[lc] && sc != 0) return;
				if(lc > 0) {
					--lc;
					sc = 0;
				}
				else return;
			}
			else {
				if(++sc > k) return;
			}
		}
//		if(lc != 1) return;
//		if(hl[lc] && hc[lc] && sc != 0) return;
		if(lc != 0) return;
		
		INC(ans);
		return;
	}
	
	while(x <= n && s2[x] != '?') ++x;
	if(x > n) dfs(x);
	else {
		s2[x] = '(';
		dfs(x + 1);
		s2[x] = ')';
		dfs(x + 1);
		s2[x] = '*';
		dfs(x + 1);
		s2[x] = '?';
	}
}

int main() {
	freopen("bracket.in", "r", stdin);
	freopen("bracket.out", "w", stdout);
	scanf("%d%d", &n, &k);
	scanf("%s", s1 + 1);
	memcpy(s2, s1, sizeof s1);
	
	dfs(1);
	
	printf("%d", ans);
	return 0;
}
