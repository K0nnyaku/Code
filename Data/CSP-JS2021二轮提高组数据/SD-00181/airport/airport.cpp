#include<iostream>
#include<cstdio>
#include<stdio.h>
#include<cmath>
#include<algorithm>
using namespace std;
int n,m1,m2,sum,vis[100010],loser[100010],loser1[100010],num[100010],k,n1,n2;
struct nm
{
	int start;
	int leave;
	int na;
	int guo;
}a[100010];
bool cmp(nm x,nm y)
{
	if (x.start<y.start) return 1;
	if (x.start==y.start&&x.leave<y.leave) return 1;
	return 0;
} 
int cmp1(int x) 
{
	int i=1;
	for (i=1;i<=n1;++i)
	if (x<=loser[i]) break;
	return i-1;
}
int cmp2(int x) 
{
	int i=1;
	for (i=1;i<=n2;++i) 
	if (x<=loser1[i]) break;
	return i-1;
}
/*void print()
{
	cout<<endl;
	for (int i=1;i<=k;++i) cout<<num[i]<<" ";
	cout<<endl<<sum<<endl<<n1<<" "<<n2<<endl;
}*/
void dfs(int ans)
{
	int b=0;
	for (int i=1;i<=m1+m2;++i)
	{
		if (vis[i]==0)
		{
			int L;
			if (a[i].guo==1) 
			{
				L=cmp1(a[i].start);
				if (L!=0&&a[i].start>loser[L]&&L<=n1)
				{
					int lo=loser[L];
					loser[L]=a[i].leave;
					sort(loser+1,loser+n1+1);
					vis[i]=1;
					b=1;
					num[++k]=a[i].na;
					dfs(ans+1);
					loser[L]=lo;
					vis[i]=0;
					num[L]=0;
					k--;
				}
			}
			else
			{
				L=cmp2(a[i].start);
				if (L!=0&&a[i].start>loser1[L]&&L<=n2)
				{
					int lo=loser1[L];
					loser1[L]=a[i].leave;
					sort(loser1+1,loser1+n2+1);
					vis[i]=1;
					b=1;
					num[++k]=a[i].na;
					dfs(ans+1);
					loser1[L]=lo;
					vis[i]=0;
					num[L]=0;
					k--;
				}
			}
		}
	}
	if (b==0)
	{
		/*int c=0;
		if (ans>sum) c=1;*/
		sum=max(ans,sum);
		//if (c==1) print();
		return;
	}
}
int main()
{	
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	cin>>n>>m1>>m2;
	for (int i=1;i<=n;++i) loser[i]=-1;
	for (int i=1;i<=m1;++i)
	{
		cin>>a[i].start>>a[i].leave; 
		a[i].na=i;
		a[i].guo=1;
	}
	for (int i=m1+1;i<=m1+m2;++i)
	{
		cin>>a[i].start>>a[i].leave; 
		a[i].na=i;
		a[i].guo=2;
	}
	sort(a+1,a+m1+m2+1,cmp);
	/*for (int i=1;i<=m1+m2;++i)
	{
		if (a[i].leave<=a[i+1].start)
		{
			sum++;
			continue;
		}
		
		else continue;
	}*/
	//for (int i=1;i<=m1+m2;++i) cout<<a[i].start<<" "<<a[i].leave<<" "<<a[i].na<<endl;
	for (int i=1;i<=n;++i)
	{
		n1=i;
		n2=n-i;
		int jb=0;
		for (int j=1;j<=m1+m2;++j)
		{
			if (jb==n1) break;
			if (a[j].guo==1)
			{
				vis[j]=1;
				loser[j]=a[j].leave;
				num[++k]=a[j].na;
				jb++;
			}
		}
		jb=0;
		for (int j=1;j<=max(n2,m2);++j)
		{
			if (jb==n2) break;
			if (a[j].guo==2)
			{
				vis[j]=1;
				loser1[j]=a[j].leave;
				num[++k]=a[j].na;
				jb++;
			}
		}
		dfs(n);
	}
	printf("%d",sum);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
