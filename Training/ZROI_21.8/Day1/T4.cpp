#include<cstdio>
#include<algorithm>
using namespace std;
const int MAXN = 3e2 + 10;
const int MAXM = 3e2 + 10;

long long Mp[MAXN][MAXM], Q[MAXN][MAXM];
long long n, m, k, ans;
long long read();

int main() {
	freopen("In.in", "r", stdin);
	n = read(); m = read(); k = read();

	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= m; j++) {
			Mp[i][j] = read();
			Mp[i][j] -= k;
		}
	}

	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= m; j++) {
			Q[i][j] = Q[i-1][j] + Q[i][j-1] - Q[i-1][j-1] + Mp[i][j];
		}

	for(int x1 = 1; x1 <= n; x1++) 
		for(int y1 = 1; y1 <= m; y1++) 
			for(int x2 = x1; x2 <= n; x2++) 
				for(int y2 = y1; y2 <= m; y2++) {

					long long sum = Q[x2][y2] - Q[x2][y1-1] - Q[x1-1][y2] + Q[x1-1][y1-1];
					long long ar = (x2 - x1 + 1) * (y2 - y1 + 1), t = 0;
					if(sum >= k) ans = max(ans, ar);
//					printf("x1 = %d, y1 = %d, x2 = %d, y2 = %d, sum = %d, ar = %d\n",
//							x1, y1, x2, y2, sum, ar);
				}


	printf("%lld", ans);

	return 0;
}

inline long long read()
{
	long long x=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9'){if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9'){x=x*10+ch-48;ch=getchar();}
	return x*f;
}







