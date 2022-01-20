#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<ctime>
#include<cmath>
using namespace std;
inline int read() {
	int f=0,res=0; char ch;
	while(ch<'0'||ch>'9') {if(ch=='-')f=1; ch=getchar();}
	while(ch>='0'&&ch<='9'){res=(res<<1)+(res<<3)+(ch^48);ch=getchar();}
	return f?-res:res; 
}
const int maxn=1e5+10;
bool flag;
int n,a[maxn],b[maxn];
char ans[maxn];
inline bool check() {
	//for(int i=1;i<=n*2;i++) cout<<b[i]<<" "; cout<<endl;
	for(int i=1;i<=n;i++)
	  if(b[i]!=b[n*2-i+1])
	    return false;
	return true;
}
inline void dfs(int x,int l,int r) {
	if(x==2*n+1) {
		if(check()) flag=true;
		return;
	} b[x]=a[l]; ans[x]='L'; dfs(x+1,l+1,r);
	if(flag) return;
	b[x]=a[r]; ans[x]='R'; dfs(x+1,l,r-1);
}
int main()
{
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	int T=read();
	while(T--) {
		n=read(); flag=false;
		for(int i=1;i<=n*2;i++) a[i]=read();
		dfs(1,1,n*2);
		if(!flag) cout<<-1<<endl;
		else for(int i=1;i<=n*2;i++) cout<<ans[i]; cout<<endl;
	} fclose(stdin); fclose(stdout);
	return 0;
}
