#include<cstdio>
#include<algorithm>
using namespace std;

int n, m, q;

int main() {
	freopen("In.in", "r", stdin);

	scanf("%d%d", &n, &m);
	int** C = new int* [n+10];
	for(int i = 0; i < n + 10; i++) C[i] = new int [m+10];

	for(int i = 0; i < n + 10; i++) 
		for(int j = 0; j < m + 10; j++) C[i][j] = 0;
	
	scanf("%d", &q);
	while(q--) {
		int a, b, x, y;
		scanf("%d%d%d%d", &a, &b, &x, &y);
		a = n - a + 1; x = n - x + 1;
		C[]<++>

	}

	return 0;
}











