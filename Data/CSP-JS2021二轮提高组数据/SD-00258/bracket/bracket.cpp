#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <cmath>
#include <ctime>
#include <functional>
#include <cctype>
#include <queue>
#include <utility>

namespace chiaro {

const int inf = 503;
const int INF = 0x7fffffff;
const int ha = 1e9 + 7;

template <class T>
inline void read(T &num) {
	num = 0; char c = getchar(), up = c;
	while(!isdigit(c)) up = c, c = getchar();
	while(isdigit(c)) num = (num << 1) + (num << 3) + (c - '0'), c = getchar();
	up == '-' ? num = -num : 0;
}

inline void setting() {
	freopen("bracket.in", "r", stdin);
	freopen("bracket.out", "w", stdout);
}

int f[inf][inf];
int far[inf], sum[inf];
int n, k, K;
char s[inf];

inline int add(int x, int y) {return x + y >= ha ? x + y - ha : x + y;}
inline bool chkl(int x) {return s[x] == '?' || s[x] == '(';}
inline bool chkr(int x) {return s[x] == '?' || s[x] == ')';}
inline bool chkx(int x) {return s[x] == '*';}

inline int check1(int l, int r) {
	return chkl(l) && chkr(r) && far[l + 1] >= r && r - l - 1 <= k;
}

inline int check2(int l, int r) {
	int res = 0;
	for(int k = l + 1; k < r; k++) {
		res = add(res, 1ll * f[l][k] * f[k + 1][r] % ha);
//		printf("k = %d, increas %lld\n", k, 1ll * f[l][k] * f[k + 1][r] % ha);
	}
	return res;
}

inline int check4(int l, int r) {
	if(r - l + 1 >= 3) return 1ll * chkl(l) * chkr(r) * f[l + 1][r - 1];
	else return 0;
}

inline int check5(int l, int r) {
	if(r - l + 1 >= 5 && chkl(l) && chkr(r)) {
		int res = 0;
		int km = std::min (k + l, std::min (far[l + 1] - 1, r - 1));
		for(int k = l + 1; k <= km; k++) {
			res = add(res, f[k + 1][r - 1]);
		}
		return res;
	} else return 0;
}

inline int check6(int l, int r) {
	if(r - l + 1 >= 5 && chkl(l) && chkr(r)) {
		int res = 0;
		int km = r;
		for(int k = r - 1; k > l; k--) {
			if(far[k] >= r && r - k <= K) {
				km = k;
			} else break;
		}
		for(int k = km; k < r; k++) {
			res = add(res, f[l + 1][k - 1]);
		}
		return res;
	} else return 0;
}

inline int getans(int l, int r) {
	if(l > r) return 0;
//	printf("l = %d, r = %d, suml = %d, sumr + 1 = %d\n", l, r, sum[l], sum[r + 1]);
	return (sum[l] - sum[r + 1] + ha) % ha;
}

// (*??*??

inline int check3(int l, int r) {
	if(r - l + 1 < 5) return 0;
	int res = 0;
	for(int k = l + 2; k < r - 1; k++) {
		int pm = std::min (K + k - 1, std::min (r - 2, far[k] - 1));
//		printf("k = %d, pm = %d, getans = %d\n", k, pm, getans(k + 1, pm + 1));
		res = add(res, 1ll * f[l][k - 1] * getans(k + 1, pm + 1) % ha);
	}
	return res;
}

int ra;
int p[inf];

inline bool check() {
	int now = 0, lk = 0;
	for(int i = 1; i <= n; i++) {
		now += p[i];
		if(p[i] == 0) {
			if(++lk > k) return 0;
		} else lk = 0;
		if(now < 0) return 0;
	}
	return now == 0;
}

void dfs(int x) {
	if(x > 15) {
		if(check()) ra = add(ra, 1);
		return;
	}
	if(s[x] == '(') {
		p[x] = 1;
		dfs(x + 1);
	} else if(s[x] == ')') {
		p[x] = -1;
		dfs(x + 1);
	} else if(s[x] == '*') {
		p[x] = 0;
		dfs(x + 1);
	} else {
		p[x] = 1;
		dfs(x + 1);
		p[x] = -1;
		dfs(x + 1);
		p[x] = 0;
		dfs(x + 1);
	}
}

inline void solve15 () {
	dfs(1);
	std::cout << ra << '\n';
	exit(0);
}

inline void solvemain () {
	read(n); read(k); K = k;
	scanf("%s", s + 1);
//	if(n <= 15) solve15();
	for(int i = 1; i <= n; i++) {
		for(int j = i; j <= n + 1; j++) {
			if(s[j] != '*' && s[j] != '?') {
				far[i] = j;
				break;
			}
		}
	}
	for(int r = 2; r <= n; r++) {
		if(chkx(r)) continue;
		std::fill(sum, sum + 1 + n, 0);
		for(int l = r - 1; l; l--) {
			if(chkx(l)) {
				sum[l] = sum[l + 1];
				continue; 
			}
			f[l][r] = check1(l, r);
//			printf("\n(*)[%d, %d] = %d\n", l, r, f[l][r]);
			f[l][r] = add(f[l][r], check2(l, r));
//			printf("AB[%d, %d] = %d\n", l, r, f[l][r]);
			f[l][r] = add(f[l][r], check3(l, r));
//			printf("ASB[%d, %d] = %d\n", l, r, f[l][r]);
			f[l][r] = add(f[l][r], check4(l, r));
//			printf("(A)[%d, %d] = %d\n", l, r, f[l][r]);
			f[l][r] = add(f[l][r], check5(l, r));
//			printf("(SA)[%d, %d] = %d\n", l, r, f[l][r]);
			f[l][r] = add(f[l][r], check6(l, r));
//			printf("(AS)[%d, %d] = %d\n", l, r, f[l][r]);
			sum[l] = add(sum[l + 1], f[l][r]);
//			printf("sum %d = %d\n", l, sum[l]);
		}
	}
	std::cout << f[1][n] << '\n';
}

}

signed main () {
	chiaro::setting();
	chiaro::solvemain();
	fclose(stdin);
	fclose(stdout);
	return 0;
}

