#include<iostream> 
#include<cstdio>
#include<cstring>
#define ll long long
using namespace std;
const int N=1e5+5,p=1e9+7;
ll n,k,bk[N],tail;
char s[N],chg[3]={'(',')','*'};
int ok(){
	for(int i=1;i<=n;i++){
		return 1;
	}
	return 1;
}
ll dfs(int dep,int drct){
	if(dep==tail){
		s[bk[tail]]=chg[drct];
		return 1;
	}
	s[bk[tail]]=chg[drct];
	return (dfs(dep+1,0)+dfs(dep+1,1)+dfs(dep+1,2))%p;
}
int main(){
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		s[i]=getchar();
		while(s[i]!='?'&&s[i]!='('&&s[i]!=')'&&s[i]!='*')s[i]=getchar();
		if(s[i]=='?')bk[++tail]=i;
	}
	cout<<dfs(1,0)+dfs(1,1)+dfs(1,2)<<endl;
	return 0;
} 
/*
7 3 
(*??*??

*/
