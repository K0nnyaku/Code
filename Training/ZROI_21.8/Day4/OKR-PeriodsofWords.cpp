#include<cstdio>
#include<algorithm>
using namespace std;
const int MAXN = 1e6 + 10;

int Next[MAXN], F[MAXN];
int k;
char A[MAXN];

int main() {
	#ifdef LOCAL
		freopen("In.in", "r", stdin);
	#endif

	scanf("%d", &k);
	scanf("%s", A + 1);

	for(int i = 2, j = 0; i <= k; i++) {
		while(j && A[j+1] != A[i])	j = Next[j];
		if(A[i] == A[j+1]) Next[i] = ++j;
	}

	long long ans = 0;
	for(int i = 1; i <= k; i++) {
		int j = i;
		while(Next[j]) j = Next[j];
		if(Next[i]) Next[i] = j;
		ans += i - j;
	}

	printf("%lld", ans);

	return 0;
}
