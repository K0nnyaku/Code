#include<bits/stdc++.h>
using namespace std;

#define IOR(i, st, ed) for(int i = st; i < ed; i++)
#define LOR(i, st, ed) for(int i = st; i > ed; i--)
#define EOR(i, x) for(int i = Head[x]; i; i = E[i].next)
#define V(x) E[x].val
#define T(x) E[x].to


const int MB = 1 << 21;
struct FastIO {
    char Buf[MB+10], *p, *e;
    int GetChar() {
        if(p == e) p = Buf, e = Buf + fread(Buf,  1, MB, stdin);
        return p == e ? EOF : *p++;
    }
    template<typename T>
    FastIO& operator>>(T& x) {
        char c, l;
        for(c = 0; !isdigit(c); c = GetChar()) l = c;
        for(x = 0; isdigit(c); c = GetChar()) x = x * 10 - '0' + c;
        if(l == '-') x = -x;
        return *this;
    }
}IO;

const int MAXN = 1e5 + 10;
const int INF = 0x3f3f3f3f;

struct { int to, next, val; } E[MAXN << 2];
int Head[MAXN], idx = 1;
void Add(int pre, int _to, int _val) {
    E[++idx] = { _to, Head[pre], _val }; Head[pre] = idx; }

int I[MAXN];
int sc, mt;
int Dinic();
int Work(int x, int in);
void Pre();
void In(int pos);

int main() { /**/
#define LOCAL
    freopen("In.in", "r", stdin);
    freopen("Out.out", "w", stdout);
#endif

    int n, m; scanf("%d%d", &n, &m);
    sc = n + m; mt = sc+1;
    IOR(i, 0, m) {
        int cost = 0; scanf("%d", &cost);
        Add(sc, i, cost);
        In(i);
    }

    IOR(i, 0, n) {
        int cost; scanf("%d", &cost);
        Add(i, mt, cost); 
    }

    Dinic(sc, mt);
    
    

    return 0;
} /**/

void Add(int pre, int to, int val) {
    Ver[++idx] = to; Eg[idx] = val;
    Next[idx] = Head[pre]; Head[pre] = idx;
}

void In(int pos) {
    char tools[10000];
    memset(tools,0,sizeof tools);
    cin.getline(tools,10000);
    int ulen=0,tool;

    while (sscanf(tools+ulen,"%d",&tool)==1)//之前已经用scanf读完了赞助商同意支付该实验的费用
    {//tool是该实验所需仪器的其中一个      
         //这一行，你可以将读进来的编号进行储存、处理，如连边。
        Add(pos, tool, INF);

        if (tool==0)  ulen++;
        else  while (tool) { tool/=10; ulen++; }
        ulen++;
    } 
}

int Dinic() {
    long long ans = 0;
    while(Pre()) 
        ans += Work(sc, INF);
    return ans;
}

void Pre() {
    memset(Pos, 0, (n+1) * sizeof(int));
    queue<int> Q;
    Q.push(sc); Pos[sc] = 1; I[sc] = Head[sc];
    while(!Q.empty()) {
        int x = Q.front(); Q.pop();
        EOR(i, x) if(V(i) && !Pos[T(i)]) {
            Q.push(T(i)); Pos[T(i)] = Pos[x] + 1;
            I[T(i)] = Head[T(i)];
            if(T(i) == mt) return 1;
        }
    }
}

int Work(int x, int in) {
    if(x == mt) return in;
    int out = 0;
    for(int& i = I[x]; i; i = E[i].next) 
        if(V(i) && Pos[T(i)] = Pos[x] + 1) {
            int k = Work(T(i), min(in, V(i))); 
            V(i) -= k, V(i ^ 1) += k;
            in -= k; out += k;
            if(!in) break;
        }
    return out;
}
