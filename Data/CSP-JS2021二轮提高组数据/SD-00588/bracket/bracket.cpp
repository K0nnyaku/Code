#include<cstdio>
#include<iostream>
#include<string>
using namespace std;
int n,k,ans;
char s[510],c[3]={'(',')','*'};
int redd(){
	int x=0,f=1;char c;c=getchar();
	while(c<'0'||'9'<c){if(c=='-')f=-1;c=getchar();}
	while('0'<=c&&c<='9'){x=x*10+c-'0';c=getchar();}
	return x*f;
}
void dfs(int x,int t,int z){
	if(t>k)
		return;
	if(z<0)
		return;
	if(x==n-1){
		if(z==1){
			ans++;
		}
		return;
	}
	if(s[x]=='?')
		for(int i=0;i<3;i++){
			s[x]=c[i];
			if(i==0)
				dfs(x+1,0,z+1);
			if(i==1)
				dfs(x+1,0,z-1);
			if(i==2)
				dfs(x+1,t+1,z);	
			s[x]='?';
		}
	if(s[x]=='(')
		dfs(x+1,0,z+1);
	if(s[x]==')')
		dfs(x+1,0,z-1);
	if(s[x]=='*')
		dfs(x+1,t+1,z);
	return;
}
int main(){
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	n=redd();k=redd();
	cin>>s;
	s[0]='(',s[n-1]=')';
	dfs(1,0,1);
	printf("%d",ans);
	return 0;
}
