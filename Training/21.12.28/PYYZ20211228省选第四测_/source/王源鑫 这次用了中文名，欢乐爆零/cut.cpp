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
	freopen("cut.in","r",stdin);
	freopen("cut.out","w",stdout);
}

const int N=52;
int n,m,q;
bitset<N> a[N];

bool operator<(bitset<N> x,bitset<N> y){
	go(i,N-1,0) if(x[i]!=y[i]) return x[i]<y[i];
	return 0;
}

signed main(){
//	file();
	cin>>n>>q;
	while(q--){
		int x=read(),y=read();
		string s;cin>>s;
		bitset<N> tmp(s),b(0),ans(0);
		//cout<<tmp<<endl;
		a[x]=a[x]^tmp;a[y]=a[y]^tmp;
		fo(i,0,(1<<n)-1){
			b.reset();
			fo(j,1,n) if(i&(1<<j-1)) b^=a[j];
			if(ans<b) ans=b;
			//go()
		}
		//cout<<ans<<endl;
		go(i,N-1,0) if(ans[i]){
			go(j,i,0) cout<<ans[j];
			puts("");goto H;
		}
		puts("0");
		H:;
	}
	return 0;
}
/*
3 6
1 2 1
1 2 1
3 3 111
1 3 101101
1 2 1011
2 3 111011
-------------------------------------------------
1
0
0
101101
101101
110000
*/
