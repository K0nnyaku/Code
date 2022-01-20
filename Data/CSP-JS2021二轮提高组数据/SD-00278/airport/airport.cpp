#include<bits/stdc++.h>
using namespace std;

long long n,m1,m2,l,na,nb,nt,nm,ans,mint,maxt;
long long ansa,ansb;
bool a1[100005],b1[100005],ai[100005],bi[100005];
struct  node
{
	long long tin;
	long long tout;
};
node a[100005],b[100005];

int cmp(node x,node y)
{
	return x.tin<y.tin;
}

int main()
{
	
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	cin>>n>>m1>>m2;
	for(long long i=1;i<=m1;i++)
	{
		cin>>a[i].tin>>a[i].tout;
		mint=min(mint,a[i].tin);
		maxt=max(maxt,a[i].tout);
	}
	for(long long i=1;i<=m2;i++)
	{
		cin>>b[i].tin>>b[i].tout;
		mint=min(mint,b[i].tin);
		maxt=max(maxt,b[i].tout);
	}
	sort(a+1,a+m1+1,cmp);
	sort(b+1,b+m2+1,cmp);
	for(long long k=0;k<=n;k++)
	{
		nm=0;nt=0;ansa=0;
		memset(a1,0,sizeof(a1));
		memset(b1,0,sizeof(b1));
		memset(ai,0,sizeof(ai));
		memset(bi,0,sizeof(bi));
		for(int i=1;i<=m1;i++)
		{
			if(k==0)
			{
				break;
			}
			nt=a[i].tin;
			for(long long j=1;j<=i;j++)
			{
				if(a[j].tout<=nt&&a1[j]==0&&ai[j]==1)
				{
					a1[j]=1;
					nm--;
				}
			}
			if (nm<k)
			{
				nm++;
				ansa++;
				ai[i]=1;
			}
		}
		nm=0;nt=0;ansb=0;
		for(int i=1;i<=m2;i++)
		{
			nt=b[i].tin;
			for(long long j=1;j<=i;j++)
			{
				if(b[j].tout<=nt&&b1[j]==0&&bi[j]==1)
				{
					b1[j]=1;
					nm--;
				}
			}
			if (nm<(n-k))
			{
				nm++;
				ansb++;
				bi[i]=1;
			}
		}
		ans=max(ansa+ansb,ans);
	}
	cout<<ans<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
