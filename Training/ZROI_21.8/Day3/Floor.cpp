#include<cstdio>
using namespace std;
const int MAXN = 30 + 10;

long long f[MAXN] = {0, 1, 2};

int main() {
	freopen("In.in", "r", stdin);

	for(int i = 3; i <= 30; i++) {
		f[i] = f[i-1] + f[i-2];
	}

	int x;
	while(~scanf("%d", &x)) {
		printf("%lld\n", f[x]);
	}

	return 0;
}
