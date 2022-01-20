#include <algorithm>
#include <cstring>
#include <cstdio>

using namespace std;

#define inf 0x3f3f3f3f
#define maxn 1000001
#define ll long long

void read(int &x) {
	char F = getchar();
	int flag = 1; x = 0;
	while(F > '9' || F < '0') {
		if(F == '-') flag = -1;
		F = getchar();
	}
	while(F >= '0' && F <= '9') {
		x *= 10;
		x += F - '0';
		F = getchar();
	}
	x *= flag;
}

int n, a[maxn], T, vis[maxn];
bool work[maxn];

bool dfs(int o, int l, int r) {
	if(o == (n << 1 | 1)) return 1;
	bool flag = 0;
	if(! vis[a[l]] || vis[a[l]] + o == (n << 1 | 1)) {
		work[o] = 0;
		if(! vis[a[l]]) vis[a[l]] = o;
		flag |= dfs(o + 1, l + 1, r);
		if(vis[a[l]] == o) vis[a[l]] = 0;
		if(flag) return 1;
	}
	if(! vis[a[r]] || vis[a[r]] + o == (n << 1 | 1)) {
		work[o] = 1;
		if(! vis[a[r]]) vis[a[r]] = o;
		flag |= dfs(o + 1, l, r - 1);
		if(vis[a[r]] == o) vis[a[r]] = 0;
		if(flag) return 1;
	}
	return 0;
}

int main() {
	freopen("palin.in", "r", stdin);
	freopen("palin.out", "w", stdout);
	read(T);
	while(T --) {
		read(n);
		for(int i = 1; i <= (n << 1); i ++) read(a[i]);
		if(dfs(1, 1, n << 1)) {
			for(int i = 1; i <= (n << 1); i ++) {
				if(work[i]) printf("R");
				else printf("L");
			}
			puts("");
		}
		else printf("%d\n", -1);
	}
	return 0;
}

/*2
5
4 1 2 4 5 3 1 2 3 5
3
3 2 1 2 1 3*/
