#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;
#define int long long
#define rep(i,x,y) for(int i=x;i<=y;i++)
#define _rep(i,x,y) for(int i=x;i>=y;i--)
#define N 550
const int inf=1e18;
const int mod=1e9+7;
int read()
{
	int num=0,fu=1; char c;
	while((c>'9'||c<'0')&&c!='-') c=getchar();
	if(c=='-') fu=-1,c=getchar();
	while(c>='0'&&c<='9') num=(num<<3)+(num<<1)+(c^48),c=getchar();
	return fu*num;
}

int n,k,ans,pos[N],cnt,st[N][2],ads[N],top;

char a[N],b[N],c[N];

void dfs(int x)
{
	if(x==cnt+1)
	{
		int len=0,l,flag=1; top=0;
		if(b[1]=='*'||b[n]=='*') flag=0;
		
		rep(i,1,n)
		{
			if(b[i]=='*')
			{
				int amt=1;
				if(len) st[++top][0]=i,st[top][1]=ads[len];
				if(top>1&&st[top][1]==st[top-1][1]) flag=0;
				while(b[i+1]=='*'&&i<n) i++,amt++;
				i++;
				if(amt>k) {flag=0; break;}
			}
			if(b[i]==')'&&c[len]=='(') 
			{
				while(st[top][0]>ads[len]) top--;
				len--;
			}
			else c[++len]=b[i],ads[len]=i;
		}
		if(flag&&len==0&&top==0) 
		{
			ans++; ans%=mod;
		}
		return;
	}
	b[pos[x]]='*'; dfs(x+1);
	b[pos[x]]='('; dfs(x+1);
	b[pos[x]]=')'; dfs(x+1);
}

signed main()
{
	freopen("bracket.in","r",stdin);
	freopen("bracket.in","w",stdout);
	n=read(); k=read();
	scanf("%s",a+1);
	rep(i,1,n) if(a[i]=='?') pos[++cnt]=i;else b[i]=a[i];
	dfs(1);
	printf("%lld\n",ans);
	return 0;
}
