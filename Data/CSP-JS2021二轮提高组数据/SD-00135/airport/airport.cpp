#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
#pragma GCC optimize(2)
const int N=5e5+10;
int a[N][2],b[N][2],len1,len2;
int a2[N][2],b4[N][2],len3,len4;
int k[N],k2[N];
bool b3[N],b2[N];
int main()
{
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	int n,m1,m2;
	cin>>n>>m1>>m2;
	for(int i=1;i<=m1;i++) scanf("%d%d",&a[i][0],&a[i][1]);//cin>>a[i][0]>>a[i][1];
	for(int i=1;i<=m2;i++) scanf("%d%d",&b[i][0],&b[i][1]);
	len1=m1,len2=m2;
	for(int i=1;i<=n;i++)
	{
		if(i%2)
		{
			int j=1;
			int r=a[j][1];
			b3[j]=1;
			int add=1;
			for(int j2=j+1;j2<=len1;j2++)
			if(a[j2][0]>r&&!b3[j2])  add++,r=a[j2][1],b3[j2]=true;
			len3=0;
			for(int i=1;i<=len1;i++) if(!b3[i]) a2[++len3][0]=a[i][0],a2[len3][1]=a[i][1];else b3[i]=false;
			if(len3==0)
			{
				for(int i2=i;i2<=n;i2++) k[i2]=m1;
				break;
			}
			k[i]=k[i-1]+add;
	    }
	    else
	    {
	    	int j=1;
			int r=a2[j][1];
			b3[j]=1;
			int add=1;
			for(int j2=j+1;j2<=len3;j2++)
			if(a2[j2][0]>r&&!b3[j2])  add++,r=a2[j2][1],b3[j2]=true;
			len1=0;
			for(int i=1;i<=len3;i++) if(!b3[i]) a[++len1][0]=a2[i][0],a[len1][1]=a2[i][1];else b3[i]=false;
			if(len1==0)
			{
				for(int i2=i;i<=n;i++) k[i2]=m1;
				break;
			}
			k[i]=k[i-1]+add;
		}
	}
	for(int i=1;i<=n;i++)
	{
		if(i%2)
		{
			int j=1;
			int r=b[j][1];
			int add=1;
			b2[j]=1;
			for(int j2=j+1;j2<=len2;j2++)
			if(b[j2][0]>r&&!b2[j2])  add++,r=b[j2][1],b2[j2]=true;
			len4=0;
			for(int j=1;j<=len2;j++) 
			{
			    if(!b2[j]) b4[++len4][0]=b[j][0],b4[len4][1]=b[j][1];else b2[j]=false;
			}
			if(len4==0)
			{
				for(int i2=i;i2<=n;i2++) k2[i2]=m2;
				break;
			}
			k2[i]=k2[i-1]+add;
	    }
	    else
	    {
	    	int j=1;
			int r=b4[j][1];
			int add=1;
			b2[j]=1;
			for(int j2=j+1;j2<=len4;j2++)
			if(b4[j2][0]>r&&!b2[j2])  add++,r=b4[j2][1],b2[j2]=true;
			len2=0;
			for(int j=1;j<=len4;j++) if(!b2[j]) b[++len2][0]=b4[j][0],b[len2][1]=b4[j][1];else b2[j]=false;
			if(len2==0)
			{
				for(int i2=i;i2<=n;i2++) k2[i2]=m2;
				break;
			} 
			k2[i]=k2[i-1]+add;
		}
	}
	int ans=0;
	for(int i=0;i<=n;i++) ans=max(ans,k[i]+k2[n-i]);
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
