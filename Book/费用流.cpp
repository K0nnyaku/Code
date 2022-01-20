#include<cstdio>
#include<cstring>
#include<algorithm>
#define inf 0x3f3f3f3f
#define N 5005
#define M 50005

int n,m,s,t;

int hd[N],_hd=1;
struct edge{
	int v,f,w,nxt;
}e[M<<1];
inline void addedge(int u,int v,int f,int w){
	e[++_hd]=(edge){v,f,w,hd[u]};
	hd[u]=_hd;
}

int mc,mf,c,cur[N];
bool vis[N];
inline int dfs(int u,int flw){
	if(u==t){
		mc+=c*flw;
		mf+=flw;
		return flw;
	}
	vis[u]=1;
	int res=0;
	for(int i=cur[u];i;i=e[i].nxt){
		cur[u]=i;
		int v=e[i].v,f=e[i].f,w=e[i].w;
		if(f&&!w&&!vis[v]){
			f=dfs(v,std::min(flw,f));
			e[i].f-=f;
			e[i^1].f+=f;
			res+=f;
			flw-=f;
			if(!flw)
				break;
		}
	}
	return res;
}
inline bool bfs(){
	int tmp=inf;
	for(int u=1;u<=n;u++)
		if(vis[u])
			for(int i=hd[u];i;i=e[i].nxt)
				if(e[i].f&&!vis[e[i].v])
					tmp=std::min(tmp,e[i].w);
	if(tmp==inf)
		return 0;
	for(int u=1;u<=n;u++)
		if(vis[u])
			for(int i=hd[u];i;i=e[i].nxt){
				e[i].w-=tmp;
				e[i^1].w+=tmp;
			}
	c+=tmp;
	return 1;
}
inline void mcmf(){
	do{
		do{
			memset(vis,0,sizeof(vis));
			for(int i=1;i<=n;i++)
				cur[i]=hd[i];
		}while(dfs(s,inf));
	}while(bfs());
}

int main(){
	scanf("%d%d%d%d",&n,&m,&s,&t);
	for(int i=1;i<=m;i++){
		int u,v,w,f;
		scanf("%d%d%d%d",&u,&v,&f,&w);
		addedge(u,v,f,w);
		addedge(v,u,0,-w);
	}
	mcmf();
	printf("%d %d\n",mf,mc);
}

