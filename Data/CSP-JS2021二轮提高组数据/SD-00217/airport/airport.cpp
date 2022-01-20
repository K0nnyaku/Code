#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<deque>
#include<stack>
#include<queue>
#include<vector>

using namespace std;

/*
4个队列
两个优先队列存当前在廊桥上的飞机
两个优先队列存 i 时刻来临的飞机编号 
*/
struct lzj{
	int st,fn;
};
int n,m1,m2;
lzj in[100005],out[100005];

typedef pair<int,int> Pair; 
priority_queue<Pair,vector<Pair>,greater<Pair> > v1,v2;

int ans=0;
//vector<int> c1[100005],c2[100005];//动态数组开太大运行时间长，待优化 

bool cmp(lzj x,lzj y)
{
	if(x.st!=y.st)return x.st<y.st;
	else return x.fn<y.fn;
}

Pair r1[1000005],r2[1000005];
int ct1=0,ct2=0;
priority_queue<int,vector<int>,greater<int> > pq1,pq2;//结束时间 

void solve(int s1,int s2)
{
	int tot1=0,tot2=0;
	while(!v1.empty()) 
	{
		Pair cur=v1.top();
		v1.pop();
		if(!pq1.empty())
		{
			int t=pq1.top();
			while(cur.first>=t&&!pq1.empty())
			{
				pq1.pop();
				t=pq1.top();
			}
		}
		//处理已走的飞机
		for(int i=0;i<1&&pq1.size()<s1;i++)//如果还没满 
		{
			tot1++;
			int index=cur.second;
			pq1.push(in[index].fn);
		}
	}
	//国内
	while(!v2.empty()) 
	{
		Pair cur=v2.top();
		v2.pop();
		if(!pq2.empty())
		{
			int t=pq2.top();
			while(cur.first>=t&&!pq2.empty())
			{
				pq2.pop();
				t=pq2.top();
			}
		}
		//处理已走的飞机
		for(int i=0;i<1&&pq2.size()<s2;i++)//如果还没满 
		{
			tot2++;
			int index=cur.second;
			pq2.push(out[index].fn);
		}
	}
	ans=max(ans,tot1+tot2);
	while(pq1.size())pq1.pop();
	while(pq2.size())pq2.pop(); 
	for(int i=1;i<=ct1;i++)
	{
		v1.push(r1[i]);
	}
	for(int i=1;i<=ct2;i++)
	{
		v2.push(r2[i]);
	}
	return;
	//国外 
}
int main(){
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	scanf("%d%d%d",&n,&m1,&m2);
	for(int i=1;i<=m1;i++)
	{
		scanf("%d%d",&in[i].st,&in[i].fn);
	} 
	for(int i=1;i<=m2;i++)
	{
		scanf("%d%d",&out[i].st,&out[i].fn);
	} 
	sort(in+1,in+1+m1,cmp);
	sort(out+1,out+1+m2,cmp);
	for(int i=1;i<=m1;i++)
	{
		v1.push(make_pair(in[i].st,i));//这一时刻有飞机 
		r1[++ct1].first=in[i].st;
		r1[ct1].second=i;
	}
	for(int i=1;i<=m2;i++)
	{

		v2.push(make_pair(out[i].st,i));
		r2[++ct2].first=out[i].st;
		r2[ct2].second=i;
	}
	/*for(int i=1;i<=m1;i++)
	{
		c1[in[i].st].insert(c1[in[i].st].begin()+c1[in[i].st].size(),i);
	}
	for(int i=1;i<=m2;i++)
	{
		c2[out[i].st].insert(c2[out[i].st].begin()+c2[out[i].st].size(),i);
	} */
	for(int i=0;i<=n;i++)
	{
		solve(i,n-i);
	}
	printf("%d",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
/*
3 5 4
1 5
3 8
6 10
9 14
13 18
2 11
4 15
7 17
12 16
*/
/*
2 4 6
20 30
40 50
21 22
41 42
1 19
2 18
3 4
5 6
7 8
9 10
*/
/*
cur：
动态数组ｉ表示所有在ｉ时刻到来的飞机　 
优化：
 
*/ 
