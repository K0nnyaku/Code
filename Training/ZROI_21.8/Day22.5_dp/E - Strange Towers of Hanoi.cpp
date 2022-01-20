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

const int MAX = 65;
unsigned long long F[MAX], S[MAX];

int main() { /**/
#ifdef LOCAL
	freopen("Out.out", "w", stdout);
#endif

	memset(S, 0x7f, sizeof S);
	
	F[1] = 1, F[2] = 3;
	IOR(i, 1, 65) 
		F[i] = pow(2, i) - 1;

	S[1] = 1, S[2] = 3;
	
	IOR(i, 3, 65)
		IOR(v, 1, i)
			S[i] = min(S[i], S[v] * 2 + F[i-v]);

	IOR(i, 1, 13) 
		printf("%llu\n", S[i]);

	return 0;
} /**/