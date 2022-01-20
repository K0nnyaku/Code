#include<cstdio>
#include<algorithm>
using namespace std;
const int P = 1e9 + 7;

long long n, ans;
int main() {
//	freopen("In.in", "r", stdin);

	scanf("%lld", &n);
	printf("%lld", ((n * (n + 1) / 2) + 1) % P);

	return 0;
}
