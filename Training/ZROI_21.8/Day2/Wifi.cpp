#include<cstdio>
#include<algorithm>
using namespace std;
const int MAXN = 129;

long long Mp[MAXN][MAXN];
long long ans, way;
int d, w, mxx, mxy;

long long Check(int x, int y);

int main() {
	freopen("In.in", "r", stdin);

	scanf("%d%d", &d, &w);
	for(int i = 1; i <= w; i++) {
		int x, y;
		scanf("%d%d", &x, &y);
		if(x > 128 || y > 128) continue;
		scanf("%lld", &Mp[x][y]);
		mxx = max(mxx, x);
		mxy = max(mxy, y);
	}

	for(int i = 0; i <= 128; i++) 
		for(int j = 0; j <= 128; j++) {
			long long T = Check(i, j);
//			printf("i = %d, j = %d\n", i, j);
			if(T > ans) {
				ans = T;
				way = 1;
			}else if(T == ans) way++;
		}

	printf("%lld %lld", way, ans);	

	return 0;
}

long long Check(int x, int y) {
	long long sum = 0;
	for(int i = max(x - d, 0); i <= min(x + d, 128); i++)
		for(int j = max(y - d, 0); j <= min(y + d, 128); j++) {
			sum += Mp[i][j];
		}
	return sum;
}











