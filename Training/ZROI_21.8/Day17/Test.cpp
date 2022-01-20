#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdlib>
#include <climits>
#include <cctype>
#include <utility>
#include <queue>
#define Fo(i,a,b) for(int i=(a);i<(b);++i)
#define Fr(i,a,b) for(int i=(a);i<=(b);++i)
#define Fl(i,a,b) for(int i=(a);i>=(b);--i)
#define Fill(x,n) memset((x),(n),sizeof(x))
#define Fe(i,x) for(int i=H[x];i;i=E[i].nx)
using namespace std;
typedef long long ll;
const int MX=120000;
const ll Inf=0x3f3f3f3f3f3f3f3fll;
struct Edge{int y,nx;ll w;}E[MX<<1];
int H[MX],ec=1;
void Add(int x,int y,ll w)
	{ E[++ec].y=y,E[ec].w=w,E[ec].nx=H[x],H[x]=ec; }
void Bee(int x,int y,ll w)
	{ Add(x,y,w),Add(y,x,0); }

int N,M,S,T;

#define y E[i].y
int D[MX],I[MX];
bool bfs()
{
	memset(D,0,(N+1)*sizeof(int));
	queue<int> Q;
	Q.push(S),D[S]=1,I[S]=H[S];
	while(!Q.empty())
	{
		int x=Q.front();Q.pop();
		Fe(i,x)if(E[i].w&&!D[y])
		{
			Q.push(y),D[y]=D[x]+1,I[y]=H[y];
			if(y==T)return 1;
		}
	}
	return 0;
}
ll dfs(int x,ll in)
{
	if(x==T)return in;
	ll out=0;
	for(int& i=I[x];i;i=E[i].nx)
		if(E[i].w&&D[y]==D[x]+1)
		{
			int r=dfs(y,min(in,E[i].w));
			E[i].w-=r,E[i^1].w+=r;
			in-=r,out+=r;
//			if(!in)break;
		}
	if(!out) D[x] = 0;
	return out;
}
#undef y
ll Dinic()
{
	ll ans=0;
	while(bfs())ans+=dfs(S,Inf);
	return ans;
}

int main()
{
	scanf("%d%d%d%d",&N,&M,&S,&T);
	Fr(i,1,M)
	{
		int x,y;
		ll w;
		scanf("%d%d%lld",&x,&y,&w);
		Bee(x,y,w);
	}
	printf("%lld\n",Dinic());
	
	for(int i = 1; i <= N; i++) 
		printf("%d ", D[i]);

	return 0;
}