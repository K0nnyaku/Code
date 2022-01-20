#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

const int N = 510;
int n, cnt, m, T, num, dp[N * N][2];
bool vis[N];
pair<int, int> b[N];//1 - up£¬ 2 - down£¬3 - right£¬4 - left 
int map[N][N], hd[N];

struct Edge{
	int nt, to, w;
}e[N];

void add(int x, int y, int v){
	e[++cnt].w = v;
	e[cnt].to = y;
	e[cnt].nt = hd[x];
	hd[x] = cnt;	
}

void dfs(int fa){
	vis[fa] = true;
	for(int i = hd[fa]; i; i = e[i].nt){
		if(dp[fa][1] != -1) dp[e[i].to][1] = min(dp[e[i].to][1], dp[fa][0] + e[i].w);
		if(dp[fa][0] != -1) dp[e[i].to][0] = min(dp[e[i].to][0], dp[fa][1] + e[i].w);
		if(!vis[e[i].to]) 
			dfs(e[i].to);
	} 
}

int main(){
	freopen("traffic.in", "r", stdin);
	freopen("traffic.out", "w", stdout);
	scanf("%d%d%d", &n, &m, &T);
	
	for(int i = 1; i <= m; i++) b[i] = make_pair(i, 1), b[m + n + m - i + 1] = make_pair(i, 2);
	for(int i = 1; i <= n; i++) b[m + 1] = make_pair(i, 3), b[m + m + n + n - i + 1] = make_pair(i, 4);  
	
	
	for(int i = 1; i < n; i++)
		for(int j = 1; j <= m; j++)
			map[i][j] = ++num;
	
	for(int i = 1; i < n; i++){
		for(int j = 1; j <= m; j++){
			int u;
			scanf("%d", &u);
			add(map[i][j], map[i + 1][j], u);
			add(map[i + 1][j], map[i][j], u);
		}
	}
	
	for(int i = 1; i <= n; i++){
		for(int j = 1; j < m; j++){
		int u;
		scanf("%d", &u);
		add(map[i][j], map[i][j + 1], u);
		add(map[i][j + 1], map[i][j], u);
		}
	}
	int t = num;
//	cout << t << endl;
	
	while(T--){
		for(int i = 1; i <= num; i++){
			dp[i][1] = INT_MAX;
			dp[i][0] = INT_MAX;
		}
		num = t;
		int k;
		scanf("%d", &k);
		for(int i = 1; i <= k; i++){
			int shu, u, co;
			scanf("%d%d%d", &shu, &u, &co);
			pair<int, int> a = b[shu];
			int x = a.first;
			int y = a.second;
			if(y == 1) add(++num, map[1][x], u), add(map[1][x], num, u);
			if(y == 2) add(++num, map[n][x], u), add(map[n][x], num, u);
			if(y == 3) add(++num, map[x][m], u), add(map[x][m], num, u);
			if(y == 4) add(++num, map[x][1], u), add(map[x][1], num, u);
			
			if(co == 1){
				dp[num][1] = 0;
				dp[num][0] = -1;
			}
			if(co == 0){
				dp[num][0] = 0;
				dp[num][1] = -1;
			}  
		}
		
		dfs(num);
		
		printf("%d\n", min(dp[1][0], dp[1][1]));
	}
	return 0;
}
