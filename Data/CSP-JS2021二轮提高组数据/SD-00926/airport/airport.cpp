#include<bits/stdc++.h>
#define x first
#define y second
using namespace std;
const int N=1000100;
pair<int,int> a[N],b[N];
int n,m1,m2;

int main()
{
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	cin>>n>>m1>>m2;
	for(int i=1;i<=m1;i++)
	{
		cin>>a[i].x>>a[i].y;
	}
	for(int i=1;i<=m2;i++)
	{
		cin>>b[i].x>>b[i].y;
	}
	sort(a+1,a+1+m1);
	sort(b+1,b+1+m2);
	int ans=0;
	for(int len=1;len<=n;len++)
	{
		int cnt=1;
		int flag1=m1,flag2=m2;
		int l=a[1].y;
		int sec=a[1].y;
		for(int i=1;i<=m1;i++)
		{
			if(i==1)continue;
			if(a[i].x>l)
			{
				if(a[i].y<sec)
				{
					l=a[i].y;
				}
				else 
				{

					int t=sec;
					sec=a[i].y;
					l=t;
				}
			}
			else
			{
				if(cnt>len)
				{
				flag1--;
				continue;
				}
				cnt++;
				if(l>a[i].y)
				{
					l=a[i].y;
				}
				else
				{
					int t=sec;
					sec=a[i].y;
					l=t;
				}
			}
			if(cnt>len)
			{
				flag1--;
				continue;
			}
		}
		int cnt1=1;
		l=b[1].y,sec=b[1].y;
 		for(int i=1;i<=m2;i++)
		{
			if(i==1)continue;
			if(b[i].x>l)
			{
				if(b[i].y<sec)
				{
					l=b[i].y;
				}
				else
				{	
					int t=sec;
					sec=b[i].y;
					l=t;
				}
			}
			else
			{
 				cnt1++;  
				 if(cnt1>n-len)
				{
				flag2--;
				continue;
				}      
				if(l>a[i].y)
				{
					l=b[i].y;
				}
				else
				{
					int t=sec;
					sec=b[i].y;
					l=t;
				}
			}
		}
		ans=max(ans,flag2+flag1);
	}
	cout<<ans<<endl;
}                       
