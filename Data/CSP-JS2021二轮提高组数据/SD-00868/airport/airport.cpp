#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
typedef long long ll;
using namespace std;
inline int read()
{
    int s=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9')
	{
		if(ch=='-')
		f=-1;
		ch=getchar();
    }	
	while(ch>='0'&&ch<='9')
	{
		s=s*10+ch-'0';
		ch=getchar();
	}
	return s*f;
} 
struct ss{
	int s,e,f;
}g1[100003],g2[100003];
int main()
{
    int n,m1,m2,a1,a2,b1,b2;
	int x=1,ans1=0,maxx=0;
	freopen("airport1.in","r",stdin);
	freopen("airport1.out","w",stdout);
	n=read();
	m1=read();
	m2=read();
	for(int i=1;i<=m1;i++)
	{
		a1=read();
		b1=read();
		x=max(x,b1);
		g1[a1].s=1;
		g1[a1].e=b1;
		g1[b1].f=1;
	}
	for(int i=1;i<=m2;i++)
	{
		a2=read();
		b2=read();
		x=max(x,b2);
		g2[a2].s=1;
		g2[a1].e=b1;
		g2[b2].f=1;
	}
	for(int j=1;j<=n;j++)
	{
		int p=j,q=n-j;
		for(int i=1;i<=x;i++)
		{
			if(p>0)
			{
				if(g1[i].f==1)
			{
				p++;
			}
			if(g1[i].s==1&&p>0)
			{
				p--;
				ans1++;
			}
			if(g1[i].s==1&&p==0)
			{
				g1[g1[i].e].f++;
			}
	}
			if(q>0)
			{
				if(g2[i].f==1)
			{
				q++;
			}
			     if(g2[i].s==1&&q>0)
			{
				q--;
				ans1++;
			}
			     if(g2[i].s==1&&q==0)
			{
				g2[g2[i].e].f++;
			}
			}
		
		}
	}
	maxx=max(ans1,maxx);ans1=0;
	cout<<maxx;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
 
