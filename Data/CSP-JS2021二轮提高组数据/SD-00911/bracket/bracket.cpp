#include<iostream>
#include<cstdio>
#include<string>
#define ll long long
using namespace std;
const ll p=1e9+7;
inline ll read(){
	register ll x=0,f=1;
	register char ch=getchar();
	while(ch<'0'|| ch>'9'){
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(ch>='0' && ch<='9'){
		x=(x<<1)+(x<<3)+(ch^48);
		ch=getchar();
	}
	return x*f;
}

char s[510];
char tmp[510];
ll n,k,ans;
ll stk[510];
inline bool check(){
	ll cnt=0,del=0;
	for(int i=1;i<=n;i++){
		if(tmp[i]=='(') stk[++cnt]=i;
		else if(tmp[i]==')'){
			if((i-stk[cnt]-1)>k || cnt==0) return 0;
			else cnt--;
		}
	}
	if(cnt!=0 || tmp[n]!=')' || tmp[1]!='(') return 0;
	return 1;
}
inline void dfs(int x){
	if(x==n+1){
		if(check()){
			ans=(ans+1)%p;
			cout<<endl;
		}
		return ;
	}
	if(s[x]=='*'){
		tmp[x]='*';
		dfs(x+1);
	}
	else if(s[x]=='('){

		tmp[x]='(';
		dfs(x+1);

	}
	else if(s[x]==')'){
		tmp[x]=')';
		dfs(x+1);
	}
	else if(s[x]=='?'){
		tmp[x]='*';
		dfs(x+1);
		tmp[x]='(';
		dfs(x+1);
		tmp[x]=')';
		dfs(x+1);
	}
	 
}
int main(){
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	n=read(),k=read();
	for(int i=1;i<=n;i++) cin>>s[i];
//	for(int i=1;i<=n;i++) cout<<s[i];
	dfs(1);
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
/*
7 3 
(*??*??
*/

