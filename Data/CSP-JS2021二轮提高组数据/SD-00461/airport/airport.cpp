#include<bits/stdc++.h>
using namespace std;
namespace _mzf
{
	#define ll long long
	const int N=1e5+100;
	ll n,m1,m2,nans,ians,ans,h,t;
	struct node
	{
		int l,r;
	}na[N],in[N];
	priority_queue<int> q;
	ll read()
	{
		ll flag=1,sum=0;
		char ch=getchar();
		while(ch<'0'||ch>'9')
		{
			if(ch=='-') flag=-1;
			ch=getchar();
		}
		while(ch>='0'&&ch<='9')
		{
			sum=sum*10+ch-'0';
			ch=getchar();
		}
		return flag*sum;
	}
	bool cmp(node a,node b)
	{
		return a.l<b.l;
	}
	void gn(int x)
	{
		int  lq=x;
		if(!x) return;
		while(!q.empty()) q.pop();
		for(int i=1;i<=m1;i++)
		{
			if(lq)
			{
				q.push(-na[i].r);
				lq--;
				nans++;
			}
			else
			{
				int y=-q.top();
				if(na[i].l>y&&y)
				{
					q.pop();
					q.push(-na[i].r);
					nans++;
				}
				else continue;
			}
		}
	}
	void gj(int x)
	{
		int  lq=x;
		while(!q.empty()) q.pop();
		if(!x) return;
		for(int i=1;i<=m2;i++)
		{
			if(lq)
			{
				q.push(-in[i].r);
				lq--;
				ians++;
			}
			else
			{
				int y=-q.top();
				if(in[i].l>y&&y)
				{
					q.pop();
					q.push(-in[i].r);
					ians++;
				}
			}
		}
	}
	void work1()
	{
		for(int i=0;i<=n;i++)
		{
			ians=0;
			nans=0;
			gn(i);
			gj(n-i);
			//cout<<nans<<"???"<<ians<<endl;
			ans=max(ans,ians+nans);
		}
		cout<<ans<<endl;
	}
	void mzfmain()
	{
		n=read();
		m1=read();
		m2=read();
		for(int i=1;i<=m1;i++)
		{
			na[i].l=read();
			na[i].r=read();
		}
		sort(na+1,na+1+m1,cmp);
		for(int i=1;i<=m2;i++)
		{
			in[i].l=read();
			in[i].r=read();
		}
		sort(in+1,in+1+m2,cmp); 
		work1();
	}
}
int main()
{
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	_mzf::mzfmain(); 
	return 0;
}
