#include<cstdio>
#include<algorithm>
#include<iostream>
#include<queue>
using namespace std;
typedef long long lli;
lli n,a[60];
bool tr(lli p) {
	vector<lli>b;
	for(lli ii=n+n-1,l=1,r=n+n; ii>=0; ii--) {
		if((p>>ii)&1) {
			b.push_back(a[r--]);
		} else {
			b.push_back(a[l++]);
		}
	}
	for(lli i=0; i<n; i++) {
		if(b[i]!=b[n+n-i-1]) {
			return 0;
		}
	}
	return 1;
}
int main() {
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	lli t;
	scanf("%lli",&t);
	while(t--) {
		scanf("%lli",&n);
		for(lli i=1; i<=n+n; i++) {
			scanf("%lli",&a[i]);
		}
		a[n+n+1]=0;
		lli aa=1;
		for(lli i=0; i<(1<<(n+n)); i++) {
			if(tr(i)) {
				for(lli ii=n+n-1; ii>=0; ii--) {
					if((i>>ii)&1) {
						printf("R");
					} else {
						printf("L");
					}
				}
				printf("\n");
				aa=0;
				break;
			}
		}
		if(aa) {
			printf("-1\n");
		}
	}
	return 0;
}

