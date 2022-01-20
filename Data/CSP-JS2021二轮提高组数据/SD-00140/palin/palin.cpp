#include <iostream>
#include <cstdio>
using namespace std;
inline int read() {
	int x = 0, f = 1;
	char t = getchar();
	while(!isdigit(t)) {
		if(t == '-')
			f = -1;
		t = getchar();
	}
	while(isdigit(t)) {
		x *= 10;
		x += t - '0';
		t = getchar();
	}
	return x*f;
}
inline void write(int x, char t) {
	if(x < 0) {
		putchar('-');
		x = -x;
	}
	if(!x) {
		putchar('0'), putchar(t);
		return ;
	}
	int _stk[15], _stk_cnt = 0;
	while(x) {
		_stk[++ _stk_cnt] = x%10;
		x /= 10;
	}
	while(_stk_cnt)
		putchar(_stk[_stk_cnt --] + '0');
	putchar(t);
}
const int N = 5e5 + 5;
int n, a[N*2], pos, cnt;
bool opt[N*2];
void work(int ll, int lr, int rl, int rr) {
	while(cnt < n) {
		int _ll = ll, _lr = lr, _rl = rl, _rr = rr;
		bool flag = 0;
		if((a[ll] == a[lr] && ll < lr) || a[ll] == a[rl]) {
			opt[++ cnt] = 0;
			if(a[ll] == a[lr] && ll < lr)
				opt[n*2 - cnt + 1] = 0, _lr --;
			if(a[ll] == a[rl])
				opt[n*2 - cnt + 1] = 1, _rl ++;
			_ll ++, flag = 1;
		}
		else if((a[rr] == a[rl] && rr > rl) || a[rr] == a[lr]) {
			opt[++ cnt] = 1;
			if(a[rr] == a[rl] && rr > rl)
				opt[n*2 - cnt + 1] = 1, _rl ++;
			if(a[rr] == a[lr])
				opt[n*2 - cnt + 1] = 0, _lr --;
			_rr --, flag = 1;
		}
		if(!flag)
			break;
		ll = _ll, lr = _lr, rl = _rl, rr = _rr;
	}
}
void solve() {
	n = read();
	pos = 0, cnt = 0;
	for(int i = 1; i <= n*2; i ++)
		a[i] = read();
	for(int i = 2; i <= n*2; i ++)
		if(a[i] == a[1])
			pos = i;
	opt[++ cnt] = 0, opt[n*2] = 0;
	work(2, pos - 1, pos + 1, n*2);
	if(cnt == n) {
		for(int i = 1; i <= n*2; i ++) {
			if(!opt[i])
				putchar('L');
			else
				putchar('R');
		}
		putchar('\n');
		return ;
	}
	pos = 0, cnt = 0;
	for(int i = 1; i < n*2; i ++)
		if(a[i] == a[n*2])
			pos = i;
	opt[++ cnt] = 1, opt[n*2] = 0;
	work(1, pos - 1, pos + 1, n*2 - 1);
	if(cnt == n) {
		for(int i = 1; i <= n*2; i ++) {
			if(!opt[i])
				putchar('L');
			else
				putchar('R');
		}
		putchar('\n');
		return ;
	}
	write(-1, '\n');
}
int main() {
	freopen("palin.in", "r", stdin);
	freopen("palin.out", "w", stdout);
	int t = read();
	for(int i = 1; i <= t; i ++)
		solve();
	return 0;
}
