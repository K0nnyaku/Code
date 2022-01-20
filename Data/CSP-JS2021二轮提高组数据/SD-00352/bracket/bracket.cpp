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

int n, k, ans;
char s[555];
char st[555];
int vis[555];
int qwq[555];
pii now[555];

void dfs(int th, int a, int b) {
	if(b > k) return ;
	if(th > n) {
		if(a != 0) return ;
		re(i, n) vis[i] = 0;
		int lst = 0, num = 0;
		re(i, n) {
			if(st[i] == '(') qwq[++lst] = i;
			else if(st[i] == ')') { now[++num] = mp(qwq[lst], i), vis[qwq[lst]] = vis[i] = num; --lst; }
		}
		lst = 0;
		re(i, num) {
			int l = now[i].first;
			int r = now[i].second;
			--l, ++r;
			if(st[l] == st[r] && st[l] == '*') {
				while(l) {
					--l;
					if(st[l] != '*') break;
				}
				while(r) {
					++r;
					if(st[r]!= '*') break;
				}
				if(vis[l] == vis[r]) return ;
			}
		}
		if(st[n] == '*') return ;
		++ans;
		return ;
	}
	if(s[th] != '?') {
		st[th] = s[th];
		if(s[th] == '(') dfs(th+1, a+1, 0);
		else if(s[th] == '*') {
			if(b + 1 > k) return ;
			dfs(th+1, a, b+1);
		}
		else {
			if(!a) return ;
			dfs(th+1, a-1, 0);
		}
	}
	else {
		st[th] = '*';
		if(b + 1 <= k) dfs(th+1, a, b+1);
		st[th] = ')';
		if(a) dfs(th+1, a-1, 0);
		st[th] = '(';
		dfs(th+1, a+1, 0);
	}
}

int main () {
	freopen("bracket.in", "r", stdin);
	freopen("bracket.out", "w", stdout);
	read(n), read(k);
	cin >> (s+1);
		if(s[1] != '?') {
			st[1] = s[1];
			if(s[1] == ')') {
				out(0);
				return 0; 
			}
			else if(s[1] == '(') {
				dfs(2, 1, 0);
			}
			else if(s[1] == '*') {
				out(0);
				return 0;
			}
		}
		else {
			st[1] = '(';
			dfs(2, 1, 0);
		}
	out(ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
