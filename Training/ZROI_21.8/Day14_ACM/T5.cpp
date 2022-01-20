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

long long  n,m,x,y,a,b,c,d;

typedef pair<long long ,long long> pllll;

pllll xx,yy; // rep -> make an diff
pllll ex,ey; // e-> end
long long da,db; // d-> diff
long long ans1,ans2,ans;

int main() {
    scanf("%lld%lld%lld%lld%lld%lld%lld%lld",&n,&m,&x,&y,&a,&b,&c,&d);
    xx=(pllll){d*y,c};
    yy=(pllll){c*x,d};
    printf("%lld %lld %lld %lld\n",xx.first,xx.second,yy.first,yy.second);
    if(d*y<x*c) ex=xx;
    else ex=(pllll){x,1};
    if(c*x<d*y) ey=yy;
    else ey=(pllll){y,1};
    da=a-n;
    db=b-m;
    ans1=(da/ex.second+((da%ex.second)?1:0))*ex.first;
    ans2=(db/ey.second+((db%ey.second)?1:0))*ey.first;
    ans=ans1+ans2;
    printf("%lld %lld %lld %lld\n",da,db,da/ex.second,db/ey.second);
    printf("%lld %lld\n%lld %lld\n%lld %lld\n",ex.first,ex.second,ey.first,ey.second,ans1,ans2);
    printf("%lld",ans);
    return 0;
}