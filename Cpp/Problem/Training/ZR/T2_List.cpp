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
//

const int MAXN = 1e6 + 10;

long long ans;
int A[MAXN], Lf[MAXN], Tr[MAXN<<2];
int n, m;
bool Vis[MAXN<<2];

bool Check();
bool Wk(int now);
void Solve(int x);

int main() { /**/
#ifdef LOCAL
	freopen("In.in", "r", stdin);
//	freopen("Out.out", "w", stdout);
#endif
    IOR(i, 1, 10) {
        printf("i = %d, ans = ", i);
        Solve(i);
    }

	return 0;
} /**/

bool Check() {
    memset(Vis, 0, sizeof Vis);
    if(!Wk(1)) return false;

    return true;
}

bool Wk(int now) {
    if(!Tr[now*2] && !Tr[now*2+1]) {
        Vis[Tr[now]] = 1; 
        return true;
    }
    if(Tr[now*2] > Tr[now] || Tr[now*2+1] > Tr[now]) return false;
    return Wk(now*2) && Wk(now*2+1);
}

void Solve(int x) {
    int ans = 0;
    IOR(i, 1, x+1) Tr[i] = i;

    do {
        ans += Check();
/*
        printf("\n---------------\n");
        IOR(i, 1, n+1) printf("i = %d, Tr = %d\n", i, Tr[i]);
        printf("---------------\n");
*/
    }while(next_permutation(Tr+1, Tr+x+1));

    printf("%lld\n", ans);
}