#include<iostream>
#include<cstdio>
#include<algorithm>
#include<queue>
#include<cmath>
#define N 100001
#define ll long long
using namespace std;

int re()
{
	int s=0,f=1;
	char c=getchar();
	for(;c<'0'||c>'9';c=getchar())
		if(c=='-') f=-1;
	for(;c<='9'&&c>='0';c=getchar())
		s=s*10+c-'0';
	return f*s;		 
}

int n,m1,m2;

/*int irnk[N];
struct In_Nat
{
	int s,e;
	int num;
}inat[N];
int imxn;

int rnk[N];
struct Nat
{
	int s,e;
}nat[N];
int mxn;

int sum[N],isum[N];

bool cmp1(Nat a,Nat b)
{
	return a.s<b.s;
}
bool cmp2(In_Nat a,In_Nat b)
{
	return a.s<b.s;
}*/

int main()
{
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	n=re(),m1=re(),m2=re();
	int a,b;
	for(int i=1;i<=m1;i++)
	{
		a=re(),b=re();
		
	}
	for(int i=1;i<=m2;i++)
	{
		a=re(),b=re();
	}
/*	sort(nat+1,nat+m1+1,cmp1);
	sort(inat+1,inat+m2+1,cmp2);
	
	int now=0,inow=0;
	int num=0,inum=0;
	for(int i=1;i<=m;i++)
	{
		if(rnk[i])
		{
			if(nat[rnk[i]].s>=now)
			{
				sum[++mxn]=sum[mxn-1];now=nat[rnk[i]].e;
			}
		}
		if(irnk[i])
		{
			inum++;
			if(inat[rnk[i]].s>=inow)
			{
				isum[++imxn]=isum[imxn-1];inow=nat[rnk[i]].e;
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		if(sum[i]==0) sum[i]=sum[i-1];
		if(isum[i]==0) isum[i]=isum[i-1];
	}
	m=0;
	for(int i=1;i<=n;i++)	
		if(sum[i]+isum[n-1]>m)
			m=sum[i]+isum[n-1];*/
	printf("%d",m1+m2);		
	return 0;
} 
