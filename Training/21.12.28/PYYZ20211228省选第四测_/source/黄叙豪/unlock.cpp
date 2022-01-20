#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=1437;
ll t,n,k,a[N],suf[N],lenlen;
ll fac[N];
vector<ll>siz;
bool vis[N];
void rfs(ll st)
{
	ll cnt=1,End=st,Now=a[st];
	while(Now!=End) cnt++,vis[Now]=1,Now=a[Now];
	siz.push_back(cnt);
}
ll ans,per;
ll C(ll n,ll m)
{
	return fac[n]/(fac[m]*fac[n-m]);
}
void dfs(ll layer,ll ball,ll cou,bool isall)
{
//	printf("%lld %lld %lld %d %lld %lld\n",layer,ball,cou,isall,ans,per);
	if(ball>k) return void();
	if(ball+suf[layer]<k) return void();
	if(layer>lenlen)
	{
		if(ball==k)
		{
			if(isall) ans+=cou;
			per+=cou;
		}
		return ;
	}
	for(ll i=0;i<=siz[layer];i++)
	{
		if(isall==0 || i==0) dfs(layer+1,ball+i,cou*C(siz[layer],i),0);
		else dfs(layer+1,ball+i,cou*C(siz[layer],i),1);
	}
}
int main()
{
	clock_t c1=clock();
	freopen("unlock.in","r",stdin);
	freopen("unlock.out","w",stdout);

	//================================
	scanf("%lld",&t);
	fac[0]=1;
	for(ll i=1;i<=100;i++) fac[i]=fac[i-1]*i;
	while(t--)
	{
		per=ans=0;
		siz.clear();memset(vis,0,sizeof(vis));
		scanf("%lld%lld",&n,&k);
		for(ll i=1;i<=n;i++) scanf("%lld",&a[i]);
		for(ll i=1;i<=n;i++) if(!vis[i]) vis[i]=1,rfs(i);
		lenlen=siz.size()-1;
//		printf("=====");for(auto i:siz) printf("%lld ",i);puts("");
		for(int i=lenlen;i>=0;i--) suf[i]=suf[i+1]+siz[i];
//		for(int i=0;i<=lenlen;i++) printf("%lld ",suf[i]);
		dfs(0,0,1,1);
		printf("%.9Lf\n",(long double)1.0*ans/per);
	}
	//================================
	cerr<<endl<<"Time:"<<clock()-c1<<"(ms)";
    return 0;
}
/*
1
20 9
2 3 4 5 1 7 8 9 6 11 12 13 10 15 16 17 18 19 14 20
*/
