#include<iostream>
#include<cstdio>
#include<algorithm>
#define mN 100005
#define mM 100005
using namespace std;
struct api{
	int at,lt;
}a1[mM],a2[mM];
struct lq{
	int t,num;
}u[mN],tp;
int n,m1,m2,nowu,l1[mN],l2[mN],u1,u2,maxn; 

inline int rf()
{
	int rx=0,rfh=1,rch=0;
	while(rch<'0'||rch>'9') {rch=getchar();if(rch=='-')  rfh=-1;}
	while(rch>='0'&&rch<='9') {(rx*=10)+=(rch^48);rch=getchar();}
	return rx*rfh;
}
bool cmpm(api p,api q)
{
	return p.at<q.at;
}
inline void deala1()
{
	u[1].t=a1[1].lt;u[1].num=1;
	nowu=1; 
	int gto=0;
	for(int i=2;i<=m1;i++)
	{
		gto=1;
		for(;gto<=nowu;gto++)
			if(u[gto].t<a1[i].at)	break;
		if(gto<=nowu)
		{
			u[gto].t=a1[i].lt;u[gto].num++;
		}
		else
		{
			if(nowu==n)	continue;
			u[++nowu].num=1;u[nowu].t=a1[i].lt;			
		}
	}
	u1=nowu;
	for(int i=1;i<=nowu;i++)
		l1[i]=l1[i-1]+u[i].num;
	return;	
}
inline void deala2()
{
	u[1].t=a2[1].lt;u[1].num=1;
	nowu=1;
	int gto=0;
	for(int i=2;i<=m2;i++)
	{
		gto=1;
		for(;gto<=nowu;gto++)
			if(u[gto].t<a2[i].at)	break;
		if(gto<=nowu)
		{
			u[gto].t=a2[i].lt;u[gto].num++;
		}
		else
		{
			if(nowu==n)	continue;
			u[++nowu].num=1;u[nowu].t=a2[i].lt;			
		}		
	}
	u1=nowu;
	for(int i=1;i<=nowu;i++)
		l2[i]=l2[i-1]+u[i].num;
	return;
}
int main()
{
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	n=rf();m1=rf();m2=rf();
	if(n>=m1+m2)	{printf("%d",n);return 0;}
	
	for(int i=1;i<=m1;i++){
		a1[i].at=rf();a1[i].lt=rf();
	}
	for(int i=1;i<=m2;i++){
		a2[i].at=rf();a2[i].lt=rf();
	}
	sort(a1+1,a1+m1+1,cmpm);
	sort(a2+1,a2+m2+1,cmpm);
	
	deala1();
	for(int i=1;i<=nowu;i++)
		u[i].t=u[i].num=0;
	nowu=0;
	deala2();
	
	maxn=0;
	for(int i=0;i<=n;i++)
	{
		if(l1[i]+l2[n-i]>maxn)
			maxn=l1[i]+l2[n-i];
	}
	printf("%d",maxn);
	fclose(stdin);fclose(stdout);
	return 0;
}

