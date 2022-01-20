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
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
}
const int N=110;
int T,n,a[N],col[N],b[N],ans[N],ok=0;
bool chk(){
	int i=1,j=n,cnt=0;
	for(int k=1;k<=n;k++){
		if(col[k]==0) b[++cnt]=a[i],i++;
		if(col[k]==1) b[++cnt]=a[j],j--;
	}
	i=1,j=n;
	while(b[i]==b[j]&&i<j) i++,j--;
	if(i==j+1||i==j) return true;
	return false;
}
void com(){
	int flag=0;
	for(int i=1;i<=n;i++){
		if(col[i]<ans[i]){
			flag=1;break;
		}
		else if(col[i]==ans[i]) continue;
		else return;
	}
	if(flag) for(int i=1;i<=n;i++) ans[i]=col[i];
}
void dfs(int x){
	for(int i=1;i<=x;i++){
		if(col[i]>ans[i]) return;
	}
	if(x==n+1){
		if(chk()) com(),ok=1;
		return;
	}
	col[x]=0;dfs(x+1);
	col[x]=1;dfs(x+1);
}
int main(){
	file();
	T=read();
	while(T--){
		n=read();n<<=1;
		memset(ans,0x3f,sizeof(ans));ok=0;
		for(int i=1;i<=n;i++) a[i]=read();
		dfs(1);
		if(!ok) puts("-1");
		else{
			for(int i=1;i<=n;i++){
				if(ans[i]==0) putchar('L');
				else putchar('R');
			}
			puts("");
		}
	}
	return 0;
}
