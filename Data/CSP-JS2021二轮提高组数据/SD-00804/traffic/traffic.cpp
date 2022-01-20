#include<iostream>
#include<algorithm>
#include<cstdio>
#include<vector>
#include<queue>
#include<string>
#include<cstring>
#include<cmath>
using namespace std;
inline long long read() {
	long long x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9') {if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9') {x=x*10+ch-48;ch=getchar();}
	return x*f;
}
struct Edge {
	int to,q;
};
long long n,m,num,T,mx,vis[100005];
int col[100005];
queue <long long> q;
vector <Edge> v[250005];
vector <Edge> now[200005];
long long pos(long long x,long long y) {
	return (x-1)*m+y;
}
long long test(long long h) {
	if(h<=m) return pos(1,h);
	if(h<=m+n) return pos(h-m,m);
	if(h<=2*m+n) return pos(n,2*m+n-h+1);
	return pos(2*m+2*n-h+1,1);
}
long long k1,k2,ans=0x3f;
void dfs(int x,long long col) {
	if(col>ans) return;
	if(x==n*m+1) {
		for(int i=n*m+1;i<=n*m+num;i++) {
			for(int j=0;j<now[i].size();j++) {
				col+=now[i][j].q;
			}
		}
		ans=min(ans,col);
	}
	long long num=0;
	col[x]=1;
	for(int i=0;i<v[x].size();i++) 
		if(col[x]!=col[v[x][i].to]&&v[x][i].to!=-1)
		    num+=v[x][i].q;
	dfs(x+1,col+num);
	long long num=0;
	col[x]=0;
	for(int i=0;i<v[x].size();i++) 
		if(col[x]!=col[v[x][i].to]&&v[x][i].to!=-1)
		    num+=v[x][i].q;
	dfs(x+1,col+num);
}
int main() {
	//freopen("traffic.in","r",stdin);
	//freopen("traffic.out","w",stdout);
	n=read();m=read();T=read();
	for(int i=1;i<n;i++)
	    for(int j=1;j<=m;j++) {
	    	long long x=read();
	    	mx=max(x,mx);
	    	v[pos(i,j)].push_back((Edge){pos(i+1,j),x});
	    	v[pos(i+1,j)].push_back((Edge){pos(i,j),x});
	    	cout<<pos(i,j)<<pos(i+1,j)<<'\n';
		}
	for(int i=1;i<=n;i++)
	    for(int j=1;j<m;j++) {
	    	long long x=read();
	    	mx=max(x,mx);
	    	v[pos(i,j)].push_back((Edge){pos(i,j+1),x});
	    	v[pos(i,j+1)].push_back((Edge){pos(i,j),x});
		}
	while(T--) {
		ans=0x3f;
		num=read();
		for(int i=1;i<=n*m+num;i++) now[i].clear();
		memset(col,-1,sizeof col);
		for(int i=1;i<=num;i++) {
			long long q=read(),h=read(),c=read();
			mx=max(mx,q);
			vis[test(h)]=true;
			now[test(h)].push_back((Edge){n*m+i,q});
			now[n*m+i].push_back((Edge){test(h),q});
		}
		dfs(1);
		cout<<ans<<'\n';
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

