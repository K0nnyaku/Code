#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
const int N=2010;
#define re register int
#define ll long long
int read(){
	int x=0,mark=1;char c=getchar();
	while(c<'0'||c>'9'){if (c=='-')mark=-1;c=getchar();}
	while('0'<=c&&c<='9'){x=(x<<1)+(x<<3)+c-'0';c=getchar();}
	return x*mark;
}
int a[N],b[N],n;
int path[N];
bool check(){
	for(re i=1;i<=n;i++){
		if (b[i]!=b[2*n-i+1]) return false;
	}
return true;}
int last[N],limit1;
bool dfs(int x,int l,int r){
	if (x==limit1){
		if (check()) return true;
		return false;
	}
	if (last[a[l]]==0||x+last[a[l]]==limit1){
		b[x]=a[l];path[x]=0;
		int w=last[a[l]];
		last[a[l]]=x;
		if (dfs(x+1,l+1,r)) return true;
		last[a[l]]=w;
	}
	if (last[a[r]]==0||x+last[a[r]]==limit1){
		b[x]=a[r];path[x]=1;
		int w=last[a[r]];
		last[a[r]]=x;
		if (dfs(x+1,l,r-1)) return true;
		last[a[r]]=w;
	}
	return false;
}
int main(){
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	int T=read();
	while (T--){
		memset(a,0,sizeof a);
		memset(b,0,sizeof b);
		n=read();
		for (re i=1;i<=2*n;i++){
			a[i]=read();
		}
		memset(last,0,sizeof last);
		memset(path,0,sizeof path);
		limit1=2*n+1;
		if (!dfs(1,1,2*n)) printf("-1");
		else for (re i=1;i<=2*n;i++){
			if (path[i]==0)printf("L");
			else printf("R");
		}
		puts("");
	}
	fclose(stdin);
	fclose(stdout);
return 0;}


