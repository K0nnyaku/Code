#include<vector>
#include<algorithm>
#include<bitset>
#include<cassert>
#include<cctype>
#include<cmath>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<ctime>
#include<deque>
#include<functional>
#include<iomanip>
#include<iostream>
#include<list>
#include<map>
#include<queue>
#include<set>
#include<sstream>
#include<stack>
#include<string>
#define qr read()
#define in(x) x=read()
#define mp make_pair
#define nc getchar
#define int ll
#define y0 ccf
#define y1 moe
#define ps wxj
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
inline ll read()
{
	char ch=' ';
	int f=1;
	ll x=0;
	for(;!isdigit(ch);ch=nc())if(ch=='-')f*=-1;
	for(;isdigit(ch);ch=nc())x=x*10+ch-'0';
	return f*x;
}
#define mod 1000000007
int f[1010][1010],g[1010][1010],n,k,h[1010][1010];
char s[1000010];
int dfs2(int l,int r);
int dfs3(int l,int r);
int dfs1(int l,int r)
{
	if(l>=r)return 0;
	if(s[l]=='*'||s[r]=='*'||s[l]==')'||s[r]=='(')return 0;
	if(f[l][r]!=-1)return f[l][r];
	int ans=0;
	if((s[l]=='('||s[l]=='?')&&(s[r]=='?'||s[r]==')'))ans+=dfs1(l+1,r-1)+dfs2(l+1,r-1),ans%=mod;
	for(int i=l+1;i<=r-1;i++)
	{
		if(s[i]==')'||s[i]=='?')
		{
			int lv=(dfs1(l+1,i-1)+dfs2(l+1,i-1))%mod;
			int rv=(dfs1(i+1,r)+dfs3(i+1,r))%mod;
//			cout<<l<<"~"<<r<<":"<<i<<","<<lv<<','<<rv<<'\n';
			ans+=lv*rv,ans%=mod;
		}
	}
//	cout<<"dfs1:"<<l<<' '<<r<<":"<<ans<<'\n';
	return f[l][r]=ans;
}
int dfs2(int l,int r)
{
	if(l==r+1)return 1;
	if(l>r)return 0;
	if(s[l]==')'||s[r]=='(')return 0;
	if(g[l][r]!=-1)return g[l][r];
	int h=1,ans=0;
	for(int i=l;i<=r;i++)
	{
		if(s[i]=='('||s[i]==')')h=0;
	}
	if(h&&r-l+1<=k)ans++;
	for(int i=l;i<=r-1&&i-l+1<=k;i++)
	{
		if(s[i]!='*'&&s[i]!='?')break;
		ans+=dfs1(i+1,r),ans%=mod;
	}
	for(int i=r;i>=l+1&&r-i+1<=k;i--)
	{
		if(s[i]!='*'&&s[i]!='?')break;
		ans+=dfs1(l,i-1),ans%=mod;
	}
//	cout<<"dfs2:"<<l<<' '<<r<<":"<<ans<<'\n';
	return g[l][r]=ans;
}
int dfs3(int l,int r)
{
	if(l>r)return 0;
	if(s[l]==')'||s[r]=='(')return 0;
	if(h[l][r]!=-1)return h[l][r];
	int ans=0;
	for(int i=l;i<=r-1&&i-l+1<=k;i++)
	{
		if(s[i]!='*'&&s[i]!='?')break;
		int v=dfs1(i+1,r);
	//	cout<<"dfs3:"<<l<<"~"<<r<<":"<<i+1<<"~"<<r<<":"<<v<<'\n';
		ans+=v,ans%=mod;
	}
	return h[l][r]=ans;
}
signed main()
{
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	memset(f,-1,sizeof(f));
	memset(g,-1,sizeof(g));
	memset(h,-1,sizeof(h));
	n=qr,k=qr;
	char ch=nc();
	for(;ch!='*'&&ch!='('&&ch!=')'&&ch!='?';ch=nc());
	for(int i=1;i<=n;i++,ch=nc())s[i]=ch;
	cout<<dfs1(1,n);
	return 0;
}
//真合法（f）： 
//1.去括号 ->真合法 
//2.两边没有* 拆左侧() ->左、右假合法/真合法 (右侧假合法：*靠左，h)
//3.去括号 ->假合法
//假合法：（真合法的括号内，g）
//1. 全*/空
//2.左侧* ->右真合法
//3.右侧* ->左真合法
