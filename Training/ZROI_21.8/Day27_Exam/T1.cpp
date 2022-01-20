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

vector<int> V[MAXN];
long long ans;
int n, m, tot, t;
bool Vis[MAXN];

void Wk(int x, int last) {
	if(!Vis[x]) V[tot].push_back(x);
	Vis[x] = 1;
	EOR(i, x) {
		if(T(i) == last || Vis[T(i)]) 
			continue;
		Wk(T(i), x);
	}
}

void Init() {
	memset(Vis, 0, sizeof Vis);
	memset(Head, 0, sizeof Head);
	IOR(i, 0, tot) V[i].clear();
	tot = ans = 0;
}

int In[MAXN];
bool T[MAXN][MAXN];

int main() { /**/
#ifdef LOCAL
	freopen("In.in", "r", stdin);
	freopen("Out.out", "w", stdout);
#endif
	IN >> t;
	while(t--) {
	Init();

	IN >> n >> m;
	while(m--) {
		int u, v; IN >> u >> v;
		In[v]++;
		Add(u, v);
	}

	IOR(i, 1, n+1) {
		if(!In[i]) {
			memset(Vis, 0, sizeof Vis);
			Wk(i, -1), tot++;
		}
	}

	IOR(i, 0, tot) {
		int s = V[i].size();
		ans += s * (s + 1) / 2;
		if(s != 1) ans += s;
		printf("%d\n", s);
	}

	printf("%lld", ans);
	}

	return 0;
} /**/

