#include<cstdio>
#include<algorithm>
using namespace std;
const int MAXN = 2e5 + 10;
const int P = 13331;

unsigned long long H[50][MAXN], E[MAXN] = {1};
int n, m;
char A[MAXN];

int main() {
#ifdef LOCAL
	freopen("In.in", "r", stdin);
    freopen("Out.out", "w", stdout);
#endif

	scanf("%d%d", &n, &m);
	scanf("%s", A+1);

	for(int i = 1; i <= n; i++) 
		E[i] = E[i-1] * P;

	for(int j = 0; j < 26; j++) 
		for(int i = 1; i <= n; i++) {
			H[j][i] = H[j][i-1] * P + (A[i] - 'a' == j);
		}

	while(m--) {
		int x, a, k;
		bool flag = 0;
		scanf("%d%d%d", &x, &a, &k);

		unsigned long long TF[50], TS[50];
		for(int i = 0; i < 26; i++) {
			TF[i] = H[i][x+k-1] - H[i][x-1] * E[k];
			TS[i] = H[i][a+k-1] - H[i][a-1] * E[k];
		}

		sort(TF, TF + 26); sort(TS, TS + 26);

		for(int i = 0; i < 26; i++) 
			if(TF[i] != TS[i]) {
				printf("NO\n");
				flag = 1; break;
			}

		if(!flag) printf("YES\n");
	}

	return 0;
}

