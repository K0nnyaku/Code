#include<bits/stdc++.h>

using namespace std;

#define IOR(i, st, ed) for(int i = st; i < ed; i++)
#define LOR(i, st, ed) for(int i = st; i > ed; i--)

const int MB=1<<21;
struct FastIO {
	char buf[MB+100],*p,*e;
	int getChar() { if(p==e)p=buf,e=buf+fread(buf,1,MB,stdin); return p==e?EOF:*p++; }
	template<typename T>
	FastIO& operator>>(T& x) { char c,l; for(c=0;!isdigit(c);c=getChar())l=c; for(x=0;isdigit(c);c=getChar())x=x*10-'0'+c; if(l=='-')x=-x; return *this; }
};


const int MAXN = 1e5 + 10;

unsigned long long  n,m,x,y,a,b,c,d;
unsigned long long np, mp, xp, yp, ap, bp, cp, dp, turna, turnb;
unsigned long long cur, ned, ans, p;

bool ws=0; //which small


unsigned long long Gcd(unsigned long long x, unsigned long long y) {
    return y ? Gcd(y, x%y) : x;
}

int main() {
    scanf("%lld%lld%lld%lld%lld%lld%lld%lld",&n,&m,&x,&y,&a,&b,&c,&d);
    unsigned long long lm = c * d / Gcd(c, d);
    turna = lm / c; turnb = lm / d;
    n *= turna; m *= turnb;
    a *= turna; b *= turnb;

    ned = a + b - n - m;

    ans = ned / turna * x;
    if(ned % turna) {
        unsigned long long t = ned % turna;
        ans += min(x, t / turnb * y);
    }

    unsigned long long ans2 = ned / turnb * y;
    if(ned % turnb) {
        unsigned long long t = ned % turnb;
        ans2 += min(t / turna * x, y);
    }

    ans = min(ans, ans2);

    printf("%lld", ans);

    return 0;
}