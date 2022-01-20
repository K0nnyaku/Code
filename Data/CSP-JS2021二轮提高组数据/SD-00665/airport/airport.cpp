#include <bits/stdc++.h>
using namespace std;
inline int rapid_read()
{
	int x=0,minus=1;
	char ch=getchar();
	while(ch<'0'||ch>'9')
	{
		if(ch=='-')
			minus=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9')
	{
		x=(x<<1)+(x<<3)+(ch^48);
		ch=getchar();
	}
	return x*minus;
}
int n,m1,m2,ans;
struct T
{
	int a,b;
}t1[100005],t2[100005];
bool cmp(T a,T b)
{
	return a.a<b.a;
}
void dfs(int x)
{
	int y=n-x;
	int ans_=0;
//	printf("dfs(%d)\n",x);
	int x0=0,y0=0;
	priority_queue <int,vector<int>,greater<int> > qx,qy;
	if(x!=0)
	for(int i=1;i<=m1;i++)
	{
		if(qx.size()>=x)
		{
			while(t1[i].a>qx.top()&&!qx.empty())
				qx.pop();
		}
		if(qx.size()<x)
		{
			qx.push(t1[i].b);
			ans_++;
			x0++;
		}
	}
	if(y!=0)
	for(int i=1;i<=m2;i++)
	{
		if(qy.size()>=y)
		{
			while(t2[i].a>qy.top()&&!qy.empty())
				qy.pop();
		}
		if(qy.size()<y)
		{
			qy.push(t2[i].b);
			ans_++;
			y0++;
		}
	}
	ans=max(ans,ans_);
//	printf("dfs(%d) ans_=%d x0=%d y0=%d\n",x,ans_,x0,y0);
	return ;
}
int main(void)
{
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	cin>>n>>m1>>m2;
	for(int i=1;i<=m1;i++)
	{
 		t1[i].a=rapid_read();
		t1[i].b=rapid_read();
	}
	for(int i=1;i<=m2;i++)
	{
		t2[i].a=rapid_read();
		t2[i].b=rapid_read();
	}
	sort(t1+1,t1+m1+1,cmp);
	sort(t2+1,t2+m2+1,cmp);
	for(int i=0;i<=n;i++)
		dfs(i);
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
