#include<bits/stdc++.h>
using namespace std;
namespace _wf
{
	typedef long long ll;
	const ll N=100005;
	ll n,m1,m2,cnt1,cnt2;
	ll v[N],ans;
	ll track1[N],track2[N];//分配每条跑道停多少 
	ll sum1[N],sum2[N];
	inline void read(ll &x)
	{
		x=0;ll f=1;
		char ch=getchar();
		while(!isdigit(ch))
		{
			if(ch=='-') f=-1;
			ch=getchar();
		}
		while(isdigit(ch))
		{
			x=(x<<1)+(x<<3)+(ch^48);
			ch=getchar();
		}
		x=x*f;
	}
	struct node
	{
		ll time;
		bool in;
		ll pos;
	}e1[N];
	struct edge
	{
		ll time;
		bool in;
		ll pos;
	}e2[N];
	bool cmp1(node a,node b)
	{
		return a.time<b.time;
	}
	bool cmp2(edge a,edge b)
	{
		return a.time<b.time;
	}
	priority_queue<ll>q;
	void mymain()
	{ 
		read(n),read(m1),read(m2);
		for(ll i=1,a,b;i<=m1;i++) 
		{
			read(a),read(b),e1[++cnt1]=(node){a,1,i},e1[++cnt1]=(node){b,0,i};
		}
		sort(e1+1,e1+1+cnt1,cmp1);
		memset(v,0,sizeof(0));
		for(ll i=1;i<=m1+5;i++) q.push(i*-1);
		for(ll i=1;i<=cnt1;i++)
		{
			if(e1[i].in)
			{
				v[e1[i].pos]=(q.top())*-1;
				track1[v[e1[i].pos]]++;
				q.pop();
			}
			else
			{
				q.push((v[e1[i].pos])*-1);
			}
		}
		for(ll i=1;i<=n;i++) sum1[i]=sum1[i-1]+track1[i];
		
		
		for(ll i=1,a,b;i<=m2;i++) 
		{
			read(a),read(b),e2[++cnt2]=(edge){a,1,i},e2[++cnt2]=(edge){b,0,i};
		}
		sort(e2+1,e2+1+cnt2,cmp2);
		while(!q.empty()) q.pop();
		memset(v,0,sizeof(v));
		for(ll i=1;i<=m2+5;i++) q.push(i*-1);
		for(ll i=1;i<=cnt2;i++)
		{
			if(e2[i].in)
			{
				v[e2[i].pos]=(q.top())*-1;
				track2[v[e2[i].pos]]++;
				q.pop();
			}
			else
			{
				q.push((v[e2[i].pos])*-1);
			}
		}
		for(ll i=1;i<=n;i++) sum2[i]=sum2[i-1]+track2[i];
		for(ll i=0;i<=n;i++)
		ans=max(sum1[i]+sum2[n-i],ans);
		cout<<ans;
	} 
}
int main()
{
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	_wf::mymain();
	return 0;
}

