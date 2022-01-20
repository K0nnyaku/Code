#include<map>
#include<time.h>
#include<queue>
#include<stack>
#include<cstdio>
#include<iomanip>
#include<cstring>
#include<iostream>
#include<algorithm>
#define inf 0x3f3f3f3f
using namespace std;
const int MAXN = 2e3 + 100;
int a[MAXN][MAXN], b [MAXN][MAXN];

int main() {
	freopen("traffic.in", "r", stdin);
	freopen("traffic.out", "w", stdout);
	int n, m , t;
	cin >> n >> m >> t; 
	for(int i = 1; i <= n - 1; i ++) {
		for(int j = 1; j <= m; j++) {
			cin >> a[i][j];
		} 
	}
	for(int i = 1; i <= n; i ++) {
		for(int j = 1; j <= m - 1; j++) {
			cin >> b[i][j];
		} 
	}
	for(int i = 1; i <= t; i++) {
		int x = 1e9 + 7;
		srand(time(NULL));
		cout << rand() % x + 1 << endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}


