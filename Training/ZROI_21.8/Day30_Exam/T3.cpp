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

const int MAXN = 1e5 + 10;
const int MAXM = 2e5 + 10;

struct { int to, next; } E[MAXM << 2];
int Head[MAXN << 2], idx;
void Add(int pre, int _to) {
	E[++idx] = { _to, Head[pre] }; Head[pre] = idx; }

struct Node { 
	int pos, dep; 
	friend bool operator<(Node x, Node y) { return x.dep < y.dep; }
} Dep[MAXN << 2];

int In[MAXN << 2], Rt[MAXN << 2];
int n, m, cnt, ans;
bool Vis[MAXN << 2];

void Tp(int x);
void Wk(int now, int step);
void Depth(int x, int last);

int main() { /**/
#ifdef LOCAL
	freopen("In.in", "r", stdin);
	freopen("Out.out", "w", stdout);
#endif
	IN >> n >> m;
	IOR(i, 0, m) {
		int u, v; IN >> u >> v;
		In[v]++; Add(u, v);
	}

	if(m) {


	IOR(i, 1, n+1) 
		if(In[i] == 0) Tp(i);

	IOR(i, 1, n+1) 
		Dep[i].pos = i;

	IOR(i, 0, cnt) 
		Add(0, Rt[i]);

	Depth(0, -1);

	IOR(i, 1, n+1) {
		IOR(v, 1, n+1) {
			if(v == i) continue;
			if(Dep[i].dep == Dep[v].dep) 
				Add(Dep[i].pos + MAXN, Dep[v].pos + MAXN);
		}
	}

	memset(Vis, 0, sizeof Vis);

	Wk(0, min(n, 3));

	printf("%d\n", ans);

	}
	else {
		long long u = 1, v = 1;
		IOR(i, 1, n+1)
			u *= i;
		IOR(i, 1, n-3 + 1)
			v *= i;
		printf("%lld", u / v);
	}

	return 0;
} /**/

int Ni[MAXN << 2];
void Tp(int x) {
	queue<int> Q; Q.push(x);
	Rt[cnt++] = x + MAXN;
	IOR(i, 1, n+1) 
		Ni[i] = In[i];

	while(!Q.empty()) {
		int t = Q.front(); Q.pop();
		Vis[t] = 1;
		EOR(i, t) {
			Ni[T(i)]--;
			if(!Ni[T(i)]) {
				Q.push(T(i));
				Add(t + MAXN, T(i) + MAXN);
			} 
		}
	}
}

void Wk(int now, int step) {
	if(step == 0) { ans++; return; }

	EOR(i, now) {
		if(Vis[T(i)]) continue;

		Vis[T(i)] = 1;

		Wk(T(i), step-1);

		Vis[T(i)] = 0;
	} 
}

void Depth(int x, int last) {
	EOR(i, x) {
		if(T(i) == last) continue;
		Dep[T(i) - MAXN].dep = Dep[x != 0 ? x - MAXN : 0].dep + 1;
		Depth(T(i), x);
	}
}