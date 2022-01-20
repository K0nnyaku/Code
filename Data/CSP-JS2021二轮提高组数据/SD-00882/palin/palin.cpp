#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int N = 5e5 + 5;

inline int read() {
	int res = 0, f = 1;
	char c = getchar();
	while (c > '9' || c < '0') {
		if (c == '-')  f = -1;
		c = getchar();
	}
	while (c >= '0' && c <= '9') {
		res = (res << 3) +  (res << 1) + c - '0';
		c = getchar();
	}
	return res * f;
}

int T;
int n;
int a[N], pos[N];
char ans[N], tmp[N];

void cpy() {
	if (!ans[1]) {
		for (int i = 1; i <= n; ++i)
			ans[i] = tmp[i];
	}
}

int l, r;
inline void dfs(int nw) {
	if (nw == n + 1) {
		cpy();
		return ;
	}
	
	bool ok = 0;
	tmp[nw] = 'L';
	if (!pos[a[l]]) {
		pos[a[l]] = nw;
		ok = 1; 
		l++;
		dfs(nw + 1);
		l--;
	}
	else  if (nw + pos[a[l]] == n + 1) {
		l++;
		dfs(nw + 1);
		l--;
	}
	if (ok)  pos[a[l]] = 0;
	
	ok = 0;
	tmp[nw] = 'R';
	if (!pos[a[r]]) {
		pos[a[r]] = nw;
		ok = 1; 
		r--;
		dfs(nw + 1);
		r++;
	}
	else  if (nw + pos[a[r]] == n + 1) {
		r--;
		dfs(nw + 1);
		r++;
	}
	if (ok)  pos[a[r]] = 0;
}

int main() {
	freopen("palin.in", "r", stdin);
	freopen("palin.out", "w", stdout);
	T = read();
	while (T--) {
		n = read();
		n <<= 1;
		l = 1, r = n;
		for (int i = 1; i <= n; ++i)  a[i] = read();
		for (int i = 1; i <= n; ++i) {
			ans[i] = tmp[i] = 0;
			pos[i] = 0;
		}
		dfs(1);
		if (ans[1] == 0)  printf("-1\n");
		else {
			for (int i = 1; i <= n; ++i)
			  printf("%c", ans[i]);
			printf("\n");
		}
		continue;
	}

	return 0;
}

