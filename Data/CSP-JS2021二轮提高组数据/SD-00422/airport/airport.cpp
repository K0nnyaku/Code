#include<bits/stdc++.h>
#define int long long
using namespace std;
struct aaa
{
	int r,l,flag=0;
}air[100050];
struct aa
{
	int r,l,flag=0;
}ai[100050];
int cmp(int a,int b)
{
	return a<b;
}
int cmp1(aaa a,aaa b)
{
	return a.l<b.l;
}
int cmp2(aa a,aa b)
{
	return a.l<b.l;
}
int n,m1,m2,num=0;
inline int read()
{
	char ch=getchar(),fl=1;
	while(ch>'9'||ch<'0')
	{
		if(ch=='-')
		{
			fl=-1;
		}
		ch=getchar();
	}
	int p=0;
	while(ch>='0'&&ch<='9')
	{
		p=(p<<1)+(p<<3)+(ch^48);
		ch=getchar();
	}
	return fl*p;
}
signed main()
{
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	n=read(),m1=read(),m2=read();
	for(int i=1;i<=m1;i++)
	{
		air[i].l=read(),air[i].r=read();
	}
	for(int i=1;i<=m2;i++)
	{
		ai[i].l=read(),ai[i].r=read();
	}
	sort(air+1,air+1+m1,cmp1);
	sort(ai+1,ai+1+m2,cmp2);
	int t=n;
	for(t=n;t>=0;t--)
	{
		int a=t,b=n-t;
		int w=1,ans=0;
		for(int i=1;i<=m1;i++)
		{
			air[i].flag=0;
		}
		for(int i=1;i<=m2;i++)
		{
			ai[i].flag=0;
		}
		for(int i=1;i<=m1;i++)
		{
			int e=10000000;
			e=min(e,air[w].r);
			if(i!=1&&air[i].l>=e)
			{
				if(air[w].flag==1&&a+1<=t)
				{
					a++;
				}
				w++;
				e=10000000;
				for(int j=w;j<=i;j++)
				{
					e=min(e,air[j].r);
				}
			}
			if(a>=1)
			{
				a--;
				ans++;
				air[i].flag=1;
			}
		}
		w=1;
		for(int i=1;i<=m2;i++)
		{
			int e=10000000;
			e=min(e,ai[w].r);
			if(i!=1&&ai[i].l>=e)
			{
				if(ai[w].flag==1&&b+1<=n-t)
				{
					b++;
				}
				w++;
				e=10000000;
				for(int j=w;j<=i;j++)
				{
					e=min(e,ai[j].r);
				}
			}
			if(b>=1)
			{
				b--;
				ans++;
				ai[i].flag=1;
			}
		}
		num=max(ans,num);
	}
	cout<<num;
	return 0;
}

