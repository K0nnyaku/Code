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

int i = 1;

int main() { /**/
#ifdef LOCAL
    freopen("In.in", "r", stdin);
    freopen("Out.out", "w", stdout);
#endif 
    long long n, m;
    while(cin >> n >> m && n != 0) {
        long long sum = n * (n + 1) / 2;
        printf("Case %d: ", i++);
        if(sum < m) 
            printf("%d lines cannot make exactly %d crossings.\n", n, m);
        else 
            printf("%d lines with %d crossings can cut the plane into %d pieces at most.\n", n, m, sum+1);
    }

    return 0;
} /**/
