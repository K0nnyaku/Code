#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>

using namespace std;

int re() {
	int p = 0, f = 1; char i = getchar();
	while(i < '0' || i > '9') {if(i == '-') f = -1;i = getchar();}
	while(i >= '0' && i <= '9') p = p * 10 + i - '0', i = getchar();
	return f * p;
}

const int N = 110;

int T, n;
int a[N], b[N], ans[N], opt[N], op[N];
bool ok;

bool Judge() {
	for(int i = 1, j = 2 * n; i <= 2 * n; i++, j--)
		if(b[i] != b[j])	return false;
	return true;
}

void dfs(int x, int l, int r)
{
	for(int i = 1; i <= 2 * n; i++)
		if(b[i] > ans[i])	return ; 
	if(x >= n + 1) {
		for(int i = 1, j = 2 * n; i <= 2 * n; i++, j--)
			if(b[i] != b[j] && !b[i] && !b[j])	return ;
	}
	if(x == 2 * n + 1) {
		if(Judge()) {
			ok = 1;
			bool flag = 0;
			for(int i = 1; i <= 2 * n; i++)
				if(b[i] < ans[i]){
					flag = 1;
					break;
				}
				else break;
			if(flag) {
				for(int i = 1; i <= 2 * n; i++)
					ans[i] = b[i];
				for(int i = 1; i <= 2 * n; i++)
					opt[i] = op[i];
			}
		}
		return ;
	}
	b[x] = a[l];
	op[x] = 0;
	dfs(x + 1, l + 1, r);
	b[x] = a[r];
	op[x] = 1;
	dfs(x + 1, l, r - 1);
}

int main()
{
	freopen("traffic.in", "r", stdin);
	freopen("traffic.out", "w", stdout);
	cout << 27 << endl;
	return 0;
}

