#include<cstdio>
#include<algorithm>
using namespace std;
const int MAXN = 1e3 + 10;

int C[MAXN][MAXN], A[MAXN][MAXN];
int n, m;

int main() {
	freopen("In.in", "r", stdin);

	scanf("%d%d", &n, &m);

	while(m--) {
		int a, b, x, y;
		scanf("%d%d%d%d", &a, &b, &x, &y);
		C[a][b]++;
		C[a][y+1]--;
		C[x+1][b]--;
		C[x+1][y+1]++;
	}

//	for(int i = 1; i <= n; i++) {
//		for(int j = 1; j <= n; j++)
//			printf("%d ", C[i][j]);
//		printf("\n");
//	}
//
//	printf("\n");

	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= n; j++)
			C[i][j] += C[i-1][j] + C[i][j-1] - C[i-1][j-1];
	}
	
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= n; j++) 
			printf("%d ", C[i][j]);
		printf("\n");
	}



	return 0;
}

