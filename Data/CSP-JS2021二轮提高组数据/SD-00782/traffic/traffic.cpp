#include<bits/stdc++.h>
using namespace std;
namespace _xzy
{
	typedef long long ll;
	inline int read()
	{
		ll sm=0,flag=1;
		char ch=getchar();
		while(ch<'0'||ch>'9'){if(ch=='-')flag=-1;ch=getchar();}
		while(ch>='0'&&ch<='9'){sm=(sm<<1)+(sm<<3)+(ch^48);ch=getchar();}
		return sm*flag;
	}
	ll n,m,t,ans=1e9,maxn;
	ll g[502][502][5];//1об 2ио 3вС 4ср 
	ll jiantu[1<<27];
	ll num[55],color[55],dis[55];
	void js(ll situation)
	{
		maxn=max(maxn,situation);
		for(ll i=1;i<=n;++i)
		for(ll j=1;j<=m;++j)
		{
			ll now=(i-1)*m+j;now=n*m-now;now=(1<<now)&situation;
			if(i<n)
			{
				ll xia=i*m+j;xia=n*m-xia;xia=(1<<xia)&situation;
				if((now==0&&xia)||(now&&xia==0))jiantu[situation]+=g[i][j][1];
			}
			if(j<m)
			{
				ll you=(i-1)*m+j+1;you=n*m-you;
				you=(1<<you)&situation;
				if((now==0&&you)||(now&&you==0))jiantu[situation]+=g[i][j][4];
			}
		}
	}
	void ask(ll step,ll situation)
	{
		if(step>n*m)js(situation);
		if(step>n*m)return;
		ask(step+1,situation<<1);ask(step+1,(situation<<1)|1);
	}
	void My_main()
	{
		n=read();m=read();t=read();
		for(ll i=1;i<n;++i)
		for(ll j=1;j<=m;++j)
		{
			ll x=read();
			g[i][j][1]=x;g[i+1][j][2]=x;
		}
		for(ll i=1;i<=n;++i)
		for(ll j=1;j<m;++j)
		{
			ll x=read();
			g[i][j][4]=x;g[i][j+1][3]=x;
		}
		if(n*m<=25)
		{
			ask(1,0);
			while(t--)
			{
				ll k=read();
				for(ll i=1;i<=k;++i)
				{
					ll x=read(),y=read(),z=read();
					dis[i]=x;num[i]=y;color[i]=z;
				}
				for(ll situation=1;situation<=maxn;++situation)
				{
					ll sum=0;
					for(ll i=1;i<=k;++i)
					{
						ll to;
						if(num[i]>=1&&num[i]<=m)
						{
							to=num[i];to=n*m-to;to=1<<to;
						}
						else if(num[i]>=m+1&&num[i]<=m+n)
						{
							to=(num[i]-m-1)*m+m;to=n*m-to;to=1<<to;
						}
						else if(num[i]>=m+n+1&&num[i]<=2*m+n)
						{
							to=(n-1*m)+m-(num[i]-n-m)+1;to=n*m-to;to=1<<to;
						}
						else if(num[i]>=2*m+n+1&&num[i]<=2*(m+n))
						{
							to=(n-(num[i]-n-2*m))*m+1;to=n*m-to;to=1<<to;
						}
						to=situation&to;
						if(to&&color[i]==0)sum+=dis[i];
						if(to==0&&color[i])sum+=dis[i];
					}
					ans=min(ans,sum+jiantu[situation]);
				}
				cout<<ans;
			}
		}
		
	}
}
int main()
{
	freopen("traffic.in","r",stdin);
	freopen("traffic.out","w",stdout);
	_xzy::My_main();
	return 0;
}
