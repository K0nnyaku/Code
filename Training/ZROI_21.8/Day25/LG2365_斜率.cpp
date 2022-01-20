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

int Qc[MAXN], Qt[MAXN], F[MAXN], Deq[MAXN << 1];
int n, s, l, r;

int main() { /**/
#ifdef LOCAL
	freopen("In.in", "r", stdin);
//	freopen("Out.out", "w", stdout);
#endif
    IN >> n >> s;
    IOR(i, 1, n+1) {
        int x, y; IN >> x >> y;
        Qt[i] = Qt[i-1] + x;
        Qc[i] = Qc[i-1] + y;
    }

    memset(F, 0x3f, sizeof F);
    F[0] = 0; Deq[1] = 0;
    l = r = 1;
    IOR(i, 1, n+1) {
        while(l < r && s + Qt[i] >= (F[Deq[l+1]] - F[Deq[l]]) / 
                (Qc[Deq[l+1]] - Qc[Deq[l]])) l++, printf("%d %d\n", i, l);
        F[i] = F[Deq[l]] - (s + Qt[i]) * Qc[Deq[l]] 
                + Qt[i] * Qc[i] + s * Qc[n];
        while(l < r && (F[Deq[r]] - F[Deq[r-1]]) / (Qc[Deq[r]] - Qc[r-1]) 
                >= (F[i] - F[Deq[r]]) / (Qc[i] - Qc[Deq[r]])) r--;
        Deq[++r] = i;
    }
    printf("%d", F[n]);

	return 0;
} /**/