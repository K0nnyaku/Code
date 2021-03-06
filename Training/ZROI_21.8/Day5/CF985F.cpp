#include<cstdio>
#include<algorithm>
using namespace std;
const int MAXN = 2e5 + 10;
const int P = 13331;
const int MOD = 1e9 + 7;

unsigned long long H[50][MAXN], E[MAXN] = {1};
int n, m;
char A[MAXN];

int main() {
	#ifdef LOCAL
		freopen("In.in", "r", stdin);
	#endif

	scanf("%d%d", &n, &m);
	scanf("%s", A+1);

	for(int i = 1; i <= n; i++) 
		E[i] = ((E[i-1] % MOD) * P) % MOD;

	for(int j = 0; j < 26; j++) 
		for(int i = 1; i <= n; i++) {
			H[j][i] = (((H[j][i-1] % MOD) * P) % MOD + (A[i] - 'a' == j)) % MOD;
		}

	while(m--) {
		int x, a, k;
		bool flag = 0;
		scanf("%d%d%d", &x, &a, &k);

		unsigned long long TF[50], TS[50];
		for(int i = 0; i < 26; i++) {
			TF[i] = (H[i][x+k-1] % MOD - ( (H[i][x-1] % MOD) * (E[k] % MOD) % MOD) + MOD) % MOD;  
			TS[i] = (H[i][a+k-1] % MOD - ( (H[i][a-1] % MOD) * (E[k] % MOD) % MOD) + MOD) % MOD;  
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

