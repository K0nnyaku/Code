#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define gc getchar()
#define mem(x,y) memset(x,y,sizeof(x))
using namespace std;
const int N=1e5+10;
int n,m1,m2,build1[N],build2[N],s1[N],s2[N];
int read()
{
	char c=gc;
	int a=0,b=1;
	while (c<'0'||c>'9') {if (c=='-') b=-1;c=gc;}
	while (c>='0'&&c<='9') a=(a<<3)+(a<<1)+c-'0',c=gc;
	return a*b;
}
struct poiu
{
	int a,b;
}air1[N],air2[N];
bool lkj(poiu x,poiu y)
{
	return x.a<y.a;
}
int solve1(int x)//x廊桥数量 
{
	mem(build1,0);
	int num=0;
	for (int i=1;i<=m1;i++)
	{
		sort(build1+1,build1+1+x);
		for (int j=1;j<=x;j++)
		  if (air1[i].a>build1[j])
		  {
		  	num++;build1[j]=air1[i].b;
		  	break;
		  }
	}
	s1[x]=num;//
	return num;
}
int solve2(int x)//x廊桥数量 
{
	mem(build2,0);
	int num=0;
	for (int i=1;i<=m2;i++)
	{
		sort(build2+1,build2+1+x);
		for (int j=1;j<=x;j++)
		  if (air2[i].a>build2[j])
		  {
		  	num++;build2[j]=air2[i].b;
		  	break;
		  }
	}
	s2[x]=num;//
	return num;
}
int main()
{
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	n=read();m1=read();m2=read();
	for (int i=1;i<=m1;i++)
	  air1[i].a=read(),air1[i].b=read();
	for (int i=1;i<=m2;i++)
	  air2[i].a=read(),air2[i].b=read();  
	sort(air1+1,air1+1+m1,lkj);
	sort(air2+1,air2+1+m2,lkj);
	  
	int ans=0,maxn=0; 
	for (int i=0;i<=n;i++)
	{
		ans=solve1(i)+solve2(n-i);
		//printf("%d ",ans);
		maxn=max(maxn,ans);
	}
	printf("%d",maxn);
	fclose(stdin);
	fclose(stdout);
	return 0;
}

