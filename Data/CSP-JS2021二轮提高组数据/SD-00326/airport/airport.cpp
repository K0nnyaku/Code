#include<iostream>
#include<cstring>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<cstdlib>
#include<queue>
using namespace std;
int n,m1_,m2_,ans,ans_=-1919810;
struct qwq{
	int a,b;
};
qwq m1__[100005];
qwq m2__[100005];
priority_queue<int,vector<int>,greater <int> > q1;
priority_queue<int,vector<int>,greater <int> > q2;
bool cmp(qwq myk,qwq tql)
{
	return myk.a<tql.a;
}
int main()
{
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	scanf("%d%d%d",&n,&m1_,&m2_);
	for(int i=1;i<=m1_;i++)
		scanf("%d%d",&m1__[i].a,&m1__[i].b);
	for(int i=1;i<=m2_;i++)
		scanf("%d%d",&m2__[i].a,&m2__[i].b);
	sort(m1__,m1__+m1_+1,cmp);
	sort(m2__,m2__+m2_+1,cmp);
	for(int i=0;i<=n;i++)
	{
		ans=0;
		int cnt1=0,cnt2=0;
		while(!q1.empty()) q1.pop();
		while(!q2.empty()) q2.pop(); 
		if(i)
		{
			while(q1.size()<i and cnt1<=m1_)
			{
				ans++;
				cnt1++;
				if(!q1.empty() and m1__[cnt1].a >= q1.top() )
				{
					q1.pop();
					q1.push(m1__[cnt1].b);
					continue;
				}
				q1.push(m1__[cnt1].b);
			}
		}
		if(n-i){
			while(q2.size()<(n-i) and cnt2<=m2_)
			{
				ans++;
				cnt2++;
				if(!q2.empty() and m2__[cnt2].a>=q2.top())
				{
					q2.pop();
					q2.push(m2__[cnt2].b);
					continue;
				}
				q2.push(m2__[cnt2].b);
			}
		}
		if(i)
		{
			for(int j=cnt1+1;j<=m1_;j++)
			{
				int t1=q1.top();
				if(q1.size()<i)
				{
					q1.push(m1__[j].b);
					ans++;
					continue;
				}
				if(m1__[j].a>=t1) 
				{
					q1.pop();
					q1.push(m1__[j].b);
					ans++;
				} 
			}
		}
		if(n-i)
		{
			for(int j=cnt2+1;j<=m2_;j++)
			{
				int t2=q2.top();
				if(q2.size()<(n-i))
				{
					q2.push(m2__[j].b);
					ans++;
					continue;
				}
				if(m2__[j].a>=t2)
				{
					q2.pop();
					q2.push(m2__[j].b);
					ans++;
				}
			}	
		}
		ans_=max(ans_,ans);
	}
	cout<<ans_<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
