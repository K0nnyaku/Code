#include<bits/stdc++.h>
using namespace std;

#define IOR(i, st, ed) for(int i = st; i < ed; i++)
#define LOR(i, st, ed) for(int i = st; i > ed; i--)
#define EOR(i, x) for(int i = Head[x]; i; i = E[i].next)
#define ZERO(x) memset(x, 0, sizeof x);
#define T(x) E[x].to
#define V(x) E[x].val

const int MB=1<<21;
struct FastIN
{
	char buf[MB+100],*p,*e;
	int getChar()
	{
		if(p==e) p=buf,e=buf+fread(buf,1,MB,stdin);
		return p==e?EOF:*p++;
	}
	template<typename T>
	FastIN& operator>>(T& x)
	{
		char c,l;
		for(c=0;!isdigit(c);c=getChar())l=c;
		for(x=0;isdigit(c);c=getChar())x=x*10-'0'+c;
		if(l=='-')x=-x;
		return *this;
	}
}IN;

const int MAXN = 3e3 + 10;

struct { int to, next; } E[MAXN << 1];
int Head[MAXN], idx;
void Add(int pre, int to) {
	E[++idx] = { to, Head[pre] }; Head[pre] = idx; }

long long ans;
int n, m, t;
bool Vis[MAXN];
bitset<3010> B[MAXN];

void Wk(int rt, int x, int last) {
	Vis[x] = 1;
	EOR(i, x) {
		if(T(i) == last || Vis[T(i)]) 
			continue;
        B[T(i)][rt] = 1;       
		Wk(rt, T(i), x);
	}
}

void Init() {
	memset(Vis, 0, sizeof Vis);
	memset(Head, 0, sizeof Head);
    IOR(i, 0, n+10) IOR(v, 0, 3010) 
        B[i][v] = 0;
    IOR(i, 0, n+10) 
        B[i][i] = 1;
	ans = 0;
}

int main() { /**/
#ifdef LOCAL
	freopen("In.in", "r", stdin);
	freopen("Out.out", "w", stdout);
#endif
	IN >> t;
	while(t--) {

	    IN >> n >> m;
	    Init();
	    while(m--) {
		    int u, v; IN >> u >> v;
		    Add(u, v);
	    }

	    IOR(i, 1, n+1) {
            memset(Vis, 0, sizeof Vis);
		    Wk(i, i, -1);
	    }

        IOR(i, 1, n+1) IOR(v, 1, n+1) 
            ans += ((B[i] & B[v]) != 0);
        
	    printf("%lld\n", ans);
	}

	return 0;
} /**/
