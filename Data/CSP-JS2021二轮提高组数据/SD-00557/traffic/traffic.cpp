/*

*/

#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<string>
#include<map>
#include<queue>
#include<vector>
#define LL long long
#define orz cout<<"lkp AK IOI!\n"
using namespace std;
const int MAXN = 1e5 + 10;
const int mod = 1e9 + 7;
const int INF = 1e9 + 7;

struct edge {
    int to, w, nxt;
}e[MAXN << 1];
int head[MAXN], num_edge = 1;
int Head[MAXN], Num_edge = 1;

int n, m, T;
int dis[MAXN], cur[MAXN], id[MAXN];
bool vis[MAXN];

int S, End;

void add_edge(int from, int to, int w) { e[++num_edge] = (edge){to, w, head[from]}, head[from] = num_edge; }
bool bfs() {
    queue<int> q;
    memcpy(cur, head, sizeof cur);
    memset(dis, -1, sizeof dis);
    q.push(S), dis[S] = 0;
    while(!q.empty()) {
        int u = q.front(); q.pop();
        for(int i = head[u]; i; i = e[i].nxt) {
            int v = e[i].to;
            if(dis[v] == -1 && e[i].w) {
                dis[v] = dis[u] + 1;
                q.push(v);
                if(v == End) return true;
            }
        }
    }
    return false;
}

int dfs(int u, int limit) {
    if(u == End) return limit;
    int flow = 0;
    for(int i = cur[u]; i && flow < limit; i = head[u]) {
        cur[u] = i;
        int v = e[i].to;
        if(dis[v] == dis[u] + 1 && e[i].w) {
            int f = dfs(v, min(e[i].w, limit - flow));
            if(!f) dis[v] = -1;
            e[i].w -= f, e[i ^ 1].w += f, flow += f;
        } 
    }
    return flow;
}

int Dinic() {
    int max_flow = 0, flow = 0;
    while(bfs()) {
        while(flow = dfs(1, INF)) {
            max_flow = max(max_flow, flow);
        }
    }
    return max_flow;
}

int main() {
    freopen("traffic.in","r",stdin);
    freopen("traffic.out","w",stdout);
    int sum = 0;
    scanf("%d%d%d", &n, &m, &T);
    for(int i = 1; i < n; ++i) {
        for(int j = 1; j <= m; ++j) {
            int x;
            scanf("%d", &x);
            add_edge(i * n + j + 1, (i + 1) * n + j + 1, x);
            add_edge((i + 1) * n + j + 1, i * n + j + 1, 0);
            sum = sum + x;
        }
    }
    for(int i = 1; i < m; ++i) {
        for(int j = 1; j <= n; ++j) {
            int x;
            scanf("%d", &x);
            add_edge((j) * n + i + 1, (j + 1) * n + i + 1, x);
            add_edge((j + 1) * n + i + 1, (j) * n + i + 1, 0);
            sum = sum + x;
        }
    }
    memcpy(Head, head, sizeof head);
    Num_edge = num_edge;
    for(int i = 1; i <= m; ++i) id[i] = i;
    for(int i = 1; i <= n; ++i) id[m + i] = i * n + m + 2;
    for(int i = 1; i <= m; ++i) id[n + m + i] = (n) * m + (m - i + 1);
    for(int i = 1; i <= n; ++i) id[2 * m + n + i] = (n - i + 1) * m + (n - i + 1);
    while(T--) {
        int k, tmp = 0;
        scanf("%d", &k); 
        for(int i = 1, x, p, col; i <= k; ++i) {
            scanf("%d%d%d", &p, &x, &col);
            tmp = tmp + p;
            if(x <= m) add_edge(id[x], id[x] + m, p), add_edge(id[x] + m, id[x], 0);
        }
    } 

    fclose(stdin);
    fclose(stdout);
    return 0;
}

