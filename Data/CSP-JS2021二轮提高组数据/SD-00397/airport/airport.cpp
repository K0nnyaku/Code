#include<cmath>
#include<cctype>
#include<cstdio>
#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
#include<queue>

#define I inline
#define fi first
#define se second

using std::pair;
using std::vector;
using std::set;
using std::map;
using std::priority_queue;

typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int ui;
typedef pair<int,int> pii;

template<class T>I void read(T &x) {
	x=0; char c=getchar(); int f=1;
	while(!isdigit(c)) { if(c=='-') f=-1; c=getchar(); }
	while(isdigit(c)) { x=x*10+c-'0'; c=getchar(); } x*=f;
}

void File() {
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
}

const int N=100005;

int n,m,M[2];
int cnt[2][N];
pii a[N];
priority_queue<pii> heap; //{ne,ne}
priority_queue<int> num;  //ne

int main() {
	
	File();
	
	read(n);read(M[0]),read(M[1]);
	int tp=0;
	while(tp<2) {
		m=M[tp];
		while(!heap.empty()) heap.pop();
		while(!num.empty()) num.pop();
		for(int i=1;i<=M[0]+M[1];i++) num.push(-i); //ne
		for(int i=1;i<=m;i++) read(a[i].fi),read(a[i].se);
		std::sort(a+1,a+1+m);

		for(int i=1;i<=m;i++) {
			while((!heap.empty())&&(a[i].fi>(-heap.top().fi))) {
//				printf("SIZE:%d  i:%d --- %d %d\n",heap.size(),i,a[i].fi,-heap.top().fi);
				num.push(heap.top().se),heap.pop();
			}
			int v=-num.top();
			num.pop();
			cnt[tp][v]++;
			heap.push({-a[i].se,-v});
//			printf("i:%d v:%d %d\n",i,v,-a[i].se);
		}
		tp++;
	} 
	
	for(int i=1;i<=n;i++) {
		cnt[0][i]+=cnt[0][i-1];
		cnt[1][i]+=cnt[1][i-1];
//		printf("cnt[0][%d]:%d  cnt[1][%d]:%d\n",i,cnt[0][i],i,cnt[1][i]);
	} 
	
	int ans=0;
	for(int i=0;i<=n;i++) ans=std::max(ans,cnt[0][i]+cnt[1][n-i]);
	std::cout<<ans<<'\n';
	return 0;
}

