//T1 暴力 
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#define re register
using namespace std;
const int N=100005;

inline int read()
{
	re int x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-') f=-1; ch=getchar();}
	while(ch>='0'&&ch<='9') x=(x<<1)+(x<<3)+(ch^48),ch=getchar();
	return x*f;
}

int n,m1,m2,ans;
struct Port{//升降时间 
	int s,f;
	bool operator < (const Port& a) const
	{
	    return s<a.s;
	}
};

Port a1[N],a2[N];
int stop1[N],stop2[N];//现在停着 

int work1(int langnum)
{
	if(langnum==0) {return 0;}
	int pren=0,sum1=0;
	for(int i=1;i<=m1;i++) stop1[i]=0;
	for(int i=1;i<=m1;i++)
	{
		bool flag=0;
		for(int j=1;j<=pren;j++)
		{
			if(a1[i].s>a1[stop1[j]].f)
			{
				stop1[j]=i;
				sum1++;
				flag=1;
				break;
			}
		}
		if(pren<langnum&&!flag)
		{
			stop1[++pren]=i;
			sum1++;
		}
	}
	return sum1;
}

int work2(int langnum)
{
	if(langnum==0) {return 0;}
	int pren=0,sum2=0;
	for(int i=1;i<=m2;i++) stop2[i]=0;
	for(int i=1;i<=m2;i++)
	{
		bool flag=0;
		for(int j=1;j<=pren;j++)
		{
			if(a2[i].s>a2[stop2[j]].f)
			{
				stop2[j]=i;
				sum2++;
				flag=1;
				break;
			}
		}
		if(pren<langnum&&!flag)
		{
			stop2[++pren]=i;
			sum2++;
		}
	}
	return sum2;
}


int main()
{
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	n=read(),m1=read(),m2=read();
	for(re int i=1;i<=m1;i++) a1[i].s=read(),a1[i].f=read();
	for(re int i=1;i<=m2;i++) a2[i].s=read(),a2[i].f=read();
	sort(a1+1,a1+1+m1);
	sort(a2+1,a2+1+m2);
	for(int i=0;i<=n;i++)
	{
		int sum=work1(i)+work2(n-i);
		ans=max(ans,sum);
	}
	printf("%d\n",ans);
	return 0;
}
