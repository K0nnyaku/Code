#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;
int n,m1,m2;
struct point{
	int l,r;
}a[100010];
int ans1,ans2;
int mxx=-1;
int cnt,cnt2;
int end[100010];
int end2[100010];
struct point b[100010];
bool cmp(struct point x,struct point y)
{
	return x.l<y.l;
}
int main()
{
	freopen("airport.in","h",stdin);
	freopen("airport.out","w",stdout);
	cin>>n>>m1>>m2;
	for(int i=1;i<=m1;i++)
		cin>>a[i].l>>a[i].r;
	for(int i=1;i<=m2;i++)
		cin>>b[i].l>>b[i].r;
	sort(a+1,a+m1+1,cmp);
	sort(b+1,b+m2+1,cmp);
	for(int k=0;k<=n;k++)
	{
		cnt=0;
		cnt2=0;
		ans1=0;
		ans2=0;
		for(int i=1;i<=m1;i++)
		{
			if(cnt<k)	
			{
				cnt++;
				end[cnt]=a[i].r;
				ans1++;
			}
			else 
			{
			for(int j=1;j<=cnt;j++)
			{
				if(end[j]<=a[i].l)
				{
					end[j]=a[i].r;
					ans1++;
					break;
				}
			
			}
			}
		} 
		
		for(int i=1;i<=m2;i++)
		{
			if(cnt2<n-k)	
			{
				cnt2++; 
				end2[cnt2]=b[i].r;
				ans2++;
			}
			else 
			{
				for(int j=1;j<=cnt2;j++)
				{
					if(end2[j]<=b[i].l)
					{
						end2[j]=b[i].r;
						ans2++;
						break;
					}
				}
			}
		}
		
		if(ans1+ans2>mxx)
		{
			mxx=ans1+ans2;
		}
	}
	cout<<mxx;
	return 0;
 } 
