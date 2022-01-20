#include<bits/stdc++.h>
#define fo(i,x,y) for(int i=x;i<=y;++i)
#define go(i,x,y) for(int i=x;i>=y;--i)
#define sml(x,y) x=min(x,y)
#define big(x,y) x=max(x,y)
#define ll long long
#define mk make_pair
#define pb push_back
#define fi first
#define se second
#define pii pair<int,int>
#define umap unordered_map
using namespace std;
inline void out(int *a,int l,int r){fo(i,l,r) printf("%d ",*(a+i));puts("");}

inline int read(){
	char ch=getchar();
	int x=0,f=1;
	while(!isdigit(ch)){
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(isdigit(ch)){
		x=(x<<1)+(x<<3)+(ch^48);
		ch=getchar();
	}
	return x*f;
}

const int N=1e6+5;
int a[N],b[N],n,m;

void solve(){
	cin>>n;n*=2;
	fo(i,1,n) a[i]=read();
	fo(i,0,(1<<n)-1){
		m=0;int l=1,r=n;
		go(j,n-1,0){
			if(i>>j&1) b[++m]=a[r--];
			else b[++m]=a[l++];
		}
		//go(j,n-1,0) putchar((i>>j&1)?'R':'L');puts("");
		//out(b,1,n);system("Pause");
		int flg=1;
		fo(i,1,n/2) if(b[i]!=b[n-i+1]){
			flg=0;
			break;
		}
		if(flg){
			go(j,n-1,0) putchar((i>>j&1)?'R':'L');puts("");
			return;
		}
	}
	puts("-1");
}

void file(){
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
}

int main(){
	file();
	int T=read();
	while(T--) solve();
	return 0;
}
/*
2
5
4 1 2 4 5 3 1 2 3 5
3
3 2 1 2 1 3
---------------------
LRRLLRRRRL
-1
*/
