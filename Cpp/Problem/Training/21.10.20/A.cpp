#include<bits/stdc++.h>
using namespace std;

#define IOR(i, st, ed) for(int i = st; i < ed; i++)
#define LOR(i, st, ed) for(int i = st; i > ed; i--)
#define EOR(i, x) for(int i = Head[x]; i; i = E[i].next)
#define T(x) E[x].to
#define V(x) E[x].val

struct FastIN
{
	template<typename T>
	FastIN& operator>>(T& x)
	{
		char c,l;
		for(c=0;!isdigit(c);c=getchar())l=c;
		for(x=0;isdigit(c);c=getchar())x=x*10-'0'+c;
		if(l=='-')x=-x;
		return *this;
	}
}IN;

unsigned long long a, b, c;

int main() { /**/
#ifdef LOCAL
	freopen("I:\\Code\\In.in", "r", stdin);
	freopen("I:\\Code\\Out.out", "w", stdout);
#else 
	freopen("A.in", "r", stdin);
	freopen("A.out", "w", stdout);
#endif

	IOR(i, 0, 5) 
		IN >> c, a += c;
	IOR(i, 0, 5) 
		IN >> c, b += c;

	if(a >= b) 
		printf("BB\n");
	else
		printf("SLS\n");

	return 0;
} /**/
















