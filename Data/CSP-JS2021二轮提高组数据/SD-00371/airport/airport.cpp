#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<queue>

using namespace std;

int n,ma,mb;
struct qwq{
	int co,le;
};

inline bool cmp(qwq a,qwq b)
{
	return a.co<b.co;
}

qwq a[100010],b[100010];
int res=0,ans=-0x3f3f3f;

int main()
{
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	scanf("%d%d%d",&n,&ma,&mb);
	for(int i=1;i<=ma;i++)
		scanf("%d%d",&a[i].co,&a[i].le);
	for(int i=1;i<=mb;i++)
		scanf("%d%d",&b[i].co,&b[i].le);
	sort(a+1,a+ma+1,cmp);
	sort(b+1,b+mb+1,cmp);
	
	for(int i=0;i<=n;i++)
	{
		int cnt1=0,cnt2=0;
		int j=n-i;
		bool flag1=true,flag2=true;
		if(i==0) cnt1=0,flag1=false;
		if(j==0) cnt2=0,flag2=false;
		int lqa=i,lqb=j;
		priority_queue<int> q1;
		priority_queue<int> q2;
		if(flag1==true)
		{
			for(int k=1;k<=ma;k++)
			{
				if(k==1)
				{
					q1.push((-1)*a[k].le);
					cnt1++;
					lqa--;
				}
				else
				{
					if(a[k].co>(-1)*q1.top())
					{
//						if(i==2)cout << (-1)*q1.top() << endl;
//						if(i==2)cout << k << endl;
						cnt1++;
						q1.pop();
						q1.push((-1)*a[k].le);
					}
					else
					{
						if(lqa>0)
						{
							lqa--;
							cnt1++;
							q1.push((-1)*a[k].le);
						}
						else
						{
							continue;
						}
					}
				}
			}
		}
		if(flag2==true)
		{
			for(int k=1;k<=mb;k++)
			{
				if(k==1)
				{
					q2.push((-1)*b[k].le);
					cnt2++;
					lqb--;
				}
				else
				{
					if(b[k].co> (-1)*q2.top())
					{
						cnt2++;
						q2.pop();
						q2.push((-1)*b[k].le);
					}
					else
					{
						if(lqb>0)
						{
							lqb--;
							cnt2++;
							q2.push((-1)*b[k].le);
						}
						else
						{
							continue;
						}
					}
				}
			}
		}
//		cout << cnt1 << " " << cnt2 << endl;
		res=cnt1+cnt2;
		ans=max(res,ans);
	}
	cout << ans << endl;
	fclose(stdin);
	fclose(stdout);
	return 0;	
}
