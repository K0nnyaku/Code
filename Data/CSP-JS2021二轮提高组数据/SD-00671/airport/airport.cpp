#include<iostream>
#include<cstdio>
#include<set>
#include<algorithm>
using namespace std;
inline int read()
{
	int x=0;
	char c=getchar();
	while(c<'0'||c>'9') c=getchar();
	while('0'<=c&&c<='9')
	{
		x=(x<<1)+(x<<3)+c-'0';
		c=getchar();
	}
	return x;
}
struct pa
{
	int _1,_2,id;
	pa(int _11,int _22,int _id)
	{
		_1=_11;
		_2=_22;
		id=_id;
	}
};
bool operator < (pa x,pa y)
{
	
	return x._1>y._1;
}
set<pa> s1;
set<pa> s2;
set<pa>::iterator t;
int n,m1,m2,num,gnk,gjk,ans;
pair<int,int> g1[100005],g2[100005];
pair<int,int> gn[100005],gj[100005];
int tgn[100005],tgj[100005];
int main()
{
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	n=read(),m1=read(),m2=read();
	int a,b;
	for(int i=1;i<=m1;i++)
	{
		a=read(),b=read();
		g1[i]=make_pair(a,b);
	}
	for(int i=1;i<=m2;i++)
	{
		a=read(),b=read();
		g2[i]=make_pair(a,b);
	}
	sort(g1+1,g1+1+m1);
	sort(g2+1,g2+1+m2);
	for(int i=1;i<=m1;i++)
	{
		a=g1[i].first,b=g1[i].second;
		t=s1.lower_bound(pa(a,1,1));
		if(t==s1.end())
		{
			num++;
			if(num<=n) s1.insert(pa(b,1,num));
		}
		else
		{
			int tmp=(*t)._2;
			int tid=(*t).id;
			s1.erase(t);
			s1.insert(pa(b,tmp+1,tid));
		}
	}
	for(t=s1.begin();t!=s1.end();t++)
	{
		gn[++gnk]=make_pair((*t).id,(*t)._2);
	}
	sort(gn+1,gn+1+gnk);
	for(int i=1;i<=gnk;i++)
	{
		tgn[i]=tgn[i-1]+gn[i].second;
	}
	num=0;
	for(int i=1;i<=m2;i++)
	{
		a=g2[i].first,b=g2[i].second;
		t=s2.lower_bound(pa(a,1,1));
		if(t==s2.end())
		{
			num++;
			if(num<=n) s2.insert(pa(b,1,num));
		}
		else
		{
			int tmp=(*t)._2;
			int tid=(*t).id;
			s2.erase(t);
			s2.insert(pa(b,tmp+1,tid));
		}
	}
	for(t=s2.begin();t!=s2.end();t++)
	{
		gj[++gjk]=make_pair((*t).id,(*t)._2);
	}
	sort(gj+1,gj+1+gjk);
	for(int i=1;i<=gjk;i++)
	{
		tgj[i]=tgj[i-1]+gj[i].second;
	}
	for(int i=0;i<=n;i++)
	{
		int tm=tgn[i]+tgj[n-i];
		if(tm>ans) ans=tm;
	}
	cout<<ans;
	return 0;
}
