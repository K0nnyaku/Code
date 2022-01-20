#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int const _=1e5+5;
int n,m,k,sum,ans1[_],ans2[_];
struct fj
{
	int bg;
	int ed;
} a[_],b[_],p1[_],p2[_];
int read()
{
	char ch=getchar();
	int x=0,cf=1;
	while(ch<'0'||ch>'9'){if(ch=='-');cf=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
	return x*cf;
}
int cmp(fj x,fj y)
{
	return x.bg<y.bg; 
}
int main()
{
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	n=read();
	m=read();
	k=read();
	for(int i=1;i<=m;i++)
	{
		a[i].bg=read();
		a[i].ed=read();
	}
	for(int i=1;i<=k;i++)
	{
		b[i].bg=read();
		b[i].ed=read();
	}
	sort(a+1,a+m+1,cmp);
	sort(b+1,b+k+1,cmp);
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=i;j++)
		{
			p1[j].bg=a[j].bg;
			p1[j].ed=a[j].ed;
		}
		ans1[i]=i;
		for(int o=i+1;o<=m;o++)
		{
			for(int l=1;l<=i;l++)
			{
				if(a[o].bg>p1[l].ed)
				{
					ans1[i]++;
					p1[l].bg=a[o].bg;
					p1[l].ed=a[o].ed;
					break ;
				}
			}
		}
		for(int j=1;j<=i;j++)
		{
			p2[j].bg=b[j].bg;
			p2[j].ed=b[j].ed;
		}
		ans2[i]=i;
		for(int o=i+1;o<=k;o++)
		{
			for(int l=1;l<=i;l++)
			{
				if(b[o].bg>p2[l].ed)
				{
					ans2[i]++;
					p2[l].bg=b[o].bg;
					p2[l].ed=b[o].ed;
					break ;
				}
			}
		}
	}
	for(int i=0;i<=n;i++)
	{
		int u=ans1[i]+ans2[n-i];
		sum=max(u,sum);
	}
	cout<<sum<<endl;
	return 0;
}

