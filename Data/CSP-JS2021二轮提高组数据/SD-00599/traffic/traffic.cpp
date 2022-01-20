#include <bits/stdc++.h>
using namespace std;
int n, m, t, dis[20][20][20][20], k;
struct node{
	int a, b, c;
}x[55];
pair <int, int> col[505 * 505];
int main(){
	freopen("traffic.in", "r", stdin);
	freopen("traffic.out", "w", stdout);
	int a;
	scanf("%d%d%d", &n, &m, &t);
	for (int i = 1; i < n; ++i){
		for (int j = 1; j <= m; ++j){
			scanf("%d", &a);
			dis[i][j][i + 1][j] = a;
			dis[i + 1][j][i][j] = a;
		}
	}
	for (int i = 1; i <= n; ++i){
		for (int j = 1; j < m; ++j){
			scanf("%d", &a);
			dis[i][j][i][j + 1] = a;
			dis[i][j + 1][i][j] = a;
		}
	}
	while (t --){
		scanf("%d", &k);
		for (int j = 1; j <= k; ++j){
			scanf("%d%d%d", &x[i].a, &x[i].b, &x[i].c);
			dis[]
		}
	}
}
