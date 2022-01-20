#include<bits/stdc++.h>
using namespace std;

#define IOR(i, st, ed) for(int i = st; i < ed; i++)
#define LOR(i, st, ed) for(int i = st; i > ed; i--)
#define EOR(i, x) for(int i = Head[x]; i; i = E[i].next)
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

int T;

int main() { /**/
#ifdef LOCAL
	freopen("In.in", "r", stdin);
//	freopen("Out.out", "w", stdout);
#endif
	
	IN >> T;
	while(T--) {
		int n; IN >> n;
		int res, tem;

		IN >> res; n--;
		while(n--)
			IN >> tem, res ^= tem;
		
		res ? cout << "Yes\n" : cout << "No\n";
	}

	return 0;
} /**/











