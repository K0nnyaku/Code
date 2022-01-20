#include<iostream>
#include<cstdio>

using namespace std;

const int maxn=510,p=1e9+7;

int n,k,ans;
char s[maxn];

void dfs(int now,int cnt,int pre){
	if(now==n+1){
	    if(!cnt&&!pre) ans=(ans+1)%p;
		return; 
	}
	if(s[now]=='(') dfs(now+1,cnt+1,0);
	else if(s[now]=='*'){
		if(pre+1>k) return;
		dfs(now+1,cnt,pre+1);
	} 
	else if(s[now]==')') dfs(now+1,cnt-1,0);
	else{
		if(pre+1<=k&&(cnt||now-pre-1)) dfs(now+1,cnt,pre+1);
		if(cnt) dfs(now+1,cnt-1,0);
		dfs(now+1,cnt+1,0);
	}
}

int main(){
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	scanf("%d%d",&n,&k);
	scanf("%s",s+1);
	//int cnt=0;
	dfs(1,0,0);
	printf("%d",ans);
	return 0;
}
