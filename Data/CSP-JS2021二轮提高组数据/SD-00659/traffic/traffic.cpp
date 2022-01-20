#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cstdlib>
//#include<ctime>
#include<vector>
#include<set>
//#include<cassert>
#define R register
#define N 1020050
#define ll long long
#define P 1000000007

//输麻了
//大洋里得跑9s

inline ll Rd(){
	R ll x=0; R char ch;
	do{
		ch=getchar();
	}while(ch<'0'||ch>'9');
	do{
		x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
	}while(ch>='0'&&ch<='9');
	return x;
}

const ll inf=1e15;
int hm[250050],nxt[N],to[N],cur[250050],cnt=1,S,T,n,m,d[N],q[N];
ll sm[N],Q1[505][505],Q2[505][505],ddx[505][505][2];

inline void add(int a,int b,int c){
	nxt[++cnt]=hm[a],hm[a]=cnt,to[cnt]=b,sm[cnt]=c;
}

inline void adf(int a,int b,int c){
	add(a,b,c),add(b,a,0);
}
inline void adff(int a,int b,int c){
	add(a,b,c),add(b,a,c);
}
inline bool bfs(){
	for(R int i=1;i<=T;++i) d[i]=0;
	R int l=1,r=1; q[1]=S,d[S]=1;
	while(l<=r){
		R int u=q[l++];
		for(R int i=hm[u];i;i=nxt[i]){
			R int v=to[i];
			if(sm[i]<=0) continue;
			if(!d[v]){
				d[v]=d[u]+1; q[++r]=v;
			}
		}
	} return d[T];
}

inline ll dfs(int x,ll ff){
	if(x==T) return ff;
	R ll ss=0;
	for(R int &i=cur[x];i;i=nxt[i]){
		R int v=to[i];
		if(d[v]!=d[x]+1||sm[i]<=0) continue;
		R ll lyt=dfs(v,std::min(sm[i],ff));
		if(!lyt) continue;
		ff-=lyt,ss+=lyt,sm[i]-=lyt,sm[i^1]+=lyt;
		if(!ff) return ss;
	} return ss;
}

inline ll dinic(){
	R ll qc=0;
	while(1){
		if(!bfs()) return qc;
		for(R int i=1;i<=T;++i) cur[i]=hm[i];
		qc+=dfs(S,inf);
	} return 0;
}

inline void rstg(){
	for(R int i=1;i<=T;++i) hm[i]=0;
	cnt=1;
}

inline int shu(int x,int y){
	return (x-1)*m+y;
}

inline void bdg(){
	rstg();
	memset(ddx,0,sizeof(ddx));
	R int ka=Rd();
	for(R int i=1;i<=ka;++i){
		R int qz=Rd(),bh=Rd(),ys=Rd();
		if(bh>=1&&bh<=m){
			ddx[1][bh][ys]+=qz;
		}
		else if(bh>=m+1&&bh<=m+n){
			bh-=m;
			ddx[bh][m][ys]+=qz;
		}
		else if(bh<=m+m+n){
			bh-=m+n;
			bh=m-bh+1;
			ddx[n][bh][ys]+=qz;
		}
		else{
			bh-=m+m+n;//std::cerr<<bh<<"!!!!\n";
//			std::cerr<<"!!!!"<<bh<<"\n";
			bh=n-bh+1;
			ddx[bh][1][ys]+=qz;
		}
	}
//	for(R int i=1;i<=n;++i)
//		for(R int j=1;j<=m;++j)
//			printf("%d %d %lld %lld\n",i,j,ddx[i][j][0],ddx[i][j][1]);
	S=n*m+1,T=n*m+2;
	R ll znn=0;
	for(R int i=1;i<=n;++i)
		for(R int j=1;j<=m;++j){
			if(ddx[i][j][0]) adf(S,(i-1)*m+j,ddx[i][j][0]),znn+=ddx[i][j][0];
			if(ddx[i][j][1]) adf((i-1)*m+j,T,ddx[i][j][1]),znn+=ddx[i][j][1];
		}
	for(R int i=1;i<n;++i)
		for(R int j=1;j<=m;++j){
			adff(shu(i,j),shu(i+1,j),Q1[i][j]),znn+=Q1[i][j];
		}
	for(R int i=1;i<=n;++i)
		for(R int j=1;j<m;++j)
			adff(shu(i,j),shu(i,j+1),Q2[i][j]),znn+=Q2[i][j];
	R ll qc=dinic();
	printf("%lld\n",qc);
}

int main(){
//	srand(time(0));
	freopen("traffic.in","r",stdin);
	freopen("traffic.out","w",stdout);
R int W=0;
	n=Rd(),m=Rd(),W=Rd();
	for(R int i=1;i<n;++i)
		for(R int j=1;j<=m;++j) Q1[i][j]=Rd();
	for(R int i=1;i<=n;++i)
		for(R int j=1;j<m;++j) Q2[i][j]=Rd();
	while(W-- > 0){
		bdg();
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
//一定别忘了加上freopen、fclose
//一定要检查数组大小！
//特判所有的边界情况！
//多测要清空！
//模数要写对了！
//尽量不要随机化乱搞！
//有时间的话和暴力对拍！
//先做简单题，再做难的！
//做不出的话就写暴力！
//qwqwq
