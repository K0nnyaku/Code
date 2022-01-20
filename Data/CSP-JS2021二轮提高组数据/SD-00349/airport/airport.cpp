#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int N=1002021;
int n,ans,m;
int F[N],G[N],c[N],stk[N],L[N],fa[N],nxt[N];
struct node{
	int l,r;
	node(int _l=0,int _r=0){l=_l;r=_r;};
}p[N];
bool cmp(const int &x,const int &y){
	return p[x].l<p[y].l;
}
int find(int x){
	return (fa[x]==x)?x:(fa[x]=find(fa[x]));
}
void jump(int x){
	if(!c[x]){
		fa[x-1]=x;
		c[x]=1,++ans;
	}
	while(nxt[x]<=m){
		x=nxt[x];
		if(c[x]){
			x=find(x)+1;
			if(x>m)return;
			c[x]=1;++ans; fa[x-1]=x;
			if(c[x+1])fa[x]=find(x+1);
		} else{
			c[x]=1;++ans;
			if(x && c[x-1])fa[x-1]=x;
			if(x<m && c[x+1])fa[x]=find(x+1);
		}
	}
}
void solve(int *f){
	for(int i=0;i<=m+1;i++)c[i]=0;
	int top=0; p[m+1].l=p[m+1].r=2e9;
	for(int i=1;i<=m+1;i++)stk[++top]=i;
	sort(stk+1,stk+top+1,cmp);
	for(int i=1;i<=top;i++)L[i]=p[stk[i]].l;
	for(int i=1;i<=m;i++)
		nxt[i]=(lower_bound(L+1,L+top+1,p[stk[i]].r)-L);
//	cout<<"L:";for(int i=1;i<=top;i++)cout<<L[i]<<" ";cout<<endl;
//	cout<<"nxt:";for(int i=1;i<=m;i++)cout<<nxt[i]<<" ";cout<<endl;
	for(int i=1;i<=m;i++)fa[i]=i,c[i]=0;
	ans=0; f[0]=0;
	for(int i=1;i<=m;i++){
		jump(i),f[i]=ans;
		if(ans==m){
			for(int j=i;j<=n;j++)f[j]=m;
			return;
		}
	}
}
int read(){
	int x=0,f=1; char ch=getchar();
	while(ch<'0' || ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0' && ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
int main()
{
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	n=read(); int m1=read(),m2=read();
	for(int i=1;i<=m1;i++)
		p[i].l=read(),p[i].r=read();
	m=m1; solve(F);
//	cout<<"F:";for(int i=1;i<=n;i++)cout<<F[i]<<" ";cout<<endl;
	for(int i=1;i<=m2;i++)
		p[i].l=read(),p[i].r=read();
	m=m2; solve(G);
//	cout<<"G:";for(int i=1;i<=n;i++)cout<<G[i]<<" ";cout<<endl;
	ans=0;
	for(int i=0;i<=n;i++)
		ans=max(ans,F[i]+G[n-i]);
	cout<<ans<<endl;
	return 0;
}
/*
3 5 4 
1 5
3 8
6 10
9 14
13 18
2 11
4 15
7 17
12 16

2 4 6
20 30
40 50
21 22
41 42
1 19
2 18
3 4
5 6
7 8
9 10

*/
