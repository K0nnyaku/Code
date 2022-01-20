#include<bits/stdc++.h>
#define mod (1000000007)
using namespace std;
inline int rread(){
	int x=0;
	char c=getchar(),o=' ';
	while(c<'0'||c>'9')o=c,c=getchar();
	while(c>='0'&&c<='9')x=x*10+(c^48),c=getchar();
	if(o=='-')x=~x+1;
	return x; 
}
int n,k;
char s[501];
int f[501];
int mp[300];

int ans=0;
int st[501],top=0,ct;
bool check(){
	if(f[1]!=1||f[n]!=2)return 0; 
	top=0;
	ct=0;
	f[0]=f[n+1]=3;
	for(int i=1;i<=n;i++){
		if(f[i]==-1){
			ct++;
			if(ct>k)return 0;
		}else{
			if(f[i]==1){
				st[++top]=i;
				ct=0;
			}else{
				if(f[st[top]-1]==-1&&f[i+1]==-1)return 0;
				top--;
			}
		}
	}
	return top==0;
}
void dfs(int x){
	if(x>n){
//		for(int i=1;i<=n;i++){
//			cout<<f[i]<<' ';
//		}
//		cout<<'\n';
		if(check()){
			ans++;
			if(ans>mod)ans-=mod;
		}
		return;
	}
	if(x<1||s[x]!='?'){
		f[x]=mp[(int)s[x]],dfs(x+1); 
		return;
	}
	f[x]=1;
	dfs(x+1);
	f[x]=2;
	dfs(x+1);
	f[x]=-1;
	dfs(x+1);
	return;
}
int main(){
	mp[(int)'*']=-1;
	mp[(int)'(']=1;
	mp[(int)')']=2;
	mp[(int)'#']=3;
	n=rread();
	k=rread();
	scanf("%s",s+1);
	s[0]='#';
	dfs(0);
	cout<<ans<<'\n';
	return 0;
}
