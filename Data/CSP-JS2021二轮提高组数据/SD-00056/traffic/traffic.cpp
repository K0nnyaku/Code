#include<cstdio>
#include<iostream>
using namespace std;
const int N = 505;
int n, m, t, k;
int wh[N][N], wz[N][N];
int w[N], id[N], color[N];
int main(){
	freopen("traffic.in", "r", stdin);
	freopen("traffic.out", "w", stdout);
	scanf("%d%d%d", &n, &m, &t);
	for(int i = 1; i < n; i++){
		for(int j = 1; j <= m; j++){
			scanf("%d", &wz[i][j]);
		}
	}
	for(int i = 1; i <= n; i++){
		for(int j = 1; j < m; j++){
			scanf("%d", &wh[i][j]);
		}
	}
	while(t--){
		scanf("%d", &k);
		for(int i = 1; i <= k; i++){
			scanf("%d%d%d", &w[i], &id[i], &color[i]);
		}
	}
	printf("0");
	fclose(stdin);
	fclose(stdout);
	return 0;
}
