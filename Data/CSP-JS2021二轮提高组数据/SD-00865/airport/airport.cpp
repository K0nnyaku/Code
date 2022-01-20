#include<iostream>
#include<cstdio>
#include<vector>
#include<cstring>
#include<map>
#include<queue>
#include<algorithm>
#include<cmath>
#include<string>
using namespace std;
int n,m1,m2;
struct node
{
	int l,r;
}gn[100005];
struct node1
{
	int l,r;
}gw[100005];
int num[100005],num1[100005],tot,tot1,ans,q1[100005],q2[100005];
inline int read()
{
	char v=getchar();
	int x=0,f=1;
	while(!isdigit(v))
	{
		if(v=='-')
		f=-1;
		v=getchar();
	}
	while(isdigit(v))
	{
		x=x*10+v-'0';
		v=getchar();
	}
	return x*f;
}
int cmp(int x,int y)
{
	return x>y;
}
int cmp1(node x,node y)
{
	return x.l<y.l;
}
int cmp2(node1 x,node1 y)
{
	return x.l<y.l;
}
int main()
{
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	n=read(),m1=read(),m2=read();
	for(int i=1;i<=m1;i++)
	{
		gn[i].l=read(),gn[i].r=read();
	}
	sort(gn+1,gn+m1+1,cmp1);
	int ok1=0;
	for(int i=1;i<=m1;i++)
	{
		for(int j=1;j<=tot+1;j++)
		{
			if(gn[i].l>num1[j])
			{
				num[j]++,num1[j]=gn[i].r;
				if(j==tot+1)
				tot++;
				break;
			}
		}
	}
	int ok=tot;
	for(int i=1;i<=m2;i++)
	{
		cin>>gw[i].l>>gw[i].r;
	}
	sort(gw+1,gw+m2+1,cmp2);
	for(int i=1;i<=m2;i++)
	{
		for(int j=ok+1;j<=tot+1;j++)
		{
			if(gw[i].l>num1[j])
			{
				num[j]++,num1[j]=gw[i].r;
				if(j==tot+1)
				tot++;
				break;
			}
		}
	}
	q1[1]=num[1];
	q2[1]=num[ok+1];
	for(int i=2;i<=ok;i++)
	{
		q1[i]=q1[i-1]+num[i];
	}
	for(int i=2;i<=tot-ok;i++)
	{
		q2[i]=q2[i-1]+num[ok+i];
	}
	for(int i=0;i<=min(ok,n);i++)
	{
		ans=max(ans,q1[i]+q2[n-i]);
//		cout<<q1[i]<<" "<<q2[n-i]<<endl; 
	}
//	sort(num+1,num+tot+1,cmp);
//	for(int i=1;i<=tot;i++)
//	{
//		cout<<num[i]<<" ";
//	}
	cout<<ans<<endl; 
	return 0;
}
