#include<iostream>
#include<cstdio>
#include<queue>
#include<cstring>
#include<stdlib.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
inline int read(){
	int x=0,f=1;char ch=getchar();
	while(!isdigit(ch)){
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(isdigit(ch)){
		x=x*10+ch-48;
		ch=getchar();
	}
	return x*f;
}
inline void file(){
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
}
const int N=510;
int n,k,ans,top,a[N],cnt,st[N],vis[N];
char s[N],now[N];
bool chk(){
	top=0,cnt=1;
	memset(a,0,sizeof(a));
	memset(vis,0,sizeof(vis));
	for(int i=1;i<=n;i++){
		if(now[i]=='(') st[++top]=i;
		else if(now[i]==')'){
			if(now[st[top]]!='(') return false;
			else{
				a[st[top]]=++cnt,a[i]=++cnt;
				top--;
			} 
		}
	}
	if(top||!a[1]||!a[n]) return false;
	for(int i=1;i<=n;i++){
		if(a[i]!=0) continue;
		int j=i,res=0;
		while(a[j]==0) j++,res++;
		if(res>k) return false;
		if(a[i-1]%2==a[j]%2){
			if(a[j]%2){
				vis[a[i-1]]=1;
				if(vis[a[i-1]^1]) return false;
			}
			else{
				
				vis[a[j]]=1;
				if(vis[a[j]^1]) return false;
			}
		}
		i=j-1;
	}
	return true;
}
void dfs(int x){
	if(x==n+1){
		if(chk()){
			ans++;
		}
		return;
	}
	if(s[x]=='?'){
		now[x]='*';dfs(x+1);
		now[x]='(';dfs(x+1);
		now[x]=')';dfs(x+1);
	}
	else{
		now[x]=s[x];dfs(x+1);
	}
}
int main(){
	file();
	n=read(),k=read();
	scanf("%s",s+1);
	dfs(1);
	printf("%d\n",ans);
	return 0;
}
