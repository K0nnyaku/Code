#include<iostream>
#include<cstdio>
using namespace std;
const int N=505,mod=1e9+7;
int n,ans,k,stk[N];
char s[N],t[N];
const char a[3]={'*',')','('};
void check() {
	int tot=0,num=0;
	if(t[1]=='*'||t[n]=='*') return;
	for(int i=1;i<=n;i++) {
		if(t[i]!='*') tot=0;
		else tot++;
		if(tot>k) return;
		if(t[i]=='(') num++;
		if(t[i]==')') {
//			if(t[i+1]=='*'&&t[stk[num]-1]=='*') return;
			num--;
		}
		if(num<0) return;
	}
	if(num>0) return;
	bool flag=0;
	for(int i=1;i<=n;i++) {
		if(t[i]=='(') stk[++num]=i,flag=0;
		if(t[i]==')') {
			if(t[i+1]=='*'&&(t[stk[num]-1]=='*')) flag=1;
			num--;
		}
		if(num<0) return;
	}
	if(flag) return; 
	ans++;
	ans-=(ans>=mod?mod:0);
//	printf("%s\n",t+1);
}
void dfs(int now) {
	if(now==n+1) {
		check();
		return;
	}
	if(s[now]=='?') {
		for(int i=0;i<3;i++) {
			t[now]=a[i];
			dfs(now+1); 
		}
	}
	else dfs(now+1);
}
int main(){
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	scanf("%d%d",&n,&k);
	scanf("%s",s+1);
	for(int i=1;i<=n;i++) t[i]=s[i];
	dfs(1);
	printf("%d\n",ans); 
	return 0;
}
// rfl(bright_sky2020) AK IOI!
// as(Asrit)(NH3_H2O)(asqxSHUO) AK IOI!
// ahawzlc is so weak. T_T.
