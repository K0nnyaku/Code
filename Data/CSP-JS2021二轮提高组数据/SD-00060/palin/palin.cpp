#include<cstdio>
#include<iostream>
#include<cmath>
#include<cstdlib>
#include<string>
#include<cstring>
#include<ctime>
#include<algorithm>
#include<queue>
#include<map>
#include<set>
#include<vector>
#include<bitset>
#include<deque>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;
#define mkp make_pair
#define lb lower_bound
#define ub upper_bound
#define eb emplace_back
#define pq priority_queue
#define space putchar(' ')
#define enter putchar('\n')
#define sz(x) (int)x.size()
#define all(x) x.begin(),x.end()
#define ms(x,y) memset(x,y,sizeof(x))
#define debug(x) cerr<<#x<<"= "<<(x)<<endl
template<class T> inline T read(T &x){
	x=0;int f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-') f=-f;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9') x=(x<<1)+(x<<3)+(ch^48),ch=getchar();
	return x*=f;
}
template<class T> inline void print(T x){
	char buf[20];int cnt=0;
	if(x<0) putchar('-'),x=-x;
	if(!x) putchar('0');
	while(x) buf[++cnt]=x%10^48,x/=10;
	while(cnt) putchar(buf[cnt--]);
}
#define mod 998244353
#define inf 1000000001
#define fpi freopen("palin.in","r",stdin)
#define fpo freopen("palin.out","w",stdout)
int a[1000005],now[500005],ans[1000005];
bool yes[500005];
void solve(){
	int n=read(n),i,j;
	for(i=1;i<=n<<1;i++) read(a[i]);
	if(n>20){
		for(i=1;i<=n;i++) yes[i]=0;
		for(i=1;i<=n;i++){
			if(yes[a[i]]){
				puts("-1");return ;
			}yes[a[i]]=1;
		}
		for(i=1;i<=n<<1;i++) putchar('L');enter;
		return ;
	}
	for(i=0;i<1<<n;i++){
		int l=1,r=n<<1;
		bool no=0;
		for(j=n-1;~j;j--){
			if(i&1<<j) now[n-j]=a[r--],ans[n-j]=1;
			else now[n-j]=a[l++],ans[n-j]=0;
		}
		for(j=n;j;j--){
			if(a[l]^now[j]&&a[r]^now[j]){
				no=1;break;
			}
			if(a[l]==now[j]) ans[(n<<1)-j+1]=0,l++;
			else if(a[r]==now[j]) ans[(n<<1)-j+1]=1,r--;
		}
		if(!no){
			for(j=1;j<=n<<1;j++){
				if(ans[j]) putchar('R');
				else putchar('L');
			}
			enter;return ;
		}
	}puts("-1");
}
int main(){
	fpi,fpo;
	int t=read(t);
	while(t--) solve(); 
	return 0;
}
