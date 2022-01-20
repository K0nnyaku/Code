#include<bits/stdc++.h>
using namespace std;
int n,k,a[100005],v[100005],ans[75][75],tot,tot1[75],ans1,ans2;
int ans3[75][75],cnt,cnt1[75];
int main()
{
	freopen("num.in","r",stdin);
	freopen("num.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=k;i++)
	{
		tot++;
		cnt++;
		for(int j=i;j<=n;j+=k)
		{
			ans[tot][++tot1[tot]]=a[j];
			ans3[cnt][++cnt1[cnt]]=a[j];
		}
	}
	for(int i=k;i>=1;i--)//第i个集合 
	{
		for(int j=i+1;j<=k;j++)
		{
			int ok=0;
			for(int l=1;l<=n/k;l++)
			{
				if(ans[i][n/k]==ans[j][l])
				{					
					ok=1;
					break;
				}
			}
			for(int l=1;l<=n/k;l++)
			{
				if(ans[j][1]==ans[i][l])
				{
					ok=1;
					break;
				}
			}
			if(ok==1)
			continue;
			if(ans[i][n/k]>ans[j][1])
			{
//				cout<<ans[i][n/k]<<" "<<ans[j][1]<<endl;
				swap(ans[i][n/k],ans[j][1]);
				for(int r1=1;r1<=n/k;r1++)
				{
					for(int r2=r1+1;r2<=n/k;r2++)
					{
						if(ans[i][r1]>ans[i][r2])
						swap(ans[i][r1],ans[i][r2]);
					}
				}
				for(int r1=1;r1<=n/k;r1++)
				{
					for(int r2=r1+1;r2<=n/k;r2++)
					{
						if(ans[j][r1]>ans[j][r2])
						swap(ans[j][r1],ans[j][r2]);
					}
				}
			}
		}
		for(int j=i-1;j>=1;j--)
		{
			int ok=0;
			for(int l=1;l<=n/k;l++)
			{
				if(ans[i][1]==ans[j][l])
				{
					ok=1;
					break;
				}
			}
			for(int l=1;l<=n/k;l++)
			{
				if(ans[i][l]==ans[j][n/k])
				{
					ok=1;
					break;
				}
			}
			if(ok==1)
			continue;
			if(ans[i][1]<ans[j][n/k])
			{
//				cout<<ans[i][1]<<" "<<ans[j][n/k]<<endl;
				swap(ans[i][1],ans[j][n/k]);
				for(int r1=1;r1<=n/k;r1++)
				{
					for(int r2=r1+1;r2<=n/k;r2++)
					{
						if(ans[i][r1]>ans[i][r2])
						swap(ans[i][r1],ans[i][r2]);
					}
				}
				for(int r1=1;r1<=n/k;r1++)
				{
					for(int r2=r1+1;r2<=n/k;r2++)
					{
						if(ans[j][r1]>ans[j][r2])
						swap(ans[j][r1],ans[j][r2]);
					}
				}
			}
		}
	}
	for(int i=1;i<=k;i++)
	{
		ans1+=ans[i][n/k]-ans[i][1];
	}
	for(int i=1;i<=k;i++)//第i个集合 
	{
		for(int j=i+1;j<=k;j++)
		{
			int ok=0;
			for(int l=1;l<=n/k;l++)
			{
				if(ans3[i][n/k]==ans3[j][l])
				{					
					ok=1;
					break;
				}
			}
			for(int l=1;l<=n/k;l++)
			{
				if(ans3[j][1]==ans3[i][l])
				{
					ok=1;
					break;
				}
			}
			if(ok==1)
			continue;
			if(ans3[i][n/k]>ans3[j][1])
			{
//				cout<<ans[i][n/k]<<" "<<ans[j][1]<<endl;
				swap(ans3[i][n/k],ans3[j][1]);
				for(int r1=1;r1<=n/k;r1++)
				{
					for(int r2=r1+1;r2<=n/k;r2++)
					{
						if(ans3[i][r1]>ans3[i][r2])
						swap(ans3[i][r1],ans3[i][r2]);
					}
				}
				for(int r1=1;r1<=n/k;r1++)
				{
					for(int r2=r1+1;r2<=n/k;r2++)
					{
						if(ans3[j][r1]>ans3[j][r2])
						swap(ans3[j][r1],ans3[j][r2]);
					}
				}
			}
		}
		for(int j=i-1;j>=1;j--)
		{
			int ok=0;
			for(int l=1;l<=n/k;l++)
			{
				if(ans3[i][1]==ans3[j][l])
				{
					ok=1;
					break;
				}
			}
			for(int l=1;l<=n/k;l++)
			{
				if(ans3[i][l]==ans3[j][n/k])
				{
					ok=1;
					break;
				}
			}
			if(ok==1)
			continue;
			if(ans3[i][1]<ans3[j][n/k])
			{
//				cout<<ans[i][1]<<" "<<ans[j][n/k]<<endl;
				swap(ans3[i][1],ans3[j][n/k]);
				for(int r1=1;r1<=n/k;r1++)
				{
					for(int r2=r1+1;r2<=n/k;r2++)
					{
						if(ans3[i][r1]>ans3[i][r2])
						swap(ans3[i][r1],ans3[i][r2]);
					}
				}
				for(int r1=1;r1<=n/k;r1++)
				{
					for(int r2=r1+1;r2<=n/k;r2++)
					{
						if(ans3[j][r1]>ans3[j][r2])
						swap(ans3[j][r1],ans3[j][r2]);
					}
				}
			}
		}
	}
	for(int i=1;i<=k;i++)
	{
		ans2+=ans3[i][n/k]-ans3[i][1];
	}
//	for(int i=1;i<=k;i++)
//	{
//		for(int j=1;j<=n/k;j++)
//		{
//			cout<<ans[i][j]<<" ";
//		}
//		cout<<endl;
//	}
	cout<<min(ans1,ans2)<<endl;
}
