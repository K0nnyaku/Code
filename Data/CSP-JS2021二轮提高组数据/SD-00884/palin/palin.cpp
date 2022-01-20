#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
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

int T,n,l,r,a[N],b[N],ans[N];
bool flag=0;

void dfs(int x)
{
	if(flag) return;
	if(x==2*n+1)
	{
		flag=1;
		rep(i,1,n)
			if(b[i]!=b[2*n+1-i]) {flag=0; break;}
		if(flag)
		{
			rep(i,1,2*n) 
				if(ans[i]) printf("L");
				else printf("R");
			printf("\n"); 
		}
		return;
	}
	b[x]=a[l++]; ans[x]=1; dfs(x+1); l--; 
	b[x]=a[r--]; ans[x]=0; dfs(x+1); r++;
}

signed main()
{
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	T=read();
	while(T--)
	{
		n=read(); flag=0; memset(ans,0,sizeof(ans)); memset(b,0,sizeof(b));
		rep(i,1,2*n) a[i]=read();
		l=1; r=2*n;
		dfs(1);
		if(!flag) puts("-1");
	}
	return 0;
}
