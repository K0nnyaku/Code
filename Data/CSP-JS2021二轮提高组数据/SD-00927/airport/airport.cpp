#include<cstdio>
#include<iostream>
#include<cstring>
#include<map>
#include<vector>
#include<queue>
#include<cmath>
#include<algorithm>
#define ll long long
#define fi first
#define se second
#define pii pair<int,int>
#define mp(a,b) make_pair(a,b)
using namespace std;

void read (int &x)
{
	x=0;int fl=1;
	char ch=getchar();
	while(ch<'0'||ch>'9') {if(ch=='-') fl=-1;ch=getchar();}
	while(ch<='9'&&ch>='0') x=x*10+ch-'0',ch=getchar();
	x*=fl;
}
void read (ll &x)
{
	x=0;ll fl=1;
	char ch=getchar();
	while(ch<'0'||ch>'9') {if(ch=='-') fl=-1;ch=getchar();}
	while(ch<='9'&&ch>='0') x=x*10+ch-'0',ch=getchar();
	x*=fl;
}

const int N=2e5+50;
struct air
{
	int L,id,R,flag,now;//flag=0 l,flag=1 r
}a1[N],a2[N];
bool cmp(air A,air B)
{
	return A.now<B.now;
}
int vis1[N],vis2[N];
int ans=0;
int n,m1,m2;
void init()
{
	int now=0;
	priority_queue<int,vector<int>,greater<int> > q; 
	while(!q.empty()) q.pop();
	for(int i=1;i<=m1*2;i++)
	{
		if(a1[i].flag==0)
		{
			if(q.empty())
			{
				int u=++now;
				vis1[a1[i].id]=u;
			}
			else 
			{
				int u=q.top();
				q.pop();
				vis1[a1[i].id]=u;
			}
		}
		else if(a1[i].flag==1)
		{
			int u=vis1[a1[i].id];
			q.push(u);
		}
	}
	while(!q.empty()) q.pop();
	now=0;
	for(int i=1;i<=m2*2;i++)
	{
		if(a2[i].flag==0)
		{
			if(q.empty())
			{
				int u=++now;
				vis2[a2[i].id]=u;
			}
			else 
			{
				int u=q.top();
				q.pop();
				vis2[a2[i].id]=u;
			}
		}
		else if(a2[i].flag==1)
		{
			int u=vis2[a2[i].id];
			q.push(u);
		}
	}

}
struct UPS
{
	int c[N];
	int lowbit(int x) {return x&(-x);}
	void add(int x,int k){ while(x<=n){ c[x]++;x+=lowbit(x);}}
	int query(int x){int res=0;while(x>0){res+=c[x]; x-=lowbit(x);} return res;}
}T1,T2;
int f1[N],f2[N];
int main()
{
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	scanf("%d%d%d",&n,&m1,&m2);
	
	for(int i=1;i<=m1;i++)
	{
		int al,ar;
		read(al),read(ar);
		//cout<<al<<" "<<ar<<std::endl;
		a1[i].L=al,a1[i].now=al,a1[i].flag=0,a1[i].id=i;
		a1[i+m1].R=ar,a1[i+m1].now=ar,a1[i+m1].flag=1,a1[i+m1].id=i; 
	}
	for(int i=1;i<=m2;i++)
	{
		int al,ar;
		read(al),read(ar);
		a2[i].L=al,a2[i].now=al,a2[i].flag=0,a2[i].id=i;
		a2[i+m2].R=ar,a2[i+m2].now=ar,a2[i+m2].flag=1,a2[i+m2].id=i; 
	}
	std::sort(a1+1,a1+1+2*m1,cmp);
	std::sort(a2+1,a2+1+2*m2,cmp);
	init();
	for(int i=1;i<=m1;i++) T1.add(vis1[i],1);
	for(int i=1;i<=m2;i++) T2.add(vis2[i],1);
	for(int i=0;i<=n;i++) f1[i]=T1.query(i);
	for(int i=0;i<=n;i++) f2[i]=T2.query(i);
	for(int i=0;i<=n;i++)
	ans=max(ans,f1[i]+f2[n-i]);
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
}
