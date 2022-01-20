#include<bits/stdc++.h>
using namespace std;

#define IOR(i, st, ed) for(int i = st; i < ed; i++) 
#define LOR(i, st, ed) for(int i = st; i > ed; i--)
#define ZERO(x) memset(x, 0, sizeof x);

const int MB = 1 << 21;
struct FastIO {
    char Buf[MB+100], *p, *e;
    int GetChar() {
        if(p == e) p = Buf, e = Buf+fread(Buf, 1, MB, stdin);
        return p == e ? EOF : *p++;
    }
    template<typename T>
    FastIO& operator>>(T& x) {
        char c, l;
        for(c = 0; !isdigit(c); c = GetChar()) l = c;
        for(x = 0; isdigit(c); c = GetChar()) x = x * 10 + c - '0';
        if(l == 'x') x = -x;
        return *this;
    }
}IO;

const int MAXN = 2e2 + 10;
const int MAXM = 5e3 + 10;
const int INF = 0x3f3f3f3f;

long long Head[MAXN], Next[MAXM<<1], Ver[MAXM<<1], Eg[MAXM<<1];
int idx = 1;
void Add(int pre, int to, int val); 

long long s, t, n, m, ans = 0;
int Pos[MAXN];

bool Pre();
long long Dinic(int s, long long flow = INF);

int main() { /**/

#ifdef LOCAL 
    freopen("I:\\Code\\ZROI\\Day17\\In.in", "r", stdin);
    freopen("Out.out", "w", stdout);
#endif

    IO >> n >> m >> s >> t;
    while(m--) {
        int u, v, w; IO >> u >> v >> w;
        Add(u, v, w); Add(v, u, 0);
    }

    int t;
    while(Pre()) 
        while(t = Dinic(s)) ans += t;
    printf("%lld\n", ans);

    IOR(i, 1, n+1) printf("%d ", Pos[i]);

    return 0;
} /**/

void Add(int pre, int to, int val) { 
    Ver[++idx] = to; Eg[idx] = val;
    Next[idx] = Head[pre]; Head[pre] = idx;
}

bool Pre() {
    ZERO(Pos); queue<int> q;
    q.push(s); Pos[s] = 1;
    while(!q.empty()) {
        int x = q.front(); q.pop();
        for(int i = Head[x]; i; i = Next[i]) 
            if(Eg[i] && !Pos[Ver[i]]) {
                q.push(Ver[i]); Pos[Ver[i]] = Pos[x] + 1;
                if(Ver[i] == t) return 1;
            }
    }
    return 0;
}

long long Dinic(int x, long long flow) {
    if(x == t) return flow;
    long long res = flow, k;
    for(int i = Head[x]; i && res; i = Next[i]) 
        if(Eg[i] && Pos[Ver[i]] == Pos[x] + 1) {
            k = Dinic(Ver[i], min(res, Eg[i]));
            if(!k) Pos[Ver[i]] = 0;
            Eg[i] -= k; Eg[i ^ 1] += k;
            res -= k;
        }
    return flow - res;
}