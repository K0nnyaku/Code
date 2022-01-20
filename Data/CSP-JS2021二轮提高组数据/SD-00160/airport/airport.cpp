#include<bits/stdc++.h>
using namespace std;
const int N=1e5+7;
inline int read()
{
	int sum=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9')
	{
		if(c=='-')f=-1;
		c=getchar(); 
	}
	while(c>='0'&&c<='9')
	{
		sum=(sum<<1)+(sum<<3)+(c^48);
		c=getchar();
	}
	return sum*f;
}
struct node
{
	int comin;
	int goout;
}a[N],b[N];
bool cmp(node a,node b)
{
	return a.comin<b.comin;
}
int n,m1,m2,color,ans1[N],ans2[N],H1[N],H2[N],ans;
signed main()
{
	
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	
	n=read(),m1=read(),m2=read();
	
	for(int i=1;i<=m1;i++)
	{
		a[i].comin=read();
		a[i].goout=read();
	}
	
	for(int i=1;i<=m2;i++)
	{
		b[i].comin=read();
		b[i].goout=read();
	}
	
	sort(a+1,a+1+m1,cmp);
	sort(b+1,b+1+m2,cmp);
	
	for(int i=1;i<=m1;i++)
	{	
		for(int j=1;j<=i;j++)
		{
			if(a[i].comin>=a[j].goout)
			{
				a[j].goout=a[i].goout;
				H1[i]=j;
				break;
			}
			H1[i]=i;
		}
	}
	
	for(int i=1;i<=m1;i++)
	{
		ans1[H1[i]]++;
	}
	
	for(int i=1;i<=n;i++)
	{
		ans1[i]+=ans1[i-1];
	} 
	
	for(int i=1;i<=m2;i++)
	{
		for(int j=1;j<=i;j++)
		{
			if(b[i].comin>=b[j].goout)
			{
				b[j].goout=b[i].goout;
				H2[i]=j;
				break;
			}
			H2[i]=i;
		}
	}
	
	for(int i=1;i<=m2;i++)
	{
		ans2[H2[i]]++;
	}
	
	for(int i=1;i<=n;i++)
	{
		ans2[i]+=ans2[i-1];
	} 
	
	
	for(int i=0;i<=n;i++)
	{
		ans=max(ans1[i]+ans2[n-i],ans);
	}
	
	cout<<ans;
	return 0;
}
