#include<bits/stdc++.h>
#define rep(i,m,n) for(int i=m;i<=n;i++)
using namespace std;
	const int N=1e5+100;
	struct node{
		int st,en;
	}e[N],ee[N];
	int n,m1,m2,ans=0;
	int cmp(node a,node b)
	{
		return a.st<b.st;
	}
	void work()
	{
		int a[N],b[N];
		rep(u,0,n)
		{
			int cnt=0,cnt2=0;
			int sum=0,sum2=0;
			rep(i,1,m1)
			{
				for(int j=cnt;j>=1;j--)
				{
					if(cnt==0)break;
					if(a[j]<e[i].st)
					{
						cnt--;
					}
				}
				if(cnt==u)continue;
				a[++cnt]=e[i].en;
				sum++;
				for(int j=cnt-1;j>=1;j--)
				{
					if(a[j]<a[j+1])
					{
						int c=a[j];
						a[j]=a[j+1];
						a[j+1]=c;
					}
					else break;
				}
			}
			rep(i,1,m2)
			{
				for(int j=cnt2;j>=1;j--)
				{
					if(cnt2==0)break;
					if(b[j]<ee[i].st)
					{
						cnt2--;
					}
				}
				if(cnt2==n-u)continue;
				b[++cnt2]=ee[i].en;
				sum2++;
				for(int j=cnt2-1;j>=1;j--)
				{
					if(b[j]<b[j+1])
					{
						int c=b[j];
						b[j]=b[j+1];
						b[j+1]=c;
					}
					else break;
				}
			}
			ans=max(ans,sum+sum2);
		 } 
		 cout<<ans;
	}

int main()
{
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	cin>>n>>m1>>m2;
	rep(i,1,m1)
	{
		cin>>e[i].st>>e[i].en;
	}
	sort(e+1,e+1+m1,cmp);
	rep(i,1,m2)
	{
		cin>>ee[i].st>>ee[i].en;
	}
	sort(ee+1,ee+1+m2,cmp);
	work();
	return 0;
}
