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

const int MAXN = 25 + 10;
typedef __int128 ULL;

ULL t;

ULL Qp(ULL, ULL);

int main() { /**/
#ifdef LOCAL
	freopen("In.in", "r", stdin);
	freopen("Out.out", "w", stdout);
#endif
    IN >> t;
    while(t--) {
        ULL n, s, k, v, idx = 0, ans = 0;
        IN >> n >> s >> k >> v;

        if(k != 1) {
        bool flag = 0;
        LOR(i, n, 1) {
            if(idx == v && flag) idx++;

            if(i != k) 
                s -= Qp(++idx, i),
                ans += idx;
            else 
                if(idx+1 > v) 
                    s -= Qp(++idx, i),
                    ans += idx;
                else {
                    s -= Qp(v+1, i);
                    ans += v+1;
                    flag = 1;
                }
        }

        ans += s;
        if(s <= 0) 
            printf("-2147483648\n");
        else 
            printf("%llu\n", ans);
    }

    else {
        ULL sum = 0;
        LOR(i, n, 1) 
            sum += Qp(++idx, i), 
            ans += idx;
        if(s - sum <= v) 
            printf("-2147483648\n");
        else
            printf("%llu\n", ans + s - sum);
    }
    }
    

	return 0;
} /**/

ULL Qp(ULL x, ULL e) {
    if(!e) return 1;
    int res = Qp(x, e/2);
    return e % 2 ? res * res * x : res * res;
}