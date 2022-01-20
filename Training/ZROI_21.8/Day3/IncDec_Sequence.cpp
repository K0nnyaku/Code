#include<cstdio>
#include<algorithm>
using namespace std;
const int MAXN = 1e5 + 10;

long long A[MAXN], C[MAXN];
int n;

long long Abs(long long x);

int main() {
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) scanf("%lld", &A[i]);
	for(int i = 1; i <= n; i++) C[i] = A[i] - A[i-1];

	long long pos = 0, neg = 0;
	for(int i = 2; i <= n; i++) {
		pos += C[i] > 0 ? C[i] : 0;
		neg += C[i] < 0 ? -C[i] : 0;
	}

	printf("%lld\n", max(pos, neg));
	printf("%lld", Abs(pos - neg) + 1);

	return 0;
}

long long Abs(long long x) {
	return x < 0 ? -x : x;
}
