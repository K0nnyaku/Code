// ver 1.1 brute
#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
const int N=500005;
int n,a[N<<1],ans[N<<1],b[N<<1];
bool ok;
//inline int read() {
//	int sum=0,w=1;
//	char ch=getchar();
//	while(ch<'0'||ch>'9') {
//		if(ch=='-') w=-1;
//		ch=getchar();
//	}
//	while(ch>='0'&&ch<='9') {
//		sum=(sum<<3)+(sum<<1)+(ch^48);
//		ch=getchar();
//	}
//	return sum*w;
//}
inline void dfs(int now,int l,int r) {
	if(ok) return;
	if(now>n+1) if(b[now-1]!=b[2*n-(now-1)+1]) return;
	if(now==n*2+1) {
		ok=1;
		return;
	}
	b[now]=a[l];
	ans[now]=1;
	dfs(now+1,l+1,r);
	if(ok) return;
	b[now]=a[r];
	ans[now]=2;
	dfs(now+1,l,r-1);
}
int main() {
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	int t;
	scanf("%d",&t);
	while(t--) {
		ok=0;
//		n=read();
//		for(int i=1; i<=n*2; i++) a[i]=read();
		scanf("%d",&n);
		for(int i=1; i<=n*2; i++) scanf("%d",&a[i]);
		dfs(1,1,n*2);
		if(ok) for(int i=1; i<=n*2; i++) putchar(ans[i]==1?'L':'R');
		else putchar('-'),putchar('1');
		putchar('\n');
	}
	return 0;
}

