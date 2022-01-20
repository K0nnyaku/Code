#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 55;
char opt;
int n, q, tot, Flag = 1, Ans;
int F[N], Col[N], Dis[N], Num[N], Size[N];

int Cnt = 1, Last[N];
struct Edge{
	int to, nt;
}E[N << 1];
void Add(int u, int v) {
	E[++Cnt].to = v; E[Cnt].nt = Last[u];
	Last[u] = Cnt;
}

void Prepare(int u, int x) {
	Col[u] = u; Num[u] = ++tot; Size[u] = 1;
	for (int i = Last[u]; i; i = E[i].nt) {
		int v = E[i].to;
		if (i == (x ^ 1))	continue;
		F[v] = u;
		Prepare(v, i);
//		Dis[Num[v]] = Dis[Num[u]] + 1;
		Size[u] += Size[v];
	}
}

void Solve(int u, int x, int dis) {
	Dis[Num[u]] = dis;
	for (int i = Last[u]; i; i = E[i].nt) {
		int v = E[i].to;
		if (i == (x ^ 1))	continue;
		if (Col[u] == Col[v])	Solve(v, i, dis);
		else	Solve(v, i, dis + 1);
	}
}

int main() {
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	scanf("%d",&n);
	for (int i = 1, u, v; i < n; i++) {
		scanf("%d%d",&u,&v);
		Add(u, v); Add(v, u);
	}
	
	F[0] = -1;
	Prepare(0, 0);
	
	scanf("%d",&q);
	for (int i = 1, u; i <= q; i++) {
		scanf(" %c%d",&opt,&u);
		if (opt == 'O') {
			Col[u] = n;
			while (F[u] != -1) {
				u = F[u]; Col[u] = n;
			}
			n++; Flag = 1;
		}
		else {
			if (Flag) {
				Solve(0, 0, 0);
				Flag = 0;
			}
			Ans = 0;
			for (int j = Num[u]; j < Num[u] + Size[u]; j++) {
//				printf("Dis[%d] = %d\n",j,Dis[j]);
				Ans += Dis[j];
			}
//			printf("Ans = %d Size[%d] = %d\n",Ans,u,Size[u]);
			printf("%.10lf\n",1.0 * Ans / (1.0 * Size[u]));
		}
	}
	
	return 0;
}

/*
13
0 1
0 2
1 11
1 10
1 9 
9 12
2 5
5 8
2 4
2 3
4 6
4 7
7
q 0
O 4
q 6
q 2
O 9
q 9
q 2
*/
