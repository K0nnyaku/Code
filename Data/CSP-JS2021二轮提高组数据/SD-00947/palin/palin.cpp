#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<queue>
#include<map>
#include<set>
#include<stack>
#define ll long long
using namespace std;
int re()
{
	int x=0,p=1;
	char y=getchar();
	while(y>'9'||y<'0')
	{
		if(y=='-')
		p=-1;
		y=getchar();
	}
	while(y>='0'&&y<='9')
	{
		x=10*x+y-'0';
		y=getchar();
	}
	return x*p;
}
int n;
bool zzs[500006];
struct head
{
	int l,r,suml,sumr;
}a,b,c;
int sum[500006];
bool bfs(int k)
{
	if(k==n+1)
	return true;
	if(a.l==b.l&&a.suml!=b.suml)
	{
		zzs[k]=true;
		zzs[2*n-k+1]=true;
		a.l=sum[a.suml+1];
		b.l=sum[b.suml-1];
		a.suml=a.suml+1;
		b.suml=b.suml-1;
		if(bfs(k+1))
		return true;
		zzs[k]=true;
		zzs[2*n-k+1]=true;
		a.l=sum[a.suml-1];
		a.suml=a.suml-1;
		b.l=sum[b.suml+1];
		b.suml=b.suml+1;
	}
	if(a.l==b.r&&a.suml!=b.sumr)
	{
		zzs[k]=true;
		zzs[2*n-k+1]=false;
		a.l=sum[a.suml+1];
		a.suml=a.suml+1;
		b.r=sum[b.sumr+1];
		b.sumr=b.sumr+1;
		if(bfs(k+1))
		return true;
		zzs[k]=true;
		zzs[2*n-k+1]=true;
		a.l=sum[a.suml-1];
		a.suml=a.suml-1;
		b.r=sum[b.sumr-1];
		b.sumr=b.sumr-1;
	}
		if(a.r==b.l&&a.sumr!=b.suml)
	{
		zzs[k]=false;
		zzs[2*n-k+1]=true;
		a.sumr=a.sumr-1;
		a.r=sum[a.sumr];
		b.suml=b.suml-1;
		b.l=sum[b.suml];
		if(bfs(k+1))
		return true;
		zzs[k]=true;
		zzs[2*n-k+1]=true;
		a.sumr=a.sumr+1;
		a.r=sum[a.sumr];
		b.suml=b.suml+1;
		b.l=sum[b.suml];
	}
	if(a.r==b.r&&a.sumr!=b.sumr)
	{
		zzs[k]=false;
		zzs[2*n-k+1]=false;
		a.sumr=a.sumr-1;
		a.r=sum[a.sumr];
		b.sumr=b.sumr+1;
		b.r=sum[b.sumr];
		if(bfs(k+1))
		return true;
		zzs[k]=true;
		zzs[2*n-k+1]=true;
		a.sumr=a.sumr+1;
		a.r=sum[a.sumr];
		b.sumr=b.sumr-1;
		b.r=sum[b.sumr];
	}
	return false;
}
bool pd;
void out()
{
	for(int i=1;i<=2*n;++i)
	{
		if(zzs[i])
		cout<<"L";
		else
		cout<<"R";
	}
	cout<<endl;
	return;
}
int main()
{
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	int T=re();
	for(int ppt=1;ppt<=T;++ppt)
	{
		n=re();
		a.l=a.r=a.suml=a.sumr=0;
		zzs[2*n]=true,zzs[1]=true;
		for(int i=1;i<=2*n;++i)
		sum[i]=re();
		a.l=sum[++a.suml];
		a.r=sum[2*n];
		a.sumr=2*n;
		if(a.l==a.r)
		{
			for(int i=1;i<=n;++i)
			if(sum[i]!=sum[2*n-i+1])
			pd=true;
			if(pd)
			cout<<-1;
			else
			for(int i=1;i<=2*n;++i)
			{
				cout<<"L";
			}
			cout<<endl;
		}
		else
		{
			for(int i=2;i<=2*n-1;++i)
			{
				zzs[i]=true;
				if(sum[i]==a.l)
				{
					b.l=sum[i-1];
					b.r=sum[i+1];
					b.suml=i-1;
					b.sumr=i+1;
				}
				if(sum[i]==a.r)
				{
					c.l=sum[i-1];
					c.r=sum[i+1];
					c.suml=i-1;
					c.sumr=i+1;
				}
			}
			a.l=sum[2];
			a.suml=2;
			if(!bfs(2))
			{
				b.l=c.l;
				b.r=c.r;
				b.suml=c.suml;
				b.sumr=c.sumr;
				a.l=sum[1];
				a.suml=1;
				a.r=sum[2*n-1];
				a.sumr=2*n-1;
				zzs[1]=false;
				if(!bfs(2))
				{
					cout<<-1<<endl;
				}
				else out();
			}
			else out();
		}
		
	}
	return 0;
}
