#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<iostream>
using namespace std;
const int maxn=10000001;
int a[5010],b[5010];
int main()
{
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	int n,m1,m2,ll,ans,time=0;
	bool s[100010];
	ll=0;
	ans=0;
	memset(s,0,sizeof(s));
	scanf("%d%d%d",&n,&m1,&m2);
	for(int i=1;i<=m1+m2;i++)
	    cin>>a[i]>>b[i];
	if(n==m1+m2)ans=n;
	else 
	{
	  for(int i=0;i<=n;i++)
	 {
		ans=0;
		for(int j=1;j<=m1;j++)
		{
		  if(j<=i)
			{s[j]=1;ans++;}	
		else
		{
			for(int l=1;l<m1;l++)
			{while(a[j]>b[l]&&s[l]==1)
			   {
			    s[l]=0;
			    ans++;
			    s[j]=1;
			    break; 
			   }
			}
		}}
		for(int x=m1+1;x<=m2;x++)
		{
			if(x<=(n-i))
			{s[x]=1;ans++;}
			else 
			{
				for(int q=m1+1;q<=m2;q++)
				{while(s[q]==1&&a[x]>b[q])
				   {
					s[q]=0;
					s[x]=1;
					ans++;
					break;
					}
				}
			}
			
		}
		ll=max(ll,ans);
	 }
	ans=ll;
	}
	cout<<ans+1<<endl;
	return 0;
}
