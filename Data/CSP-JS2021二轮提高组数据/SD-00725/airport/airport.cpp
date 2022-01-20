#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <queue>
#define MAXN 200010
#define INF 0x3f3f3f3f
#define LLINF 0x3f3f3f3f3f3f3f3f
#define MOD 1000000007
#define FUP(i,x,y) for(int i=(x);i<=(y);i++)
#define FDW(i,x,y) for(int i=(x);i>=(y);i--)
#define FED(i,x) for(int i=head[x];i;i=ed[i].nxt)
#define pr pair<int,int>
#define mkp(a,b) make_pair(a,b)
#define ll long long
#define db double
using namespace std;
int read()
{
	int w=0,flg=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-'){flg=-1;}ch=getchar();}
	while(ch<='9'&&ch>='0'){w=w*10-'0'+ch,ch=getchar();}
	return w*flg;
}
const bool is_print=0;
int n,m1,m2,ans1[MAXN],ans2[MAXN],ans,re[MAXN];
int fw[MAXN];
int lbt(int x){return x&(-x);}
void update(int x,int d){for(;x<=n;x+=lbt(x))fw[x]+=d;}
int query(int x)
{
	int re=0;
	for(;x;x-=lbt(x)) re+=fw[x];
	return re;
}
struct node{
	int pos,w,id;
};
bool operator<(node x,node y)
{
	if(x.pos>y.pos) return true;
	if(x.pos<y.pos) return false;
	return x.w>y.w;
}
priority_queue<node>pq;
int main(){
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	n=read(),m1=read(),m2=read();
	FUP(i,1,m1)
	{
		node p;
		p.pos=read(),p.w=1,p.id=i;
		pq.push(p);
		p.pos=read()+1,p.w=-1,p.id=i;
		pq.push(p);
	}
	while(!pq.empty())
	{
		node p=pq.top();pq.pop();
		if(p.w==1)
		{
			int l=1,r=n,tmp=n+1;
			while(l<=r)
			{
				int mid=(l+r)>>1;
				int sum=query(mid);
				if(sum<mid) r=mid-1,tmp=mid;
				else l=mid+1;
			}
			re[p.id]=tmp,ans1[tmp]++;
			update(tmp,1);
		}
		else update(re[p.id],-1);
	}
	FUP(i,1,n) ans1[i]+=ans1[i-1];
	
	FUP(i,1,m2)
	{
		node p;
		p.pos=read(),p.w=1,p.id=i;
		pq.push(p);
		p.pos=read()+1,p.w=-1,p.id=i;
		pq.push(p);
	}
	while(!pq.empty())
	{
		node p=pq.top();pq.pop();
		if(p.w==1)
		{
			int l=1,r=n,tmp=n+1;
			while(l<=r)
			{
				int mid=(l+r)>>1;
				int sum=query(mid);
				if(sum<mid) r=mid-1,tmp=mid;
				else l=mid+1;
			}
			re[p.id]=tmp,ans2[tmp]++;
			update(tmp,1);
		}
		else update(re[p.id],-1);
	}
	FUP(i,1,n) ans2[i]+=ans2[i-1];
	FUP(i,0,n) ans=max(ans,ans1[i]+ans2[n-i]);
	printf("%d\n",ans);
	return 0;
}
