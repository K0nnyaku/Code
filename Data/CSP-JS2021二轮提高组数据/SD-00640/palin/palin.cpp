#include<iostream>
#include<cstdio>
#include<algorithm>
#include<queue>
#include<set>
using namespace std;
inline long long r_ll(){
	long long f=1,x=0;int c;
	do{c=getchar();if(c=='-')f=-1;}while((c<'0'||c>'9')&&c!=EOF);
	do{x=(x<<3)+(x<<1)+c-'0',c=getchar();}while(c>='0'&&c<='9');
	return f*x;
}
int n,T;
int a[1010];
int b[1010];
int cz[1010];
int ans[1010];
bool fd;
void dfs(int now,int lp,int rp){
	if(now==n+1){
		for(int i=1;i<=n;i++){
			ans[i]=cz[i];
		}
		fd=1;
		return;
	}
	b[now]=a[lp],cz[now]=1;
	if(lp<=rp&&(n+1-now>now||b[now]==b[n+1-now])){
		dfs(now+1,lp+1,rp);
	}
	b[now]=0;
	if(fd) return;
	b[now]=a[rp],cz[now]=2;
	if(lp<rp&&(n+1-now>now||b[now]==b[n+1-now])){
		dfs(now+1,lp,rp-1);
	}
	b[now]=0;
	return;
}
int main(){
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	T=r_ll();
	while(T--){
		n=r_ll();
		n<<=1;
		for(int i=1;i<=n;i++){
			a[i]=r_ll();
		}
		fd=0;
		dfs(1,1,n);
		if(fd){
			for(int i=1;i<=n;i++){
				if(ans[i]==1){
					putchar('L');
				}else
				putchar('R');
			}
			putchar('\n');
		}else{
			printf("-1\n"); 
		}
	}
	return 0;
}
