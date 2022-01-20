#include<cstdio>
#include<algorithm>
using namespace std;

int n, m, q;

int main() {
	freopen("In.in", "r", stdin);

	scanf("%d%d", &n, &m);
//	int A[n][m];
	int** Q = new int*[n+1];
	for(int i = 0; i <= n; i++) Q[i] = new int[m+1];

	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= m; j++) {
			scanf("%d", &Q[i][j]);
			Q[i][j] += Q[i-1][j] + Q[i][j-1] - Q[i-1][j-1];
		}

	scanf("%d", &q);
//	for(int i = 1; i <= n; i++) {
//		for(int j = 1; j <= m; j++)
//			printf("%d ", A[i][j]);
//		printf("\n");
//	}
//
//	printf("\n");
//
//	for(int i = 1; i <= n; i++) {
//		for(int j = 1; j <= m; j++)
//			printf("%d ", Q[i][j]);
//		printf("\n");
//	}

	while(q--) {
		int x, y, a, b;
		scanf("%d%d%d%d", &a, &b, &x, &y);
		printf("%d\n", Q[x][y] - Q[a-1][y] - Q[x][b-1] + Q[a-1][b-1]);
	}

	return 0;
}
