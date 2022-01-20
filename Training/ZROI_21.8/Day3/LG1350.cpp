#include<cstdio>
#include<algorithm>
using namespace std;
const int MAXN = 2e3 + 10;
const int P = 1e5 + 3;

int A[MAXN][MAXN];
int a, b, c, d, k;

int main() {
	scanf("%d%d%d%d%d", &a, &b, &c, &d, &k);

	for(int i = 1; i <= d + b; i++) A[i][0] = 1;

	A[0][0] = 1;
	for(int i = 1; i <= c; i++) {
		for(int j = 0; j <= k; j++) 
			A[i][j] = (A[i-1][j] + A[i-1][j-1] * (d - j + 1)) % P;
	}

	for(int i = c+1; i <= c + a; i++) {
		for(int j = 0; j <= k; j++)
			A[i][j] = (A[i-1][j] + A[i-1][j-1] * (d + b - j + 1)) % P;
	}

	printf("%d", A[a+c][k]);

	return 0;
}
