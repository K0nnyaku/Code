#include<bits/stdc++.h>
using namespace std;

#define IOR(i, st, ed) for(int i = st; i < ed; i++)
#define LOR(i, st, ed) for(int i = st; i > ed; i--)
#define EOR(i, x) for(int i = Head[x]; i; i = E[i].next)
#define ZERO(x) memset(x, 0, sizeof x);

const int MB=1<<21;
struct FastIO
{
	char buf[MB+100],*p,*e;
	int getChar()
	{
		if(p==e) p=buf,e=buf+fread(buf,1,MB,stdin);
		return p==e?EOF:*p++;
	}
	template<typename T>
	FastIO& operator>>(T& x)
	{
		char c,l;
		for(c=0;!isdigit(c);c=getChar())l=c;
		for(x=0;isdigit(c);c=getChar())x=x*10-'0'+c;
		if(l=='-')x=-x;
		return *this;
	}
}IO;

const int INF = 0x3f3f3f3f;
const int MAXN = 1e3 + 10;
const int MAXM = 2e3 + 10;

struct { int u, v, w; } Qt[MAXM<<2];
int E[MAXN<<2][MAXN<<2], T[MAXN<<2][MAXN<<2];
int n, m, idx;

void Turtle();
void Change(int x, int y, int val);

int main() {
#ifdef LOCAL 
    freopen("In.in", "r", stdin);
    freopen("Out.out", "w", stdout); 
#endif

    memset(E, 0x3f, sizeof E);
    IO >> n >> m;
    while(m--) {
        int u, v, w; IO >> u >> v >> w;
        E[u][v] = E[v][u] = w;
        Qt[idx++] = { u, v, w };
    } 
    IOR(i, 1, n+1) E[i][i] = 0;

    Turtle();

    IOR(i, 1, n+1) {
        printf("%d\n", E[1][i] + E[i][n]);
    }


    IOR(i, 0, idx) {
        int u = Qt[i].u, v = Qt[i].v;
        Change(u, v, INF);
        int ans1 = min(T[1][Qt[i].u] + T[Qt[i].v][n], T[1][Qt[i].v] + T[Qt[i].u][n]);
        Change(u, v, Qt[i].v);
        int ans2 = min(T[1][Qt[i].u] + T[Qt[i].v][n], T[1][Qt[i].v] + T[Qt[i].u][n]);

        if(ans1 == ans2) printf("%d\n", min(T[1][Qt[i].u] + T[Qt[i].v][n], T[1][Qt[i].v] + T[Qt[i].u][n]) + Qt[i].w);
        else printf("%d\n", min(T[1][Qt[i].u] + T[Qt[i].v][n], T[1][Qt[i].v] + T[Qt[i].u][n])); 
    }

    return 0;
}

void Turtle() {
    IOR(k, 1, n+1) IOR(i, 1, n+1) IOR(v, 1, n+1) {
        E[i][v] = min(E[i][v], E[i][k] + E[k][v]);
        E[v][i] = min(E[v][i], E[v][k] + E[k][i]);
    }
}

void Change(int x, int y, int val) {
    IOR(i, 1, n+1) IOR(v, 1, n+1) T[i][v] = E[i][v];
    T[x][y] = T[y][x] = val;
    IOR(i, 1, n+1) IOR(v, 1, n+1) {
        T[i][v] = min(T[i][v], T[i][x] + T[x][v]);
        T[v][i] = min(T[v][i], T[v][x] + T[x][i]);
    }

    IOR(i, 1, n+1) IOR(v, 1, n+1) {
        T[i][v] = min(T[i][v], T[i][y] + T[y][v]);
        T[v][i] = min(T[v][i], T[v][y] + T[y][i]);
    }
}