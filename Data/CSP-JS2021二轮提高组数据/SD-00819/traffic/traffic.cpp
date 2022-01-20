#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<queue>
using namespace std;

namespace _yz
{
	typedef long long ll;
	const ll N=1000000+10;
	struct edge{ll nxt,to,len;}e[N];
	ll n,m,k,head[N],cnt=0,nume,numh=0;
	ll Len[N],Pos[N],Col[N],vis[N],ans=0;
	queue<ll>q;
	
	void add(ll a,ll b,ll len)
	{
		e[++cnt]=(edge){head[a],b,len};
		head[a]=cnt;
	}
	ll getp(ll x,ll y)
	{
		return (x-1)*m+y;
	}
	void getans()
	{
		ll jud=0;
		//printf("\n");
		for(ll i=1;i<=numh;i++)
		{
			for(ll j=head[i];j;j=e[j].nxt)
			{
				ll to=e[j].to;
				if(vis[to]==vis[i]) continue;
				//printf("<%lld,%lld> = %lld\n",to,i,e[j].len);
				jud+=e[j].len;
			}
		}
		//printf("%lld\n",jud);
		if(jud==0) return;
		ans=min(ans,jud/2);
	}
	void bfs(ll st)
	{
		ll go;
		if(st>=1&&st<=m)
		{
			go=getp(1,st);
		}
		else if(st>m&&st<=m+n)
		{
			go=getp(st-m,m);
		}
		else if(st>m+n&&st<=2*m+n)
		{
			go=getp(n,m-(st-m-n)+1);
		}
		else
		{
			go=getp(n-(st-m-m-n)+1,1);
		}
		
		/*for(ll i=head[go];i;i=e[i].nxt)
		{
			jud+=e[i].len;
		}
		ans=min(ans,jud);*/
		q.push(go);
		while(!q.empty())
		{
			ll now=q.front();
			q.pop();
			vis[now]=1;
			getans();
			for(ll i=head[now];i;i=e[i].nxt)
			{
				ll to=e[i].to;
				if(vis[to]) continue;
				q.push(to);
			}
		}
	}
	void main()
	{
		ll T,tmp;
		scanf("%lld%lld%lld",&n,&m,&T);
		for(ll i=1;i<=n-1;i++)
		{
			for(ll j=1;j<=m;j++)
			{
				scanf("%lld",&tmp);
				add(getp(i,j),getp(i+1,j),tmp);
				add(getp(i+1,j),getp(i,j),tmp);
				numh=max(numh,max(getp(i,j),getp(i+1,j)));
				//printf("<%lld,%lld> = %lld\n",getp(i,j),getp(i+1,j),tmp);
			}
		}
		for(ll i=1;i<=n;i++)
		{
			for(ll j=1;j<=m-1;j++)
			{
				scanf("%lld",&tmp);
				add(getp(i,j),getp(i,j+1),tmp);
				add(getp(i,j+1),getp(i,j),tmp);
				numh=max(numh,max(getp(i,j),getp(i,j+1)));
				//printf("<%lld,%lld> = %lld\n",getp(i,j),getp(i,j+1),tmp);
			}
		}
		//nume=cnt;
		while(T--)
		{
			scanf("%lld",&k);
			memset(vis,0,sizeof(vis));
			for(ll i=1;i<=k;i++)
			{
				scanf("%lld%lld%lld",Len+i,Pos+i,Col+i);
			}
			if(k==1)
			{
				printf("0\n");
			}
			else if(k==2&&Col[1]==Col[2])
			{
				printf("0\n");
			}
			else if(k==2&&Col[1]!=Col[2])
			{
				ans=min(Len[1],Len[2]);
				bfs(Pos[1]);
				printf("%lld\n",ans);
			}
			else {	}
		}
		return;
	}
}
int main()
{
	freopen("traffic.in","r",stdin);
	freopen("traffic.out","w",stdout);
	_yz::main();
	return 0;
}
/*
2 3 1
9 4 7
3 8
10 5
2
19 3 1
17 9 0

12
-------
3 2 1
9 9
9 1
9
9
1
2
90 2 1
60 6 0


*/
