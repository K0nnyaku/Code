#include <bits/stdc++.h>
//#define int long long
using namespace std;
const int MAXN=5e5+5;
inline int read(){
	int s=0,w=1;char ch=getchar();
	while(ch>'9'||ch<'0') {if(ch=='-')w=-1;ch=getchar();}
	while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
	return s*w;
}int a[MAXN],b[MAXN],cz[MAXN],n,ans=0;
bool fg=0;
void print(){
	for(int i=1;i<=2*n;i++){
		if(cz[i]==1) cout<<"L";
		else cout<<"R";
	}
	cout<<endl;
}bool cheak(){
	memset(b,0,sizeof b);
	int l=1,r=2*n,tot=0;
	for(int i=1;i<=2*n;i++){
		if(cz[i]==1) b[++tot]=a[l++];
		else b[++tot]=a[r--];
	}for(int i=1;i<=n;i++){
		if(b[i]!=b[2*n+1-i]) return false;
	}return true;
}inline void dfs(int s,int k){
	cz[s]=k;
	if(s==2*n){
		if(cheak()){
			print();
			fg=1;
		}return;
	}for(int i=1;i<=2;i++) {
		if(fg==1) return;
		dfs(s+1,i);
	}
}int main (){
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	int T;
	T=read();
	while(T--){
		memset(a,0,sizeof a);
		memset(cz,0,sizeof cz);
		fg=0;
		n=read(); int N=2*n;
		for(int i=1;i<=N;i++){
			a[i]=read();
		}
		for(int i=1;i<=2;i++) dfs(1,i);
		if(!fg) cout<<"-1"<<endl;
	}
	return 0;
}

/*
2
5
4 1 2 4 5 3 1 2 3 5
3
3 2 1 2 1 3

*/

