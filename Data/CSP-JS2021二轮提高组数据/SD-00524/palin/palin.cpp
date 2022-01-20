#include <bits/stdc++.h>
#define N 1000005
using namespace std;

int T, n, a[2 * N], b[2 * N];
int f, cnt, head, tail, jishu;
char ch[2 * N];

int read() {
	char ch = getchar();
	int f = 0, h = 1;
	while(!isdigit(ch)) {
		if(ch == '-')
		h = -1;
		ch = getchar();
	}
	while(isdigit(ch)) {
		f = f * 10 + ch - '0';
		ch = getchar();
	}
	return f;
}

void dfs(int sum, int lr, int head, int tail) {
	if(sum == 2 * n) {
		f = 1; return;
	}
	b[++cnt] = a[head];
	ch[++jishu] = 'L';
	head++;
	sum++;
	dfs(sum, 1, head, tail);
	b[cnt] = a[tail];
	ch[jishu] = 'R';
	tail--; head--;
	dfs(sum, 2, head, tail);
	if(sum > n) {
		if(b[2 * n + 1 - sum] != b[sum])
		return;
	}
	return;
}

int main() {
	freopen("palin.in", "r", stdin);
	freopen("palin.out", "w", stdout);
	//I'm free to be whatever I.
	T = read();
	while(T--) {
		head = tail = 1;
		n = read();
		f = -1; cnt = 0;
		jishu = 0;
		memset(a, 0, sizeof(a));
		memset(b, 0, sizeof(b));
		for (int i = 1; i <= 2 * n; i++) {
			a[i] = read();
		}
		dfs(0, 1, 1, 2 * n);
		if(f = -1) {
			cout << -1 << endl;
			continue;
		}
		else {
			for (int i = 1; i <= jishu; i++)
			cout << ch[i];
			cout << endl;
		}
	}
	return 0;
}
