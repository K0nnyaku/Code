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

const int N = 1e5+3;
int n, _m1, _m2;

struct node {
	int s, t;
}a[N], b[N];

inline bool cmp (node a, node b) {
	return a.s < b.s;
}

int vis1[N], vis2[N];
int now, lst;
priority_queue<int>q;
int ans;

int main () {
	freopen("airport.in", "r", stdin);
	freopen("airport.out", "w", stdout);
	read(n), read(_m1), read(_m2);
	re(i, _m1) {
		read(a[i].s), read(a[i].t);
	}
	re(i, _m2) {
		read(b[i].s), read(b[i].t);
	}
	sort(a+1, a+_m1+1, cmp);
	sort(b+1, b+_m2+1, cmp);
	
	while(!q.empty()) q.pop();
	int x = 1, y = 1;
	now = 1;
	q.push(-a[1].t);
	rep(i, 2, _m1) {
		while(!q.empty()) {
			int cnt = q.top();
			cnt = -cnt;
			if(a[i].s > cnt) {
				q.pop();
				--now;
			}
			else break;
		}
		q.push(-a[i].t);
		++now;
		x = max(x, now);
	}
	
	while(!q.empty()) q.pop();
	now = 1;
	q.push(-b[1].t);
	rep(i, 2, _m2) {
		while(!q.empty()) {
			int cnt = q.top();
			cnt = -cnt;
			if(b[i].s > cnt) {
				q.pop();
				--now;
			}
			else break;
		}
		q.push(-b[i].t);
		++now;
		y = max(y, now);
	}
	if(x + y <= n) {
		write(_m1+_m2);
		return 0;
	}
	re(lim, n) {
	while(!q.empty()) q.pop();
	++vis1[lim];
	now = 1;
	q.push(-a[1].t);
	rep(i, 2, _m1) {
		while(!q.empty()) {
			int cnt = q.top();
			cnt = -cnt;
			if(a[i].s > cnt) {
				q.pop();
				--now;
			}
			else break;
		}
		if(now + 1 > lim) continue;
		q.push(-a[i].t);
		++now;
		++vis1[lim];
	}
	}
	re(lim, n) {
	while(!q.empty()) q.pop();
	++vis2[lim];
	now = 1;
	q.push(-b[1].t);
	rep(i, 2, _m2) {
		while(!q.empty()) {
			int cnt = q.top();
			cnt = -cnt;
			if(b[i].s > cnt) {
				q.pop();
				--now;
			}
			else break;
		}
		if(now + 1 > lim) continue;
		q.push(-b[i].t);
		++now;
		++vis2[lim];
	}
	}
	rep(i, 0, n) {
		ans = max(ans, vis1[i] + vis2[n-i]);
	}
	out(ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
