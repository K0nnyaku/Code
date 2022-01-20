#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long ll;
template<typename T> void Read(T &x)
{
	x=0;bool f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9')
	{
		if(ch=='-') f=0;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9')
	{
		x=x*10+(ch^48);
		ch=getchar();
	}
	x=f==1?x:-x;
}
struct fj
{
	int t,val,nxt,index;
} a1[200001],a2[200001];
int n,m1,m2,ans=0,sl1=0,sl2=0,dy1[200001],dy2[200001],z1[200001],z2[200001],val1[100001],val2[100001];
bool cmp(fj x1,fj x2)
{
	return x1.t<x2.t;
}
int lowbit(int x){return x&(-x);}
int main()
{
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	Read(n);Read(m1);Read(m2);
	for(int i=1;i<=m1;i++)
	{
		Read(a1[2*i-1].t);
		a1[2*i-1].val=1;
		a1[2*i-1].nxt=2*i;
		a1[2*i-1].index=2*i-1;
		Read(a1[2*i].t);
		a1[2*i].val=-1;
		a1[2*i].index=2*i;
	}
	for(int i=1;i<=m2;i++)
	{
		Read(a2[2*i-1].t);
		a2[2*i-1].val=1;
		a2[2*i-1].nxt=2*i;
		a2[2*i-1].index=2*i-1;
		Read(a2[2*i].t);
		a2[2*i].val=-1;
		a2[2*i].index=2*i;
	}
	sort(a1+1,a1+1+2*m1,cmp);
	sort(a2+1,a2+1+2*m2,cmp);
	for(int i=1;i<=2*m1;i++) dy1[a1[i].index]=i;
	for(int i=1;i<=2*m2;i++) dy2[a2[i].index]=i;
	for(int qwq=n;qwq>=1;qwq--)
	{
		for(int i=1;i<=2*m1;i++)
		{
			if(z1[i-1]==qwq&&a1[i].val==1)
				a1[i].val=a1[dy1[a1[i].nxt]].val=0;
			z1[i]=z1[i-1]+a1[i].val;
			if(a1[i].val==1) val1[qwq]++;
		}
		for(int i=1;i<=2*m2;i++)
		{
			if(z2[i-1]==qwq&&a2[i].val==1)
				a2[i].val=a2[dy2[a2[i].nxt]].val=0;
			z2[i]=z2[i-1]+a2[i].val;
			if(a2[i].val==1) val2[qwq]++;
		}
	}
	for(int i=0;i<=n;i++) ans=max(ans,val1[i]+val2[n-i]);
	printf("%d",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
