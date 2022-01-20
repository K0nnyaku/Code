#include<cstdio>
#include<algorithm>
using namespace std;
const int MAXN = 1e6 + 10;

long long A[MAXN];
long long n, ans;

int main() {
	freopen("In.in", "r", stdin);

	scanf("%lld", &n);
	for(int i = 1; i <= n; i++) scanf("%lld", &A[i]);
	
	for(int i = 1; i < n; i++) {
		int t = min(A[i], A[i+1]);
		A[i] -= t;
		A[i+1] -= t;
		ans += t;
	}

	printf("%lld", ans);
	

	return 0;
}

