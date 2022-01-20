#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int n,m1,m2,ans=0;
long long maxa,maxb;
struct gn
{
	long long d;
	long long l;
}a[100001];
struct gj
{
	long long d;
	long long l;
}b[100001];
bool cmpa(gn a,gn b)
{
	if(a.d<b.d) return 1;
	return 0;
}
bool cmpb(gj a,gj b)
{
	if(a.d<b.d) return 1;
	return 0;
}
int js(int n1,int n2)
{
	int g=0;
	int h[100005];
	int nn1=n1,nn2=n2,summ=0;
	for(long long i=0;i<=maxa;i++)
	{
		if(a[g].d==i)
		{
			if(nn1>0)
			{
				nn1--;
				h[n1-nn1-1]=g;
				summ++;
			}
			g++;
		}
		for(long long j=0;j<n1-nn1;j++)
		{
			if(a[h[j]].l==i)
			{
				h[j]=h[n1-nn1-1];
				h[n1-nn1-1]=0;
				nn1++;
			}
		}
	}
	g=0;
	for(long long i=0;i<=maxb;i++)
	{
		if(b[g].d==i)
		{
			if(nn2>0)
			{
				nn2--;
				h[n2-nn2-1]=g;
				summ++;
			}
			g++;
		}
		for(long long j=0;j<n2-nn2;j++)
		{
			if(b[h[j]].l==i)
			{
				h[j]=h[n2-nn2-1];
				h[n2-nn2-1]=0;
				nn2++;
			}
		}
	}
	if(summ>ans) ans=summ;
}
int main(){
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	cin>>n>>m1>>m2;
	for(int i=0;i<m1;i++)
	{
		cin>>a[i].d>>a[i].l;
		if(a[i].l>maxa) maxa=a[i].l;
	}
	sort(a,a+m1,cmpa);
	for(int i=0;i<m2;i++)
	{
		cin>>b[i].d>>b[i].l;
		if(b[i].l>maxb) maxb=b[i].l;
	}
	sort(b,b+m2,cmpb);
	for(int i=0;i<=n;i++)
	{
		js(i,n-i);
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
