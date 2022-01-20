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

const int N = 500000 + 5;

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

int T, n, m, a[N], res[N], tmp[N], cnt[N];

void cpp() {
	int th = 0;
	F(i, 1, m) {
		if (res[i] < tmp[i]) {
			th = 0; break;
		}
		if (res[i] > tmp[i]) {
			th = 1; break;
		}
	}
	if (th) {
		F(i, 1, m) res[i] = tmp[i];
	}
}

signed main() {
	freopen("palin.in", "r", stdin);
	freopen("palin.out", "w", stdout);
	T = read();
	while (T--) {
		n = read(); m = 2 * n; 
		F(i, 1, m) {
			a[i] = read();
		}
		F(i, 1, m) cnt[i] = 0, res[i] = 0;
		F(i, n + 1, m) cnt[a[i]]++;
		int cz = 0;
		F(i, 0, n) {
			if (i) cnt[a[i]]++, cnt[a[m - (n - i)]]--;
			bool flag = 1;
			F(j, 1, n) if (!cnt[j] || cnt[j] == 2) flag = 0;
			if (!flag) continue;
			int h = i + 1, t = h + n - 1, l = i, r = t + 1, ll = n, rr = n + 1;
			while (ll >= 1 && rr <= m) {
				int s1 = 0, s2 = 0;
				if (a[h] == a[l] && l > 0) s1 = 1;
				else if (a[h] == a[r] && r <= m) s1 = 2;
				if (a[t] == a[l] && l > 0) s2 = 1;
				else if (a[t] == a[r] && r <= m) s2 = 2;
				if (s1 && s2 && h < t) {
					if (s1 == 2) {
						tmp[ll] = 2; tmp[rr] = 1;
						h++;
						r++;
					}
					else if (s2 == 2) {
						tmp[ll] = 2; tmp[rr] = 2;
						t--;
						r++;
					}
				}
				else if (s1 || s2) {
					if (s1) {
						tmp[ll] = s1; tmp[rr] = 1;
						h++;
						if (s1 == 1) l--;
						else r++;
					}
					else {
						tmp[ll] = s2; tmp[rr] = 2;
						t--;
						if (s2 == 1) l--;
						else r++;
					}
				}
				else {
					flag = 0; break;
				}
				ll--; rr++;
			} 
			if (!flag) continue;
			if (!cz) {
				cz = 1;
				F(j, 1, m) res[j] = tmp[j];
			}
			else {
				cpp();
			}
		}
		if (!cz) cout << -1 << '\n';
		else {
			F(i, 1, m) cout << (res[i] == 1 ? 'L' : 'R');
			cout << '\n';
		} 
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
/*
2
5
4 1 2 4 5 3 1 2 3 5
3
3 2 1 2 1 3
*/
