#include<bits/stdc++.h>

using namespace std;

#define rep(i,a,b)for(int i=(a),ed##i=(b);i<=ed##i;++i)
#define re(i,a)rep(i,1,a)
#define per(i,a,b)for(int i=(a),ed##i=(b);i>=ed##i;--i)
#define in Read()
#define up(a,b) (((a)<(b))and((a)=(b)))
#define down(a,b) (((a)>(b))and((a)=(b)))
#define dbg(x) (cerr<<#x" = "<<(x)<<'\n')
#define fio(x) freopen(x".in","r",stdin),freopen(x".out","w",stdout)
#define each(x,y) for(auto&&x:(y))

typedef long long ll;
typedef unsigned long long ull;

int Read(){
	int x=0,c=getchar();
	while(not isdigit(c))c=getchar();
	while(isdigit(c))x*=10,x+=c^'0',c=getchar();
	return x;
}

void out(int x){
	printf("%d",x);
}
void out(ll x){
	printf("%lld",x);
}
#define ENDL putchar('\n')
#define ENDS putchar(' ')


const int N=1e6+9;

int n,a[N],b[N];

bool Ck(){
	re(i,n)cerr<<b[i]<<' ';cerr<<'\n';
	re(i,n/2)if(b[i]!=b[n-i+1])return 0;return 1;
}

void Work(){
	n=in;n*=2;re(i,n)a[i]=in;
	rep(ans,0,(1<<n)-1){
		int l=1,r=n;
		rep(i,0,n-1){
			if(!((ans>>i)bitand 1))b[i+1]=a[l++];
			else b[i+1]=a[r--];
		}
		if(Ck()){
			string s;
			rep(i,0,n-1){
				if(!((ans>>i)bitand 1))putchar('L');
				else putchar('R');
			}
			ENDL;return;
		}
	}
	puts("-1");
}

signed main(){
	fio("palin1");
	int T=in;
	while(T--)Work();
	return 0;
}
