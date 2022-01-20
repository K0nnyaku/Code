#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<string>
#include<cmath>
#include<algorithm>
using namespace std;
struct plane
{
	int a,b;
};
plane t1[100000],t2[100000];
bool cmp(plane x,plane y)
{
	return x.a<y.a;
}
int main()
{
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	int n,m1,m2,i,j,e,end[100000]={},cnt,tmp,ans=0,p;
	cin>>n>>m1>>m2;
	for(i=0;i<m1;i++)cin>>t1[i].a>>t1[i].b;
	for(i=0;i<m2;i++)cin>>t2[i].a>>t2[i].b;
	sort(t1,t1+m1,cmp);
	sort(t2,t2+m2,cmp);
	for(i=max(n-m1,0);i<=min(m2,n);i++)
	{
		tmp=0;cnt=0;
		e=n-i;
		for(j=0;j<m1;j++)
		{
			if(e!=0)
			{
				e--;
				end[tmp++]=t1[j].b;
				cnt++;
			}
			else
			{
				for(p=0;p<tmp;p++)
				{
					if(end[p]<=t1[j].a)
					{
						cnt++;
						end[p]=t1[j].b;
						break;
					}
				}
			}
		}
		e=i;tmp=0;
		for(j=0;j<m2;j++)
		{
			if(e!=0)
			{
				e--;
				end[tmp++]=t2[j].b;
				cnt++;
			}
			else
			{
				for(p=0;p<tmp;p++)
				{
					if(end[p]<=t2[j].a)
					{
						cnt++;
						end[p]=t2[j].b;
						break;
					}
				}
			}
		}
		ans=max(ans,cnt);
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
