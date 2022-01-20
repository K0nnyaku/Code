#include<iostream>
#include<cstring>
#include<queue>
#define N 100001
using namespace std;

long long  a[N],b[N],t[N];
long long T,maxn = 0;
long long tp,cnt = 0,bak,A;

bool check() {
	for(long long i = 1;i <= maxn;i ++) {
		if(t[i] && t[i] != 2) return false;
	}
	return 1;
}

void PT(long long x,long long n) {
	for(long long j = n;j >= 0;j --) {
		if(x >> j & 1) cout<<"R";
		else cout<<"L";
	}
}

int main() {
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	cin>>T;
	for(long long i = 1;i <= T;i ++) {
		long long n;
		cin>>n;
		maxn = 0;
		tp = 1;
		bak = 2*n;
		cnt = 0;
		memset(a,0,sizeof(a));
		A = 1; 
		for(long long i = 1;i <= 2*n;i ++) {
			cin>>a[i];
			t[i] ++;
			maxn = max(maxn,a[i]);
		}
		if(check()) {
			cout<<"-1"<<endl;
			continue;
		}
		for(long long  x = 0;x <= 1 << (2*n+1) -1;x ++) {
			tp = 1;
			bak = 2*n;
			cnt = 0;
			memset(b,0,sizeof(0));
			for(long long  j = 2*n - 1;j >= 0;j --) {
				if(x >> j& 1) {
					b[++cnt] = a[bak];
					bak --;
				}
				else {
					b[++cnt] = a[tp];
					tp ++;
				}
			}
			A = 1;
			for(long long j = 1;j <= n;j ++) {
				if(b[j] != b[2*n-j+1]) {
					A = 0;
					break; 
				}
			}
			if(A) { PT(x,2*n-1);cout<<endl;break;} 
		}
		if(!A)	cout<<"-1"<<endl;
	}
	return 0;
}
