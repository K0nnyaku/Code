#include<cstdio>
#include<algorithm>
using namespace std;
const int MAXF = 15 + 10;

long long F[MAXF][MAXF];

long long Qy(int n, int k);

int main() {
	freopen("In.in", "r", stdin);

	int x;
	while(~scanf("%d", &x)) {
		long long sum = 0;
		if(x == 0) printf("%d\n", 1);
		else {
			for(int i = 1; i <= x; i++) {
				sum += Qy(x, i);
			}
			printf("%d\n", sum);
		}
	}

	return 0;
}

long long Qy(int n, int k) {
	if(n < k) return 0;
	if(n == k || k == 1) return 1;

	return (F[n-1][k-1] ? F[n-1][k-1] : F[n-1][k-1] = Qy(n-1, k-1)) + k * (F[n-1][k] ? F[n-1][k] : F[n-1][k] = Qy(n-1, k));
}
