#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cstring>
#include <ctype.h> 
#include <queue>
using namespace std;
#define rep(i, f, t) for(int i(f); i <= t; ++i)
#define per(i, t, f) for(int i(t); i >= f; --i)
#define re(i, t) for(int i(1); i <= t; ++i)
#define pe(i, t) for(int i(t); i >= 1; --i)
#define nx(i, u) for(int i(link[u]); i; i = e[i].nxt)
#define inf 0x3f3f3f3f

template<class I>
inline I read(I &x) {
	x = 0;
	I f = 1;
	char ch = getchar();
	while(!isdigit(ch)) {
		if(ch == '-')
			f = f * (-1);
		ch = getchar();
	}
	while(isdigit(ch)) {
		x = (x << 1) + (x << 3) + (ch ^ 48);
		ch = getchar();
	}
	return x = x * f;
}

char buf[1003];

template<class I>
inline void write(I x) {
	if(x == 0) {
		putchar('0');
		return ;
	}
	I tmp = 0, cnt = 0;
	tmp = x < 0 ? (-x) : x;
	if(x < 0) putchar('-');
	while(tmp) {
		buf[cnt++] = (tmp % 10 + '0');
		tmp /= 10;
	}
	while(cnt) putchar(buf[--cnt]);
	return ;
}

#define out(x) write(x), putchar(' ')
#define outn(x) write(x), putchar('\n')
#define pii pair<int, int>
#define mp(i, j) make_pair(i, j)
typedef long long ll;

int n, m, t, w, x, p, T, k;
const int N = 1003;
int head_[N*N];

struct node {
	int to, nxt, val;
}e[N*N];

int link[N*N], cnt;

inline void add (int u, int v, int w) {
	e[++cnt] = (node){v, link[u], w};
	link[u] = cnt;
}

ll ans;
int col[N*N];

int main () {
	freopen("traffic.in", "r", stdin);
	freopen("traffic.out", "w", stdout);
	read(n), read(m), read(T);
	re(i, n - 1) {
		re(j, m) {
			read(w);
			int u = (i - 1) * m + j;
			int v = i * m + j;
			add(u, v, w);
		}
	}
	re(i, n) {
		re(j, m - 1) {
			read(w);
			int u = (i - 1) * m + j;
			int v = (i - 1) * m + j + 1;
			add(u, v, w);
		}
	}
	
	while(T--) {
		ans = inf;
		ll now = 0;
		int lst = cnt;
		re(i, n * m) head_[i] = link[i];
		read(k);
		int lat = -1;
		bool flag = 0;
		re(_, k) {
			read(x), read(p), read(t);
			int u = 0;
			if(p <= m) {
				u = p;
			} 
			else if(p <= m+n) {
				u = (p - m - 1) * m + m;
			}
			else if(p <= 2*m + n) {
				u = (n - 1) * m + m - (p - m - n) + 1;
			}
			else {
				u = 1 + (n - (p - 2 * m - n)) * m;
			}
			add(u, n * m + _, x);
			col[n * m + _] = t;
			if(lat == -1) lat = t;
			else if(lat ^ t) flag = 1;
			lat = t;
		}
		if(!flag) {
			outn(0);
			continue;
		}
		rep(i, 0, (1 << (n * m))-1) {
			rep(j, 0, n * m - 1) {
				if((1 << j) & i) col[j+1] = 1;
				else col[j+1] = 0;
			}
			now = 0;
			re(j, n * m + k) {
				nx(l, j) {
					int v = e[l].to;
					if(col[j] ^ col[v]) now += e[l].val;
				}
			}
			ans = min(ans, now);
		}
		re(i, n * m) link[i] = head_[i];
		rep(i, n * m + 1, n * m + k) link[i] = 0;
		cnt = lst;
		outn(ans);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
