#include <iostream>
#include <cstdio>
#include <algorithm>
#include <queue>
#include <cstring>
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
const int N = 1e5 + 5;
int n, m[3], a[N], b[N], num[N*2], num_cnt, tm[N*2], pos[N], f[3][N], ans;
priority_queue<int, vector<int>, greater<int> > q;
inline int get_num(int x) {
	return lower_bound(num + 1, num + 1 + num_cnt, x) - num;
}
void solve(int id) {
	for(int i = 1; i <= m[id]; i ++) {
		a[i] = read(), b[i] = read();
		num[++ num_cnt] = a[i], num[++ num_cnt] = b[i];
	}
	sort(num + 1, num + 1 + num_cnt);
	for(int i = 1; i <= m[id]; i ++) {
		a[i] = get_num(a[i]), b[i] = get_num(b[i]);
		tm[a[i]] = i, tm[b[i]] = -i;
	}
	for(int i = 1; i <= n; i ++)
		q.push(i);
	for(int i = 1; i <= num_cnt; i ++) {
		if(tm[i] > 0) {
			int x = tm[i];
			if(!q.empty()) {
				pos[x] = q.top();
				q.pop();
				f[id][pos[x]] ++;
			}
		}
		else {
			int x = -tm[i];
			if(pos[x]) {
				q.push(pos[x]);
				pos[x] = 0;
			}
		}
	}
	for(int i = 1; i <= n; i ++)
		f[id][i] += f[id][i - 1];
}
int main() {
	freopen("airport.in", "r", stdin);
	freopen("airport.out", "w", stdout);
	n = read(), m[1] = read(), m[2] = read();
	solve(1);
	num_cnt = 0;
	while(!q.empty())
		q.pop();
	solve(2);
	for(int i = 0; i <= n; i ++)
		ans = max(ans, f[1][i] + f[2][n - i]);
	write(ans, '\n');
	return 0;
}
