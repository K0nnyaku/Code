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

const int MAXN = 6e3 + 10;

struct Edge { 
    int u, v, val; 
    
    friend bool operator<(Edge x, Edge y) {
        return x.val < y.val; }
    
} E[MAXN*MAXN];


int Fa[MAXN], Size[MAXN];
int t, n, ans, m;

void Init();
void Union(int x, int y);
int Find(int x);

int main() { /**/
#ifdef LOCAL
	freopen("In.in", "r", stdin);
	freopen("Out.out", "w", stdout);
#endif

    IN >> t;
    while(t--) {
        Init();
        IN >> n; m = n - 1;

        IOR(i, 0, m) {
            int u, v, val; 
            IN >> u >> v >> val;
            E[i] = { u, v, val };
        }
        sort(E, E+m);

        IOR(i, 0, m) {
            int x = Find(E[i].u), y = Find(E[i].v);
            if(Find(x) == Find(y)) continue;
            ans += (E[i].val + 1) * (Size[x] * Size[y] - 1);
            Union(x, y);
        }
        cout << ans << "\n";
    }

	return 0;
} /**/

void Init() {
    IOR(i, 1, MAXN) 
        Fa[i] = i, Size[i] = 1;
    ans = 0;
}

void Union(int x, int y) {
    int xFa = Find(x), yFa = Find(y);
    Size[xFa] += Size[yFa]; Fa[yFa] = xFa;
}

int Find(int x) {
    return Fa[x] = (Fa[x] == x) ? x : Find(Fa[x]);
}