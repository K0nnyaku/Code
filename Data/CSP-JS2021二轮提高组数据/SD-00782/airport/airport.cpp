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
	const ll N=1e5+2;
	ll n,m1,m2,time;
	ll ans;
	struct node
	{
		ll arrive,leave;
	};
	node one[N],two[N];
	ll vis_one[N],vis_two[N];
	int cmp(node x,node y)
	{
		return x.arrive<y.arrive;
	}
	void search(ll onee,ll twoo,ll head_one,ll head_two,ll now,ll sum)
	{
		ans=max(ans,sum);
		if(now>=time)return;
		for(ll i=1;i<head_one;++i)
		if(vis_one[i]&&one[i].leave<=now)
		{
			vis_one[i]=0;onee++;
		}
		for(ll i=1;i<head_two;++i)
		if(vis_two[i]&&two[i].leave<=now)
		{
			vis_two[i]=0;twoo++;
		}
		while(one[head_one].arrive<=now&&head_one<=m1)
		{
			if(onee>0)
			{
				vis_one[head_one]=1;onee--;sum++;
			}
			head_one++;
		}
		while(two[head_two].arrive<=now&&head_two<=m2)
		{
			if(twoo>0)
			{
				vis_two[head_two]=1;twoo--;sum++;
			}
			head_two++;
		}
		search(onee,twoo,head_one,head_two,now+1,sum);
	}
	void work1()
	{
		sort(one+1,one+1+m1,cmp);
		sort(two+1,two+1+m2,cmp);
		for(ll i=0;i<=n;++i)
		search(i,n-i,1,1,0,0);
		cout<<ans;
	}
	void My_main()
	{
		n=read();m1=read();m2=read();
		for(ll i=1;i<=m1;++i)
		{
			one[i].arrive=read();one[i].leave=read();time=max(time,one[i].leave);
		}
		for(ll i=1;i<=m2;++i)
		{
			two[i].arrive=read();two[i].leave=read();time=max(time,two[i].leave);
		}
		work1(); 
	}
}
int main()
{
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	_xzy::My_main();
	return 0;
}
