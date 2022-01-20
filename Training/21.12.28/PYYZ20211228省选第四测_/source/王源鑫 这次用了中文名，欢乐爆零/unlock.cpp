//author:ÍûÔ¶ÐÇ
#include<bits/stdc++.h>
#define pii pair<int,int>
#define fi first
#define se second
#define pb push_back
#define mk make_pair
#define sml(x,y) (x=min(x,y))
#define big(x,y) (x=max(x,y))
#define ll long long
#define ull unsigned long long
#define db double
#define fo(i,x,y) for(int i=x;i<=y;++i)
#define go(i,x,y) for(int i=x;i>=y;--i)
using namespace std;
inline int read(){int x=0,fh=1; char ch=getchar(); while(!isdigit(ch)){if(ch=='-') fh=-1; ch=getchar();} while(isdigit(ch)){x=(x<<1)+(x<<3)+ch-'0'; ch=getchar();} return x*fh;}
inline void out(int *a,int l,int r){fo(i,l,r) cout<<*(a+i)<<' ';puts("");}

void file(){
	freopen("unlock.in","r",stdin);
	freopen("unlock.out","w",stdout);
}

#define ld long double

const int N=305;
vector<int> e[N];
int stk[N],top,dfn[N],low[N],ti,ins[N],bel[N],num,n,k,a[N],deg[N],id,siz[N],sum;
ld f[N][N];

void tarjan(int x){
	dfn[x]=low[x]=++ti;
	stk[++top]=x;ins[x]=1;
	for(int i:e[x]){
		if(!dfn[i]) tarjan(i),sml(low[x],low[i]);
		else if(ins[i]) sml(low[x],dfn[i]);
	}
	if(low[x]==dfn[x]){
		++num;int p;
		//printf("%d:",num);
		do{
			p=stk[top--];
			//printf("%d ",p);
			bel[p]=x,ins[p]=0;
		}while(p!=x);//puts("");
	}
}

ld C(int n,int m){
	if(m>n||m<0) return 0;
	//printf("C(%d,%d)\n",n,m);
	if(m>n/2) return C(n,n-m);
	ld ret=1;
	fo(i,0,m-1) ret*=(n-i)/(i+1.0);
	//cout<<ret<<endl;
	return ret;
	/*ld fm=1,fz=1;
	fo(i,1,m) fm*=i;
	fo(i,0,m-1) fz*=n-i;
	return fz/fm;*/
}

void solve(){
	cin>>n>>k;ti=top=num=id=0;
	fo(i,1,n) e[i].clear(),dfn[i]=low[i]=bel[i]=ins[i]=deg[i]=siz[i]=0;
	fo(i,1,n) a[i]=read(),e[i].pb(a[i]);
	fo(i,1,n) if(!dfn[i]) tarjan(i);
	fo(i,1,n)
		for(int j:e[i]) if(bel[i]!=bel[j]) deg[bel[j]]++;
	fo(i,1,n) if(bel[i]==i&&!deg[i]){
		++id;
		fo(j,1,n) if(bel[j]==i) siz[id]++;
	}sum=0;
	//cout<<id<<endl;out(siz,1,id);
	if(id>k){
		puts("0.0000000000");
		return;
	}f[0][0]=1;
	fo(i,1,id){
		sum+=siz[i];
		fo(j,0,n) f[i][j]=0;
		go(j,min(k,sum),0)
			fo(w,1,min(j,siz[i])) f[i][j]+=f[i-1][j-w]*C(siz[i],w);
		//cout<<i<<":";fo(j,0,sum) printf("%lld ",f[i][j]);puts("");
	}
	long double ans=0;
	fo(i,0,min(k,sum)) if(f[id][i]>0){
		ans+=f[id][i]*C(n-sum,k-i)/C(n,k);
		/*long double fz=f[id][i],fm=1;
		fo(j,0,k-i-1) fz*=n-sum-j;
		fo(j,0,k-1) fm*=n-j;
		fo(j,k-i+1,k) fz*=j;
		//cout<<fz<<'/'<<fm<<endl;
		ans+=fz/fm;*/
	}
	cout<<fixed<<setprecision(10)<<ans<<endl;
}

signed main(){
	file();
	int T=read();
	while(T--) solve(); 
	return 0;
}
/*
4
5 1
2 5 4 3 1
5 2
2 5 4 3 1
5 3
2 5 4 3 1
5 4
2 5 4 3 1
-------------------------------------------------
*/
