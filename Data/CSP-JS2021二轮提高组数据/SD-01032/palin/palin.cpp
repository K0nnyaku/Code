#include<bits/stdc++.h>
#define rep(i,m,n) for(int i=m;i<=n;i++)
using namespace std;
	const int N=5e5+100;
	int t,n,a[N],b[N],cnt=0,cnt1=0,cnt2=0;
	int ans=2000001;
	int cheak()
	{
		int l=1,r=n;
		while(l<=n&&r<=n)
		{
			if(b[l]!=b[r])
			{
				return 0;
			}
			l++;
			r--;
		}
		return 1;
	}
int main()
{
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	cin>>t;
	rep(u,1,t)
	{
		ans=2000001;
		cin>>n;
		n*=2;
		rep(i,1,n)
		{
			cin>>a[i];
		}
		int w;
		for(int i=0;i<=2000000;i++)
		{
			w=i;
			cnt=0;cnt1=0;cnt2=0;
			while(cnt<n)
			{
				if(w%2==1)
				{
					b[++cnt]=a[n-cnt1];
					cnt1++;
				}
				else
				{
					++cnt2;
					b[++cnt]=a[cnt2];
				}
				w/=2;
			}
			if(cheak()==1)
			{
				w=i;
				int x=1,sum=0;
				for(int i=1;i<=n;i++)
				{
					x*=2;
				}
				for(int i=1;i<=n;i++)
				{
					int v=w%2;
					sum+=v*x;
					x/=2;
					w/=2;
				}
				ans=min(ans,sum);
			}
		}
		if(ans==2000001)
		{
			cout<<"-1"<<endl;
			continue;
		}
		while(n)
		{
			n--;
			if(ans%2==0)cout<<"L";
			if(ans%2==1)cout<<"R";
			ans/=2;
		}
		cout<<endl;
	}
	return 0;
}
/*
2
5
4 1 2 4 5 3 1 2 3 5
3
3 2 1 2 1 3

*/

