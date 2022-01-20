#include<bits/stdc++.h>
using namespace std;

#define IOR(i, st, ed) for(int i = st; i < ed; i++)
#define LOR(i, st, ed) for(int i = st; i > ed; i--)
#define EOR(i, x) for(int i = Head[x]; i; i = E[i].next)
#define TO(x) E[x].to
#define VAL(x) E[x].val

const int MB = 1 << 21;
struct FastIO {
    char Buf[MB+100], *p, *e;
    int GetChar() {
        if(p == e) p = Buf, e = Buf + fread(Buf, 1, MB, stdin);
        return p == e ? EOF : *p++;
    }
    template<typename T>
    FastIO& operator>>(T& x) {
        char c, l;
        for(c = 0; !isdigit(c); c = GetChar()) l = c;
        for(x = 0; isdigit(c); c = GetChar()) x = x * 10 + c - '0';
        if(l == '-') x = -x;
        return *this;
    }
}IN;

const int MAXN = 1e5 + 10;
const int MAXM = 2e5 + 10;

struct { int to, next, val; } E[MAXM<<1];
int idx, Head[MAXN];
void Add(int pre, int _to, int _val) {
    E[++idx] = { _to, Head[pre], _val }; Head[pre] = idx; }

struct { int u, v, val; } Qt[MAXN];
int Re[2][MAXN];
int n, m;
bool Vis[MAXN];

void Dijkstra(int s, int pos);

int main() { /**/
#ifdef LOCAL 
    freopen("In.in", "r", stdin);
    freopen("Out.out", "w", stdout);
#endif

    IN >> n >> m;
    IOR(i, 1, m+1) {
        int u, v, w; IN >> u >> v >> w;
        Add(u, v, w); Add(v, u, w);
        Qt[i] = { u, v, w };
    }

    Dijkstra(1, 0); Dijkstra(n, 1);

    IOR(i, 1, n+1) printf("%d\n", Re[0][i] + Re[1][i]);
    IOR(i, 1, m+1) {
        int u = Qt[i].u, v = Qt[i].v, val = Qt[i].val;
        printf("%d\n", min(Re[0][u] + Re[1][v], Re[0][v] + Re[1][u]) + val);
    }

    return 0;
} /**/

void Dijkstra(int s, int pos) {
    priority_queue<pair<int, int> > Q;

    memset(Re[pos], 0x3f, (n+1)*sizeof(int)); 
    memset(Vis, 0, (n+1)*sizeof(bool));

    Re[pos][s] = 0; Q.push(make_pair(0, s));

    while(!Q.empty()) {
        int x = Q.top().second; Q.pop();
        if(Vis[x]) continue; Vis[x] = 1; 

        EOR(i, x) if(VAL(i) + Re[pos][x] < Re[pos][TO(i)]) 
            Re[pos][TO(i)] = VAL(i) + Re[pos][x], Q.push(make_pair(-Re[pos][TO(i)], TO(i)));
    }
}



