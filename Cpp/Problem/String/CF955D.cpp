#include<bits/stdc++.h>
using namespace std;

#define IOR(i, st, ed) for(int i = st; i < ed; i++)
#define LOR(i, st, ed) for(int i = st; i > ed; i--)
#define EOR(i, x) for(int i = Head[x]; i; i = E[i].next)
#define ZERO(x) memset(x, 0, sizeof x);
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

const int MAXN = 5e5 + 10;
const int P = 131;

unsigned long long HS[MAXN];
unsigned long long ht;
long long E[MAXN] = {1};
int k, slen, tlen;
char S[MAXN], T[MAXN];

int main() { /**/
#ifdef LOCAL
	freopen("In.in", "r", stdin);
	freopen("Out.out", "w", stdout);
#endif
    IN >> slen >> tlen >> k;
    scanf("%s%s", S, T);

    IOR(i, 1, len) E[i] = E[i-1] * P;

    IOR(i, 0, slen) 
        HS[i] += HS[i-1] + (unsigned long long)(S[i] - 'a') * E[i];
    
    IOR(i, 0, tlen) ht += (T[i] - 'a') * E[i];

    for(int p = 0, q = p + k - 1; q + k < slen; p += k, q += k) {
        if(HS[])
    }



	return 0;
} /**/