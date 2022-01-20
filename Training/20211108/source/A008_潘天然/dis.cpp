#include<cstdio>
#include<algorithm>
#include<cstring>
#define int long long
using namespace std;
const int N = 1e5 + 5, K = 55;
char opt[K];
int n, m, x, Ans, Vis[N], Tag[K][K];

int Cnt, Last[N];
struct Edge{
	int to, nt;
}E[N << 1];
void Add(int u, int v) {
	E[++Cnt].to = v;
	E[Cnt].nt = Last[u];
	Last[u] = Cnt; 
} 

void Solve(int j, int u, int dis) {
	Vis[u] = 1;
	if (dis > x)	return ;
	if (u > j and dis <= x)	Ans++;
	for (int i = Last[u]; i; i = E[i].nt) {
		int v = E[i].to;
		if (Vis[v] or Tag[u][v])	continue;
		Solve(j, v, dis + 1);
	}
}

signed main() {
	freopen("dis.in","r",stdin);
	freopen("dis.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for (int i = 2; i <= n; i++) {
		Add(i, i >> 1); Add(i >> 1, i);
	}
	
//	DFS(1); Vis[2] = 1; Solve(1);
//	printf("---%lld\n",F[3][3]);
	
	for (int i = 1; i <= m; i++) {
		scanf("%s%lld",opt,&x);
		if (opt[0] == '?') {
			Ans = 0;
			for (int j = 1; j < n; j++) {
				for (int k = j + 1; k <= n; k++) {
					int dis = 0, Flag = 1;
					int jj = j, kk = k;
					while (jj != kk) {
						if (jj > kk)	swap(jj, kk);
						if (Tag[kk][kk >> 1] or dis > x) {
							Flag = 0; break;
						}
						kk >>= 1; dis++;
					}
					if (dis <= x and Flag)	Ans++;	
				}
			}
			printf("%lld\n",Ans);
		}
		else {
			Tag[x][x >> 1] = Tag[x >> 1][x] = 1;
		}
	}
	
	return 0;
}
