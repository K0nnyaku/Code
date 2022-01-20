#include <bits/stdc++.h>
#define lint long long
#define rint register int
using namespace std;
inline int read(){
	char c;int res=0,f=1;
	while(c=getchar(),!isdigit(c))if(c=='-')f=-f;
	while(isdigit(c))res=res*10+c-'0',c=getchar();
	return res*f;
}
const lint N=505,P=5e5,M=2e6,inf=1e15;
struct graph{
	int hed[P],nxt[M],cur[P],ver[M],cnt=1;
	lint f[M];
	inline void ae(int u,int v,lint _f){
		ver[++cnt]=v;nxt[cnt]=hed[u];
		hed[u]=cnt;f[cnt]=_f;
	}
	inline void abe(int u,int v,lint _f)
		{ae(u,v,_f);ae(v,u,0);}
	inline void init()
		{memcpy(cur,hed,sizeof cur);}
}g0,g;
int sp=P-1,tp=P-2;
int n,m,T,k;
//返回交点编号 
inline int id0(int i,int j)
	{return (i-1)*m+j;}
//获取附加点i的邻点编号 
inline int id1(int i){
	if(i<=m)return id0(1,i);
	if(m<i&&i<=n+m)return id0(i-m,m);
	if(n+m<i&&i<=2*m+n)return id0(n,m-(i-n-m)+1);
	if(2*m+n<i&&i<=2*m+2*n)return id0(n-(i-2*m-n)+1,1); 
}
int dep[P];queue<int> que;
inline bool BFS(){
	while(!que.empty())que.pop();
	memset(dep,0,sizeof dep);
	dep[sp]=1;que.push(sp);
	while(!que.empty()){
		int u=que.front();que.pop();
		for(rint e=g.hed[u];e;e=g.nxt[e]){
			int v=g.ver[e];
			if(!g.f[e]||dep[v])continue;
			dep[v]=dep[u]+1;
			if(v==tp)return true;
			que.push(v);
		}
	}
	return false;
}
lint DFS(int u,lint incf){
	if(u==tp)return incf;
	int out=0;
	for(rint &e=g.cur[u];e;e=g.nxt[e]){
		int v=g.ver[e];
		if(!g.f[e]||dep[v]!=dep[u]+1)continue;
		int upd=DFS(v,min(incf,g.f[e]));
		g.f[e]-=upd;g.f[e^1]+=upd;
		incf-=upd;out+=upd;
		if(!incf)break;
	}
	return out;
}
inline lint Dinic(){
	lint res=0;
	while(BFS()){
//		cout<<"Dinic"<<endl;
		g.init();
		res+=DFS(sp,inf);
	}
	return res;
}
int main(){
	freopen("traffic.in","r",stdin);
	freopen("traffic.out","w",stdout);
	n=read();m=read();T=read();
	for(rint i=1;i<=n-1;++i)
		for(rint j=1;j<=m;++j){
			int _w=read(); 
			g0.abe(id0(i,j),id0(i+1,j),_w);
			g0.abe(id0(i+1,j),id0(i,j),_w);
		}
	for(rint i=1;i<=n;++i)
		for(rint j=1;j<=m-1;++j){
			int _w=read();
			g0.abe(id0(i,j),id0(i,j+1),_w);
			g0.abe(id0(i,j+1),id0(i,j),_w);
		}
	while(T--){	
		k=read();g=g0;
		for(rint i=1;i<=k;++i){
			int _w=read(),p=read(),t=read();
			g.abe(n*m+p,id1(p),_w);
			g.abe(id1(p),n*m+p,_w);
//			cout<<"con:"<<p<<" "<<id1(p)<<endl;
			if(t==0)//强制白 向汇点连inf
				g.abe(n*m+p,tp,inf);
			else//强制黑 起点向其连inf 
				g.abe(sp,n*m+p,inf);
		}
		printf("%lld\n",Dinic());
	}
	return 0;
}
/*
2 3 1
9 4 7
3 8
10 5
2
19 3 1
17 9 0
*/
