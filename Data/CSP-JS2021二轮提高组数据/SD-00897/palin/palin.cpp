#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
#define N 400010
#define int long long
typedef long long ll;
using namespace std;

int T,n,a[N],b[N];
ll pos = 2147483647;
void work(ll x){
	int head = 0,tail = n+n;
	for(ll i=n+n-1,j=1;i>=0;i--,j++){
		if(((x>>i) & 1)){
			b[j] = a[tail];
			tail--;
		}
		else b[j] = a[++head];
	}
	int tmp = 0;
	for(int i=1;i<=n+n;i++){
		if(b[i] == b[n+n-i+1]) tmp++;
	}
	if(tmp == n*2){
		pos = min(pos,x);
	}
}

signed main(){
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	scanf("%lld",&T);
	while(T--){
		scanf("%lld",&n);
		pos = 1e18;
		for(int i=1;i<=n+n;i++){
			scanf("%lld",&a[i]);
		}
		int kk = (1ll<<(n+n));
		for(ll i=0;i<=kk;i++){
			work(i);
		}
		if(pos == 1e18){
			printf("-1\n");
		}
		else{
			for(ll i=n+n-1;i>=0;i--){
				if((pos>>i) & 1){
					printf("R");
				}
				else printf("L");
			}
			printf("\n");
		}
	}
	return 0;
}

