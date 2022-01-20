#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

const long long N=501;
long long n,k,ans;
char a[N+10];
const long long mod=1e9+7;

void dfs(long long x,long long s,long long l,long long ls,long long att){
	if(x==1){
		if(a[x]=='*' || a[x]==')') return;
		dfs(x+1,0,1,0,0);
	}
	if(x==n){
		if(a[x]=='*' || a[x]=='(') return;
		if(l!=1) return;
		ans++;
		ans%=mod;
		return;
	}
	if(a[x]=='*'){
		if(s<k || !att){
			dfs(x+1,s+1,l,0,0);
		}
		else return;
	}
	if(a[x]=='('){
		if(s) dfs(x+1,0,1,1,0);
		else dfs(x+1,0,1,0,0);
	}
	if(a[x]==')'){
		if(l==0) return;
		if(!ls)
			dfs(x+1,0,l-1,0,0);
		else
			dfs(x+1,0,l-1,0,1);
	}
	if(a[x]=='?'){
		if(s) dfs(x+1,0,1,1,0);
		else dfs(x+1,0,l+1,0,0);
		if(s<k && !att) dfs(x+1,s+1,0,0,0);
		if(l>0){
			if(!ls)
				dfs(x+1,0,l-1,0,0);
			else
				dfs(x+1,0,l-1,0,1);
		}
	}
}

int main(){
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	long long i,j,u,v;
	cin>>n>>k;
	scanf("%s",a+1);
	dfs(1,0,0,0,0);
	cout<<ans<<endl;
	return 0;
}
