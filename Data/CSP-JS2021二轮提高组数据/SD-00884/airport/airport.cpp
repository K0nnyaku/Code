#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <queue>
using namespace std;
#define int long long
#define rep(i,x,y) for(int i=x;i<=y;i++)
#define _rep(i,x,y) for(int i=x;i>=y;i--)
#define N 200010
const int inf=1e18;
int read()
{
	int num=0,fu=1; char c;
	while((c>'9'||c<'0')&&c!='-') c=getchar();
	if(c=='-') fu=-1,c=getchar();
	while(c>='0'&&c<='9') num=(num<<3)+(num<<1)+(c^48),c=getchar();
	return fu*num;
}

struct node{
	int st,ed;
}a[N],b[N];

bool cmp(node n1,node n2) {return n1.st<n2.st;}

int n,m1,m2,ans,s,f1[N],f2[N],nxt1[N],nxt2[N],pre1[N],pre2[N];

priority_queue<int> q; 

void zdc()
{
	rep(k,0,n)
	{
		int amt=0; int res=0; while(!q.empty()) q.pop();
		rep(i,1,m1)
		{
			int mn=0;
			if(!q.empty()) {mn=-1ll*q.top(); q.pop();}
			if(mn&&a[i].st>mn) q.push(-1ll*a[i].ed),res++;
			else 
			{
				if(mn) q.push(-1ll*mn);
				if(amt<k) amt++,q.push(-1ll*a[i].ed),res++;
			}
		}
		amt=0; while(!q.empty()) q.pop();
		rep(i,1,m2)
		{
			int mn=0;
			if(!q.empty()) {mn=-1ll*q.top(); q.pop();}
			if(mn&&b[i].st>mn) q.push(-1ll*b[i].ed),res++;
			else 
			{
				if(mn) q.push(-1ll*mn);
				if(amt<n-k) amt++,q.push(-1ll*b[i].ed),res++;
			}
		}
		ans=max(res,ans);
	}
	printf("%lld\n",ans);
}


signed main()
{
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	n=read(); m1=read(); m2=read();
	rep(i,1,m1) a[i].st=read(),a[i].ed=read(),nxt1[i]=i+1,pre1[i]=i-1;
	rep(i,1,m2) b[i].st=read(),b[i].ed=read(),nxt2[i]=i+1,pre2[i]=i-1;
	sort(a+1,a+1+m1,cmp); sort(b+1,b+1+m2,cmp);
	if(n<=5000) {zdc(); return 0;}
	s=1;
	rep(k,1,n)
	{
		int lst=0,res=0;
		for(int i=s;i<=m1;i=nxt1[i])
		{
			if(a[i].st>lst) 
			{
				lst=a[i].ed; res++;
				nxt1[pre1[i]]=nxt1[i]; pre1[nxt1[i]]=pre1[i];
			}
		}
		s=nxt1[0];
		f1[k]=f1[k-1]+res;
	}
	s=1;
	rep(k,1,n)
	{
		int lst=0,res=0;
		for(int i=s;i<=m2;i=nxt2[i])
		{
			if(b[i].st>lst) 
			{
				lst=b[i].ed; res++;
				nxt2[pre2[i]]=nxt2[i]; pre2[nxt2[i]]=pre2[i];
			}
		}
		s=nxt2[0];
		f2[k]=f2[k-1]+res;
	}	
	rep(k,0,n) ans=max(ans,f1[k]+f2[n-k]);
	printf("%lld\n",ans);
	return 0;
}
