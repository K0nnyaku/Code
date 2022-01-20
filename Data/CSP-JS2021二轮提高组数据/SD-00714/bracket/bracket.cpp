#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
int N,K;
long long dfn[505][505];
bool vis[505][505];
char str[505];
long long dfs(int L,int R){
	if(vis[L][R]) return dfn[L][R];
	vis[L][R]=true;
	if(L>=R) return 0;
	if((str[L]!='('&&str[L]!='?')||(str[R]!=')'&&str[R]!='?')){
		return 0;
	}
	dfn[L][R]+=dfs(L+1,R-1);
	int l=R-1,r=L+1;
	for(int i=L+1,j=0;i<R;++i,++j){
		if(j>=K||(str[i]!='*'&&str[i]!='?')){
			l=i-1;
			break;
		}
	}
	for(int i=R-1,j=0;i>L;--i,++j){
		if(j>=K||(str[i]!='*'&&str[i]!='?')){
			r=i+1;
			break;
		}
	}
	if(r<=l) ++dfn[L][R];
	for(int i=L+1;i<=l;++i){
		dfn[L][R]+=dfs(i+1,R-1);
		dfn[L][R]%=mod;
	}
	for(int i=R-1;i>=r;--i){
		dfn[L][R]+=dfs(L+1,i);
		dfn[L][R]%=mod;
	}
	return dfn[L][R];
}
int main(){
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	cin>>N>>K>>str+1;
	cout<<dfs(1,N);
	return 0;
}
