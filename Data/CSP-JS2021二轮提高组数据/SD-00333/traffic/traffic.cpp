#include<bits/stdc++.h>
using namespace std;
inline int rread(){
	int x=0;
	char c=getchar(),o=' ';
	while(c<'0'||c>'9')o=c,c=getchar();
	while(c>='0'&&c<='9')x=x*10+(c^48),c=getchar();
	if(o=='-')x=~x+1;
	return x; 
}
inline int mmin(int x,int y){
	return x<y?x:y;
}
int n,m,tt;
int k;
struct edge{
	int s,e,v,to,l;
}e[4000001];
int from[1000001],cnt=0;
void add(int x,int y,int z){
	e[++cnt]=(edge){x,y,z,from[x],e[from[x]].l};
	e[from[x]].l=from[x]=cnt; 
}
void del(){
	if(e[cnt].l==0){
		from[e[cnt].s]=e[cnt].to;
		e[e[cnt].to].l=e[cnt].l;
	}else{
		e[e[cnt].to].l=e[cnt].l;
		e[e[cnt].l].to=e[cnt].to;
	}
	cnt--;
}
int co[1000006];
int findc(int p){
	if(p<=m){
		return p;
	}else if(p<=n+m){
		return (p-m)*m;
	}else if(p<=n+2*m){
		return n*m-(p-m-n)+1;
	}else{
		return (n-(p-m*2-n))*m+1;
	}
}
int ans=0x3fffffff;
bool vis[1000001];
int num;
void dfs(int x,int d,int v){
//	cout<<x<<'\n';
	for(int i=from[x];i;i=e[i].to){
		if(co[e[i].e]&&co[e[i].e]!=co[x]){
			v+=e[i].v;
		}
//		cout<<e[i].e<<' ';
	}
//	cout<<'\n';
//	cout<<co[x]<<' '<<d<<' '<<v<<'\n';
	if(v>ans)return;
	if(d==num)ans=mmin(v,ans);
	for(int i=from[x];i;i=e[i].to){
		if(!co[e[i].e]){
			co[e[i].e]=1;
			dfs(e[i].e,d+1,v);
			co[e[i].e]=2;
			dfs(e[i].e,d+1,v);
			co[e[i].e]=0;
		}
	}
}
int main(){
//	freopen("traffic.in","r",stdin);
//	freopen("traffic.out","w",stdout); 
	n=rread();
	m=rread();
	tt=rread();
	for(int i=1;i<n;i++){
		for(int j=1;j<=m;j++){
			int x=rread();
			add((i-1)*m+j,i*m+j,x);
			add(i*m+j,(i-1)*m+j,x);
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<m;j++){
			int x=rread();
			add((i-1)*m+j,(i-1)*m+j+1,x);
			add((i-1)*m+j+1,(i-1)*m+j,x);
		}
	}
	while(tt--){
		int ct=cnt;
		k=rread();
		num=n*m;
		memset(vis,0,(sizeof(int))*(mmin((sizeof vis)/(sizeof(int)),n+10)));
		for(int i=1;i<=n*m;i++)co[i]=0;
		for(int i=1;i<=k;i++){
			int x=rread(),p=rread(),t=rread();
			int cl=findc(p);
			add(n*m+p,cl,x);
			add(cl,n*m+p,x);
			co[n*m+p]=t+1;
//			cout<<n*m+p<<' '<<t+1<<'\n';
		}
		co[1]=1;
		dfs(1,1,0);
		for(int i=1;i<=n*m;i++)co[i]=0;
		co[1]=2;
		dfs(1,1,0);
		cout<<ans<<'\n';
		while(cnt>ct)del();
	}
	return 0;
}
