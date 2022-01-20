#include<bits/stdc++.h>
#define int long long
#define dd double
#define mem0(x) memset(x, 0, sizeof(x))
#define mem0x3f(x) memset(x, 0x3f, sizeof(x))
#define F(Ti,Ta,Tb) for(int Ti=(Ta);Ti<=(Tb);Ti++)
#define D(Ti,Ta,Tb) for(int Ti=(Ta);Ti>=(Tb);Ti--)
#define mod 1000000007
#define Base 233
#define inf 1e12
#define limt 1000000

using namespace std;

const int N = 500 + 5;

int read() {
	int x = 0, f = 1;
	char ch = getchar();
	while (ch < '0' || ch > '9') {
		if (ch == '-') f = -1;
		ch = getchar();
	}
	while (ch >= '0' && ch <= '9') {
		x = (x << 1) + (x << 3) + (ch ^ 48);
		ch = getchar();
	}
	return x * f;
}

int n, m, f[N][N], g[N][N], vis[N][N], cz[N][N];
char c[N];

void add(int &x) {
	if (x >= mod) x -= mod;
}

void calc1(int l, int r) {
	int len = r - l + 1;
	if ((c[l] == '(' || c[l] == '?') && (c[r] == ')' || c[r] == '?')) {
		f[l][r] += f[l + 1][r - 1]; add(f[l][r]);//(A)
		vis[l][r] |= vis[l + 1][r - 1];
		F(k, 1, min(len - 3, m)) {//(SA)
			f[l][r] += f[l + 1 + k][r - 1] * g[l + 1][l + 1 + k - 1]; add(f[l][r]);
			vis[l][r] |= (vis[l + 1 + k][r - 1] & cz[l + 1][l + 1 + k - 1]);
		}
		F(k, 1, min(len - 3, m)) {//(AS)
			f[l][r] += f[l + 1][r - 1 - k] * g[r - 1 - k + 1][r - 1]; add(f[l][r]);
			vis[l][r] |= (vis[l + 1][r - 1 - k] & cz[r - 1 - k + 1][r - 1]);
		}
	}
}  

void calc2(int l, int r) {
	F(k, l + 1, r - 1) {//AB
		int ok = 1;
		if ((f[l][k] * f[k + 1][r])) {
			F(kk, l + 1, k - 1) {
				if ((f[l][kk] * f[kk + 1][r])) {
					if (f[kk + 1][k]) {
						ok = 0;
					}
				}
			}
			if (ok) {
				f[l][r] += (f[l][k] * f[k + 1][r]) % mod; 
				vis[l][r] |= (vis[l][k] & vis[k + 1][r]);
			}
			add(f[l][r]);
		}
	}
	F(k1, l + 1, r - 1) {//ASB
		F(k2, k1, r - 1) {
			if (k2 - k1 + 1 > m) break;
			f[l][r] += ((f[l][k1 - 1] * f[k2 + 1][r]) % mod * g[k1][k2]) % mod;
			add(f[l][r]);
			vis[l][r] = ((vis[l][k1 - 1] & vis[k2 + 1][r]) & cz[k1][k2]);
		}
	}
}

signed main() {
	freopen("bracket.in", "r", stdin);
	freopen("bracket.out", "w", stdout);
	n = read(); m = read();
	cin >> c + 1;
	F(l, 1, n) {
		int val = 1;
		if (l < n) {
			if ((c[l] == '(' || c[l] == '?') && (c[l + 1] == ')' || c[l + 1] == '?')) {
				f[l][l + 1] = 1; vis[l][l + 1] = 1;
			}
		}
		F(r, l, n) {
			if (c[r] == '(' || c[r] == ')' || r - l + 1 > m) val = 0;
			g[l][r] = val; cz[l][r] = val;
		}
		
	}
	F(len, 3, 2 + m) {
		F(l, 1, n - len + 1) {
			int r = l + len - 1;
			if ((c[l] == '(' || c[l] == '?') && (c[r] == ')' || c[r] == '?')) {
				f[l][r] += g[l + 1][r - 1]; add(f[l][r]);
				if (f[l][r]) vis[l][r] = 1;
				//cout << l << ' ' << r << ' ' << f[l][r] << ' ' << vis[l][r] << '\n';
			}
		}
	}
	F(len, 4, n) {
		F(l, 1, n - len + 1) {
			int r = l + len - 1;
			calc1(l, r); calc2(l, r); 
		}
	}
	cout << f[1][n] % mod << '\n';
	fclose(stdin);
	fclose(stdout);
	return 0;
}
/*
7 3
(*??*??
5
10 2
???(*??(?)
19
100 18
?*?????)?????*????????*??(*???????*????????????*???*?????*?????*??????*****??*??????????*???????????

*/
