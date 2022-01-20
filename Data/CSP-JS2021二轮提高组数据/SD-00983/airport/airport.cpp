#include<bits/stdc++.h>

using namespace std;

const int N = 310;

int n,m1,m2;
int s1[N],s2[N],e1[N],e2[N],f1[N],f2[N],wz1[2*N],wz2[N*2];
int a[N*2];
int maxv; 
struct ha
{
	int num,pla;
}a1[N*2];
ha a2[N*2];

bool cmp(ha a,ha b)
{
	return a.pla<b.pla;
}

int main()
{
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	
	cin>>n>>m1>>m2;
	
	for(int i=1;i<=m1;i++)
	{
		cin>>s1[i]>>e1[i];
		a1[i]={i,s1[i]},a1[m1+i]={m1+i,e1[i]};
	}
	sort(a1+1,a1+2*m1+1,cmp);
	
	for(int i=1;i<=2*m1;i++)
	{
		wz1[a1[i].num]=i;
	}
	
		for(int i=1;i<=m2;i++)
	{
		cin>>s2[i]>>e2[i];
		a2[i]={i,s2[i]},a2[m2+i]={m2+i,e2[i]};
	}
	sort(a2+1,a2+2*m2+1,cmp);
	
	for(int i=1;i<=2*m2;i++)
	{
		wz2[a2[i].num]=i;
	}
	
	for(int i=1;i<=n;i++)
	{
		memset(a,0,sizeof(a));
		for(int j=1;j<=m1;j++)
		{
			if(a[wz1[j]]+1>i)continue;
			for(int k=wz1[j];k<=wz1[m1+j];k++)
			{
				a[k]++;
			}
			f1[i]++;
		}
	}
	for(int i=1;i<=n;i++)
	{
		memset(a,0,sizeof(a));
		for(int j=1;j<=m2;j++)
		{
			if(a[wz2[j]]+1>i)continue;
			for(int k=wz2[j];k<=wz2[m2+j];k++)
			{
				a[k]++;
			}
			f2[i]++;
		}
	}
	
	for(int i=0;i<=n;i++)
	{
		maxv=max(maxv,f1[i]+f2[n-i]);
	}
	
	cout<<maxv<<endl;
	
	return 0;
}
