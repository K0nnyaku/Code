#include<bits/stdc++.h>
using namespace std;

#define IOR(i, st, ed) for(int i = st; i < ed; i++)
#define LOR(i, st, ed) for(int i = st; i > ed; i--)
#define ZERO(x) memset(x, 0, sizeof x);

const int MAXN = 5e3 + 10;
const int MAXM = 5e4 + 10;
const int INF = 0x3f3f3f3f;

int Head[MAXN], Next[MAXM<<1], Ver[MAXM<<1], Eg[MAXM<<1], Cap[MAXM<<1];
int idx = 1;
void Add(int pre, int to, int val);

int n, m, s, t, ans;
int Pos[MAXN];
bool Vis[MAXN];

int main() { /**/
    scanf("%d%d%d%d", &n, &m, &s, &t);
    while(m--) {
        int u, v, w, c; scanf("%d%d%d%d", &u, &v, &w, &c);
        Add(u, v, w, c); Add(v, u, 0, -c); 
    }

    int t;
    while(Spfa()) 
        while(t = Dinic(s, INF)) ans += t;

    return 0;
} /**/

void Add(int pre, int to, int val, int vAl) {
    Ver[++idx] = to; Eg[idx] = val; Cap[idx] = vAl;
    Next[idx] = Head[pre]; Head[pre] = Next[idx];
}

bool Spfa() {
    ZERO(Vis); memset(Pos, 0x3f, sizeof Pos);
    Pos[s] = 1; Vis[s] = 1;
    queue<int> q; q.push(s);
    
    while(!q.empty()) {
        int x = q.front(); q.pop();
        Vis[x] = 0; 
        for(int i = Head[x]; i; i = Next[i]) {
            int y = Ver[i], z = Cap[i], v = Eg[i];
            if(Pos[y] > Pos[x] + z && v) {
                Pos[y] = Pos[x] + z;
                if(!Vis[y]) q.push(y), Vis[y] = 1;
            }
        }
    }
    return Pos[t] != INF;
}

pair<int, int>Ek() {
    int flow = 0, cost = 0;
    while(Spfa()) {
        int x = T;
        while(x) {
            int i = Pos[x];
            
        }
    } 
}