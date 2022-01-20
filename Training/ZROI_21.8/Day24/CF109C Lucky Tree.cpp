#include<bits/stdc++.h>
using namespace std;

#define IOR(i, st, ed) for(int i = st; i < ed; i++)
#define LOR(i, st, ed) for(int i = st; i > ed; i--)
#define EOR(i, x) for(int i = Head[x]; i; i = E[i].next)
#define T(x) E[x].to
#define V(x) E[x].val

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
}IN;

const int MAXN = 5e5 + 10;

struct { int to, next, val; } E[MAXN << 1];
int Head[MAXN], idx = 0;
void Add(int pre, int _to, int _val) {
    E[++idx] = { _to, Head[pre], _val }; Head[pre] = idx; }

long long Fin[MAXN], Size[MAXN], Fout[MAXN];
long long ans;
int n;

bool Check(int x);
void Pre(int x, int last);
void Wk(int x, int last);

int main() { /**/
#ifdef LOCAL
	freopen("In.in", "r", stdin);
	freopen("Out.out", "w", stdout);
#endif

    IN >> n; n--;
    while(n--) {
        int u, v, w; IN >> u >> v >> w;
        Add(u, v, w); Add(v, u, w);
    }

	Pre(1, -1);
	Wk(1, -1);

	printf("%lld\n", ans);

	return 0;
} /**/

void Pre(int x, int last) {
	Size[x] = 1; 

	EOR(i, x) {
		if(T(i) == last) continue;

		Pre(T(i), x); 

		if(Check(V(i)))
			Fin[x] += Size[T(i)];
		else 
			Fin[x] += Fin[T(i)];

		Size[x] += Size[T(i)];
	} 
}

void Wk(int x, int last) {
	EOR(i, x) {
		if(T(i) == last) continue;

		if(Check(V(i)))
			Fout[T(i)] = Size[1] - Size[T(i)];
		else 
			Fout[T(i)] = Fout[x] + Fin[x] - Fin[T(i)];

		Wk(T(i), x);
	}

	ans += Fout[x] * (Fout[x] - 1)
		+ Fin[x] * (Fin[x] - 1) + 2 * Fin[x] * Fout[x];
}

bool Check(int x) {
	do 
		if(x % 10 != 4 && x % 10 != 7) return false;
	while(x /= 10);

	return true;
}