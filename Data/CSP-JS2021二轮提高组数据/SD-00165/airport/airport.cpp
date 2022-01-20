#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
inline int read()
{
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
struct Node
{
	int a,b;
}guonei[100010],guowai[100010];
int ans,n,m1,m2;
int cmp(Node x,Node y)
{
	return x.a<y.a;
}
int main()
{
	freopen("airport.in","r",stdin); 
	freopen("airport.out","w",stdout);
	n=read(),m1=read(),m2=read();
	for(int i=1;i<=m1;i++)
	{
		guonei[i].a=read();
		guonei[i].b=read(); 
	}
	for(int i=1;i<=m2;i++)
	{
		guowai[i].a=read();
		guowai[i].b=read();
	}
	sort(guonei+1,guonei+1+m1,cmp);
	sort(guowai+1,guowai+1+m2,cmp);
	for(int i=0;i<=n;i++)
	{
		int j=n-i,num=0;
		priority_queue<int,vector<int>,greater<int> >q1;
		priority_queue<int,vector<int>,greater<int> >q2;
		for(int k=1;k<=m1;k++)
		{
			if(q1.empty()&&i!=0)
			{
				num++;
				q1.push(guonei[k].b);
			}
			else
			{
				while(!q1.empty()&&q1.top()<guonei[k].a)
				{
					q1.pop();
				}
				if(q1.size()<i)
				{
					num++;
					q1.push(guonei[k].b);
				}
			}
		}
		for(int k=1;k<=m2;k++)
		{
			if(q2.empty()&&j!=0)
			{
				num++;
				q2.push(guowai[k].b);
			}
			else
			{
				while(!q2.empty()&&q2.top()<guowai[k].a)
				{
					q2.pop();
				}
				if(q2.size()<j)
				{
					num++;
					q2.push(guowai[k].b);
				}
			}
		}
		ans=max(ans,num);
	}
	printf("%d",ans);
	return 0;
} 
