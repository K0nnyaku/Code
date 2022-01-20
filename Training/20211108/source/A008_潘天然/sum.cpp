#include<cstdio>
#define int long long
using namespace std;
const int N = 5e4 + 55;
int n, Ans, A[N], Mod = 1e9 + 7;

signed main() {
	freopen("sum.in","r",stdin);
	freopen("sum.out","w",stdout);
	scanf("%lld",&n);
	for (int i = 1; i <= n; i++)	scanf("%lld",&A[i]);
	
	for (int i = 1; i <= n; i++) {
		for (int j = i; j <= n; j++) {
			int Sum = (A[i] ^ A[j]) % Mod;
			Sum = Sum * Sum % Mod; 
			Ans = (Ans + Sum) % Mod;
			if (i != j)	Ans = (Ans + Sum) % Mod;
		}
	}
	
	printf("%lld",Ans);
	return 0;
}
