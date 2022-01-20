#include <queue>
#include <cctype>
#include <cstdio>
#include <vector>
#include <climits>
#include <cstdlib>
#include <cstring>
#include <utility>
#include <algorithm>
#define rg register
#define Fo(i,a,b) for(int i=(a);i<(b);++i)
#define Fr(i,a,b) for(int i=(a);i<=(b);++i)
#define Fl(i,a,b) for(int i=(a);i>=(b);--i)
#define Fill(x,n) memset((x),(n),sizeof(x))
#define Fe(i,x) for(int i=H[x];i;i=E[i].nx)
using namespace std;
typedef long long ll;
const int MX=100000;//*******
const int Inf=0x3f3f3f3f;
char Str[MX];
vector<int> ReadLine()
{
	vector<int> res;
	fgets(Str,sizeof(Str),stdin);
	int len=strlen(Str),n=0,x=0;
	for(int j=0;j<len-1;j+=n)
		sscanf(Str+j,"%d%n",&x,&n),res.push_back(x);
	return res;
}

struct Edge{int y,w,nx;}E[MX<<1];
int H[MX],ec=1;
void Add(int x,int y,int w)
	{E[++ec].y=y,E[ec].w=w,E[ec].nx=H[x],H[x]=ec;}
void Bee(int x,int y,int w){Add(x,y,w),Add(y,x,0);}

int S,T;
int D[MX],I[MX];
#define y E[i].y
bool bfs()
{
	memset(D,0,(T+1)*sizeof(int));
	queue<int> Q;
	Q.push(S),D[S]=1,I[S]=H[S];
	while(!Q.empty())
	{
		int x=Q.front();Q.pop();
		Fe(i,x)if(E[i].w&&!D[y])
		{
			D[y]=D[x]+1,I[y]=H[y],Q.push(y);
			if(y==T)return 1;
		}
	}
	return 0;
}
int dfs(int x,int in)
{
	if(x==T)return in;
	int out=0;
	for(int i=I[x];i&&in;i=E[i].nx)
	{
		I[x]=i;
		if(E[i].w&&D[y]==D[x]+1)
		{
			int r=dfs(y,min(in,E[i].w));
			E[i].w-=r,E[i^1].w+=r;
			in-=r,out+=r;
		}
	}
	if(!out)D[x]=0;
	return out;
}
int Dinic()
{
	int ans=0;
	while(bfs())ans+=dfs(S,Inf);
	return ans;
}
#undef y

/*
* S: 0
* 仪器: 1~N
* 实验: N+1~N+M
* T: N+M+1
*/
int N,M;

signed main()
{
	scanf("%d%d ",&M,&N);
	S=0,T=N+M+1;
	int sum=0;
	Fr(j,1,M)
	{
		vector<int> v=ReadLine();
		int sz=v.size();
		Bee(N+j,T,v[0]),sum+=v[0];
		Fo(i,1,sz)Bee(v[i],N+j,Inf);
	}
	int w;
	Fr(i,1,N)scanf("%d",&w),Bee(S,i,w);
	
	int r=Dinic();
	Fr(i,1,M)if(!D[N+i])printf("%d ",i);
	putchar('\n');
	Fr(i,1,N)if(!D[i])printf("%d ",i);
	putchar('\n');
	
	printf("%d\n",sum-r);
	return 0;
}