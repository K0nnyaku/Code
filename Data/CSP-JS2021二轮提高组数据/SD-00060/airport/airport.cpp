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
#define fpi freopen("airport.in","r",stdin)
#define fpo freopen("airport.out","w",stdout)
struct seg{
	int l,r;
}a[100005],b[100005];
int m1,m2,n;
inline bool cmp(seg x,seg y){
	return x.l<y.l;
}
int check(int x){
	int res=0,i;
	pq<int,vector<int>,greater<int> > q;
	for(i=1;i<=m1;i++){
		while(!q.empty()&&q.top()<=a[i].l) q.pop();
		if(sz(q)<x) res++,q.push(a[i].r);
	}
	while(!q.empty()) q.pop();
	for(i=1;i<=m2;i++){
		while(!q.empty()&&q.top()<=b[i].l) q.pop();
		if(sz(q)<n-x) res++,q.push(b[i].r);
	}return res;
}
int main(){
	fpi,fpo;
	int i;read(n),read(m1),read(m2);
	for(i=1;i<=m1;i++) read(a[i].l),read(a[i].r);
	for(i=1;i<=m2;i++) read(b[i].l),read(b[i].r);
	sort(a+1,a+m1+1,cmp),sort(b+1,b+m2+1,cmp);
	int l=0,r=n,lmid,rmid;
	while(l+2<r){
		lmid=l+(r-l)/3,rmid=r-(r-l)/3;
		if(check(lmid)<=check(rmid)) l=lmid;
		else r=rmid;
	}
	if(l==r) print(check(l));
	if(l+1==r) print(max(check(l),check(r)));
	if(l+2==r) print(max(check(l),max(check(l+1),check(r))));
	return 0;
}
