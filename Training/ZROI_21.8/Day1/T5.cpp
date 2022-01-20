#include<cstdio>
#include<algorithm>
using namespace std;
const int MAXN = 2e5 + 10;
const double E = 1e-7;


double A[MAXN], B[MAXN];
double v, sum;
int n, iNdex = 1, ans;

int main() {
	freopen("In.in", "r", stdin);

	scanf("%d%lf", &n, &v);
	for(int i = 1; i <= n; i++) {
		scanf("%lf%lf", &A[i], &B[i]);
	}

	sort(B + 1, B + n + 1);

	int L = 0, R = n;
	while(L < R) {
		int mid = (L + R + 1) >> 1;
		if(v / mid - B[mid] >= E) L = mid;
		else R = mid - 1;
	}

	printf("%d", L);

	return 0;
}
