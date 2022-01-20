#include <iostream>
#include <cstdio>
#include <queue>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

#define FOR(i,l,r) for(int i = l;i <= r; i++)

using namespace std;

const int N = 1e6 + 10;

int n, T, operation[N], ans[N], a[N], l , r;
deque<int> q;
bool vis[N], flag;

void print() {
	FOR(i,1,2*n) {
		if(operation[i] == 1)
		printf("L");
		else if(operation[i] == 2)
		printf("R");
	}
	printf("\n");
}

void dfs(int x) {
	if(flag) return;
	if(x == (n * 2) + 1) {
		flag = true;
		return;
	}
	else if(x >= n + 1) {
		if(a[l] == ans[2 * n - x + 1]) {
			ans[x] = a[l];
			l++;
			operation[x] = 1;
			dfs(x+1);
			if(flag) return;
			l--;
		}
		if(a[r] == ans[2 * n - x + 1] ) {
			ans[x] = a[r];
			r--;
			operation[x] = 2;
			dfs(x + 1);
			if(flag) return;
			r++;
		}
		return;
	}
	else{
		if(!vis[a[l]]) {
			vis[a[l]] = true;
			ans[x] = a[l];
			l++;
			operation[x] = 1;
			dfs(x+1);
			if(flag) return;
			l--;
			vis[a[l]] = false;
		}
		if(!vis[a[r]]) {
			vis[a[r]] = true;
			ans[x] = a[r];
			r--;
			operation[x] = 2;
			dfs(x+1);
			if(flag) return;
			r++;
			vis[a[r]] = false;
		}
	}
}


int main() {

	freopen("palin.in", "r", stdin);
	freopen("palin.out", "w", stdout);
	scanf("%d", &T);
	while(T--) {
		flag = false;
		scanf("%d", &n);
		l = 1; r = (n<<1);
		//cout << l << ' ' << r << endl;
		FOR(i,1,n) vis[i] = false;
		FOR(i,1,n*2) {
			scanf("%d", &a[i]);
		}
		dfs(1);
		if(flag) {
			print();
		}
		else printf("-1\n");
	}
	fclose(stdin); fclose(stdout);
	return 0;
}

