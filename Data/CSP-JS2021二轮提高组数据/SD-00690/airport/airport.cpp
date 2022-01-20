#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
struct airplane
{
	int a,b;
	bool operator <(const airplane &other) const
	{
		return a<other.a;
	}
}p1[100001],p2[100001];
struct element
{
	int val,t;
	bool operator <(const element &other) const 
	{
		return val>other.val;
	}
};
int ans,n,m1,m2,node[100005<<1],cnt,sum[100005][2];
vector<int> tag[100005<<1];
priority_queue<element> q;
inline int read()
{
	int x=0;
	char c=getchar();
	while(c<'0'||c>'9')
		c=getchar();
	while(c>='0'&&c<='9')
	{
		x=(x<<1)+(x<<3)+(c^48);
		c=getchar();
	}
	return x;
}
int main()
{
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	n=read(),m1=read(),m2=read();
	for(int i=1;i<=m1;++i)
	{
		node[++cnt]=p1[i].a=read();
		node[++cnt]=p1[i].b=read();
	}
	for(int i=1;i<=m2;++i)
	{
		node[++cnt]=p2[i].a=read();
		node[++cnt]=p2[i].b=read();
	}
	sort(node+1,node+cnt+1);
	cnt=unique(node+1,node+cnt+1)-node-1;
	sort(p1+1,p1+m1+1);
	sort(p2+1,p2+m2+1);
	for(int i=1;i<=m1;++i)
	{
		p1[i].a=lower_bound(node+1,node+cnt+1,p1[i].a)-node;
		p1[i].b=lower_bound(node+1,node+cnt+1,p1[i].b)-node;
	}
	int tot=0,pos=1;
	for(int i=1;i<=m1;++i)
	{
		while(pos<p1[i].a)
		{
			for(int i:tag[pos])
				q.push({i,pos});
			++pos;
		}
		if(q.empty())
		{
			++tot;
			++sum[tot][0];
			tag[p1[i].b].push_back(tot);
		}
		else
		{
			++sum[q.top().val][0];
			tag[p1[i].b].push_back(q.top().val);
			q.pop();
		}
	}
	while(!q.empty())
		q.pop();
	for(int i=1;i<=cnt;++i)
		tag[i].clear();
	tot=0;
	pos=1;
	for(int i=1;i<=m2;++i)
	{
		p2[i].a=lower_bound(node+1,node+cnt+1,p2[i].a)-node;
		p2[i].b=lower_bound(node+1,node+cnt+1,p2[i].b)-node;
	}
	for(int i=1;i<=m2;++i)
	{
		while(pos<p2[i].a)
		{
			for(int i:tag[pos])
				q.push({i,pos});
			++pos;
		}
		if(q.empty())
		{
			++tot;
			++sum[tot][1];
			tag[p2[i].b].push_back(tot);
		}
		else
		{
			++sum[q.top().val][1];
			tag[p2[i].b].push_back(q.top().val);
			q.pop();
		}
	}
	for(int i=1;i<=n;++i)
	{
		sum[i][0]+=sum[i-1][0];
		sum[i][1]+=sum[i-1][1];
	}
	for(int i=0;i<=n;++i)
		ans=max(ans,sum[i][0]+sum[n-i][1]);
	printf("%d\n",ans);
	return 0;
}
