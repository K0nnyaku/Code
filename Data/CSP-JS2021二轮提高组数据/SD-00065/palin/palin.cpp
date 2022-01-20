#include <cstdio>
#include <cstring>
#include <iostream>
typedef long long ll;
int read(){
	int x=0;short f=0;char c=getchar();
	while(c<'0' || c>'9') { if(c=='-') f=1; c=getchar(); }
	while(c>='0' && c<='9') { x=(x<<1)+(x<<3)+(c^48); c=getchar(); }
	return f ? ~x+1 : x ;
}
int t,n,N,a[(int)1e5+5],sum,l,r,cnt,b[(int)1e5+5];
short vis[(int)1e5+5],p;
void print(){
	p=1;
	for (int i=1;i<=N;++i)	
		if(vis[i]==0) printf("L");
		else printf("R");
}
bool my_check(){
	for (int i=1;i<=n;++i){
		if(b[i]!=b[N-i+1])
			return false;
	}
	return true;
}
void my_dfs(int x){
	if(x==N+1){
		if(my_check()) print();
		return;
	}
	for (int i=0;i<2;++i){
		if(p)
			return;
		if(!i){
			b[++cnt]=a[++l]; my_dfs(x+1);
			--l,--cnt;
		} else {
			b[++cnt]=a[--r]; vis[cnt]=1; my_dfs(x+1);
			++r,--cnt;
		}
	}
}
int main(){
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	t=read();
	while(t--){
		n=read();N=n<<1;
		for (int i=1;i<=N;++i)
			a[i]=read();
		l=0,r=N+1;p=0;
		my_dfs(1);
		if(!p) printf("-1\n");
		else printf("\n");
	}
	return 0;
}
