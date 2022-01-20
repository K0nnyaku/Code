#include<cstdio>
#include<algorithm>
using namespace std;
const int MAXN = 1e2 + 10;

long long ans;
int A[MAXN];
int n;


int main() {
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) {
		if(i % 7 && (i%10) != 7 && i / 10 != 7) {
			ans += i * i;
		}
	}

	printf("%lld", ans);

	return 0;
}
