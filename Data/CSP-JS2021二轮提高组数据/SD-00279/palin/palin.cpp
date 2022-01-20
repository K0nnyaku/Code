#include<cstdio>
#include<iostream>
using namespace std;
typedef long long ll;
const int N=500005;
int T,n;
char anss[N<<1],ans[N<<1];
int b[N<<1],ansb[N<<1];
int vis[N],viss[N];
bool flag;
int a[N<<1],L,R;
int read(){
	int num=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-') f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		num=num*10+c-'0';
		c=getchar();
	}
	return num*f;
}
void init(){
	flag=0;
	for(int i=1;i<=n;i++) vis[i]=0;
	for(int i=1;i<=2*n;i++) ansb[i]=1e9;
}
void dfs(int now){
	if(now>2*n){
		flag=1;
		for(int i=1;i<=2*n;i++) ansb[i]=b[i],anss[i]=ans[i];
		return;
	}
	if(vis[a[L]]&&vis[a[R]]){
		if(now==2*n+1-vis[a[L]]){
			if(a[L]<=ansb[now]){
				vis[a[L]]=now;
				b[now]=a[L];
				ans[now]='L';
				L++;
				dfs(now+1);
			}
		}
		else if(now==2*n+1-vis[a[R]]){
			if(a[R]<=ansb[now]){
				vis[a[R]]=now;
				b[now]=a[R];
				ans[now]='R'; 
				R--;
				dfs(now+1);
			}
		}
		else if(now!=2*n+1-vis[a[L]]&&now!=2*n+1-vis[a[R]]){
			return;
		}
	}
	else if(vis[a[L]]&&(!vis[a[R]])){
		if(now==2*n+1-vis[a[L]]){
			if(a[L]<=ansb[now]){
				vis[a[L]]=now;
				b[now]=a[L];
				ans[now]='L';
				L++;
				dfs(now+1);
			}
			else return;
		}
		else{
			if(a[R]<=ansb[now]){
				vis[a[R]]=now;
				b[now]=a[R];
				ans[now]='R';
				R--;
				dfs(now+1);
			}
			else return;
		}
	}
	else if(vis[a[R]]&&(!vis[a[L]])){
		if(now==2*n+1-vis[a[R]]){
			if(a[R]<=ansb[now]){
				vis[a[R]]=now;
				b[now]=a[R];
				ans[now]='R';
				R--;
				dfs(now+1);
			}
			else return;
		}
		else{
			if(a[L]<=ansb[now]){
				vis[a[L]]=now;
				b[now]=a[L];
				ans[now]='L';
				L++;
				dfs(now+1);
			}
			else return;
		}
	}
	else if((!vis[a[L]])&&(!vis[a[R]])){
		for(int i=1;i<=n;i++) viss[i]=vis[i];
		if(a[R]<=ansb[now]){
			vis[a[R]]=now;
			b[now]=a[R];
			ans[now]='R';
			int tmp2=R,tmp1=L;
			R--;
			dfs(now+1);
			R=tmp2,L=tmp1;
			for(int i=1;i<=n;i++) vis[i]=viss[i];
			vis[a[R]]=0;
		}
		if(a[L]<=ansb[now]){

			vis[a[L]]=now;
			b[now]=a[L];
			ans[now]='L';
			int tmp2=R,tmp1=L;
			L++;
			dfs(now+1);
			R=tmp2,L=tmp1;
			for(int i=1;i<=n;i++) vis[i]=viss[i];
			vis[a[L]]=0;
		}
	}
}
int main(){
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	T=read();
	while(T--){
		n=read();
		init();
		for(int i=1;i<=2*n;i++) a[i]=read();
		L=1,R=2*n;
		dfs(1);
		if(flag) for(int i=1;i<=2*n;i++) printf("%c",anss[i]);
		else printf("-1");
		printf("\n");
	}
	return 0;
} 
