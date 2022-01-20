#include<iostream>
#include<cstdio>
#include<queue>
#include<map>
#include<algorithm>
using namespace std;
inline int qread(){
	int x=0;
	char c=getchar(),o=' ';
	while(c<'0'||c>'9') o=c,c=getchar();
	while(c>='0'&&c<='9') x=(x<<3)+(x<<1)+(c^48),c=getchar();
	if(o=='-') x=~x+1;
	return x;
}
const long long mod=1000000007;
long long f[3][510][510];
char s[510];
int n,m;
bool br[510][510];
long long dfs(int u,int v,int k){
	if(u>v) return 0;
	if(f[k][u][v]) return f[k][u][v];
	if(u==v){
		if(s[u]=='*'||s[u]=='?')f[k][u][v]=k&1;
		else f[k][u][v]=0;
		return f[k][u][v];
	}
	if(u==v-1){
		if(s[u]=='?'&&s[v]=='?') f[k][u][v]=1+(k&1);
		else if((s[u]=='('||s[u]=='?')&&(s[v]=='?'||s[v]==')')){
			f[k][u][v]=1;
		}else if((s[u]=='*'||s[u]=='?')&&(s[v]=='*'||s[v]=='?')){
			f[k][u][v]=(1&k);
		}else{
			f[k][u][v]=0;
		}
		return f[k][u][v];
	}
	if(s[u]==')'||s[v]=='(') return 0;
	if(k==1){
		for(int i=1;i<=m;++i){
			if(s[u+i-1]!='*'&&s[u+i-1]!='?') break;
			if(u+i>v) break;
			f[k][u][v]=(f[k][u][v]+dfs(u+i,v,0))%mod;
		}
		for(int i=1;i<=m;++i){
			if(s[v-i+1]!='*'&&s[v-i+1]!='?') break;
			if(v-i<u) break;
			f[k][u][v]=(f[k][u][v]+dfs(u,v-i,0))%mod;
		}
	}
	if(s[u]=='*'||s[v]=='*') return (k==1?f[k][u][v]:0);
	if((s[u]=='('||s[u]=='?')&&(s[v]=='?'||s[v]==')'))
		f[k][u][v]=(f[k][u][v]+dfs(u+1,v-1,1))%mod;
	if(k==2) return f[k][u][v];
	for(int i=0;i<=m;++i){
		for(int j=u+1;j<=v-i;++j){
			if(i==0||!br[j][j+i-1])f[k][u][v]=(f[k][u][v]+dfs(u,j-1,2)*dfs(j+i,v,0))%mod;
//			if(u==4&&v==10)cout<<'#'<<i<<' '<<j<<' '<<f[k][u][v]<<'\n';
		}
	}
//	cout<<k<<' '<<u<<' '<<v<<' '<<f[k][u][v]<<'\n';
	return f[k][u][v];
}
int main(){
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	n=qread(),m=qread();
	scanf("%s",s+1);
	for(int i=1;i<=n;++i) if(s[i]=='('||s[i]==')') br[i][i]=1;
	for(int i=2;i<=n;++i){
		for(int j=1;j<=n-i+1;++j){
			br[j][j+i-1]=br[j][j+i-2]|br[j+i-1][j+i-1];
		}
	}
//	cout<<dfs(4,10,0)<<'\n';
	cout<<dfs(1,n,0)<<'\n';
	return 0;
}
/*
10 2
???(*??(?)
7 3
(*??*??
*/
