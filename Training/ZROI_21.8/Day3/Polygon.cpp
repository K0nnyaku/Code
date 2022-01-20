#include<cstdio>
#include<algorithm>
using namespace std;
const int MAXN = 21 + 10;

int F[MAXN] = {1};

int main() {
//	freopen("In.in", "r", stdin);

	for(int i = 1; i <= MAXN; i++) {
		for(int j = 0; j <= MAXN - i; j++) F[i] += F[j] * F[MAXN-j-1];
	}

	int x;
	while(~scanf("%d", &x)) {
		printf("%d", F[x-1]);
	}

	return 0;
}
