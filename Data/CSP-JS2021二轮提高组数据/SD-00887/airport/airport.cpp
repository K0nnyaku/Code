#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
struct no
{
	int x;
	int y;
}a[100005];
no b[100005];
bool cmp(no w,no e)
{
	return w.x<e.x;
}
bool cmp2(int q,int p)
{
	return q>p;
}
int n,m1,m2,sa,sb,m,na[100005],nb[100005],qa[100005],qb[100005],maxn;
bool va[100005],vb[100005];
int main()
{
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	cin>>n>>m1>>m2;
	for(int i=1;i<=m1;i++)
		cin>>a[i].x>>a[i].y;
	for(int i=1;i<=m2;i++)
		cin>>b[i].x>>b[i].y;
	sort(a+1,a+m1+1,cmp);
	sort(b+1,b+m2+1,cmp);
	va[0]=true;
	while(va[0])
	{
		va[0]=false;
		for(int i=1;i<=m1;i++)
			if(!va[i])
			{
				va[0]=true;
				va[i]=true;
				sa++;
				na[sa]=1;
				m=a[i].y;
				for(int j=i+1;j<=m1;j++)
					if(!va[j])
						if(a[j].x>m)
						{
							va[j]=true;
							na[sa]++;
							m=a[j].y;
						}
				break;
			}
	}
	vb[0]=true;
	while(vb[0])
	{
		vb[0]=false;
		for(int i=1;i<=m2;i++)
			if(!vb[i])
			{
				vb[0]=true;
				vb[i]=true;
				sb++;
				nb[sb]=1;
				m=b[i].y;
				for(int j=i+1;j<=m1;j++)
					if(!vb[j])
						if(b[j].x>m)
						{
							vb[j]=true;
							nb[sb]++;
							m=b[j].y;
						}
				break;
			}
	}
	for(int i=1;i<=sa;i++)
		qa[i]=na[i]+qa[i-1];
	for(int i=1;i<=sb;i++)
		qb[i]=nb[i]+qb[i-1];
	for(int i=sa+1;i<=n;i++)
		qa[i]=qa[sa];
	for(int i=sb+1;i<=n;i++)
		qb[i]=qb[sb];
	for(int i=0;i<=n;i++)
		if(qa[i]+qb[n-i]>maxn)
			maxn=qa[i]+qb[n-i];
	cout<<maxn<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
