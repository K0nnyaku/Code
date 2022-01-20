#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,t,ans;
inline int read(){
	int f=1,q=0;
	char ch=getchar();
	while(!isdigit(ch)){if(ch=='-')f=0;ch=getchar();}
	while(isdigit(ch))q=(q<<3)+(q<<1)+(ch^48),ch=getchar(); 
	return f?q:-q;
}
inline void print(int x){
	if(x<0)putchar('-'),x=-x;
	if(x>9)print(x/10);
	putchar(x%10+48);
}
//inline void add_edge(int u,int v,int w){
//	edge[++cnt].w=w;
//	edge[cnt].to=v;
//	edge[cnt].nxt=head[u];
//	head[u]=cnt;
//}
signed main(){
	freopen("traffic.in", "r", stdin);
	freopen("traffic.out", "w", stdout);
	n=read(),m=read(),t=read();
	for(register int i=1;i<n;++i){
		for(register int j=1;j<=m;++j){
			int w=read();
			ans+=w;
//			add_edge((i-1)*m+j,i*m+j,w);
		}
	}
	for(register int i=1;i<=n;++i){
		for(register int j=1;j<m;++j){
			int w=read();
			ans+=w;
//			add_edge((i-1)*m+j,(i-1)*m+j+1,w);
		}
	}ans=sqrt(ans);
	while(t--){
		int k=read();
		while(k--){
			int x=read(),p=read(),tt=read();ans+=x/2;
		}
		print(ans/2+1);
	}
	return 0;
}
