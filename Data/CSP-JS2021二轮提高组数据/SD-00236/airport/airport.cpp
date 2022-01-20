#include <cstdio>
#include <algorithm>
#include <cmath>
#include <queue>
using namespace std;
const int N=100010;
typedef pair<int,int> PII;
struct pln
{ int s,t,p; }a[N],b[N];
int n,m1,m2,cnt,c1[N],c2[N];
priority_queue<PII,vector<PII>,greater<PII> > H1,H2;
bool cmp(const pln& a,const pln& b)
{ return a.s<b.s; }
inline int lowbit(int x)
{ return x&(-x); }
void add1(int pos,int val)
{
	for(int i=pos;i<=m1;i+=lowbit(i))
		c1[i]+=val;
}
void add2(int pos,int val)
{
	for(int i=pos;i<=m2;i+=lowbit(i))
		c2[i]+=val;
}
int q1(int pos)
{
	int sum=0;
	for(int i=pos;i>0;i-=lowbit(i))
		sum+=c1[i];
	return sum;
}
int q2(int pos)
{
	int sum=0;
	for(int i=pos;i>0;i-=lowbit(i))
		sum+=c2[i];
	return sum;
}
int main()
{
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	scanf("%d%d%d",&n,&m1,&m2);
	for(int i=1;i<=m1;i++)
		scanf("%d%d",&a[i].s,&a[i].t);
	for(int i=1;i<=m2;i++)
		scanf("%d%d",&b[i].s,&b[i].t);
	sort(a+1,a+m1+1,cmp);
	sort(b+1,b+m2+1,cmp);
	for(int i=1;i<=m1;i++)
	{
		a[i].p=H1.size()+1;
		while(!H1.empty()&&(H1.top()).first<=a[i].s)
		{
			PII tmp=H1.top();
			a[i].p=min(a[i].p,tmp.second);
			H1.pop();
		}
		if(H1.empty())
			a[i].p=1;
		H1.push(make_pair(a[i].t,a[i].p));
		printf("%d\n",a[i].p);
		add1(a[i].p,1);
	}
	for(int i=1;i<=m2;i++)
	{
		b[i].p=H2.size()+1;
		while(!H2.empty()&&(H2.top()).first<=b[i].s)
		{
			PII tmp=H2.top();
			b[i].p=min(b[i].p,tmp.second);
			H2.pop();
		}
		if(H2.empty())
			b[i].p=1;
		H2.push(make_pair(b[i].t,b[i].p));
		printf("%d\n",b[i].p);
		add2(b[i].p,1);
	}
	//printf("_____________\n\n");
	//for(int i=0;i<=n;i++)
	//	printf("[%d] [%d]\n",q1(i),q2(n-i));
	//printf("_____________\n\n");
	for(int i=0;i<=n;i++)
		cnt=max(cnt,q1(i)+q2(n-i));
	printf("%d\n",cnt);
	fclose(stdin);
	fclose(stdout);
	return 0;
}

/*
7 10 10
1 2
2 3
3 4
4 5
5 6
6 9
7 8
8 9
9 10
10 11
1 27
1 2
2 3
3 4
4 5
5 6
6 7
7 8
8 10
7 10
*/
