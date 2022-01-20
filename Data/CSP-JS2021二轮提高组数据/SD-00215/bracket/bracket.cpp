#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <string>
#include <cstdio>
#include <queue>
#include <map> 
using namespace std;
const int N=5e2+5,inf=1e9+7;
#define ll long long
#define db double
#define gc getchar()
#define rep(x,y,z) for(int x=y;x<=z;x++)
#define dep(x,y,z) for(int x=y;x>=z;x++)
int vis[N],vs[N],st[N],k,n;string s;ll ans;
inline int in()
{
	int f=0,g=1;char c=gc;
	while(!isdigit(c)) 
		g=g*(c=='-'?-1:1),c=gc;
	while(isdigit(c))
		f=f*10+c-'0',c=gc;
	return f*g;
} 
	bool work()
	{
	//	cout<<s<<endl;
		int tmp=0,tp=0,bl=0;int t=n;
		rep(i,0,t-1) vs[i]=vis[i]=0;
		if(s[0]=='*'||s[t-1]=='*') bl=1;
		rep(i,0,t-1)
		{
			while(s[i]!='*'&&s[i]!='('&&s[i]!=')') i++;
			if(s[i]=='*') 
			{
			//	if(tp==0) {cout<<i<<2;bl=1;break;}
				if(!vs[st[i]])vis[st[tp]]=1;
				tmp++;if(tmp>k){bl=1;break;}
			//	cout<<st[tp];
			}
			if(s[i]=='(')
			{
				rep(j,1,tp) vs[st[j]]=1;
				tmp=0,tp++;st[tp]=i;
			}
			if(s[i]==')')
			{
				if(tmp>0&&vis[st[tp]]&&vs[st[tp]]) {bl=1;break;}
				if(!tp) {bl=1;break;}
				tmp=0,tp--;
			}
		}
		if(tp) bl=1;return !bl;
	}
void dfs(int u)
{
//	cout<<u<<s<<endl;
	if(u==n) 
	{
		if(work()) ans++;
		return;
	}
	if(s[u]!='?') dfs(u+1);
	else 
	{
		s[u]='*';dfs(u+1);s[u]='?';
		s[u]='(';dfs(u+1);s[u]='?';
		s[u]=')';dfs(u+1);s[u]='?';
	}
}
int main()
{
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	cin>>n>>k>>s; 
	dfs(0);cout<<ans%inf;
	fclose(stdin);
	fclose(stdout);
	return 0; 
}
