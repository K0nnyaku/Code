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

deque<int> Pos[MAXN];
long long ans;
int n;

int main() { /**/
#ifdef LOCAL
	freopen("In.in", "r", stdin);
	freopen("Out.out", "w", stdout);
#endif
    IN >> n;
    IOR(i, 0, n) {
        int x; IN >> x;
        Pos[x].push_back(i+1);
    }

    IOR(i, 1, n+1) 
        while(Pos[i].size() >= 2) {
//            printf("%d %d %d\n", i, Pos[i].front(), Pos[i].back());
            ans += Pos[i].back() - Pos[i].front();
            Pos[i].pop_front(); Pos[i].pop_back();
        }

    printf("%lld", ans);

	return 0;
} /**/
