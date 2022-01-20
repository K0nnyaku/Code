#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define rop(i,a,b) for(int i=(a);i<(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
#define por(i,a,b) for(int i=(a);i>(b);i--)
using namespace std;
typedef long long ll;
namespace AnShu{

inline int read(){
	int W=0,F=1;
	char C=getchar();
	while((C<'0'||C>'9')&&C!='-') C=getchar();
	if(C=='-') F=-1,C=getchar();
	while(C>='0'&&C<='9') W=W*10+C-'0',C=getchar();
	return W*F;
}

int T,n,az[102],ans[102],qwq[102];

bool check(){
	int l=1,r=n;
	rep(i,1,n){
		if(!ans[i]) qwq[i]=az[l++];
		else qwq[i]=az[r--];
	}
	rep(i,1,n/2)
		if(qwq[i]!=qwq[n-i+1]) return false;
	return true;
} 

void output(){
	rep(i,1,n){
		if(!ans[i]) printf("L");
		else printf("R");
	}
	printf("\n");
}

bool dfs(int dep){
	if(dep>n){
		if(check()){
			output();
			return true;
		}
		return false;
	}
	ans[dep]=0;
	if(dfs(dep+1)) return true;
	ans[dep]=1;
	if(dfs(dep+1)) return true;
	return false;
}

void Main(){
	T=read();
	while(T--){
		n=read();n*=2;
		rep(i,1,n) az[i]=read();
		if(!dfs(1)) printf("-1\n");
	}
}

}

int main(){
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	AnShu::Main();
	return 0;
}

