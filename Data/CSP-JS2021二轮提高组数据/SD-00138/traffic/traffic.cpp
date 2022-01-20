#include<iostream>
#include<cstdio>
#include<queue>
using namespace std;
#define ll long long
#define For(i,l,r) for(int i=l;i<=r;i++)
#define FOR(i,u) for(int i=now[u];i!=-1;i=nxt[i])
#define INF 0x3fffffffffffff
#define MAXA 501
#define MAXN 1000001
#define MAXM 10000001
int N,M,T,s,t,x1[MAXA][MAXA],x2[MAXA][MAXA],dep[MAXN],fst[MAXN],now[MAXN],cnt,to[MAXM],nxt[MAXM];ll flow[MAXM];
int get(){int x=0;char c=getchar();while(c<'0'||c>'9')c=getchar();while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();return x;}
int id(int x,int y){return (x-1)*M+y;}
int getid(int x){if(x<=M)return id(1,x);x-=M;if(x<=N)return id(x,M);x-=N;if(x<=M)return id(N,M+1-x);x-=M;return id(N+1-x,1);}
void add(int u,int v,int f){to[++cnt]=v,flow[cnt]=f,nxt[cnt]=fst[u],fst[u]=cnt;to[++cnt]=u,flow[cnt]=0,nxt[cnt]=fst[v],fst[v]=cnt;}
bool bfs()
{
	queue<int>q;For(i,s,t)dep[i]=-1;dep[s]=0;q.push(s);
	while(!q.empty()){int u=q.front();q.pop();now[u]=fst[u];if(u==t)return 1;FOR(i,u)if(flow[i]>0&&dep[to[i]]==-1)dep[to[i]]=dep[u]+1,q.push(to[i]);}return 0;
}
ll dfs(int u,ll in)
{
	if(u==t||!in)return in;ll res=0;
	FOR(i,u){now[u]=i;if(dep[to[i]]!=dep[u]+1)continue;ll tmp=dfs(to[i],min(in,flow[i]));flow[i]-=tmp,flow[i^1]+=tmp,in-=tmp,res+=tmp;if(!in)break;}return res;
}
int main()
{
	freopen("traffic.in","r",stdin);freopen("traffic.out","w",stdout);
	N=get(),M=get(),T=get();For(i,1,N-1)For(j,1,M)x1[i][j]=get();For(i,1,N)For(j,1,M-1)x2[i][j]=get();
	while(T--)
	{
		int K=get();s=0,t=N*M+1;cnt=-1;For(i,s,t)fst[i]=-1;
		For(i,1,N-1)For(j,1,M)add(id(i,j),id(i+1,j),x1[i][j]),add(id(i+1,j),id(i,j),x1[i][j]);
		For(i,1,N)For(j,1,M-1)add(id(i,j),id(i,j+1),x2[i][j]),add(id(i,j+1),id(i,j),x2[i][j]);
		For(i,1,K){int x=get(),p=get(),c=get();c?add(s,getid(p),x):add(getid(p),t,x);}
		ll ans=0;while(bfs())ans+=dfs(s,INF);cout<<ans<<'\n';
	}
	return 0;
}
