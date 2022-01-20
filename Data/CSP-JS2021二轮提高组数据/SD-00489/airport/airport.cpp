#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iostream>
#include <queue>

#define fi first
#define se second

using std::max;
using std::min;
using std::sort;
using std::priority_queue;
using std::pair;
using std::vector;
using std::greater;

typedef pair<int,int> pii;

const int N=1e5+11;
const int INF=0x3f3f3f3f;

pii a[N],b[N];

inline int sov(int n,const pii * arr,int len) {
	if(!n) return 0;
	priority_queue<pii,vector<pii>,greater<pii> > q;
	int ret=0;
	for(int i=1;i<=len;i++) {
//		printf("ENTER: %d %d\n",arr[i].fi,arr[i].se);
		while(!q.empty() && q.top().fi<=arr[i].fi) {
//			printf("POP: %d %d\n",q.top().se,q.top().fi);
			q.pop();
		}
		if(q.size()<1u*n) {
//			printf("PUSH: %d %d\n",arr[i].fi,arr[i].se);
			q.push({arr[i].se,arr[i].fi});
			ret++;
		}
	}
	return ret;
}

int n,m1,m2;

int main() {
	
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	
	scanf("%d%d%d",&n,&m1,&m2);
	for(int i=1;i<=m1;i++) {
		scanf("%d%d",&a[i].fi,&a[i].se);
	}
	for(int i=1;i<=m2;i++) {
		scanf("%d%d",&b[i].fi,&b[i].se);
	}
	sort(a+1,a+1+m1);
	sort(b+1,b+1+m2);
//	for(int i=1;i<=m1;i++) {
//		printf("%d %d\n",a[i].fi,a[i].se);
//	}
//	for(int i=1;i<=m2;i++) {
//		printf("%d %d\n",b[i].fi,b[i].se);
//	}
	int ans=-INF;
	for(int i=0,t1,t2;i<=n;i++) {
		t1=sov(i,a,m1),t2=sov(n-i,b,m2);
		ans=max(ans,t1+t2);
//		printf("d: %d %d t: %d %d ans: %d\n",i,n-i,t1,t2,ans);
	}
	printf("%d\n",ans);
	return 0;
}
