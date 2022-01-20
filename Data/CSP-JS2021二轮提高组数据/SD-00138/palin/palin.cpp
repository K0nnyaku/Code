#include<iostream>
#include<cstdio>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
#define FOR(i,l,r) for(int i=l;i>=r;i--)
#define MAXN 1000001
int T,N,a[MAXN],b[MAXN],ans[MAXN];bool vis[MAXN];
int get(){int x=0;char c=getchar();while(c<'0'||c>'9')c=getchar();while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();return x;}
bool check(int l,int r){FOR(i,N,1)if(a[l]==b[i])l++;else if(a[r]==b[i])r--;else return 0;return 1;}
bool dfs(int x,int l,int r){if(x==N+1)return check(l,r);if(!vis[a[l]]){vis[a[l]]=1,b[x]=a[l],ans[x]=0;if(dfs(x+1,l+1,r))return 1;vis[a[l]]=0;}if(!vis[a[r]]){vis[a[r]]=1,b[x]=a[r],ans[x]=1;if(dfs(x+1,l,r-1))return 1;vis[a[r]]=0;}return 0;}
void print(){int l=1,r=N;For(i,1,N)cout<<(ans[i]?r--,'R':(l++,'L'));FOR(i,N,1)if(b[i]==a[l])cout<<'L',l++;else cout<<'R',r--;cout<<'\n';}
int main()
{
	freopen("palin.in","r",stdin);freopen("palin.out","w",stdout);T=get();
	while(T--){N=get();For(i,1,N*2)a[i]=get(),b[i]=vis[i]=0;if(dfs(1,1,N*2))print();else cout<<"-1\n";}return 0;
}
