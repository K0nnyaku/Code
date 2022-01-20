#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#include<set>
#include<vector>
#define ll long long
#define ull unsigned long long
#define next nxt
#define maxn 100100

using namespace std;

int n,M1,M2,ans,n1,n2,cnt1,cnt2,inq1[maxn],inq2[maxn],now1,now2;

template<typename type>
inline void read(type &x)
{
	x=0;bool flag(0);char ch=getchar();
	while(!isdigit(ch)) flag^=ch=='-',ch=getchar();
	while(isdigit(ch)) x=(x<<1)+(x<<3)+(ch^48),ch=getchar();
	flag?x=-x:0;
}

template<typename type>
inline void write(type x,bool mode)
{
	x<0?x=-x,putchar('-'):0;static short Stack[50],top(0);
	do Stack[++top]=x%10,x/=10;while(x);
	while(top) putchar(Stack[top--]|48);
	mode?putchar('\n'):putchar(' '); 
}

struct node{
	int a,b,index;
}m1[maxn],m2[maxn];

//inline bool comp1(node x,node y)
//{
//	return x.b<y.b; 
//}

inline bool comp(node x,node y)
{
	return x.a<y.a; 
}

bool operator <(node x,node y)
{
	return x.b<y.b;
}

bool operator >(node x,node y)
{
	return x.b>y.b;
}
//
//bool operator <(node x,int y)
//{
//	return x.b<y;
//}
//
//bool operator >(node x,int y)
//{
//	return x.b>y;
//}

queue<node>q1,q2;
//priority_queue<node,vector<int>,greater<int> >b1,b2;
//set<node>b1,b2;

struct heap{
	int n;
	node t[maxn];
	inline void push(node x)
	{
		t[++n]=x;
		swap(t[1],t[n]);
		for(int i=n;i>=1;i>>=1)
		{
			int s=(i+1)>>1;
			if(s&&t[s]<t[s+1]) s++;
			if(s&&t[s]>t[i]) swap(t[i],t[s]),i=s;
			else return;
		}
	}
	inline void pop()
	{
		swap(t[1],t[n]);
		n--;
		for(int i=1;i<=n;i<<=1)
		{
			int s=i<<1;
			if(s+1<=n&&t[s]>t[s+1]) s++;
			if(s<=n&&t[i]>t[s]) swap(t[i],t[s]),i=s;
			else return;
		}
	}
	node top()
	{
		return t[1];
	}
	inline bool empty()
	{
		return n?0:1;
	}
	inline int size()
	{
		return n;
	}
	inline void del()
	{
		n=0;
		memset(t,0,sizeof(t));
	}
}b1,b2;

signed main()
{
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	read(n),read(M1),read(M2);
	for(int i=1;i<=M1;i++) read(m1[i].a),read(m1[i].b);
	for(int i=1;i<=M2;i++) read(m2[i].a),read(m2[i].b);
//	sort(m1+1,m1+M1+1,comp1);
	sort(m1+1,m1+M1+1,comp);
//	sort(m2+1,m2+M2+1,comp1);
	sort(m2+1,m2+M2+1,comp);
	for(int i=1;i<=M1;i++) m1[i].index=i;
	for(int i=1;i<=M2;i++) m2[i].index=i;
	for(int i=0;i<=n;i++)//国内航班分配个数 
	{
		cnt1=cnt2=now1=now2=0;
		while(!q1.empty()) q1.pop();
		while(!q2.empty()) q2.pop();
		b1.del(),b2.del();
		memset(inq1,0,sizeof(inq1));
		memset(inq2,0,sizeof(inq2));
		n1=i,n2=n-i;
		for(int j=1;j<=M1;j++)
		{
			while(b1.size()&&(b1.top().b<now1 || (!inq1[b1.top().index]))) inq1[b1.top().index]=0,b1.pop();
			if(q1.size() && (!inq1[q1.front().index])) q1.pop();
			if(q1.size()<n1) q1.push(m1[j]),b1.push(m1[j]),cnt1++,inq1[j]=1,now1=m1[j].a;
			else if(q1.front().b<=m1[j].a) inq1[q1.front().index]=0,q1.pop(),q1.push(m1[j]),b1.push(m1[j]),cnt1++,inq1[j]=1,now1=m1[j].a;
			else if(q1.front().b>m1[j].a) now1=q1.front().b;
		}
		for(int j=1;j<=M2;j++)
		{
			while(b2.size()&&(b2.top().b<now2 || (!inq1[b1.top().index]))) inq2[b2.top().index]=0,b2.pop();
			if(q2.size() && !inq2[q2.front().index]) q2.pop();
			if(q2.size()<n2) q2.push(m2[j]),b2.push(m2[j]),cnt2++,inq2[j]=1,now2=m2[j].a;
			else if(q2.front().b<=m2[j].a) inq1[q1.front().index]=0,q2.pop(),q2.push(m2[j]),b2.push(m2[j]),cnt2++,inq2[j]=1,now2=m2[j].a;
			else if(q2.front().b>m2[j].a) now2=q2.front().b;
		}
		ans=max(ans,cnt1+cnt2);
	}
	write(ans,1);
	return 0;
}

/*
1.in

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
考虑用一个队列q维护廊桥的占用情况，一个优先队列b维护飞机的时效情况(离开时间) ,用数组inq维护元素是否仍在队列q中 
首先，利用b排除q中已失效的元素
若现在时间(q中飞机到达时间取max)大于离开时间(b的队头)，则inq[b.top().index]=0,b.pop() 
若inq[q.front().index]=0,则q.pop() 
然后，考虑加入新元素
若q.size()&&q.size()<n
那么直接q.push() 

*/









