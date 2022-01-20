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
#define fpi freopen("traffic.in","r",stdin)
#define fpo freopen("traffic.out","w",stdout)

int main(){
	fpi,fpo;
	srand(time(0));
	int n=read(n),m=read(m),t=read(t);
	while(t--){
		print(rand()),enter;
	}
	return 0;
}
