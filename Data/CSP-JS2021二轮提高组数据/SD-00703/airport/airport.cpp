#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
vector <int> f;
struct plane
{
	int l,r;
}a[100010];
int n,m1,m2,u,v,ans1[100010],ans2[100010],ans;
bool cmp(plane x,plane y)
{
	return x.l<y.l;
}
int main()
{
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	cin>>n>>m1>>m2;
	for(int i=1;i<=m1;i++)
	{
		cin>>a[i].l>>a[i].r;
	}
	sort(a+1,a+m1+1,cmp);
//	for(int i=1;i<=m1;i++)cout<<a[i].l<<" "<<a[i].r<<endl;
	for(int i=1;i<=m1;i++)
	{
		bool flag=false;
		for(int j=0;j<f.size();j++)
		{
			if(f[j]<=a[i].l)
			{
				f[j]=a[i].r;
				ans1[j+1]++;
				flag=true;
				break;
			}
		}
		if(flag==false)
		{
			f.push_back(a[i].r);
			ans1[f.size()]=1;
		}
	}
	f.clear();//
	for(int i=1;i<=m2;i++)
	{
		cin>>a[i].l>>a[i].r;
	}
	sort(a+1,a+m2+1,cmp);
	for(int i=1;i<=m2;i++)
	{
		bool flag=false;
		for(int j=0;j<f.size();j++)
		{
			if(f[j]<=a[i].l)
			{
				f[j]=a[i].r;
				ans2[j+1]++;
				flag=true;
				break;
			}
		}
		if(flag==false)
		{
			f.push_back(a[i].r);
			ans2[f.size()]=1;
		}
	}
//	cout<<f.size();
	for(int i=1;i<=n;i++)
	{
		ans1[i]+=ans1[i-1];
		ans2[i]+=ans2[i-1];
	}
	for(int i=0;i<=n;i++)
	{
		if(ans<ans1[i]+ans2[n-i])
		{
			ans=ans1[i]+ans2[n-i];
		}
	}
	cout<<ans<<endl;
//	for(int i=1;i<=n;i++)cout<<ans1[i]<<" ";cout<<endl;for(int i=1;i<=n;i++)cout<<ans2[i]<<" ";
	fclose(stdin);
	fclose(stdout);
	return 0;
}
