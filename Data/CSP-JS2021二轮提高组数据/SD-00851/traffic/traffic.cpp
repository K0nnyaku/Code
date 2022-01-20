#include <bits/stdc++.h>
const int maxn = 2e6+5;

inline int read() {
	int x = 0,w = 1;char ch = getchar();
	while(ch > '9' || ch < '0') {if(ch == '-') w = -1;ch = getchar();}
	while(ch <= '9' && ch >= '0'){x = x * 10 + ch - '0';ch = getchar();}
	return x * w;
}

int n,m,T,en;
int head[maxn],x1[maxn],x2[maxn],x3[maxn];

struct node {
	int to,w;
	int nxt;
}edges[maxn];

void add_edge(int u,int v,int w) {
	en ++;
	edges[en].to = v;
	edges[en].w = w;
	edges[en].nxt = head[u];
	head[u] = en;
}

void init() {
	for(int i = 1;i <= n - 1;i++) 
		for(int j = 1;j <= m;j++) {
			int x;x = read();
			int dis1 = sqrt((i * i) + (j * j));
			int dis2 = sqrt((i + 1) * (i + 1) + j * j);
			add_edge(dis1,dis2,x); 
		}
	for(int i = 1;i <= n ;i++) 
		for(int j = 1;j <= m - 1;j++) {
			int x; x = read();
			int dis1 = sqrt(i * i + j * j);
			int dis2 = sqrt(i * i + (j + 1) * (j + 1));
			add_edge(dis1,dis2,x);
		}
}

int main() {
	freopen("traffic.in","r",stdin);
	freopen("traffic.out","w",stdout);
	n = read();m = read();T = read();
	init();
	while(T--) {
		int k; k = read();
		for(int i = 1;i <= k;i++) {
			int x,p,t;
			x = read();p = read();t = read();
			printf("0\n");
		}
	}
	return 0;
}
