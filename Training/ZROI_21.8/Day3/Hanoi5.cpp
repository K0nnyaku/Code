#include<cstdio>
#include<algorithm>
using namespace std;

int t;

int main() {
	scanf("%d", &t);
	while(t--) {
		int x, y;
		scanf("%d%d", &x, &y);
		printf("%llu\n", (long long)1 << (x - y));
	}

	return 0;
}
