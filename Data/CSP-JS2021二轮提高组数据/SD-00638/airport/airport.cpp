#include<cstdio>
#include<iostream>
using namespace std;
int mana[2][100000001];
int a[2][1000001],b[2][1000001],ans[100001],adb[100001];
int n,m1,m2,an=0;
bool bj[2][100001];
int qbt[100001];
int main()
{
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	scanf("%d%d%d",&n,&m1,&m2);
	for(int i=1;i<=m1;i++)
		scanf("%d%d",&a[1][i],&b[1][i]);
	for(int i=1;i<=m2;i++)
		scanf("%d%d",&a[2][i],&b[2][i]);
	if(n==0) 
	{
		cout<<0;
		return 0;
	}
	
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m1;j++)
		{
			if(a[1][j]>mana[1][i]&&bj[1][j]==0)
			{
				mana[1][i]=b[1][j];
				bj[1][j]=1;
				ans[i]++;
			} 
		}
	}
		for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m2;j++)
		{
			if(a[2][j]>mana[2][i]&&bj[2][j]==0)
			{
				mana[2][i]=b[2][j];
				bj[2][j]=1;
				adb[i]++;
			} 
		}
	}
	for(int i=0;i<=n;i++)
	{
		ans[i]=ans[i-1]+ans[i];
		adb[i]=adb[i-1]+adb[i];
		for(int j=0;j<=n;j++)
		{
			if(i+j==n)
			{
				qbt[i]=ans[i]+adb[j];
			}
		}
		if(qbt[i]>an) an=qbt[i]-ans[0]-adb[0];
	}
	cout<<an;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

