#include<iostream>
#include<cstdio>
#include<cctype>
#include<cstring>
#include<algorithm>
#include<cstdlib>
#include<vector>
#include<map>
#include<queue>
#define N 50005
using namespace std;
template <class T> void read(T&x)
{
	int w=0;
	x=0;
	char g=getchar();
	while(!isdigit(g))
	{
		w=(g=='-');
		g=getchar();
	}
	while(isdigit(g))
	{
		x=(x<<3)+(x<<1)+(g xor 48);
		g=getchar();
	}
	x=w?-x:x;
	return ;
}
int n,m1,m2,ans,sum,c1,c2;
struct Mes{
	int in,ot;
	bool operator<(const Mes &a)const{
		return ot>a.ot;
	}
}mes1[N],mes2[N]; 
bool cmp(const Mes &a,const Mes &b)
{
	return a.in<b.in;
}
void solve()
{
	for(c1=0;c1<=n;c1++)
	{
		sum=0;
		c2=n-c1;
		priority_queue< Mes >q1,q2;
		if(c1)
		for(int i=1;i<=m1;i++)
		{
			if(q1.size()<c1)
			{
			q1.push(mes1[i]);sum++;
//			printf("%d\n",mes1[i][1]);
			}
			else
			{
				int t;
				if(q1.empty()) t=0;
				else {
				t=q1.top().ot;
				}
				while(t<mes1[i].in&&!q1.empty())
				{
//					printf("%d\n",q1.top());
					t=q1.top().ot;
					if(t<mes1[i].in)
					q1.pop();
					if(q1.empty()) break;
				}
				if(q1.size()>=c1) continue ;
				q1.push(mes1[i]);sum++;
			}
		}
		if(c2)
		for(int i=1;i<=m2;i++)
		{
			if(q2.size()<c2)
			{
			q2.push(mes2[i]);sum++;
//			printf("%d\n",mes1[i][1]);
			}
			else
			{
				int t;
				if(q2.empty()) t=0;
				else {
				t=q2.top().ot;
				}
				while(t<mes2[i].in&&!q2.empty())
				{
//					printf("%d\n",q1.top());
					t=q2.top().ot;
					if(t<mes2[i].in)
					q2.pop();
					if(q2.empty()) break;
				}
				if(q2.size()>=c2) continue ;
				q2.push(mes2[i]);sum++;
			}
		}
		ans=max(ans,sum);
	}
}
int main()
{
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);	
	read(n);read(m1);read(m2);
	for(int i=1;i<=m1;i++)
	{
		read(mes1[i].in);read(mes1[i].ot);
	}
	sort(mes1+1,mes1+1+n,cmp);
	for(int i=1;i<=m2;i++)
	{
		read(mes2[i].in);read(mes2[i].ot);
	}
	sort(mes2+1,mes2+1+n,cmp);
	solve();
	printf("%d\n",ans);
	return 0;
} 
